#ifndef PS2PALACE360_EE_TIMER_H
#define PS2PALACE360_EE_TIMER_H
#include <stdint.h>

typedef struct ps2_ee_timer {
    uint32_t count;
    uint32_t compare;
    uint8_t enabled;
    uint8_t irq_pending;
} ps2_ee_timer_t;

enum {
    PS2_EE_TIMER_OK = 0,
    PS2_EE_TIMER_ERR_ARGUMENT = -1
};

void ps2_ee_timer_reset(ps2_ee_timer_t *timer);
int ps2_ee_timer_configure(ps2_ee_timer_t *timer, uint32_t count,
                           uint32_t compare, int enabled);
int ps2_ee_timer_advance(ps2_ee_timer_t *timer, uint32_t ticks);
int ps2_ee_timer_ack_irq(ps2_ee_timer_t *timer);

#endif
