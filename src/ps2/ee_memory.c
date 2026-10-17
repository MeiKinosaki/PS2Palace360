#include "ee_memory.h"

int ps2_ee_translate_address_ex(uint32_t virtual_address, uint32_t *physical_address)
{
    uint32_t segment = virtual_address & UINT32_C(0xE0000000);
    if (physical_address == 0) return PS2_EE_TRANSLATE_ERR_ARGUMENT;
    /* KSEG0/KSEG1 are direct-mapped in this prototype only. */
    if (segment == UINT32_C(0x80000000) || segment == UINT32_C(0xA0000000)) {
        *physical_address = virtual_address & UINT32_C(0x1FFFFFFF);
        return PS2_EE_TRANSLATE_OK;
    }
    /* KUSEG/KSEG2 require a real TLB and are deliberately unsupported. */
    return PS2_EE_TRANSLATE_ERR_UNSUPPORTED;
}

/* Compatibility wrapper: preserve the original 0/-1 contract. */
int ps2_ee_translate_address(uint32_t virtual_address, uint32_t *physical_address)
{
    return ps2_ee_translate_address_ex(virtual_address, physical_address) ==
           PS2_EE_TRANSLATE_OK ? 0 : -1;
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

int ps2_ee_mem_load_virtual_ex(ps2_ee_memory_t *m, uint32_t virtual_address,
                               unsigned width, uint64_t *value)
{
    uint32_t physical_address;
    int status;
    if (value == 0 || m == 0 || m->ram == 0)
        return PS2_EE_MEM_ERR_ARGUMENT;
    status = ps2_ee_translate_address_ex(virtual_address, &physical_address);
    if (status != PS2_EE_TRANSLATE_OK)
        return PS2_EE_MEM_ERR_TRANSLATION;
    return ps2_ee_mem_load(m, physical_address, width, value) == 0
           ? PS2_EE_MEM_OK : PS2_EE_MEM_ERR_ACCESS;
}

int ps2_ee_mem_store_virtual_ex(ps2_ee_memory_t *m, uint32_t virtual_address,
                                unsigned width, uint64_t value)
{
    uint32_t physical_address;
    int status;
    if (m == 0 || m->ram == 0)
        return PS2_EE_MEM_ERR_ARGUMENT;
    status = ps2_ee_translate_address_ex(virtual_address, &physical_address);
    if (status != PS2_EE_TRANSLATE_OK)
        return PS2_EE_MEM_ERR_TRANSLATION;
    return ps2_ee_mem_store(m, physical_address, width, value) == 0
           ? PS2_EE_MEM_OK : PS2_EE_MEM_ERR_ACCESS;
}

/* Compatibility wrappers preserve the original 0/-1 behavior. */
int ps2_ee_mem_load_virtual(ps2_ee_memory_t *m, uint32_t virtual_address,
                            unsigned width, uint64_t *value)
{
    return ps2_ee_mem_load_virtual_ex(m, virtual_address, width, value) ==
           PS2_EE_MEM_OK ? 0 : -1;
}

int ps2_ee_mem_store_virtual(ps2_ee_memory_t *m, uint32_t virtual_address,
                             unsigned width, uint64_t value)
{
    return ps2_ee_mem_store_virtual_ex(m, virtual_address, width, value) ==
           PS2_EE_MEM_OK ? 0 : -1;
}

/* v0.101b: small, explicit TLB scaffold for 4 KiB pages. This is not yet
 * a complete R5900 MMU: page masks, CP0 registers, privilege checks and
 * architectural exception entry are handled by later work. */
void ps2_ee_tlb_reset(ps2_ee_tlb_t *tlb)
{
    unsigned i;
    if (tlb == 0) return;
    tlb->current_asid = 0;
    for (i = 0; i < PS2_EE_TLB_ENTRY_COUNT; ++i) {
        tlb->entries[i].virtual_page = 0;
        tlb->entries[i].physical_page = 0;
        tlb->entries[i].asid = 0;
        tlb->entries[i].valid = 0;
        tlb->entries[i].dirty = 0;
        tlb->entries[i].global = 0;
    }
}

int ps2_ee_tlb_write(ps2_ee_tlb_t *tlb, unsigned index,
                     uint32_t virtual_page, uint32_t physical_page,
                     uint8_t asid, int valid_entry, int dirty, int global)
{
    ps2_ee_tlb_entry_t *e;
    if (tlb == 0 || index >= PS2_EE_TLB_ENTRY_COUNT ||
        (virtual_page & (PS2_EE_TLB_PAGE_SIZE - 1u)) != 0u ||
        (physical_page & (PS2_EE_TLB_PAGE_SIZE - 1u)) != 0u)
        return PS2_EE_TLB_ERR_ARGUMENT;
    e = &tlb->entries[index];
    e->virtual_page = virtual_page;
    e->physical_page = physical_page;
    e->asid = asid;
    e->valid = valid_entry != 0;
    e->dirty = dirty != 0;
    e->global = global != 0;
    return PS2_EE_TLB_OK;
}

int ps2_ee_tlb_lookup(const ps2_ee_tlb_t *tlb, uint32_t virtual_address,
                      ps2_ee_tlb_entry_t *entry)
{
    uint32_t page;
    unsigned i;
    if (tlb == 0 || entry == 0) return PS2_EE_TLB_ERR_ARGUMENT;
    page = virtual_address & ~(uint32_t)(PS2_EE_TLB_PAGE_SIZE - 1u);
    for (i = 0; i < PS2_EE_TLB_ENTRY_COUNT; ++i) {
        const ps2_ee_tlb_entry_t *e = &tlb->entries[i];
        if (e->virtual_page == page && (e->global || e->asid == tlb->current_asid)) {
            *entry = *e;
            return PS2_EE_TLB_OK;
        }
    }
    return PS2_EE_TLB_ERR_MISS;
}

int ps2_ee_tlb_translate(const ps2_ee_tlb_t *tlb, uint32_t virtual_address,
                         int is_write, uint32_t *physical_address)
{
    uint32_t page, offset;
    unsigned i;
    if (tlb == 0 || physical_address == 0)
        return PS2_EE_TLB_ERR_ARGUMENT;
    page = virtual_address & ~(uint32_t)(PS2_EE_TLB_PAGE_SIZE - 1u);
    offset = virtual_address & (PS2_EE_TLB_PAGE_SIZE - 1u);
    for (i = 0; i < PS2_EE_TLB_ENTRY_COUNT; ++i) {
        const ps2_ee_tlb_entry_t *e = &tlb->entries[i];
        if (e->virtual_page != page || (!e->global && e->asid != tlb->current_asid))
            continue;
        if (!e->valid) return PS2_EE_TLB_ERR_INVALID;
        if (is_write && !e->dirty) return PS2_EE_TLB_ERR_MODIFIED;
        *physical_address = e->physical_page | offset;
        return PS2_EE_TLB_OK;
    }
    return PS2_EE_TLB_ERR_MISS;
}


/* v0.102b: small management helpers for the experimental TLB table. */
int ps2_ee_tlb_set_asid(ps2_ee_tlb_t *tlb, uint8_t asid)
{
    if (tlb == 0) return PS2_EE_TLB_ERR_ARGUMENT;
    tlb->current_asid = asid;
    return PS2_EE_TLB_OK;
}

int ps2_ee_tlb_read(const ps2_ee_tlb_t *tlb, unsigned index,
                    ps2_ee_tlb_entry_t *entry)
{
    if (tlb == 0 || entry == 0 || index >= PS2_EE_TLB_ENTRY_COUNT)
        return PS2_EE_TLB_ERR_ARGUMENT;
    *entry = tlb->entries[index];
    return PS2_EE_TLB_OK;
}

int ps2_ee_tlb_invalidate_asid(ps2_ee_tlb_t *tlb, uint8_t asid)
{
    unsigned i;
    if (tlb == 0) return PS2_EE_TLB_ERR_ARGUMENT;
    for (i = 0; i < PS2_EE_TLB_ENTRY_COUNT; ++i) {
        ps2_ee_tlb_entry_t *e = &tlb->entries[i];
        if (!e->global && e->asid == asid) e->valid = 0;
    }
    return PS2_EE_TLB_OK;
}


/* v0.103b: combine direct-mapped segments with the experimental TLB.
 * No CP0 exception entry or privilege-mode enforcement is performed here. */
int ps2_ee_translate_address_with_tlb(const ps2_ee_tlb_t *tlb,
                                      uint32_t virtual_address, int is_write,
                                      uint32_t *physical_address)
{
    uint32_t segment;
    if (physical_address == 0) return PS2_EE_TLB_ERR_ARGUMENT;
    segment = virtual_address & UINT32_C(0xE0000000);
    if (segment == UINT32_C(0x80000000) || segment == UINT32_C(0xA0000000)) {
        *physical_address = virtual_address & UINT32_C(0x1FFFFFFF);
        return PS2_EE_TLB_OK;
    }
    return ps2_ee_tlb_translate(tlb, virtual_address, is_write, physical_address);
}


/* v0.104b: memory access routed through direct-map/TLB dispatcher. */
int ps2_ee_mem_load_virtual_tlb(ps2_ee_memory_t *m, const ps2_ee_tlb_t *tlb,
                                uint32_t virtual_address, unsigned width,
                                uint64_t *value)
{
    uint32_t physical_address;
    int status;
    if (m == 0 || m->ram == 0 || value == 0) return PS2_EE_MEM_ERR_ARGUMENT;
    status = ps2_ee_translate_address_with_tlb(tlb, virtual_address, 0, &physical_address);
    if (status != PS2_EE_TLB_OK) return PS2_EE_MEM_ERR_TRANSLATION;
    return ps2_ee_mem_load(m, physical_address, width, value) == 0
           ? PS2_EE_MEM_OK : PS2_EE_MEM_ERR_ACCESS;
}

int ps2_ee_mem_store_virtual_tlb(ps2_ee_memory_t *m, const ps2_ee_tlb_t *tlb,
                                 uint32_t virtual_address, unsigned width,
                                 uint64_t value)
{
    uint32_t physical_address;
    int status;
    if (m == 0 || m->ram == 0) return PS2_EE_MEM_ERR_ARGUMENT;
    status = ps2_ee_translate_address_with_tlb(tlb, virtual_address, 1, &physical_address);
    if (status != PS2_EE_TLB_OK) return PS2_EE_MEM_ERR_TRANSLATION;
    return ps2_ee_mem_store(m, physical_address, width, value) == 0
           ? PS2_EE_MEM_OK : PS2_EE_MEM_ERR_ACCESS;
}


/* v0.107b: permission/status-only check without forming a physical address. */
int ps2_ee_tlb_check_page(const ps2_ee_tlb_t *tlb, uint32_t virtual_address,
                          int is_write)
{
    ps2_ee_tlb_entry_t entry;
    int status = ps2_ee_tlb_lookup(tlb, virtual_address, &entry);
    if (status != PS2_EE_TLB_OK) return status;
    if (!entry.valid) return PS2_EE_TLB_ERR_INVALID;
    if (is_write && !entry.dirty) return PS2_EE_TLB_ERR_MODIFIED;
    return PS2_EE_TLB_OK;
}
