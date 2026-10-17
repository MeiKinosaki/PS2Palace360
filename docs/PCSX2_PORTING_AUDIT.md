# PCSX2-to-PS2Palace360 porting audit

Status: planning and source audit only. This document does not claim PCSX2 code has been copied, that a build passed, or that Xbox 360 execution works.

## Goal

Reuse suitable PCSX2 implementation knowledge and, where license-compatible, source code to reduce duplicated work while producing an Xbox 360 RGH build. The deliverable remains `default.xex`; any ELF is an intermediate build artifact.

## Verified PS2Palace360 baseline

- `src/ps2/ee_memory.c` contains a prototype RAM buffer, direct-mapped KSEG0/KSEG1 address translation, and a small 16-entry, 4 KiB-page TLB scaffold.
- TLB scaffolding recognizes ASID/global matching, invalid entries, duplicate matches, and dirty-bit write denial.
- `tests/test_ee_state.c` contains host-side assertions for parts of the EE and memory helpers.
- The README explicitly says `src/main.c` is an empty bootstrap and that IOP, DMA, VU, GS, audio, input, media loading, and game boot are not integrated.
- The cloud XEX build requires a runner with `xenon-gcc` and `elf2xex`; the standard GitHub runner does not provide these automatically.

## Porting matrix

| Area | PCSX2 material to inspect | PS2Palace360 action | Acceptance evidence |
|---|---|---|---|
| EE/R5900 interpreter | Instruction semantics, decoder, exceptions and delay-slot behavior | Map instruction groups to existing `ee_*` modules; port only code that can be isolated from host-specific dependencies | Host tests for each added opcode and exception case |
| Memory/MMU/TLB | Virtual-address handling, TLB fault distinctions, memory access rules | Compare current experimental TLB API against architectural behavior; document unsupported cases before integrating | Tests for ASID/global, invalid, modified, duplicate, bounds and alignment cases |
| IOP | IOP CPU and memory/device interactions | Create a separate module boundary; do not pretend EE support implies IOP support | IOP instruction and interrupt tests |
| DMA and interrupts | Channel behavior, transfer completion and interrupt routing | Implement explicit channel state and completion events | Deterministic transfer and IRQ tests |
| VU0/VU1 | Vector instruction semantics and microprogram behavior | Separate scalar/vector execution from renderer integration | Vector arithmetic and microprogram tests |
| GS/video | GS register semantics, framebuffer and rendering pipeline | Replace PC-specific graphics APIs with a target abstraction suitable for Xbox 360 | Render-target test and console screenshot/boot evidence |
| Audio/input/media | SPU2, controller and disc/image interfaces | Define narrow platform interfaces before adapting backends | Device tests plus console integration |
| Build/runtime | PCSX2 build system and host libraries | Do not import the whole desktop build system; use Xbox 360 toolchain and minimal dependencies | Reproducible build log and generated `default.xex` checksum |

## Licensing and dependency gate

Before copying or adapting PCSX2 source, verify the exact upstream license, preserve copyright and license notices, identify derivative files, and satisfy applicable source-distribution and notice obligations. Keep an attribution/source manifest for every imported file. Do not copy third-party code until its license and dependencies have been reviewed.

## Recommended order

1. Produce a file-by-file dependency and license inventory of the chosen PCSX2 revision.
2. Choose one small, self-contained EE instruction group and port its semantics with tests.
3. Run the host test suite and record the exact command and result.
4. Integrate EE state, memory and exceptions before beginning IOP/VU/GS integration.
5. Configure a real Xenon toolchain runner; compile and verify `default.xex`.
6. Test on Xbox 360 RGH and report game compatibility only after observed results.

## Progress reporting rules

- Source inspected is not source ported.
- Tests added are not tests passed.
- A successful host build is not a Xenon build.
- A generated XEX is not proof of a working PS2 emulator.
- Increase the overall percentage only when functional, integrated and verified milestones justify it.
