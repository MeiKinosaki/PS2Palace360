#include "ee_decode.h"
#include "ee_ops.h"
#include "ee_immediate.h"
#include "ee_compare.h"
#include <stddef.h>
#include <limits.h>

static uint64_t abs_u64(int64_t x) { uint64_t u=(uint64_t)x; return x < 0 ? (~u + 1u) : u; }

/* Portable 64x64 -> 128-bit product using 32-bit limbs. */
static void mul_u64_128(uint64_t a, uint64_t b, uint64_t *hi, uint64_t *lo)
{
    uint64_t a0=(uint32_t)a, a1=a>>32, b0=(uint32_t)b, b1=b>>32;
    uint64_t p0=a0*b0, p1=a0*b1, p2=a1*b0, p3=a1*b1;
    uint64_t middle=(p0>>32)+(uint32_t)p1+(uint32_t)p2;
    *lo=(middle<<32)|(uint32_t)p0;
    *hi=p3+(p1>>32)+(p2>>32)+(middle>>32);
}

static uint32_t arithmetic_shift_right_u32(uint32_t value, unsigned amount)
{
    if (amount == 0u) return value;
    if (amount >= 32u) amount = 31u;
    if ((value & UINT32_C(0x80000000)) == 0u) return value >> amount;
    return (value >> amount) | (UINT32_MAX << (32u - amount));
}

static uint64_t arithmetic_shift_right_u64(uint64_t value, unsigned amount)
{
    if (amount == 0u) return value;
    if (amount >= 64u) amount = 63u;
    if ((value & UINT64_C(0x8000000000000000)) == 0u) return value >> amount;
    return (value >> amount) | (UINT64_MAX << (64u - amount));
}

static int load_value(ps2_ee_memory_t *mem, uint32_t address, unsigned width, int sign_extend, uint64_t *out)
{
    uint64_t v;
    if (ps2_ee_mem_load(mem, address, width, &v) != 0) return -1;
    if (sign_extend && width < 8u) { unsigned bits = width * 8u; uint64_t sign = UINT64_C(1) << (bits - 1u); if ((v & sign) != 0u) v |= UINT64_MAX << bits; }
    *out = v; return 0;
}

