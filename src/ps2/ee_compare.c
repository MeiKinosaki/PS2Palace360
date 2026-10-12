#include "ee_compare.h"

#include <stddef.h>

static int valid(const ps2_ee_state_t *s, unsigned rd,
                 unsigned rs, unsigned rt)
{
    return s != NULL && rd < PS2_EE_GPR_COUNT &&
           rs < PS2_EE_GPR_COUNT && rt < PS2_EE_GPR_COUNT;
}

int ps2_ee_slt64(ps2_ee_state_t *s, unsigned rd, unsigned rs, unsigned rt)
{
    if (!valid(s, rd, rs, rt)) return -1;
    if (rd != 0u) s->gpr[rd] = ((int64_t)s->gpr[rs] < (int64_t)s->gpr[rt]) ? 1u : 0u;
    s->gpr[0] = 0;
    return 0;
}

int ps2_ee_sltu64(ps2_ee_state_t *s, unsigned rd, unsigned rs, unsigned rt)
{
    if (!valid(s, rd, rs, rt)) return -1;
    if (rd != 0u) s->gpr[rd] = (s->gpr[rs] < s->gpr[rt]) ? 1u : 0u;
    s->gpr[0] = 0;
    return 0;
}

int ps2_ee_movz(ps2_ee_state_t *s, unsigned rd, unsigned rs, unsigned rt)
{
    if (!valid(s, rd, rs, rt)) return -1;
    if (s->gpr[rt] == 0u && rd != 0u) s->gpr[rd] = s->gpr[rs];
    s->gpr[0] = 0;
    return 0;
}

int ps2_ee_movn(ps2_ee_state_t *s, unsigned rd, unsigned rs, unsigned rt)
{
    if (!valid(s, rd, rs, rt)) return -1;
    if (s->gpr[rt] != 0u && rd != 0u) s->gpr[rd] = s->gpr[rs];
    s->gpr[0] = 0;
    return 0;
}
