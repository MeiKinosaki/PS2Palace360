#ifndef PS2PALACE360_EE_COMPARE_H
#define PS2PALACE360_EE_COMPARE_H

#include "ee_state.h"

int ps2_ee_slt64(ps2_ee_state_t *state, unsigned rd, unsigned rs, unsigned rt);
int ps2_ee_sltu64(ps2_ee_state_t *state, unsigned rd, unsigned rs, unsigned rt);
int ps2_ee_movz(ps2_ee_state_t *state, unsigned rd, unsigned rs, unsigned rt);
int ps2_ee_movn(ps2_ee_state_t *state, unsigned rd, unsigned rs, unsigned rt);

#endif
