#include "ee_dma.h"

#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    uint8_t memory[32];
    ps2_ee_dma_channel_t dma;
    size_t i;

    for (i = 0; i < sizeof(memory); ++i) memory[i] = (uint8_t)i;
    ps2_ee_dma_reset(&dma);
    assert(dma.active == 0 && dma.completed == 0 && dma.error == 0);

    assert(ps2_ee_dma_start(&dma, 0, 16, 8) == PS2_EE_DMA_OK);
    assert(dma.active == 1 && dma.remaining_bytes == 8);
    assert(ps2_ee_dma_step(&dma, memory, sizeof(memory), 3) == PS2_EE_DMA_OK);
    assert(dma.remaining_bytes == 5 && dma.active == 1);
    assert(ps2_ee_dma_step(&dma, memory, sizeof(memory), 8) == PS2_EE_DMA_OK);
    assert(dma.completed == 1 && dma.active == 0 && dma.remaining_bytes == 0);
    for (i = 0; i < 8; ++i) assert(memory[16 + i] == (uint8_t)i);

    assert(ps2_ee_dma_start(&dma, 0, 4, 8) == PS2_EE_DMA_OK);
    assert(ps2_ee_dma_step(&dma, memory, sizeof(memory), 8) == PS2_EE_DMA_OK);
    for (i = 0; i < 8; ++i) assert(memory[4 + i] == (uint8_t)(16 + i));

    assert(ps2_ee_dma_start(&dma, 28, 0, 8) == PS2_EE_DMA_OK);
    assert(ps2_ee_dma_step(&dma, memory, sizeof(memory), 8) == PS2_EE_DMA_ERR_RANGE);
    assert(dma.error == 1 && dma.active == 0 && dma.completed == 0);

    assert(ps2_ee_dma_start(&dma, 0, 0, 0) == PS2_EE_DMA_OK);
    assert(dma.completed == 1 && dma.active == 0);
    assert(ps2_ee_dma_step(0, memory, sizeof(memory), 1) == PS2_EE_DMA_ERR_ARGUMENT);
    assert(ps2_ee_dma_start(0, 0, 0, 1) == PS2_EE_DMA_ERR_ARGUMENT);
    puts("OK: EE DMA chunking, completion, overlap, bounds and arguments.");
    return 0;
}
