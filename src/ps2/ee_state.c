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

void ps2_ee_raise_exception(ps2_ee_state_t *state, uint32_t fault_pc,
                            uint32_t exc_code, int in_delay_slot)
{
    uint32_t vector;
    if (state == NULL) return;
    if ((state->status & UINT32_C(0x2)) == 0u) {
        state->epc = in_delay_slot ? fault_pc - UINT32_C(4) : fault_pc;
        state->cause &= ~UINT32_C(0x8000007c);
        state->cause |= (exc_code & UINT32_C(0x1f)) << 2;
        if (in_delay_slot) state->cause |= UINT32_C(0x80000000);
    }
    state->status |= UINT32_C(0x2);
    vector = (state->status & UINT32_C(0x00400000)) != 0u
           ? UINT32_C(0xBFC00380) : UINT32_C(0x80000180);
    state->pc = vector;
    state->next_pc = vector + UINT32_C(4);
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