ps2_ee_step_result_t ps2_ee_execute_word(ps2_ee_state_t *s, uint32_t insn)
{
    unsigned op, rs, rt, rd, fn, shamt;
    int rc = -1; uint64_t a, b, v; int16_t imm;
    if (s == NULL) return PS2_EE_STEP_INVALID;
    op=insn>>26; rs=(insn>>21)&31u; rt=(insn>>16)&31u; rd=(insn>>11)&31u; shamt=(insn>>6)&31u; fn=insn&63u;
    a=s->gpr[rs]; b=s->gpr[rt]; imm=(int16_t)insn;
    switch(op) {
    case 0:
        switch(fn) {
        case 0x00: v=(uint32_t)b<<shamt; if(rd)s->gpr[rd]=(uint64_t)(int64_t)(int32_t)v; break;
        case 0x02: v=(uint32_t)b>>shamt; if(rd)s->gpr[rd]=(uint64_t)(int64_t)(int32_t)v; break;
        case 0x03: v=(uint64_t)(int64_t)(int32_t)arithmetic_shift_right_u32((uint32_t)b,shamt); if(rd)s->gpr[rd]=v; break;
        case 0x04: v=(uint32_t)b<<((unsigned)a&31u); if(rd)s->gpr[rd]=(uint64_t)(int64_t)(int32_t)v; break;
        case 0x06: v=(uint32_t)b>>((unsigned)a&31u); if(rd)s->gpr[rd]=(uint64_t)(int64_t)(int32_t)v; break;
        case 0x07: v=(uint64_t)(int64_t)(int32_t)arithmetic_shift_right_u32((uint32_t)b,(unsigned)a&31u); if(rd)s->gpr[rd]=v; break;
        case 0x10: if(rd)s->gpr[rd]=s->hi; break;
        case 0x11: s->hi=a; break;
        case 0x12: if(rd)s->gpr[rd]=s->lo; break;
        case 0x13: s->lo=a; break;
        case 0x14: if(rd)s->gpr[rd]=b<<((unsigned)a&63u); break; /* DSLLV */
        case 0x16: if(rd)s->gpr[rd]=b>>((unsigned)a&63u); break; /* DSRLV */
        case 0x17: if(rd)s->gpr[rd]=arithmetic_shift_right_u64(b,(unsigned)a&63u); break; /* DSRAV */
        case 0x18: { int64_t product=(int64_t)(int32_t)a*(int64_t)(int32_t)b; uint64_t bits=(uint64_t)product; s->lo=(uint64_t)(int64_t)(int32_t)bits; s->hi=(uint64_t)(int64_t)(int32_t)(bits>>32); break; }
        case 0x19: { uint64_t product=(uint64_t)(uint32_t)a*(uint64_t)(uint32_t)b; s->lo=(uint64_t)(int64_t)(int32_t)product; s->hi=(uint64_t)(int64_t)(int32_t)(product>>32); break; }
        case 0x1a: { int32_t x=(int32_t)a, y=(int32_t)b; if(y!=0) { if(x==INT32_MIN && y==-1) { s->lo=(uint64_t)(int64_t)INT32_MIN; s->hi=0; } else { s->lo=(uint64_t)(int64_t)(x/y); s->hi=(uint64_t)(int64_t)(x%y); } } break; }
        case 0x1b: { uint32_t x=(uint32_t)a, y=(uint32_t)b; if(y!=0u) { s->lo=(uint64_t)(int64_t)(int32_t)(x/y); s->hi=(uint64_t)(int64_t)(int32_t)(x%y); } break; }
        case 0x1c: { uint64_t x=abs_u64((int64_t)a), y=abs_u64((int64_t)b), hi, lo; mul_u64_128(x,y,&hi,&lo); if(((int64_t)a<0)!=((int64_t)b<0)){ lo=~lo+1u; hi=~hi+(lo==0u); } s->hi=hi; s->lo=lo; break; } /* DMULT */
        case 0x1d: mul_u64_128(a,b,&s->hi,&s->lo); break; /* DMULTU */
        case 0x1e: { int64_t x=(int64_t)a,y=(int64_t)b; if(y!=0){ if(x==INT64_MIN&&y==-1){s->lo=(uint64_t)INT64_MIN;s->hi=0;}else{s->lo=(uint64_t)(x/y);s->hi=(uint64_t)(x%y);} } break; } /* DDIV */
        case 0x1f: if(b!=0u){s->lo=a/b;s->hi=a%b;} break; /* DDIVU */
        case 0x2c: { uint64_t z=a+b; if ((((~(a^b)) & (a^z)) >> 63) != 0u) { ps2_ee_raise_exception(s, s->pc - UINT32_C(4), 12u, 0); return PS2_EE_STEP_EXCEPTION; } if(rd)s->gpr[rd]=z; break; } /* DADD */
        case 0x2d: if(rd)s->gpr[rd]=a+b; break; /* DADDU */
        case 0x2e: { uint64_t z=a-b; if ((((a^b) & (a^z)) >> 63) != 0u) { ps2_ee_raise_exception(s, s->pc - UINT32_C(4), 12u, 0); return PS2_EE_STEP_EXCEPTION; } if(rd)s->gpr[rd]=z; break; } /* DSUB */
        case 0x2f: if(rd)s->gpr[rd]=a-b; break; /* DSUBU */
        case 0x38: if(rd)s->gpr[rd]=b<<shamt; break;
        case 0x3a: if(rd)s->gpr[rd]=b>>shamt; break;
        case 0x3b: if(rd)s->gpr[rd]=arithmetic_shift_right_u64(b,shamt); break;
        case 0x3c: if(rd)s->gpr[rd]=b<<(shamt+32u); break; /* DSLL32 */
        case 0x3e: if(rd)s->gpr[rd]=b>>(shamt+32u); break; /* DSRL32 */
        case 0x3f: if(rd)s->gpr[rd]=arithmetic_shift_right_u64(b,shamt+32u); break; /* DSRA32 */
        case 0x08: s->next_pc=(uint32_t)a; break;
        case 0x09: if(rd)s->gpr[rd]=(uint32_t)(s->pc+4u); s->next_pc=(uint32_t)a; break;
        case 0x20: rc=ps2_ee_add32(s,rd,rs,rt); if(rc==1){ps2_ee_raise_exception(s,s->pc-UINT32_C(4),12u,0);return PS2_EE_STEP_EXCEPTION;} goto done;
        case 0x21: rc=ps2_ee_addu32(s,rd,rs,rt); goto done;
        case 0x22: rc=ps2_ee_sub32(s,rd,rs,rt); if(rc==1){ps2_ee_raise_exception(s,s->pc-UINT32_C(4),12u,0);return PS2_EE_STEP_EXCEPTION;} goto done;
        case 0x23: rc=ps2_ee_subu32(s,rd,rs,rt); goto done;
        case 0x24: rc=ps2_ee_logic(s,rd,rs,rt,PS2_EE_LOGIC_AND); goto done;
        case 0x25: rc=ps2_ee_logic(s,rd,rs,rt,PS2_EE_LOGIC_OR); goto done;
        case 0x26: rc=ps2_ee_logic(s,rd,rs,rt,PS2_EE_LOGIC_XOR); goto done;
        case 0x27: rc=ps2_ee_logic(s,rd,rs,rt,PS2_EE_LOGIC_NOR); goto done;
        case 0x2a: rc=ps2_ee_slt64(s,rd,rs,rt); goto done;
        case 0x2b: rc=ps2_ee_sltu64(s,rd,rs,rt); goto done;
        case 0x0a: rc=ps2_ee_movz(s,rd,rs,rt); goto done;
        case 0x0b: rc=ps2_ee_movn(s,rd,rs,rt); goto done;
        default: return PS2_EE_STEP_UNSUPPORTED;
        } break;
    case 0x02: s->next_pc=(s->pc&UINT32_C(0xf0000000))|((insn&UINT32_C(0x03ffffff))<<2); break;
    case 0x03: s->gpr[31]=(uint32_t)(s->pc+4u); s->next_pc=(s->pc&UINT32_C(0xf0000000))|((insn&UINT32_C(0x03ffffff))<<2); break;
    case 0x04: if((uint32_t)a==(uint32_t)b)s->next_pc=s->pc+((int32_t)imm*4); break;
    case 0x05: if((uint32_t)a!=(uint32_t)b)s->next_pc=s->pc+((int32_t)imm*4); break;
    case 0x06: if((int64_t)a<=0)s->next_pc=s->pc+((int32_t)imm*4); break;
    case 0x07: if((int64_t)a>0)s->next_pc=s->pc+((int32_t)imm*4); break;
    case 0x08: rc=ps2_ee_addi32(s,rt,rs,imm); if(rc==1){ps2_ee_raise_exception(s,s->pc-UINT32_C(4),12u,0);return PS2_EE_STEP_EXCEPTION;} goto done;
    case 0x09: rc=ps2_ee_addiu32(s,rt,rs,imm); goto done;
    case 0x0a: rc=ps2_ee_slti64(s,rt,rs,imm); goto done;
    case 0x0b: rc=ps2_ee_sltiu64(s,rt,rs,imm); goto done;
    case 0x0c: if(rt)s->gpr[rt]=a&(insn&0xffffu); break;
    case 0x0d: if(rt)s->gpr[rt]=a|(insn&0xffffu); break;
    case 0x0e: if(rt)s->gpr[rt]=a^(insn&0xffffu); break;
    case 0x0f: rc=ps2_ee_lui(s,rt,(uint16_t)insn); goto done;
    case 0x18: { uint64_t addend=(uint64_t)(int64_t)imm, z=a+addend; if ((((~(a^addend)) & (a^z)) >> 63) != 0u) { ps2_ee_raise_exception(s, s->pc - UINT32_C(4), 12u, 0); return PS2_EE_STEP_EXCEPTION; } if(rt)s->gpr[rt]=z; break; } /* DADDI */
    case 0x19: if(rt)s->gpr[rt]=a+(uint64_t)(int64_t)imm; break; /* DADDIU */
    default: return PS2_EE_STEP_UNSUPPORTED;
    }
    s->gpr[0]=0; return PS2_EE_STEP_OK;
done:
    if(rc==-1)return PS2_EE_STEP_INVALID; if(rc==1)return PS2_EE_STEP_UNSUPPORTED; s->gpr[0]=0; return PS2_EE_STEP_OK;
}

