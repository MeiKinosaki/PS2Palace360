#include "ee_memory.h"

int ps2_ee_translate_address(uint32_t virtual_address, uint32_t *physical_address)
{
    uint32_t segment = virtual_address & UINT32_C(0xE0000000);
    if (physical_address == 0) return -1;
    /* KSEG0/KSEG1 are direct-mapped in this prototype only. */
    if (segment == UINT32_C(0x80000000) || segment == UINT32_C(0xA0000000)) {
        *physical_address = virtual_address & UINT32_C(0x1FFFFFFF);
        return 0;
    }
    /* KUSEG/KSEG2 require a real TLB and are deliberately unsupported. */
    return -1;
}

static int valid(const ps2_ee_memory_t *m, uint32_t address,
                 unsigned width)
{
    if (m == 0 || m->ram == 0) return 0;
    if (width != 1u && width != 2u && width != 4u && width != 8u) return 0;
    if ((address & (width - 1u)) != 0u) return 0;
    /* Subtraction form avoids overflow in address + width. */
    if ((uint64_t)address > (uint64_t)m->ram_size) return 0;
    if ((uint64_t)width > (uint64_t)m->ram_size - (uint64_t)address) return 0;
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
