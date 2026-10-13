#include "ee_decode.h"
#include "ee_ops.h"
#include "ee_immediate.h"
#include "ee_compare.h"
#include <stddef.h>

static int load_value(ps2_ee_memory_t *mem, uint32_t address, unsigned width,
                      int sign_extend, uint64_t *out)
{
    uint64_t v;
    if (ps2_ee_mem_load(mem, address, width, &v) != 0) return -1;
    if (sign_extend && width < 8u) {
        unsigned bits = width * 8u;
        uint64_t sign = UINT64_C(1) << (bits - 1u);
        if ((v & sign) != 0u) v |= UINT64_MAX << bits;
    }
    *out = v;
    return 0;
}

ps2_ee_step_result_t ps2_ee_execute_memory_word(ps2_ee_state_t *s,
                                                ps2_ee_memory_t *mem,
                                                uint32_t insn)
{
    unsigned op, rs, rt, width = 0;
    uint32_t address;
    uint64_t value;
    int store = 0, sign_extend = 0;
    if (s == NULL || mem == NULL) return PS2_EE_STEP_INVALID;
    op = insn >> 26;
    rs = (insn >> 21) & 31u;
    rt = (insn >> 16) & 31u;
    address = (uint32_t)s->gpr[rs] + (uint32_t)(int32_t)(int16_t)insn;
    switch (op) {
    case 0x20: width = 1; sign_extend = 1; break; /* LB */
    case 0x24: width = 1; break;                 /* LBU */
    case 0x21: width = 2; sign_extend = 1; break;/* LH */
    case 0x25: width = 2; break;                 /* LHU */
    case 0x23: width = 4; sign_extend = 1; break;/* LW */
    case 0x27: width = 4; break;                 /* LWU */
    case 0x37: width = 8; break;                 /* LD */
    case 0x28: width = 1; store = 1; break;      /* SB */
    case 0x29: width = 2; store = 1; break;      /* SH */
    case 0x2b: width = 4; store = 1; break;      /* SW */
    case 0x3f: width = 8; store = 1; break;      /* SD */
    default: return PS2_EE_STEP_UNSUPPORTED;
    }
    if (store) {
        if (ps2_ee_mem_store(mem, address, width, s->gpr[rt]) != 0)
            return PS2_EE_STEP_INVALID;
    } else {
        if (load_value(mem, address, width, sign_extend, &value) != 0)
            return PS2_EE_STEP_INVALID;
        if (rt != 0u) s->gpr[rt] = value;
        s->gpr[0] = 0;
    }
    return PS2_EE_STEP_OK;
}

ps2_ee_step_result_t ps2_ee_execute_word(ps2_ee_state_t *s, uint32_t insn)
{
    unsigned op, rs, rt, rd, fn;
    int rc = -1;
    if (s == NULL) return PS2_EE_STEP_INVALID;
    op = insn >> 26; rs = (insn >> 21) & 31u; rt = (insn >> 16) & 31u;
    rd = (insn >> 11) & 31u; fn = insn & 63u;
    switch (op) {
    case 0:
        switch (fn) {
        case 0x20: rc = ps2_ee_add32(s, rd, rs, rt); break;
        case 0x21: rc = ps2_ee_addu32(s, rd, rs, rt); break;
        case 0x22: rc = ps2_ee_sub32(s, rd, rs, rt); break;
        case 0x23: rc = ps2_ee_subu32(s, rd, rs, rt); break;
        case 0x24: rc = ps2_ee_logic(s, rd, rs, rt, PS2_EE_LOGIC_AND); break;
        case 0x25: rc = ps2_ee_logic(s, rd, rs, rt, PS2_EE_LOGIC_OR); break;
        case 0x26: rc = ps2_ee_logic(s, rd, rs, rt, PS2_EE_LOGIC_XOR); break;
        case 0x27: rc = ps2_ee_logic(s, rd, rs, rt, PS2_EE_LOGIC_NOR); break;
        case 0x2a: rc = ps2_ee_slt64(s, rd, rs, rt); break;
        case 0x2b: rc = ps2_ee_sltu64(s, rd, rs, rt); break;
        case 0x0a: rc = ps2_ee_movz(s, rd, rs, rt); break;
        case 0x0b: rc = ps2_ee_movn(s, rd, rs, rt); break;
        default: return PS2_EE_STEP_UNSUPPORTED;
        }
        break;
    case 0x08: rc = ps2_ee_addi32(s, rt, rs, (int16_t)insn); break;
    case 0x09: rc = ps2_ee_addiu32(s, rt, rs, (int16_t)insn); break;
    case 0x0a: rc = ps2_ee_slti64(s, rt, rs, (int16_t)insn); break;
    case 0x0b: rc = ps2_ee_sltiu64(s, rt, rs, (int16_t)insn); break;
    case 0x0f: rc = ps2_ee_lui(s, rt, (uint16_t)insn); break;
    default: return PS2_EE_STEP_UNSUPPORTED;
    }
    if (rc == -1) return PS2_EE_STEP_INVALID;
    if (rc == 1) return PS2_EE_STEP_UNSUPPORTED;
    return PS2_EE_STEP_OK;
}