ps2_ee_step_result_t ps2_ee_execute_memory_word(ps2_ee_state_t *s, ps2_ee_memory_t *mem, uint32_t insn)
{
    unsigned op,rs,rt,width=0; uint32_t address; uint64_t value; int store=0,sign_extend=0;
    if(s==NULL||mem==NULL)return PS2_EE_STEP_INVALID;
    op=insn>>26;rs=(insn>>21)&31u;rt=(insn>>16)&31u;
    switch(op){case 0x20:width=1;sign_extend=1;break;case 0x24:width=1;break;case 0x21:width=2;sign_extend=1;break;case 0x25:width=2;break;case 0x23:width=4;sign_extend=1;break;case 0x27:width=4;break;case 0x37:width=8;break;case 0x28:width=1;store=1;break;case 0x29:width=2;store=1;break;case 0x2b:width=4;store=1;break;case 0x3f:width=8;store=1;break;default:return ps2_ee_execute_word(s,insn);}
    address=(uint32_t)s->gpr[rs]+(uint32_t)(int32_t)(int16_t)insn;
    if(store){if(ps2_ee_mem_store(mem,address,width,s->gpr[rt])!=0)return PS2_EE_STEP_INVALID;}
    else{if(load_value(mem,address,width,sign_extend,&value)!=0)return PS2_EE_STEP_INVALID;if(rt)s->gpr[rt]=value;s->gpr[0]=0;}
    return PS2_EE_STEP_OK;
}

