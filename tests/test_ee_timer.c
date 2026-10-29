#include "ee_timer.h"
#include <assert.h>
#include <stdint.h>
#include <stdio.h>

int main(void)
{
    ps2_ee_timer_t timer;
    ps2_ee_timer_reset(&timer);
    assert(timer.count == 0 && timer.compare == 0);
    assert(timer.enabled == 0 && timer.irq_pending == 0);
    assert(ps2_ee_timer_advance(&timer, 10) == PS2_EE_TIMER_OK);
    assert(timer.count == 0 && timer.irq_pending == 0);
    assert(ps2_ee_timer_configure(&timer, 2, 5, 1) == PS2_EE_TIMER_OK);
    assert(ps2_ee_timer_advance(&timer, 2) == PS2_EE_TIMER_OK);
    assert(timer.count == 4 && timer.irq_pending == 0);
    assert(ps2_ee_timer_advance(&timer, 2) == PS2_EE_TIMER_OK);
    assert(timer.count == 6 && timer.irq_pending == 1);
    assert(ps2_ee_timer_ack_irq(&timer) == PS2_EE_TIMER_OK);
    assert(timer.irq_pending == 0);
    assert(ps2_ee_timer_configure(&timer, UINT32_MAX - 1u, 1u, 1) == PS2_EE_TIMER_OK);
    assert(ps2_ee_timer_advance(&timer, 3u) == PS2_EE_TIMER_OK);
    assert(timer.count == 1u && timer.irq_pending == 1u);
    assert(ps2_ee_timer_advance(0, 1) == PS2_EE_TIMER_ERR_ARGUMENT);
    assert(ps2_ee_timer_configure(0, 0, 0, 0) == PS2_EE_TIMER_ERR_ARGUMENT);
    assert(ps2_ee_timer_ack_irq(0) == PS2_EE_TIMER_ERR_ARGUMENT);
    puts("OK: EE timer reset, enable, compare crossing, wraparound and IRQ acknowledgement.");
    return 0;
}
