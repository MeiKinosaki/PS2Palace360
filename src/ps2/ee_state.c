#include "ee_state.h"

#include <limits.h>
#include <stddef.h>
#include <string.h>

void ps2_ee_reset(ps2_ee_state_t *state)
{
    if (state == NULL) {
        return;
    }

    memset(state, 0, sizeof(*state));
    state->pc = UINT32_C(0xBFC00000);
    state->next_pc = state->pc + UINT32_C(4);
    state->gpr[0] = 0;
}

int ps2_ee_add32(ps2_ee_state_t *state, unsigned rd,
                 unsigned rs, unsigned rt)
{
    int64_t a, b, sum;
    int32_t result;

    if (state == NULL || rd >= PS2_EE_GPR_COUNT ||
        rs >= PS2_EE_GPR_COUNT || rt >= PS2_EE_GPR_COUNT) {
        return -1;
    }

    a = (int64_t)(int32_t)(uint32_t)state->gpr[rs];
    b = (int64_t)(int32_t)(uint32_t)state->gpr[rt];
    sum = a + b;
    if (sum > INT32_MAX || sum < INT32_MIN) {
        return 1;
    }

    result = (int32_t)sum;
    if (rd != 0u) {
        state->gpr[rd] = (uint64_t)(int64_t)result;
    }
    state->gpr[0] = 0;
    return 0;
}

int ps2_ee_sub32(ps2_ee_state_t *state, unsigned rd,
                 unsigned rs, unsigned rt)
{
    int64_t a, b, difference;
    int32_t result;

    if (state == NULL || rd >= PS2_EE_GPR_COUNT ||
        rs >= PS2_EE_GPR_COUNT || rt >= PS2_EE_GPR_COUNT) {
        return -1;
    }

    a = (int64_t)(int32_t)(uint32_t)state->gpr[rs];
    b = (int64_t)(int32_t)(uint32_t)state->gpr[rt];
    difference = a - b;
    if (difference > INT32_MAX || difference < INT32_MIN) {
        return 1;
    }

    result = (int32_t)difference;
    if (rd != 0u) {
        state->gpr[rd] = (uint64_t)(int64_t)result;
    }
    state->gpr[0] = 0;
    return 0;
}
