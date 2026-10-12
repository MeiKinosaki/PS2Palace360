#ifndef PS2PALACE360_EE_IMMEDIATE_H
#define PS2PALACE360_EE_IMMEDIATE_H

#include "ee_state.h"

int ps2_ee_addi32(ps2_ee_state_t *state, unsigned rt,
                  unsigned rs, int16_t immediate);
int ps2_ee_addiu32(ps2_ee_state_t *state, unsigned rt,
                   unsigned rs, int16_t immediate);
int ps2_ee_slti64(ps2_ee_state_t *state, unsigned rt,
                  unsigned rs, int16_t immediate);
int ps2_ee_sltiu64(ps2_ee_state_t *state, unsigned rt,
                   unsigned rs, int16_t immediate);
int ps2_ee_lui(ps2_ee_state_t *state, unsigned rt, uint16_t immediate);

#endif
