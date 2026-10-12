#include "../src/ps2/ee_state.h"
#include "../src/ps2/ee_ops.h"
#include "../src/ps2/ee_immediate.h"
#include "../src/ps2/ee_compare.h"

#include <assert.h>
#include <stdint.h>
#include <stdio.h>

int main(void)
{
    ps2_ee_state_t s;
    ps2_ee_reset(&s);
    assert(s.pc == UINT32_C(0xBFC00000));
    assert(s.next_pc == UINT32_C(0xBFC00004));
    assert(s.gpr[0] == 0);

    s.gpr[1] = 20; s.gpr[2] = 22;
    assert(ps2_ee_add32(&s, 3, 1, 2) == 0 && s.gpr[3] == 42);
    s.gpr[1] = 5; s.gpr[2] = 9;
    assert(ps2_ee_sub32(&s, 4, 1, 2) == 0 && (int64_t)s.gpr[4] == -4);
    s.gpr[1] = UINT32_C(0x7fffffff); s.gpr[2] = 1;
    assert(ps2_ee_add32(&s, 5, 1, 2) == 1);
    s.gpr[1] = UINT32_C(0x80000000); s.gpr[2] = 1;
    assert(ps2_ee_sub32(&s, 5, 1, 2) == 1);

    s.gpr[1] = UINT32_MAX; s.gpr[2] = 2;
    assert(ps2_ee_addu32(&s, 6, 1, 2) == 0 && (uint32_t)s.gpr[6] == 1u);
    assert(ps2_ee_subu32(&s, 7, 2, 1) == 0 && (uint32_t)s.gpr[7] == 3u);
    s.gpr[1] = UINT64_C(0xF0F0); s.gpr[2] = UINT64_C(0x0FF0);
    assert(ps2_ee_logic(&s, 8, 1, 2, PS2_EE_LOGIC_AND) == 0 && s.gpr[8] == 0x00F0u);
    assert(ps2_ee_logic(&s, 9, 1, 2, PS2_EE_LOGIC_OR) == 0 && s.gpr[9] == 0xFFF0u);
    assert(ps2_ee_logic(&s, 10, 1, 2, PS2_EE_LOGIC_XOR) == 0 && s.gpr[10] == 0xFF00u);
    assert(ps2_ee_logic(&s, 11, 1, 2, PS2_EE_LOGIC_NOR) == 0 && s.gpr[11] == ~UINT64_C(0xFFF0));

    s.gpr[1] = 100;
    assert(ps2_ee_addi32(&s, 12, 1, -7) == 0 && (int64_t)s.gpr[12] == 93);
    assert(ps2_ee_addiu32(&s, 13, 1, -7) == 0 && (int64_t)s.gpr[13] == 93);
    assert(ps2_ee_slti64(&s, 14, 1, 101) == 0 && s.gpr[14] == 1);
    assert(ps2_ee_slti64(&s, 15, 1, 99) == 0 && s.gpr[15] == 0);
    assert(ps2_ee_sltiu64(&s, 16, 1, -1) == 0 && s.gpr[16] == 1);
    assert(ps2_ee_lui(&s, 17, UINT16_C(0x1234)) == 0 && (uint32_t)s.gpr[17] == UINT32_C(0x12340000));
    s.gpr[1] = UINT32_C(0x7fffffff);
    assert(ps2_ee_addi32(&s, 18, 1, 1) == 1);

    s.gpr[1] = UINT64_MAX; s.gpr[2] = 1;
    assert(ps2_ee_slt64(&s, 19, 1, 2) == 0 && s.gpr[19] == 1);
    assert(ps2_ee_sltu64(&s, 20, 1, 2) == 0 && s.gpr[20] == 0);
    s.gpr[2] = 0; s.gpr[3] = UINT64_C(0x12345678);
    assert(ps2_ee_movz(&s, 21, 3, 2) == 0 && s.gpr[21] == s.gpr[3]);
    s.gpr[2] = 1;
    assert(ps2_ee_movz(&s, 21, 1, 2) == 0 && s.gpr[21] == s.gpr[3]);
    assert(ps2_ee_movn(&s, 22, 3, 2) == 0 && s.gpr[22] == s.gpr[3]);
    s.gpr[2] = 0;
    assert(ps2_ee_movn(&s, 22, 1, 2) == 0 && s.gpr[22] == s.gpr[3]);

    assert(ps2_ee_add32(&s, 0, 1, 2) == 0 && s.gpr[0] == 0);
    assert(ps2_ee_add32(&s, 32, 1, 2) == -1);
    assert(ps2_ee_sub32(NULL, 1, 1, 2) == -1);
    assert(ps2_ee_logic(&s, 1, 1, 2, 9u) == -1);
    assert(ps2_ee_lui(&s, 32, 0) == -1);
    assert(ps2_ee_slt64(&s, 32, 1, 2) == -1);

    puts("OK: EE arithmetic, logic, immediates, comparisons, conditional moves and bounds.");
    return 0;
}
