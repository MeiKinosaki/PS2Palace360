#include "ee_ops.h"

#include <stddef.h>

static int valid_regs(const ps2_ee_state_t *state, unsigned rd,
                      unsigned rs, unsigned rt)
{
    return state != NULL && rd < PS2_EE_GPR_COUNT &&
           rs < PS2_EE_GPR_COUNT && rt < PS2_EE_GPR_COUNT;
}

int ps2_ee_addu32(ps2_ee_state_t *state, unsigned rd,
                  unsigned rs, unsigned rt)
{
    uint32_t result;
    if (!valid_regs(state, rd, rs, rt)) return -1;
    result = (uint32_t)state->gpr[rs] + (uint32_t)state->gpr[rt];
    if (rd != 0u) state->gpr[rd] = (uint64_t)(int64_t)(int32_t)result;
    state->gpr[0] = 0;
    return 0;
}

int ps2_ee_subu32(ps2_ee_state_t *state, unsigned rd,
                  unsigned rs, unsigned rt)
{
    uint32_t result;
    if (!valid_regs(state, rd, rs, rt)) return -1;
    result = (uint32_t)state->gpr[rs] - (uint32_t)state->gpr[rt];
    if (rd != 0u) state->gpr[rd] = (uint64_t)(int64_t)(int32_t)result;
    state->gpr[0] = 0;
    return 0;
}

int ps2_ee_logic(ps2_ee_state_t *state, unsigned rd,
                 unsigned rs, unsigned rt, unsigned operation)
{
    uint64_t a, b, result;
    if (!valid_regs(state, rd, rs, rt) || operation > PS2_EE_LOGIC_NOR)
        return -1;
    a = state->gpr[rs];
    b = state->gpr[rt];
    switch (operation) {
    case PS2_EE_LOGIC_AND: result = a & b; break;
    case PS2_EE_LOGIC_OR:  result = a | b; break;
    case PS2_EE_LOGIC_XOR: result = a ^ b; break;
    default: result = ~(a | b); break;
    }
    if (rd != 0u) state->gpr[rd] = result;
    state->gpr[0] = 0;
    return 0;
}
