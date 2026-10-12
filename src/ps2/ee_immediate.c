#include "ee_immediate.h"

#include <limits.h>
#include <stddef.h>

static int valid(const ps2_ee_state_t *s, unsigned rt, unsigned rs)
{
    return s != NULL && rt < PS2_EE_GPR_COUNT && rs < PS2_EE_GPR_COUNT;
}

int ps2_ee_addi32(ps2_ee_state_t *s, unsigned rt,
                  unsigned rs, int16_t immediate)
{
    int64_t a, sum;
    if (!valid(s, rt, rs)) return -1;
    a = (int64_t)(int32_t)(uint32_t)s->gpr[rs];
    sum = a + (int64_t)immediate;
    if (sum > INT32_MAX || sum < INT32_MIN) return 1;
    if (rt != 0u) s->gpr[rt] = (uint64_t)sum;
    s->gpr[0] = 0;
    return 0;
}

int ps2_ee_addiu32(ps2_ee_state_t *s, unsigned rt,
                   unsigned rs, int16_t immediate)
{
    uint32_t result;
    if (!valid(s, rt, rs)) return -1;
    result = (uint32_t)s->gpr[rs] + (uint32_t)(int32_t)immediate;
    if (rt != 0u) s->gpr[rt] = (uint64_t)(int64_t)(int32_t)result;
    s->gpr[0] = 0;
    return 0;
}

int ps2_ee_slti64(ps2_ee_state_t *s, unsigned rt,
                  unsigned rs, int16_t immediate)
{
    if (!valid(s, rt, rs)) return -1;
    if (rt != 0u) s->gpr[rt] = ((int64_t)s->gpr[rs] < (int64_t)immediate) ? 1u : 0u;
    s->gpr[0] = 0;
    return 0;
}

int ps2_ee_sltiu64(ps2_ee_state_t *s, unsigned rt,
                   unsigned rs, int16_t immediate)
{
    uint64_t rhs;
    if (!valid(s, rt, rs)) return -1;
    rhs = (uint64_t)(int64_t)immediate;
    if (rt != 0u) s->gpr[rt] = (s->gpr[rs] < rhs) ? 1u : 0u;
    s->gpr[0] = 0;
    return 0;
}

int ps2_ee_lui(ps2_ee_state_t *s, unsigned rt, uint16_t immediate)
{
    uint32_t value;
    if (s == NULL || rt >= PS2_EE_GPR_COUNT) return -1;
    value = (uint32_t)immediate << 16;
    if (rt != 0u) s->gpr[rt] = (uint64_t)(int64_t)(int32_t)value;
    s->gpr[0] = 0;
    return 0;
}
