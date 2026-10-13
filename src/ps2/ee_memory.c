#include "ee_memory.h"

static int valid(const ps2_ee_memory_t *m, uint32_t address,
                 unsigned width)
{
    if (m == 0 || m->ram == 0) return 0;
    if (width != 1u && width != 2u && width != 4u && width != 8u) return 0;
    if ((address & (width - 1u)) != 0u) return 0;
    if ((uint64_t)address + width > m->ram_size) return 0;
    return 1;
}

int ps2_ee_mem_load(ps2_ee_memory_t *m, uint32_t address,
                    unsigned width, uint64_t *value)
{
    uint64_t result = 0;
    unsigned i;
    if (value == 0 || !valid(m, address, width)) return -1;
    for (i = 0; i < width; ++i)
        result |= (uint64_t)m->ram[address + i] << (8u * i);
    *value = result;
    return 0;
}

int ps2_ee_mem_store(ps2_ee_memory_t *m, uint32_t address,
                     unsigned width, uint64_t value)
{
    unsigned i;
    if (!valid(m, address, width)) return -1;
    for (i = 0; i < width; ++i)
        m->ram[address + i] = (uint8_t)(value >> (8u * i));
    return 0;
}
