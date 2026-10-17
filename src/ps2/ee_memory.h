#ifndef PS2PALACE360_EE_MEMORY_H
#define PS2PALACE360_EE_MEMORY_H
#include <stddef.h>
#include <stdint.h>

/* v0.90b: detailed translation status codes. */
enum {
    PS2_EE_TRANSLATE_OK = 0,
    PS2_EE_TRANSLATE_ERR_ARGUMENT = -1,
    PS2_EE_TRANSLATE_ERR_UNSUPPORTED = -2
};

typedef struct ps2_ee_memory {
    uint8_t *ram;
    size_t ram_size;
} ps2_ee_memory_t;

/* Minimal EE virtual-to-physical translation scaffold (no TLB yet).
 * Returns 0 for supported direct segments, -1 for unsupported addresses.
 */
int ps2_ee_translate_address(uint32_t virtual_address, uint32_t *physical_address);
/* Detailed variant distinguishes bad output pointers from unsupported segments. */
int ps2_ee_translate_address_ex(uint32_t virtual_address, uint32_t *physical_address);

int ps2_ee_mem_load(ps2_ee_memory_t *mem, uint32_t address,
                    unsigned width, uint64_t *value);
int ps2_ee_mem_store(ps2_ee_memory_t *mem, uint32_t address,
                     unsigned width, uint64_t value);

/* Experimental virtual accessors: translate KSEG0/KSEG1 then access RAM.
 * This is not a complete PS2 memory map and does not implement a TLB.
 */
int ps2_ee_mem_load_virtual(ps2_ee_memory_t *mem, uint32_t virtual_address,
                            unsigned width, uint64_t *value);
int ps2_ee_mem_store_virtual(ps2_ee_memory_t *mem, uint32_t virtual_address,
                             unsigned width, uint64_t value);
#endif
