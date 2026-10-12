#include "ee_decode.h"
#include "ee_ops.h"
#include "ee_immediate.h"
#include "ee_compare.h"
#include <stddef.h>

static uint32_t sx16(uint32_t x) { return (uint32_t)(int32_t)(int16_t)(x & 0xffffu); }

ps2_ee_step_result_t ps2_ee_execute_word(ps2_ee_state_t *s, uint32_t insn)
{
    unsigned op, rs, rt, rd, fn;
    int rc = -1;
    if (s == NULL) return PS2_EE_STEP_INVALID;
    op = insn >> 26; rs = (insn >> 21) & 31u; rt = (insn >> 16) & 31u;
    rd = (insn >> 11) & 31u; fn = insn & 63u;
    switch (op) {
    case 0:
        switch (fn) {
        case 0x20: rc = ps2_ee_add32(s, rd, rs, rt); break;
        case 0x21: rc = ps2_ee_addu32(s, rd, rs, rt); break;
        case 0x22: rc = ps2_ee_sub32(s, rd, rs, rt); break;
        case 0x23: rc = ps2_ee_subu32(s, rd, rs, rt); break;
        case 0x24: rc = ps2_ee_logic(s, rd, rs, rt, PS2_EE_LOGIC_AND); break;
        case 0x25: rc = ps2_ee_logic(s, rd, rs, rt, PS2_EE_LOGIC_OR); break;
        case 0x26: rc = ps2_ee_logic(s, rd, rs, rt, PS2_EE_LOGIC_XOR); break;
        case 0x27: rc = ps2_ee_logic(s, rd, rs, rt, PS2_EE_LOGIC_NOR); break;
        case 0x2a: rc = ps2_ee_slt64(s, rd, rs, rt); break;
        case 0x2b: rc = ps2_ee_sltu64(s, rd, rs, rt); break;
        case 0x0a: rc = ps2_ee_movz(s, rd, rs, rt); break;
        case 0x0b: rc = ps2_ee_movn(s, rd, rs, rt); break;
        default: return PS2_EE_STEP_UNSUPPORTED;
        }
        break;
    case 0x08: rc = ps2_ee_addi32(s, rt, rs, (int16_t)insn); break;
    case 0x09: rc = ps2_ee_addiu32(s, rt, rs, (int16_t)insn); break;
    case 0x0a: rc = ps2_ee_slti64(s, rt, rs, (int16_t)insn); break;
    case 0x0b: rc = ps2_ee_sltiu64(s, rt, rs, (int16_t)insn); break;
    case 0x0f: rc = ps2_ee_lui(s, rt, (uint16_t)insn); break;
    default: return PS2_EE_STEP_UNSUPPORTED;
    }
    (void)sx16;
    if (rc == -1) return PS2_EE_STEP_INVALID;
    if (rc == 1) return PS2_EE_STEP_UNSUPPORTED;
    return PS2_EE_STEP_OK;
}
