#ifndef PS2PALACE360_EE_OPS_H
#define PS2PALACE360_EE_OPS_H

#include "ee_state.h"

int ps2_ee_addu32(ps2_ee_state_t *state, unsigned rd,
                  unsigned rs, unsigned rt);
int ps2_ee_subu32(ps2_ee_state_t *state, unsigned rd,
                  unsigned rs, unsigned rt);
int ps2_ee_logic(ps2_ee_state_t *state, unsigned rd,
                 unsigned rs, unsigned rt, unsigned operation);

#define PS2_EE_LOGIC_AND 0u
#define PS2_EE_LOGIC_OR  1u
#define PS2_EE_LOGIC_XOR 2u
#define PS2_EE_LOGIC_NOR 3u

#endif
