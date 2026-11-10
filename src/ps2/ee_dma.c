#include "ee_dma.h"

#include <string.h>

void ps2_ee_dma_reset(ps2_ee_dma_channel_t *channel)
{
    if (channel == 0) return;
    channel->source = 0;
    channel->destination = 0;
    channel->remaining_bytes = 0;
    channel->active = 0;
    channel->completed = 0;
    channel->error = 0;
}

int ps2_ee_dma_start(ps2_ee_dma_channel_t *channel, uint32_t source,
                     uint32_t destination, uint32_t byte_count)
{
    if (channel == 0) return PS2_EE_DMA_ERR_ARGUMENT;
    channel->source = source;
    channel->destination = destination;
    channel->remaining_bytes = byte_count;
    channel->active = byte_count != 0;
    channel->completed = byte_count == 0;
    channel->error = 0;
    return PS2_EE_DMA_OK;
}

int ps2_ee_dma_step(ps2_ee_dma_channel_t *channel, uint8_t *memory,
                    size_t memory_size, size_t bytes_per_step)
{
    size_t amount;
    if (channel == 0 || (memory == 0 && memory_size != 0))
        return PS2_EE_DMA_ERR_ARGUMENT;
    if (!channel->active) return PS2_EE_DMA_OK;
    if (memory == 0 || bytes_per_step == 0)
        return PS2_EE_DMA_ERR_ARGUMENT;

    if ((size_t)channel->source > memory_size ||
        (size_t)channel->destination > memory_size ||
        (size_t)channel->remaining_bytes > memory_size - (size_t)channel->source ||
        (size_t)channel->remaining_bytes > memory_size - (size_t)channel->destination ||
        channel->remaining_bytes > UINT32_MAX - channel->source ||
        channel->remaining_bytes > UINT32_MAX - channel->destination) {
        channel->active = 0;
        channel->error = 1;
        return PS2_EE_DMA_ERR_RANGE;
    }

    amount = channel->remaining_bytes;
    if (amount > bytes_per_step) amount = bytes_per_step;
    memmove(memory + channel->destination, memory + channel->source, amount);
    channel->source += (uint32_t)amount;
    channel->destination += (uint32_t)amount;
    channel->remaining_bytes -= (uint32_t)amount;
    if (channel->remaining_bytes == 0) {
        channel->active = 0;
        channel->completed = 1;
    }
    return PS2_EE_DMA_OK;
}
