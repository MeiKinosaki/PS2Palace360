#ifndef PS2PALACE360_EE_DECODE_H
#define PS2PALACE360_EE_DECODE_H
#include "ee_state.h"
#include "ee_memory.h"
#include <stdint.h>
typedef enum { PS2_EE_STEP_OK = 0, PS2_EE_STEP_UNSUPPORTED = 1, PS2_EE_STEP_INVALID = -1 } ps2_ee_step_result_t;
ps2_ee_step_result_t ps2_ee_execute_word(ps2_ee_state_t *state, uint32_t instruction);
ps2_ee_step_result_t ps2_ee_execute_memory_word(ps2_ee_state_t *state, ps2_ee_memory_t *memory, uint32_t instruction);
#endif
