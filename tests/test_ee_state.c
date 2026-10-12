#include "../src/ps2/ee_state.h"
#include "../src/ps2/ee_ops.h"

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
    assert(ps2_ee_add32(&s, 3, 1, 2) == 0);
    assert((uint32_t)s.gpr[3] == 42);
    s.gpr[1] = 5; s.gpr[2] = 9;
    assert(ps2_ee_sub32(&s, 4, 1, 2) == 0);
    assert((int64_t)s.gpr[4] == -4);
    s.gpr[1] = UINT32_C(0x7fffffff); s.gpr[2] = 1;
    assert(ps2_ee_add32(&s, 5, 1, 2) == 1);
    s.gpr[1] = UINT32_C(0x80000000); s.gpr[2] = 1;
    assert(ps2_ee_sub32(&s, 5, 1, 2) == 1);

    s.gpr[1] = UINT32_MAX; s.gpr[2] = 2;
    assert(ps2_ee_addu32(&s, 6, 1, 2) == 0);
    assert((uint32_t)s.gpr[6] == 1u);
    assert(ps2_ee_subu32(&s, 7, 2, 1) == 0);
    assert((uint32_t)s.gpr[7] == 3u);

    s.gpr[1] = UINT64_C(0xF0F0); s.gpr[2] = UINT64_C(0x0FF0);
    assert(ps2_ee_logic(&s, 8, 1, 2, PS2_EE_LOGIC_AND) == 0);
    assert(s.gpr[8] == UINT64_C(0x00F0));
    assert(ps2_ee_logic(&s, 9, 1, 2, PS2_EE_LOGIC_OR) == 0);
    assert(s.gpr[9] == UINT64_C(0xFFF0));
    assert(ps2_ee_logic(&s, 10, 1, 2, PS2_EE_LOGIC_XOR) == 0);
    assert(s.gpr[10] == UINT64_C(0xFF00));
    assert(ps2_ee_logic(&s, 11, 1, 2, PS2_EE_LOGIC_NOR) == 0);
    assert(s.gpr[11] == ~UINT64_C(0xFFF0));

    assert(ps2_ee_add32(&s, 0, 1, 2) == 0);
    assert(s.gpr[0] == 0);
    assert(ps2_ee_add32(&s, 32, 1, 2) == -1);
    assert(ps2_ee_sub32(NULL, 1, 1, 2) == -1);
    assert(ps2_ee_logic(&s, 1, 1, 2, 9u) == -1);

    puts("OK: EE reset, signed/unsigned arithmetic, logic, overflow and bounds.");
    return 0;
}
