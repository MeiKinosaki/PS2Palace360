#ifndef PS2PALACE360_EE_DMA_H
#define PS2PALACE360_EE_DMA_H

#include <stddef.h>
#include <stdint.h>

typedef struct ps2_ee_dma_channel {
    uint32_t source;
    uint32_t destination;
    uint32_t remaining_bytes;
    uint8_t active;
    uint8_t completed;
    uint8_t error;
} ps2_ee_dma_channel_t;

enum {
    PS2_EE_DMA_OK = 0,
    PS2_EE_DMA_ERR_ARGUMENT = -1,
    PS2_EE_DMA_ERR_RANGE = -2
};

void ps2_ee_dma_reset(ps2_ee_dma_channel_t *channel);
int ps2_ee_dma_start(ps2_ee_dma_channel_t *channel, uint32_t source,
                     uint32_t destination, uint32_t byte_count);
int ps2_ee_dma_step(ps2_ee_dma_channel_t *channel, uint8_t *memory,
                    size_t memory_size, size_t bytes_per_step);

#endif
