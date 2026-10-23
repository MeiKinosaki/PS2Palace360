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
    s.gpr[1]=1; s.gpr[2]=UINT64_C(0x8000000000000000);
    assert(ps2_ee_execute_word(&s,(1u<<21)|(2u<<16)|(6u<<11)|0x17u)==PS2_EE_STEP_OK && s.gpr[6]==UINT64_C(0xc000000000000000));
    s.gpr[2]=UINT64_C(0x8000000000000000);
    assert(ps2_ee_execute_word(&s,(2u<<16)|(7u<<11)|(1u<<6)|0x3bu)==PS2_EE_STEP_OK && s.gpr[7]==UINT64_C(0xc000000000000000));
    /* Portable 32-bit arithmetic right shifts with sign bit set. */
    s.gpr[1]=0; s.gpr[2]=UINT32_C(0x80000000);
    assert(ps2_ee_execute_word(&s,(1u<<21)|(2u<<16)|(8u<<11)|(1u<<6)|0x03u)==PS2_EE_STEP_OK);
    assert(s.gpr[8]==UINT64_C(0xffffffffc0000000));
    s.gpr[1]=1; /* SRAV shift amount comes from rs, not shamt. */
    assert(ps2_ee_execute_word(&s,(1u<<21)|(2u<<16)|(9u<<11)|0x07u)==PS2_EE_STEP_OK);
    assert(s.gpr[9]==UINT64_C(0xffffffffc0000000));
    /* Variable 64-bit shifts */
    s.gpr[1]=3; s.gpr[2]=UINT64_C(0x100000001); /* DSLLV uses rs as shift and rt as value. */
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
    /* v0.87b: translated KSEG0/KSEG1 accesses reach the test RAM. */
    assert(ps2_ee_mem_store_virtual(&mem, UINT32_C(0x80000010), 4,
                                    UINT32_C(0xdeadbeef)) == 0);
    assert(ps2_ee_mem_load_virtual(&mem, UINT32_C(0xA0000010), 4,
                                   &loaded) == 0);
    assert(loaded == UINT32_C(0xdeadbeef));
    assert(ps2_ee_mem_load_virtual(&mem, UINT32_C(0x00000010), 4,
                                   &loaded) == -1);
    assert(ps2_ee_mem_store_virtual(&mem, UINT32_C(0x80000040), 4, 1) == -1);
    /* V2.0.1b: invalidate all TLB entries, including global mappings. */
    { ps2_ee_tlb_t tlb; ps2_ee_tlb_reset(&tlb);
      assert(ps2_ee_tlb_write(&tlb, 0, UINT32_C(0x1000), UINT32_C(0x3000), 1, 1, 1, 0) == PS2_EE_TLB_OK);
      assert(ps2_ee_tlb_write(&tlb, 1, UINT32_C(0x2000), UINT32_C(0x4000), 2, 1, 1, 1) == PS2_EE_TLB_OK);
      assert(ps2_ee_tlb_count_valid(&tlb) == 2);
      assert(ps2_ee_tlb_invalidate_all(&tlb) == PS2_EE_TLB_OK);
      assert(ps2_ee_tlb_count_valid(&tlb) == 0);
      assert(ps2_ee_tlb_translate(&tlb, UINT32_C(0x2004), 0, &(uint32_t){0}) == PS2_EE_TLB_ERR_MISS);
      assert(ps2_ee_tlb_invalidate_all(NULL) == PS2_EE_TLB_ERR_ARGUMENT);
    }
    /* v0.109b: TLB valid-entry diagnostic count. */
    { ps2_ee_tlb_t tlb; ps2_ee_tlb_reset(&tlb);
      assert(ps2_ee_tlb_count_valid(&tlb) == 0);
      assert(ps2_ee_tlb_write(&tlb, 0, UINT32_C(0x1000), UINT32_C(0x3000), 0, 1, 1, 0) == PS2_EE_TLB_OK);
      assert(ps2_ee_tlb_write(&tlb, 1, UINT32_C(0x2000), UINT32_C(0x4000), 0, 0, 1, 0) == PS2_EE_TLB_OK);
      assert(ps2_ee_tlb_count_valid(&tlb) == 1);
      assert(ps2_ee_tlb_invalidate_asid(&tlb, 0) == PS2_EE_TLB_OK);
      assert(ps2_ee_tlb_count_valid(&tlb) == 0);
      assert(ps2_ee_tlb_count_valid(NULL) == 0);
    }
    /* v0.107b: TLB page permission status helper. */
    { ps2_ee_tlb_t tlb; ps2_ee_tlb_reset(&tlb);
      assert(ps2_ee_tlb_check_page(&tlb, UINT32_C(0x1000), 0) == PS2_EE_TLB_ERR_MISS);
      assert(ps2_ee_tlb_write(&tlb, 0, UINT32_C(0x1000), UINT32_C(0x3000), 0, 0, 0, 1) == PS2_EE_TLB_OK);
      assert(ps2_ee_tlb_check_page(&tlb, UINT32_C(0x1004), 0) == PS2_EE_TLB_ERR_INVALID);
      assert(ps2_ee_tlb_write(&tlb, 0, UINT32_C(0x1000), UINT32_C(0x3000), 0, 1, 0, 1) == PS2_EE_TLB_OK);
      assert(ps2_ee_tlb_check_page(&tlb, UINT32_C(0x1004), 0) == PS2_EE_TLB_OK);
      assert(ps2_ee_tlb_check_page(&tlb, UINT32_C(0x1004), 1) == PS2_EE_TLB_ERR_MODIFIED);
      assert(ps2_ee_tlb_write(&tlb, 0, UINT32_C(0x1000), UINT32_C(0x3000), 0, 1, 1, 1) == PS2_EE_TLB_OK);
      assert(ps2_ee_tlb_check_page(&tlb, UINT32_C(0x1004), 1) == PS2_EE_TLB_OK);
    }
    /* v0.105b: TLB lookup by virtual page. */
    { ps2_ee_tlb_t tlb; ps2_ee_tlb_entry_t entry;
      ps2_ee_tlb_reset(&tlb); tlb.current_asid=2;
      assert(ps2_ee_tlb_write(&tlb, 0, UINT32_C(0x00401000), UINT32_C(0x00002000), 1, 1, 1, 0) == PS2_EE_TLB_OK);
      assert(ps2_ee_tlb_lookup(&tlb, UINT32_C(0x00401001), &entry) == PS2_EE_TLB_ERR_MISS);
      assert(ps2_ee_tlb_write(&tlb, 1, UINT32_C(0x00401000), UINT32_C(0x00003000), 2, 1, 1, 0) == PS2_EE_TLB_OK);
      assert(ps2_ee_tlb_lookup(&tlb, UINT32_C(0x00401abc), &entry) == PS2_EE_TLB_OK && entry.physical_page == UINT32_C(0x00003000));
      /* Invalid matching entries must not shadow a later valid mapping. */
      assert(ps2_ee_tlb_write(&tlb, 2, UINT32_C(0x00401000), UINT32_C(0x00004000), 2, 0, 1, 0) == PS2_EE_TLB_OK);
      assert(ps2_ee_tlb_lookup(&tlb, UINT32_C(0x00401008), &entry) == PS2_EE_TLB_OK && entry.physical_page == UINT32_C(0x00003000));
      /* Two valid mappings for the same ASID/page are diagnosed explicitly. */
      assert(ps2_ee_tlb_write(&tlb, 3, UINT32_C(0x00401000), UINT32_C(0x00005000), 2, 1, 1, 0) == PS2_EE_TLB_OK);
      entry.physical_page = UINT32_C(0xfeedface);
      assert(ps2_ee_tlb_lookup(&tlb, UINT32_C(0x00401008), &entry) == PS2_EE_TLB_ERR_MULTIPLE);
      assert(entry.physical_page == UINT32_C(0xfeedface));
      assert(ps2_ee_tlb_invalidate_all(&tlb) == PS2_EE_TLB_OK);
      entry.physical_page = UINT32_C(0xdeadbeef);
      assert(ps2_ee_tlb_lookup(&tlb, UINT32_C(0x00401008), &entry) == PS2_EE_TLB_ERR_MISS);
      assert(entry.physical_page == UINT32_C(0xdeadbeef));
      assert(ps2_ee_tlb_lookup(&tlb, 0, NULL) == PS2_EE_TLB_ERR_ARGUMENT);
    }
    /* v0.104b: TLB-aware memory accessors. */
    { ps2_ee_tlb_t tlb; uint64_t value=0;
      ps2_ee_tlb_reset(&tlb);
      assert(ps2_ee_tlb_write(&tlb, 0, UINT32_C(0x00401000), UINT32_C(0x00000000), 0, 1, 1, 1) == PS2_EE_TLB_OK);
      assert(ps2_ee_mem_store_virtual_tlb(&mem, &tlb, UINT32_C(0x00401008), 4, UINT32_C(0xcafebabe)) == PS2_EE_MEM_OK);
      assert(ps2_ee_mem_load_virtual_tlb(&mem, &tlb, UINT32_C(0x00401008), 4, &value) == PS2_EE_MEM_OK && value == UINT32_C(0xcafebabe));
      assert(ps2_ee_mem_load_virtual_tlb(&mem, &tlb, UINT32_C(0x00402008), 4, &value) == PS2_EE_MEM_ERR_TRANSLATION);
      assert(ps2_ee_mem_store_virtual_tlb(&mem, &tlb, UINT32_C(0x00401008), 4, 1) == PS2_EE_MEM_OK);
      assert(ps2_ee_mem_load_virtual_tlb(&mem, &tlb, UINT32_C(0x00401008), 4, NULL) == PS2_EE_MEM_ERR_ARGUMENT);
      assert(ps2_ee_mem_store_virtual_tlb(&mem, NULL, UINT32_C(0x00401008), 4, 1) == PS2_EE_MEM_ERR_TRANSLATION);
    }
    /* v0.103b: unified address translation. */
    { ps2_ee_tlb_t tlb; uint32_t physical=UINT32_C(0xfeedface);
      ps2_ee_tlb_reset(&tlb);
      assert(ps2_ee_translate_address_with_tlb(&tlb, UINT32_C(0x80001234), 0, &physical) == PS2_EE_TLB_OK && physical == UINT32_C(0x1234));
      physical=UINT32_C(0xfeedface);
      assert(ps2_ee_translate_address_with_tlb(&tlb, UINT32_C(0x00401234), 0, &physical) == PS2_EE_TLB_ERR_MISS && physical == UINT32_C(0xfeedface));
      assert(ps2_ee_tlb_write(&tlb, 0, UINT32_C(0x00401000), UINT32_C(0x00002000), 0, 1, 1, 1) == PS2_EE_TLB_OK);
      assert(ps2_ee_translate_address_with_tlb(&tlb, UINT32_C(0x00401234), 0, &physical) == PS2_EE_TLB_OK && physical == UINT32_C(0x2234));
      assert(ps2_ee_translate_address_with_tlb(&tlb, 0, 0, NULL) == PS2_EE_TLB_ERR_ARGUMENT);
    }
    /* v0.102b: TLB entry inspection, ASID selection and invalidation. */
    { ps2_ee_tlb_t tlb; ps2_ee_tlb_entry_t entry; uint32_t physical=0;
      ps2_ee_tlb_reset(&tlb);
      assert(ps2_ee_tlb_set_asid(&tlb, 7) == PS2_EE_TLB_OK && tlb.current_asid == 7);
      assert(ps2_ee_tlb_write(&tlb, 0, UINT32_C(0x00401000), UINT32_C(0x00002000), 7, 1, 1, 0) == PS2_EE_TLB_OK);
      assert(ps2_ee_tlb_read(&tlb, 0, &entry) == PS2_EE_TLB_OK && entry.virtual_page == UINT32_C(0x00401000) && entry.physical_page == UINT32_C(0x00002000) && entry.asid == 7 && entry.valid && entry.dirty);
      assert(ps2_ee_tlb_invalidate_asid(&tlb, 7) == PS2_EE_TLB_OK);
      assert(ps2_ee_tlb_translate(&tlb, UINT32_C(0x00401004), 0, &physical) == PS2_EE_TLB_ERR_INVALID);
      assert(ps2_ee_tlb_read(&tlb, PS2_EE_TLB_ENTRY_COUNT, &entry) == PS2_EE_TLB_ERR_ARGUMENT);
      assert(ps2_ee_tlb_read(&tlb, 0, NULL) == PS2_EE_TLB_ERR_ARGUMENT);
      assert(ps2_ee_tlb_set_asid(NULL, 1) == PS2_EE_TLB_ERR_ARGUMENT);
      assert(ps2_ee_tlb_invalidate_asid(NULL, 1) == PS2_EE_TLB_ERR_ARGUMENT);
      assert(ps2_ee_tlb_write(&tlb, 1, UINT32_C(0x00402000), UINT32_C(0x00003000), 7, 1, 1, 1) == PS2_EE_TLB_OK);
      assert(ps2_ee_tlb_invalidate_asid(&tlb, 7) == PS2_EE_TLB_OK);
      assert(ps2_ee_tlb_translate(&tlb, UINT32_C(0x00402004), 0, &physical) == PS2_EE_TLB_OK && physical == UINT32_C(0x00003004));
    }
    /* V2.0.2b: duplicate-match diagnostic respects ASID/global and valid bits. */
    { ps2_ee_tlb_t tlb;
      ps2_ee_tlb_reset(&tlb);
      assert(ps2_ee_tlb_count_matches(&tlb, UINT32_C(0x00401234)) == 0);
      assert(ps2_ee_tlb_write(&tlb, 0, UINT32_C(0x00401000), UINT32_C(0x00002000), 3, 1, 1, 0) == PS2_EE_TLB_OK);
      assert(ps2_ee_tlb_count_matches(&tlb, UINT32_C(0x00401234)) == 0);
      assert(ps2_ee_tlb_set_asid(&tlb, 3) == PS2_EE_TLB_OK);
      assert(ps2_ee_tlb_count_matches(&tlb, UINT32_C(0x00401234)) == 1);
      assert(ps2_ee_tlb_write(&tlb, 1, UINT32_C(0x00401000), UINT32_C(0x00003000), 3, 1, 1, 0) == PS2_EE_TLB_OK);
      assert(ps2_ee_tlb_count_matches(&tlb, UINT32_C(0x00401fff)) == 2);
      assert(ps2_ee_tlb_write(&tlb, 2, UINT32_C(0x00401000), UINT32_C(0x00004000), 9, 1, 1, 0) == PS2_EE_TLB_OK);
      assert(ps2_ee_tlb_count_matches(&tlb, UINT32_C(0x00401000)) == 2);
      assert(ps2_ee_tlb_write(&tlb, 3, UINT32_C(0x00401000), UINT32_C(0x00005000), 9, 1, 1, 1) == PS2_EE_TLB_OK);
      assert(ps2_ee_tlb_count_matches(&tlb, UINT32_C(0x00401000)) == 3);
      assert(ps2_ee_tlb_write(&tlb, 4, UINT32_C(0x00401000), UINT32_C(0x00006000), 3, 0, 1, 0) == PS2_EE_TLB_OK);
      assert(ps2_ee_tlb_count_matches(&tlb, UINT32_C(0x00401000)) == 3);
      assert(ps2_ee_tlb_count_matches(NULL, 0) == 0);
      /* V2.0.3b: translation must not silently choose among duplicate valid mappings. */
      { uint32_t physical = UINT32_C(0xdeadbeef);
        assert(ps2_ee_tlb_translate(&tlb, UINT32_C(0x00401020), 0, &physical) == PS2_EE_TLB_ERR_MULTIPLE);
        assert(physical == UINT32_C(0xdeadbeef));
        assert(ps2_ee_tlb_invalidate_all(&tlb) == PS2_EE_TLB_OK);
        assert(ps2_ee_tlb_translate(&tlb, UINT32_C(0x00401020), 0, &physical) == PS2_EE_TLB_ERR_MISS);
      }
    }
    /* v0.101b: experimental 4 KiB TLB translation. */
    { ps2_ee_tlb_t tlb; uint32_t physical=UINT32_C(0xfeedface);
      ps2_ee_tlb_reset(&tlb);
      assert(ps2_ee_tlb_translate(&tlb, UINT32_C(0x00401234), 0, &physical) == PS2_EE_TLB_ERR_MISS);
      assert(physical == UINT32_C(0xfeedface));
      assert(ps2_ee_tlb_write(&tlb, 0, UINT32_C(0x00401000), UINT32_C(0x00002000), 3, 1, 1, 0) == PS2_EE_TLB_OK);
      tlb.current_asid = 3;
      assert(ps2_ee_tlb_translate(&tlb, UINT32_C(0x00401234), 0, &physical) == PS2_EE_TLB_OK && physical == UINT32_C(0x00002234));
      assert(ps2_ee_tlb_translate(&tlb, UINT32_C(0x00401234), 1, &physical) == PS2_EE_TLB_OK);
      tlb.current_asid = 4;
      assert(ps2_ee_tlb_translate(&tlb, UINT32_C(0x00401234), 0, &physical) == PS2_EE_TLB_ERR_MISS);
      assert(ps2_ee_tlb_write(&tlb, 1, UINT32_C(0x00401000), UINT32_C(0x00003000), 4, 1, 0, 0) == PS2_EE_TLB_OK);
      assert(ps2_ee_tlb_translate(&tlb, UINT32_C(0x00401234), 1, &physical) == PS2_EE_TLB_ERR_MODIFIED);
      assert(ps2_ee_tlb_write(&tlb, 2, UINT32_C(0x00401000), UINT32_C(0x00004000), 4, 0, 1, 0) == PS2_EE_TLB_OK);
      /* Remove the valid read-only mapping so the invalid entry is observable. */
      assert(ps2_ee_tlb_invalidate_asid(&tlb, 4) == PS2_EE_TLB_OK);
      assert(ps2_ee_tlb_translate(&tlb, UINT32_C(0x00401234), 0, &physical) == PS2_EE_TLB_ERR_INVALID);
      assert(ps2_ee_tlb_write(&tlb, PS2_EE_TLB_ENTRY_COUNT, 0, 0, 0, 1, 1, 0) == PS2_EE_TLB_ERR_ARGUMENT);
      assert(ps2_ee_tlb_write(&tlb, 0, 1, 0, 0, 1, 1, 0) == PS2_EE_TLB_ERR_ARGUMENT);
      assert(ps2_ee_tlb_translate(NULL, 0, 0, &physical) == PS2_EE_TLB_ERR_ARGUMENT);
    }

    /* V2.0.16b: lookup must isolate ASIDs while global entries match all ASIDs. */
    { ps2_ee_tlb_t tlb; ps2_ee_tlb_entry_t entry;
      ps2_ee_tlb_reset(&tlb);
      assert(ps2_ee_tlb_set_asid(&tlb, 5) == PS2_EE_TLB_OK);
      assert(ps2_ee_tlb_write(&tlb, 0, UINT32_C(0x00500000), UINT32_C(0x00100000), 4, 1, 1, 0) == PS2_EE_TLB_OK);
      assert(ps2_ee_tlb_lookup(&tlb, UINT32_C(0x00500123), &entry) == PS2_EE_TLB_ERR_MISS);
      assert(ps2_ee_tlb_write(&tlb, 1, UINT32_C(0x00500000), UINT32_C(0x00200000), 9, 1, 1, 1) == PS2_EE_TLB_OK);
      assert(ps2_ee_tlb_lookup(&tlb, UINT32_C(0x00500123), &entry) == PS2_EE_TLB_OK && entry.physical_page == UINT32_C(0x00200000) && entry.global);
      assert(ps2_ee_tlb_set_asid(&tlb, 4) == PS2_EE_TLB_OK);
      assert(ps2_ee_tlb_lookup(&tlb, UINT32_C(0x00500123), &entry) == PS2_EE_TLB_ERR_MULTIPLE);
    }

    /* v0.90b: detailed translation errors without breaking the legacy API. */
    { uint32_t physical=UINT32_C(0xfeedface);
      assert(ps2_ee_translate_address_ex(UINT32_C(0x80001234), &physical) == PS2_EE_TRANSLATE_OK);
      assert(physical == UINT32_C(0x1234)); }
    { uint32_t physical=UINT32_C(0xfeedface);
      assert(ps2_ee_translate_address_ex(UINT32_C(0x00001000), &physical) == PS2_EE_TRANSLATE_ERR_UNSUPPORTED);
      assert(physical == UINT32_C(0xfeedface)); }
    assert(ps2_ee_translate_address_ex(UINT32_C(0x80000000), NULL) == PS2_EE_TRANSLATE_ERR_ARGUMENT);
    assert(PS2_EE_TRANSLATE_OK == 0 && PS2_EE_TRANSLATE_ERR_ARGUMENT == -1 && PS2_EE_TRANSLATE_ERR_UNSUPPORTED == -2);
    /* v0.89b: translation segment edges and failure-output stability. */
    { uint32_t physical=UINT32_C(0xfeedface);
      assert(ps2_ee_translate_address(UINT32_C(0x9fffffff), &physical) == 0);
      assert(physical == UINT32_C(0x1fffffff)); }
    { uint32_t physical=UINT32_C(0xfeedface);
      assert(ps2_ee_translate_address(UINT32_C(0xbfffffff), &physical) == 0);
      assert(physical == UINT32_C(0x1fffffff)); }
    { uint32_t physical=UINT32_C(0xfeedface);
      assert(ps2_ee_translate_address(UINT32_C(0xc0000000), &physical) == -1);
      assert(physical == UINT32_C(0xfeedface)); }
    { uint32_t physical=UINT32_C(0xfeedface);
      assert(ps2_ee_translate_address(UINT32_C(0x00001000), &physical) == -1);
      assert(physical == UINT32_C(0xfeedface)); }
    { ps2_ee_memory_t invalid={NULL,64};
      assert(ps2_ee_mem_load_virtual(&invalid, UINT32_C(0x80000000), 4, &loaded) == -1);
      assert(ps2_ee_mem_store_virtual(&invalid, UINT32_C(0xA0000000), 4, 0) == -1); }
    assert(ps2_ee_mem_load_virtual(&mem, UINT32_C(0x80000000), 4, NULL) == -1);
    /* v0.88b: virtual accessor width, alignment and boundary checks. */
    assert(ps2_ee_mem_store_virtual(&mem, UINT32_C(0x80000020), 1, UINT64_C(0x5a)) == 0);
    assert(ps2_ee_mem_load_virtual(&mem, UINT32_C(0xA0000020), 1, &loaded) == 0 && loaded == UINT64_C(0x5a));
    assert(ps2_ee_mem_store_virtual(&mem, UINT32_C(0x80000028), 8, UINT64_C(0x0123456789abcdef)) == 0);
    assert(ps2_ee_mem_load_virtual(&mem, UINT32_C(0xA0000028), 8, &loaded) == 0 && loaded == UINT64_C(0x0123456789abcdef));
    assert(ps2_ee_mem_load_virtual(&mem, UINT32_C(0x80000021), 2, &loaded) == -1);
    assert(ps2_ee_mem_store_virtual(&mem, UINT32_C(0x8000003c), 8, 1) == -1);
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

    /* V2.0.19b: scalar load/store instructions use the direct-map/TLB dispatcher. */
    { ps2_ee_tlb_t tlb;
      ps2_ee_tlb_reset(&tlb);
      /* Map virtual 0x00001000 to physical RAM page 0 for this isolated test. */
      assert(ps2_ee_tlb_write(&tlb, 0, UINT32_C(0x00001000), UINT32_C(0x00000000), 0, 1, 1, 0) == PS2_EE_TLB_OK);
      s.gpr[1] = UINT32_C(0x00001000);
      assert(ps2_ee_mem_store(&mem, 0x00, 4, UINT32_C(0x80ff7f01)) == 0);
      assert(ps2_ee_execute_memory_word_tlb(&s, &mem, &tlb,
          (0x23u<<26)|(1u<<21)|(2u<<16)) == PS2_EE_STEP_OK);
      assert(s.gpr[2] == UINT64_C(0xffffffff80ff7f01));
      assert(ps2_ee_execute_memory_word_tlb(&s, &mem, &tlb,
          (0x27u<<26)|(1u<<21)|(3u<<16)) == PS2_EE_STEP_OK);
      assert(s.gpr[3] == UINT32_C(0x80ff7f01));
      s.gpr[4] = UINT32_C(0x1234abcd);
      assert(ps2_ee_execute_memory_word_tlb(&s, &mem, &tlb,
          (0x2bu<<26)|(1u<<21)|(4u<<16)|4u) == PS2_EE_STEP_OK);
      assert(ps2_ee_mem_load(&mem, 0x04, 4, &loaded) == 0 && loaded == UINT32_C(0x1234abcd));
      assert(ps2_ee_execute_memory_word_tlb(&s, &mem, &tlb,
          (0x23u<<26)|(1u<<21)|(5u<<16)|UINT32_C(0x1000)) == PS2_EE_STEP_INVALID);
      assert(ps2_ee_tlb_write(&tlb, 1, UINT32_C(0x00001000), UINT32_C(0x00000000), 0, 1, 1, 0) == PS2_EE_TLB_OK);
      assert(ps2_ee_execute_memory_word_tlb(&s, &mem, &tlb,
          (0x23u<<26)|(1u<<21)|(2u<<16)) == PS2_EE_STEP_INVALID);
    }

    /* V2.0.20b: execute one instruction fetched through the TLB-backed path. */
    { ps2_ee_tlb_t tlb;
      ps2_ee_tlb_reset(&tlb);
      assert(ps2_ee_tlb_write(&tlb, 0, UINT32_C(0x00001000), 0, 0, 1, 1, 0) == PS2_EE_TLB_OK);
      assert(ps2_ee_tlb_write(&tlb, 1, UINT32_C(0x00002000), 0, 0, 1, 1, 0) == PS2_EE_TLB_OK);
      /* Place LW r2,0(r1) at physical 0; data at physical 4. */
      assert(ps2_ee_mem_store(&mem, 0, 4, (UINT32_C(0x23)<<26)|(1u<<21)|(2u<<16)) == 0);
      assert(ps2_ee_mem_store(&mem, 4, 4, UINT32_C(0x76543210)) == 0);
      ps2_ee_reset(&s); s.pc=UINT32_C(0x00001000); s.next_pc=UINT32_C(0x00001004);
      s.gpr[1]=UINT32_C(0x00002004);
      assert(ps2_ee_step_tlb(&s,&mem,&tlb)==PS2_EE_STEP_OK);
      assert(s.gpr[2]==UINT32_C(0x76543210));
      assert(s.pc==UINT32_C(0x00001004));
    }
    /* V2.0.21b: regression coverage for memory boundaries and TLB permissions. */
    {
      ps2_ee_tlb_t tlb;
      ps2_ee_tlb_entry_t entry;
      uint32_t physical = UINT32_C(0xdeadbeef);
      uint64_t value = UINT64_C(0xfeedface);
      /* Misaligned and out-of-range accesses must fail without corrupting output. */
      assert(ps2_ee_mem_load(&mem, 1, 4, &value) != 0);
      assert(ps2_ee_mem_load(&mem, 64, 1, &value) != 0);
      assert(ps2_ee_mem_load(&mem, 0, 3, &value) != 0);
      assert(ps2_ee_mem_store(&mem, 63, 2, UINT16_C(0xabcd)) != 0);
      /* A failed translation must leave the caller's physical address untouched. */
      ps2_ee_tlb_reset(&tlb);
      assert(ps2_ee_tlb_translate(&tlb, UINT32_C(0x12345067), 0, &physical) == PS2_EE_TLB_ERR_MISS);
      assert(physical == UINT32_C(0xdeadbeef));
      /* Read-only mapping allows loads but rejects stores as Modified. */
      assert(ps2_ee_tlb_write(&tlb, 0, UINT32_C(0x12345000),
          UINT32_C(0x00000000), 0, 1, 0, 0) == PS2_EE_TLB_OK);
      assert(ps2_ee_tlb_translate(&tlb, UINT32_C(0x12345067), 0, &physical) == PS2_EE_TLB_OK);
      assert(physical == UINT32_C(0x67));
      assert(ps2_ee_tlb_translate(&tlb, UINT32_C(0x12345067), 1, &physical) == PS2_EE_TLB_ERR_MODIFIED);
      /* ASID mismatch is a miss; global mappings remain visible across ASIDs. */
      assert(ps2_ee_tlb_set_asid(&tlb, 7) == PS2_EE_TLB_OK);
      assert(ps2_ee_tlb_lookup(&tlb, UINT32_C(0x12345000), &entry) == PS2_EE_TLB_ERR_MISS);
      assert(ps2_ee_tlb_write(&tlb, 1, UINT32_C(0x12345000),
          UINT32_C(0x00001000), 0, 1, 1, 1) == PS2_EE_TLB_OK);
      assert(ps2_ee_tlb_lookup(&tlb, UINT32_C(0x12345000), &entry) == PS2_EE_TLB_OK);
      assert(entry.global == 1u && entry.physical_page == UINT32_C(0x1000));
    }
    /* V2.0.22b: instruction-fetch TLB miss enters TLBL exception vector. */
    {
      ps2_ee_tlb_t tlb;
      ps2_ee_tlb_reset(&tlb);
      ps2_ee_reset(&s);
      s.pc = UINT32_C(0x00003000);
      s.next_pc = UINT32_C(0x00003004);
      assert(ps2_ee_step_tlb(&s, &mem, &tlb) == PS2_EE_STEP_EXCEPTION);
      assert(s.badvaddr == UINT32_C(0x00003000));
      assert(s.epc == UINT32_C(0x00003000));
      assert(((s.cause >> 2) & 31u) == PS2_EE_EXC_TLBL);
      assert(s.pc == UINT32_C(0x80000180));
    }
    puts("OK: EE helpers, decoder, TLB-backed step, scalar memory ops and arithmetic tests.");return 0;
}
