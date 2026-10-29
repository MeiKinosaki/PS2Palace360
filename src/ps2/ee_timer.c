#include "ee_timer.h"

void ps2_ee_timer_reset(ps2_ee_timer_t *timer)
{
    if (timer == 0) return;
    timer->count = 0;
    timer->compare = 0;
    timer->enabled = 0;
    timer->irq_pending = 0;
}

int ps2_ee_timer_configure(ps2_ee_timer_t *timer, uint32_t count,
                           uint32_t compare, int enabled)
{
    if (timer == 0) return PS2_EE_TIMER_ERR_ARGUMENT;
    timer->count = count;
    timer->compare = compare;
    timer->enabled = enabled != 0;
    timer->irq_pending = 0;
    return PS2_EE_TIMER_OK;
}

int ps2_ee_timer_advance(ps2_ee_timer_t *timer, uint32_t ticks)
{
    uint32_t old_count;
    if (timer == 0) return PS2_EE_TIMER_ERR_ARGUMENT;
    if (!timer->enabled || ticks == 0) return PS2_EE_TIMER_OK;
    old_count = timer->count;
    timer->count += ticks;
    /* Prototype uses unsigned wraparound and detects compare crossings. */
    if (timer->compare == timer->count ||
        (timer->count > old_count && timer->compare > old_count &&
         timer->compare <= timer->count) ||
        (timer->count < old_count &&
         (timer->compare > old_count || timer->compare <= timer->count)))
        timer->irq_pending = 1;
    return PS2_EE_TIMER_OK;
}

int ps2_ee_timer_ack_irq(ps2_ee_timer_t *timer)
{
    if (timer == 0) return PS2_EE_TIMER_ERR_ARGUMENT;
    timer->irq_pending = 0;
    return PS2_EE_TIMER_OK;
}
