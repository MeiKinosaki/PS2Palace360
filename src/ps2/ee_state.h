#ifndef PS2PALACE360_EE_STATE_H
#define PS2PALACE360_EE_STATE_H

#include <stdint.h>

#define PS2_EE_GPR_COUNT 32u

/* MIPS-style Cause.ExcCode values used by the experimental EE core. */
#define PS2_EE_EXC_INT   0u
#define PS2_EE_EXC_MOD   1u
#define PS2_EE_EXC_TLBL  2u
#define PS2_EE_EXC_TLBS  3u
#define PS2_EE_EXC_ADEL  4u
#define PS2_EE_EXC_ADES  5u
#define PS2_EE_EXC_IBE   6u
#define PS2_EE_EXC_DBE   7u
#define PS2_EE_EXC_SYS   8u
#define PS2_EE_EXC_BP    9u
#define PS2_EE_EXC_RI    10u
#define PS2_EE_EXC_CPU   11u
#define PS2_EE_EXC_OV    12u
#define PS2_EE_EXC_TR    13u
#define PS2_EE_EXC_FPE   15u

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

/* Initial MIPS-style exception entry; exc_code is the Cause.ExcCode value. */
void ps2_ee_raise_exception(ps2_ee_state_t *state, uint32_t fault_pc,
                            uint32_t exc_code, int in_delay_slot);
void ps2_ee_reset(ps2_ee_state_t *state);
int ps2_ee_add32(ps2_ee_state_t *state, unsigned rd,
                 unsigned rs, unsigned rt);
int ps2_ee_sub32(ps2_ee_state_t *state, unsigned rd,
                 unsigned rs, unsigned rt);

#endif
