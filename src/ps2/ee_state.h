#ifndef PS2PALACE360_EE_STATE_H
#define PS2PALACE360_EE_STATE_H

#include <stdint.h>

#define PS2_EE_GPR_COUNT 32u

typedef struct ps2_ee_state {
    uint64_t gpr[PS2_EE_GPR_COUNT];
    uint64_t hi;
    uint64_t lo;
    uint32_t pc;
    uint32_t next_pc;
    uint32_t cause;
    uint32_t status;
    uint32_t epc;
} ps2_ee_state_t;

void ps2_ee_reset(ps2_ee_state_t *state);
int ps2_ee_add32(ps2_ee_state_t *state, unsigned rd,
                 unsigned rs, unsigned rt);
int ps2_ee_sub32(ps2_ee_state_t *state, unsigned rd,
                 unsigned rs, unsigned rt);

#endif
