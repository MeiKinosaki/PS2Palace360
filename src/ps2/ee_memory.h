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

/* v0.101b: TLB scaffold result codes. */
enum {
    PS2_EE_TLB_OK = 0,
    PS2_EE_TLB_ERR_ARGUMENT = -1,
    PS2_EE_TLB_ERR_MISS = -2,
    PS2_EE_TLB_ERR_INVALID = -3,
    PS2_EE_TLB_ERR_MODIFIED = -4
};

typedef struct ps2_ee_tlb_entry {
    uint32_t virtual_page;
    uint32_t physical_page;
    uint8_t asid;
    uint8_t valid;
    uint8_t dirty;
    uint8_t global;
} ps2_ee_tlb_entry_t;

enum {
    PS2_EE_TLB_ENTRY_COUNT = 16,
    PS2_EE_TLB_PAGE_SHIFT = 12,
    PS2_EE_TLB_PAGE_SIZE = 4096
};

typedef struct ps2_ee_tlb {
    ps2_ee_tlb_entry_t entries[PS2_EE_TLB_ENTRY_COUNT];
    uint8_t current_asid;
} ps2_ee_tlb_t;

void ps2_ee_tlb_reset(ps2_ee_tlb_t *tlb);
int ps2_ee_tlb_set_asid(ps2_ee_tlb_t *tlb, uint8_t asid);
int ps2_ee_tlb_read(const ps2_ee_tlb_t *tlb, unsigned index,
                    ps2_ee_tlb_entry_t *entry);
int ps2_ee_tlb_invalidate_asid(ps2_ee_tlb_t *tlb, uint8_t asid);
int ps2_ee_tlb_write(ps2_ee_tlb_t *tlb, unsigned index,
                     uint32_t virtual_page, uint32_t physical_page,
                     uint8_t asid, int valid, int dirty, int global);
int ps2_ee_tlb_lookup(const ps2_ee_tlb_t *tlb, uint32_t virtual_address,
                      ps2_ee_tlb_entry_t *entry);
int ps2_ee_tlb_translate(const ps2_ee_tlb_t *tlb, uint32_t virtual_address,
                         int is_write, uint32_t *physical_address);
int ps2_ee_translate_address_with_tlb(const ps2_ee_tlb_t *tlb,
                                      uint32_t virtual_address, int is_write,
                                      uint32_t *physical_address);
int ps2_ee_mem_load_virtual_tlb(ps2_ee_memory_t *mem, const ps2_ee_tlb_t *tlb,
                                uint32_t virtual_address, unsigned width,
                                uint64_t *value);
int ps2_ee_mem_store_virtual_tlb(ps2_ee_memory_t *mem, const ps2_ee_tlb_t *tlb,
                                 uint32_t virtual_address, unsigned width,
                                 uint64_t value);

enum {
    PS2_EE_MEM_OK = 0,
    PS2_EE_MEM_ERR_ARGUMENT = -1,
    PS2_EE_MEM_ERR_TRANSLATION = -2,
    PS2_EE_MEM_ERR_ACCESS = -3
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
/* Detailed virtual accessors distinguish translation from RAM/access errors. */
int ps2_ee_mem_load_virtual_ex(ps2_ee_memory_t *mem, uint32_t virtual_address,
                               unsigned width, uint64_t *value);
int ps2_ee_mem_store_virtual_ex(ps2_ee_memory_t *mem, uint32_t virtual_address,
                                unsigned width, uint64_t value);
#endif
