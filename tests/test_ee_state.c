#include "../src/ps2/ee_state.h"

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

    s.gpr[1] = 20;
    s.gpr[2] = 22;
    assert(ps2_ee_add32(&s, 3, 1, 2) == 0);
    assert((uint32_t)s.gpr[3] == 42);

    s.gpr[1] = 5;
    s.gpr[2] = 9;
    assert(ps2_ee_sub32(&s, 4, 1, 2) == 0);
    assert((int64_t)s.gpr[4] == -4);

    s.gpr[1] = UINT32_C(0x7fffffff);
    s.gpr[2] = 1;
    assert(ps2_ee_add32(&s, 5, 1, 2) == 1);

    s.gpr[1] = UINT32_C(0x80000000);
    s.gpr[2] = 1;
    assert(ps2_ee_sub32(&s, 5, 1, 2) == 1);

    s.gpr[7] = 99;
    assert(ps2_ee_add32(&s, 0, 1, 2) == 1);
    assert(s.gpr[0] == 0);

    assert(ps2_ee_add32(&s, 32, 1, 2) == -1);
    assert(ps2_ee_sub32(NULL, 1, 1, 2) == -1);

    puts("OK: reset EE, ADD/SUB signed overflow, zero register and invalid inputs.");
    return 0;
}