ps2_ee_step_result_t ps2_ee_step(ps2_ee_state_t *s, ps2_ee_memory_t *mem)
{
    uint64_t raw; ps2_ee_step_result_t result;
    if(s==NULL||mem==NULL)return PS2_EE_STEP_INVALID;
    if(ps2_ee_mem_load(mem,s->pc,4,&raw)!=0)return PS2_EE_STEP_INVALID;
    s->pc=s->next_pc;s->next_pc+=4u;
    result=ps2_ee_execute_memory_word(s,mem,(uint32_t)raw);s->gpr[0]=0;return result;
}

/* V2.0.19b: execute scalar load/store instructions through the experimental
 * direct-map/TLB memory path. Translation faults are surfaced as INVALID for
 * now; architectural CP0/TLB exception delivery remains future work. */
ps2_ee_step_result_t ps2_ee_execute_memory_word_tlb(ps2_ee_state_t *s,
                                                     ps2_ee_memory_t *mem,
                                                     const ps2_ee_tlb_t *tlb,
                                                     uint32_t insn)
{
    unsigned op, rs, rt, width = 0;
    uint32_t address;
    uint64_t value;
    int store = 0, sign_extend = 0, status;
    if (s == NULL || mem == NULL || tlb == NULL) return PS2_EE_STEP_INVALID;
    op = insn >> 26;
    rs = (insn >> 21) & 31u;
    rt = (insn >> 16) & 31u;
    switch (op) {
    case 0x20: width = 1; sign_extend = 1; break; /* LB */
    case 0x24: width = 1; break;                 /* LBU */
    case 0x21: width = 2; sign_extend = 1; break; /* LH */
    case 0x25: width = 2; break;                 /* LHU */
    case 0x23: width = 4; sign_extend = 1; break; /* LW */
    case 0x27: width = 4; break;                 /* LWU */
    case 0x37: width = 8; break;                 /* LD */
    case 0x28: width = 1; store = 1; break;       /* SB */
    case 0x29: width = 2; store = 1; break;       /* SH */
    case 0x2b: width = 4; store = 1; break;       /* SW */
    case 0x3f: width = 8; store = 1; break;       /* SD */
    default: return ps2_ee_execute_word(s, insn);
    }
    address = (uint32_t)s->gpr[rs] + (uint32_t)(int32_t)(int16_t)insn;
    if (store) {
        status = ps2_ee_mem_store_virtual_tlb(mem, tlb, address, width, s->gpr[rt]);
        if (status != PS2_EE_MEM_OK) return PS2_EE_STEP_INVALID;
    } else {
        status = ps2_ee_mem_load_virtual_tlb(mem, tlb, address, width, &value);
        if (status != PS2_EE_MEM_OK) return PS2_EE_STEP_INVALID;
        if (sign_extend && width < 8u) {
            unsigned bits = width * 8u;
            uint64_t sign = UINT64_C(1) << (bits - 1u);
            if ((value & sign) != 0u) value |= UINT64_MAX << bits;
        }
        if (rt != 0u) s->gpr[rt] = value;
        s->gpr[0] = 0;
    }
    return PS2_EE_STEP_OK;
}
