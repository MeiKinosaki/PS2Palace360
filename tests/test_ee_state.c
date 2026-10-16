#include "../src/ps2/ee_state.h"
#include "../src/ps2/ee_ops.h"
#include "../src/ps2/ee_immediate.h"
#include "../src/ps2/ee_compare.h"
#include "../src/ps2/ee_decode.h"
#include "../src/ps2/ee_memory.h"
#include <assert.h>
#include <stdint.h>
#include <stdio.h>

int main(void)
{
    ps2_ee_state_t s; uint8_t ram[64]={0}; ps2_ee_memory_t mem={ram,sizeof ram}; uint64_t loaded=0;
    ps2_ee_reset(&s); assert(s.pc==UINT32_C(0xBFC00000)&&s.next_pc==UINT32_C(0xBFC00004)); assert(s.gpr[0]==0);
    s.gpr[1]=20;s.gpr[2]=22;assert(ps2_ee_add32(&s,3,1,2)==0&&s.gpr[3]==42);
    s.gpr[1]=5;s.gpr[2]=9;assert(ps2_ee_sub32(&s,4,1,2)==0&&(int64_t)s.gpr[4]==-4);
    s.gpr[1]=UINT32_C(0x7fffffff);s.gpr[2]=1;assert(ps2_ee_add32(&s,5,1,2)==1);
    s.gpr[1]=UINT32_C(0x80000000);s.gpr[2]=1;assert(ps2_ee_sub32(&s,5,1,2)==1);
    s.gpr[1]=UINT32_MAX;s.gpr[2]=2;assert(ps2_ee_addu32(&s,6,1,2)==0&&(uint32_t)s.gpr[6]==1u);
    assert(ps2_ee_subu32(&s,7,2,1)==0&&(uint32_t)s.gpr[7]==3u);
    s.gpr[1]=UINT64_C(0xF0F0);s.gpr[2]=UINT64_C(0x0FF0);
    assert(ps2_ee_logic(&s,8,1,2,PS2_EE_LOGIC_AND)==0&&s.gpr[8]==0x00F0u);
    assert(ps2_ee_logic(&s,9,1,2,PS2_EE_LOGIC_OR)==0&&s.gpr[9]==0xFFF0u);
    assert(ps2_ee_logic(&s,10,1,2,PS2_EE_LOGIC_XOR)==0&&s.gpr[10]==0xFF00u);
    assert(ps2_ee_logic(&s,11,1,2,PS2_EE_LOGIC_NOR)==0&&s.gpr[11]==~UINT64_C(0xFFF0));
    s.gpr[1]=100;assert(ps2_ee_addi32(&s,12,1,-7)==0&&(int64_t)s.gpr[12]==93);assert(ps2_ee_addiu32(&s,13,1,-7)==0&&(int64_t)s.gpr[13]==93);
    assert(ps2_ee_slti64(&s,14,1,101)==0&&s.gpr[14]==1);assert(ps2_ee_slti64(&s,15,1,99)==0&&s.gpr[15]==0);assert(ps2_ee_sltiu64(&s,16,1,-1)==0&&s.gpr[16]==1);
    assert(ps2_ee_lui(&s,17,UINT16_C(0x1234))==0&&(uint32_t)s.gpr[17]==UINT32_C(0x12340000));
    s.gpr[1]=UINT32_C(0x7fffffff);assert(ps2_ee_addi32(&s,18,1,1)==1);s.gpr[1]=UINT64_MAX;s.gpr[2]=1;
    assert(ps2_ee_slt64(&s,19,1,2)==0&&s.gpr[19]==1);assert(ps2_ee_sltu64(&s,20,1,2)==0&&s.gpr[20]==0);
    s.gpr[2]=0;s.gpr[3]=UINT64_C(0x12345678);assert(ps2_ee_movz(&s,21,3,2)==0&&s.gpr[21]==s.gpr[3]);s.gpr[2]=1;
    assert(ps2_ee_movz(&s,21,1,2)==0&&s.gpr[21]==s.gpr[3]);assert(ps2_ee_movn(&s,22,3,2)==0&&s.gpr[22]==s.gpr[3]);s.gpr[2]=0;assert(ps2_ee_movn(&s,22,1,2)==0&&s.gpr[22]==s.gpr[3]);
    s.gpr[1]=40;s.gpr[2]=2;assert(ps2_ee_execute_word(&s,(1u<<21)|(2u<<16)|(3u<<11)|0x21u)==PS2_EE_STEP_OK&&s.gpr[3]==42);
    assert(ps2_ee_execute_word(&s,(0x08u<<26)|(1u<<21)|(4u<<16)|0xfffbu)==PS2_EE_STEP_OK&&(int64_t)s.gpr[4]==35);
    s.gpr[2]=0x1234;assert(ps2_ee_execute_word(&s,(0x0cu<<26)|(2u<<21)|(5u<<16)|0x00ffu)==PS2_EE_STEP_OK&&s.gpr[5]==0x34u);
    assert(ps2_ee_execute_word(&s,(0x0du<<26)|(2u<<21)|(6u<<16)|0x00ffu)==PS2_EE_STEP_OK&&s.gpr[6]==0x12ffu);
    assert(ps2_ee_execute_word(&s,(0x0eu<<26)|(2u<<21)|(7u<<16)|0x00ffu)==PS2_EE_STEP_OK&&s.gpr[7]==0x12cbu);
    s.gpr[2]=3;assert(ps2_ee_execute_word(&s,(2u<<16)|(3u<<11)|(2u<<6))==PS2_EE_STEP_OK&&s.gpr[3]==12);
    assert(ps2_ee_execute_word(&s,(0x04u<<26)|2u)==PS2_EE_STEP_OK);assert(s.next_pc==s.pc+12u);assert(ps2_ee_execute_word(&s,0xffffffffu)==PS2_EE_STEP_UNSUPPORTED);assert(ps2_ee_execute_word(NULL,0u)==PS2_EE_STEP_INVALID);
    /* DADDU and DSLL32 */
    s.gpr[1]=UINT64_C(0x100000000);s.gpr[2]=7;
    assert(ps2_ee_execute_word(&s,(1u<<21)|(2u<<16)|(3u<<11)|0x2du)==PS2_EE_STEP_OK&&s.gpr[3]==UINT64_C(0x100000007));
    assert(ps2_ee_execute_word(&s,(2u<<16)|(4u<<11)|(1u<<6)|0x3cu)==PS2_EE_STEP_OK&&s.gpr[4]==UINT64_C(0xe00000000));
    /* Portable arithmetic-right-shift helper is exercised through SRA/DSRA paths. */
    s.gpr[1]=UINT64_C(0x8000000000000000); s.gpr[2]=1;
    assert(ps2_ee_execute_word(&s,(1u<<21)|(2u<<16)|(6u<<11)|0x17u)==PS2_EE_STEP_OK && s.gpr[6]==UINT64_C(0xc000000000000000));
    s.gpr[2]=UINT64_C(0x8000000000000000);
    assert(ps2_ee_execute_word(&s,(2u<<16)|(7u<<11)|(1u<<6)|0x3bu)==PS2_EE_STEP_OK && s.gpr[7]==UINT64_C(0xc000000000000000));
    /* Portable 32-bit arithmetic right shifts with sign bit set. */
    s.gpr[1]=UINT32_C(0x80000000); s.gpr[2]=1;
    assert(ps2_ee_execute_word(&s,(1u<<21)|(2u<<16)|(8u<<11)|(1u<<6)|0x03u)==PS2_EE_STEP_OK);
    assert(s.gpr[8]==UINT64_C(0xffffffffc0000000));
    assert(ps2_ee_execute_word(&s,(1u<<21)|(2u<<16)|(9u<<11)|0x07u)==PS2_EE_STEP_OK);
    assert(s.gpr[9]==UINT64_C(0xffffffffc0000000));
    /* Variable 64-bit shifts */
    s.gpr[1]=UINT64_C(0x100000001); s.gpr[2]=3;
    assert(ps2_ee_execute_word(&s,(1u<<21)|(2u<<16)|(3u<<11)|0x14u)==PS2_EE_STEP_OK && s.gpr[3]==UINT64_C(0x800000008));
    s.gpr[1]=4; s.gpr[2]=UINT64_C(0x100000000);
    assert(ps2_ee_execute_word(&s,(1u<<21)|(2u<<16)|(4u<<11)|0x16u)==PS2_EE_STEP_OK && s.gpr[4]==UINT64_C(0x10000000));
    s.gpr[1]=1; s.gpr[2]=UINT64_C(0x8000000000000000);
    assert(ps2_ee_execute_word(&s,(1u<<21)|(2u<<16)|(5u<<11)|0x17u)==PS2_EE_STEP_OK && s.gpr[5]==UINT64_C(0xc000000000000000));
    /* 32-bit ADD, SUB, ADDI overflow should enter exception handler. */
    ps2_ee_reset(&s); s.pc=0x4004; s.status=0; s.gpr[1]=UINT32_C(0x7fffffff); s.gpr[2]=1;
    assert(ps2_ee_execute_word(&s,(1u<<21)|(2u<<16)|(3u<<11)|0x20u)==PS2_EE_STEP_EXCEPTION); assert(s.epc==0x4000u && ((s.cause>>2)&31u)==12u);
    ps2_ee_reset(&s); s.pc=0x5004; s.status=0; s.gpr[1]=UINT32_C(0x80000000); s.gpr[2]=1;
    assert(ps2_ee_execute_word(&s,(1u<<21)|(2u<<16)|(3u<<11)|0x22u)==PS2_EE_STEP_EXCEPTION); assert(s.epc==0x5000u && ((s.cause>>2)&31u)==12u);
    ps2_ee_reset(&s); s.pc=0x6004; s.status=0; s.gpr[1]=UINT32_C(0x7fffffff);
    assert(ps2_ee_execute_word(&s,(0x08u<<26)|(1u<<21)|(2u<<16)|1u)==PS2_EE_STEP_EXCEPTION); assert(s.epc==0x6000u && ((s.cause>>2)&31u)==12u);
    /* DADDI immediate arithmetic and signed overflow */
    s.gpr[1]=100; assert(ps2_ee_execute_word(&s,(0x18u<<26)|(1u<<21)|(2u<<16)|23u)==PS2_EE_STEP_OK && s.gpr[2]==123);
    s.status=0; s.pc=0x1004; s.gpr[1]=UINT64_C(0x7fffffffffffffff); assert(ps2_ee_execute_word(&s,(0x18u<<26)|(1u<<21)|(2u<<16)|1u)==PS2_EE_STEP_EXCEPTION); assert(s.epc==0x1000u && ((s.cause>>2)&31u)==12u && (s.status&2u)!=0u);
    /* Signed 64-bit overflow cases for DADD/DSUB are detected. */
    s.status=0; s.pc=0x2004; s.gpr[1]=UINT64_C(0x7fffffffffffffff); s.gpr[2]=1;
    assert(ps2_ee_execute_word(&s,(1u<<21)|(2u<<16)|(3u<<11)|0x2cu)==PS2_EE_STEP_EXCEPTION); assert(s.epc==0x2000u && ((s.cause>>2)&31u)==12u);
    s.status=0; s.pc=0x3004; s.gpr[1]=UINT64_C(0x8000000000000000); s.gpr[2]=1;
    assert(ps2_ee_execute_word(&s,(1u<<21)|(2u<<16)|(3u<<11)|0x2eu)==PS2_EE_STEP_EXCEPTION); assert(s.epc==0x3000u && ((s.cause>>2)&31u)==12u);
    s.gpr[1]=100; s.gpr[2]=23;
    assert(ps2_ee_execute_word(&s,(1u<<21)|(2u<<16)|(3u<<11)|0x2cu)==PS2_EE_STEP_OK && s.gpr[3]==123);
    /* 64-bit multiply/divide subset */
    s.gpr[1]=UINT64_C(0x100000000); s.gpr[2]=3;
    assert(ps2_ee_execute_word(&s,(1u<<21)|(2u<<16)|0x1du)==PS2_EE_STEP_OK);
    assert(s.lo==UINT64_C(0x300000000) && s.hi==0);
    s.gpr[1]=100; s.gpr[2]=9;
    assert(ps2_ee_execute_word(&s,(1u<<21)|(2u<<16)|0x1fu)==PS2_EE_STEP_OK);
    assert(s.lo==11 && s.hi==1);
    s.gpr[1]=(uint64_t)(int64_t)-100; s.gpr[2]=9;
    assert(ps2_ee_execute_word(&s,(1u<<21)|(2u<<16)|0x1eu)==PS2_EE_STEP_OK);
    assert((int64_t)s.lo==-11 && (int64_t)s.hi==-1);
    /* MULT: 6 * -3 => signed 32-bit product in HI/LO */
    s.gpr[1]=6;s.gpr[2]=(uint64_t)(int64_t)-3;
    assert(ps2_ee_execute_word(&s,(1u<<21)|(2u<<16)|0x18u)==PS2_EE_STEP_OK);
    assert((int32_t)s.lo==-18 && (int32_t)s.hi==-1);
    assert(ps2_ee_execute_word(&s,(3u<<11)|0x12u)==PS2_EE_STEP_OK&&(int64_t)s.gpr[3]==-18);
    s.gpr[1]=20;s.gpr[2]=6;assert(ps2_ee_execute_word(&s,(1u<<21)|(2u<<16)|0x1au)==PS2_EE_STEP_OK&&(int32_t)s.lo==3&&(int32_t)s.hi==2);
    assert(ps2_ee_mem_store(&mem,4,4,UINT32_C(0x1234abcd))==0);assert(ps2_ee_mem_load(&mem,4,4,&loaded)==0&&loaded==UINT32_C(0x1234abcd));
    assert(ps2_ee_mem_store(&mem,8,8,UINT64_C(0x1122334455667788))==0);assert(ps2_ee_mem_load(&mem,8,8,&loaded)==0&&loaded==UINT64_C(0x1122334455667788));
    assert(ps2_ee_mem_load(&mem,3,4,&loaded)==-1);assert(ps2_ee_mem_load(&mem,64,1,&loaded)==-1);assert(ps2_ee_mem_store(&mem,0,3,0)==-1);assert(ps2_ee_mem_load(&mem,0,1,NULL)==-1);
    s.gpr[1]=8;assert(ps2_ee_execute_memory_word(&s,&mem,(0x23u<<26)|(1u<<21)|(5u<<16))==PS2_EE_STEP_OK&&s.gpr[5]==UINT64_C(0x55667788));
    s.gpr[6]=UINT64_C(0xaabbccdd);assert(ps2_ee_execute_memory_word(&s,&mem,(0x2bu<<26)|(1u<<21)|(6u<<16)|16u)==PS2_EE_STEP_OK);assert(ps2_ee_mem_load(&mem,24,4,&loaded)==0&&loaded==UINT32_C(0xaabbccdd));
    s.gpr[1]=3;assert(ps2_ee_execute_memory_word(&s,&mem,(0x23u<<26)|(1u<<21)|(5u<<16))==PS2_EE_STEP_INVALID);
    ps2_ee_reset(&s);s.pc=0;s.next_pc=4;assert(ps2_ee_mem_store(&mem,0,4,(0x09u<<26)|(1u<<16)|7u)==0);assert(ps2_ee_step(&s,&mem)==PS2_EE_STEP_OK);assert(s.gpr[1]==7&&s.pc==4&&s.next_pc==8);
    ps2_ee_reset(&s);s.pc=0;s.next_pc=4;assert(ps2_ee_mem_store(&mem,0,4,(0x04u<<26)|2u)==0);assert(ps2_ee_mem_store(&mem,4,4,(0x09u<<26)|(2u<<16)|9u)==0);assert(ps2_ee_step(&s,&mem)==PS2_EE_STEP_OK);assert(s.pc==4&&s.next_pc==12);assert(ps2_ee_step(&s,&mem)==PS2_EE_STEP_OK);assert(s.gpr[2]==9&&s.pc==12&&s.next_pc==16);
    assert(ps2_ee_add32(&s,0,1,2)==0&&s.gpr[0]==0);assert(ps2_ee_add32(&s,32,1,2)==-1);assert(ps2_ee_sub32(NULL,1,1,2)==-1);assert(ps2_ee_logic(&s,1,1,2,9u)==-1);assert(ps2_ee_lui(&s,32,0)==-1);assert(ps2_ee_slt64(&s,32,1,2)==-1);
    /* Memory boundary, width, alignment and null-output regressions. */
    assert(ps2_ee_mem_store(&mem,60,4,UINT32_C(0x12345678))==0);
    assert(ps2_ee_mem_load(&mem,60,4,&loaded)==0&&loaded==UINT32_C(0x12345678));
    assert(ps2_ee_mem_store(&mem,63,2,1)==-1);
    assert(ps2_ee_mem_load(&mem,63,2,&loaded)==-1);
    assert(ps2_ee_mem_load(&mem,2,4,&loaded)==-1);
    assert(ps2_ee_mem_store(&mem,0,3,0)==-1);
    assert(ps2_ee_mem_load(&mem,0,4,NULL)==-1);
    { ps2_ee_memory_t invalid={NULL,64}; assert(ps2_ee_mem_load(&invalid,0,1,&loaded)==-1); }
    /* Initial direct-mapped segment translation: KSEG0/KSEG1 only. */
    { uint32_t physical=0; assert(ps2_ee_translate_address(UINT32_C(0x80001234),&physical)==0 && physical==UINT32_C(0x1234)); }
    { uint32_t physical=0; assert(ps2_ee_translate_address(UINT32_C(0xA0004321),&physical)==0 && physical==UINT32_C(0x4321)); }
    { uint32_t physical=0; assert(ps2_ee_translate_address(UINT32_C(0x00001234),&physical)==-1); }
    { assert(ps2_ee_translate_address(UINT32_C(0x80000000),NULL)==-1); }
    /* v0.86b: verify the named architectural exception-code constants. */
    assert(PS2_EE_EXC_INT == 0u && PS2_EE_EXC_MOD == 1u);
    assert(PS2_EE_EXC_TLBL == 2u && PS2_EE_EXC_TLBS == 3u);
    assert(PS2_EE_EXC_ADEL == 4u && PS2_EE_EXC_ADES == 5u);
    assert(PS2_EE_EXC_IBE == 6u && PS2_EE_EXC_DBE == 7u);
    assert(PS2_EE_EXC_SYS == 8u && PS2_EE_EXC_BP == 9u);
    assert(PS2_EE_EXC_RI == 10u && PS2_EE_EXC_CPU == 11u);
    assert(PS2_EE_EXC_OV == 12u && PS2_EE_EXC_TR == 13u);
    assert(PS2_EE_EXC_FPE == 15u);
    /* v0.85b: exception entry delay-slot metadata and EXL preservation. */
    ps2_ee_reset(&s);
    s.pc = UINT32_C(0x80001004);
    s.cause = UINT32_C(0x00000100);
    ps2_ee_raise_exception(&s, s.pc, PS2_EE_EXC_OV, 1);
    assert(s.epc == UINT32_C(0x80001000));
    assert(((s.cause >> 2) & 31u) == PS2_EE_EXC_OV);
    assert((s.cause & UINT32_C(0x80000000)) != 0u);
    assert((s.status & UINT32_C(0x2)) != 0u);
    assert(s.pc == UINT32_C(0x80000180) && s.next_pc == UINT32_C(0x80000184));
    /* A nested exception while EXL is set must preserve the first EPC/Cause. */
    { uint32_t saved_epc=s.epc, saved_cause=s.cause;
      ps2_ee_raise_exception(&s, UINT32_C(0x1234), PS2_EE_EXC_RI, 0);
      assert(s.epc == saved_epc && s.cause == saved_cause); }
    ps2_ee_raise_exception(NULL, 0, PS2_EE_EXC_INT, 0);
    puts("OK: EE helpers, decoder, 64-bit shifts/arithmetic, HI/LO and memory/step tests.");return 0;
}
