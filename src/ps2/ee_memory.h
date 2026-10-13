#ifndef PS2PALACE360_EE_MEMORY_H
#define PS2PALACE360_EE_MEMORY_H
#include <stddef.h>
#include <stdint.h>

typedef struct ps2_ee_memory {
    uint8_t *ram;
    size_t ram_size;
} ps2_ee_memory_t;

int ps2_ee_mem_load(ps2_ee_memory_t *mem, uint32_t address,
                    unsigned width, uint64_t *value);
int ps2_ee_mem_store(ps2_ee_memory_t *mem, uint32_t address,
                     unsigned width, uint64_t value);
#endif
