#!/usr/bin/env python3
"""Generate a deterministic, paginated 10,000,000-step PS2Palace360 backlog.

This script creates planning records only. It does not claim that any task has
been implemented, compiled, or tested. Use --start/--count to generate a small
page rather than one enormous file.
"""
import argparse
import csv
import sys

AREAS = [
    "EE/R5900 decode and execution",
    "EE registers, HI/LO and arithmetic",
    "CP0 exceptions and interrupts",
    "TLB and virtual memory",
    "physical memory and MMIO",
    "IOP and subsystem memory",
    "DMA channels and arbitration",
    "VU0 execution",
    "VU1 execution",
    "GIF packet transfer",
    "GS rasterization",
    "textures and framebuffer",
    "SPU2 audio",
    "CD/DVD and filesystem",
    "controllers and multitap",
    "BIOS and boot compatibility",
    "scheduler and timing",
    "JIT/dynarec for Xenon",
    "video presentation and Xenos",
    "libXenon runtime and input",
    "PowerPC/Xenon toolchain",
    "ELF/XEX packaging",
    "unit and regression tests",
    "per-game compatibility",
    "save states and memory cards",
    "game list, covers and interface",
    "per-game configuration",
    "logs and crash recovery",
    "licensing and documentation",
    "CI and hardware validation",
]
ACTIONS = [
    "define requirements and acceptance criteria",
    "audit current code and dependencies",
    "specify interfaces and error handling",
    "implement the smallest functional unit",
    "add positive and negative tests",
    "check bounds, alignment and overflow",
    "document behavior and limitations",
    "integrate with the preceding subsystem",
    "run regression tests and fix failures",
    "record build/test evidence and status",
]
STATUSES = ("pending", "implemented_unverified", "built_unverified",
            "tests_passed", "hardware_verified")


def record(stage_id: int) -> dict:
    area_index = ((stage_id - 1) * len(AREAS)) // 10_000_000
    # Cycle through areas at a finer granularity so pages cover every area.
    area_index = ((stage_id - 1) // 10) % len(AREAS)
    action = ACTIONS[(stage_id - 1) % len(ACTIONS)]
    return {
        "stage_id": f"{stage_id:08d}",
        "area": AREAS[area_index],
        "action": action,
        "subtask": ((stage_id - 1) // (len(AREAS) * len(ACTIONS))) + 1,
        "status": "pending",
        "evidence": "",
    }


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--start", type=int, default=1,
                        help="first stage ID, inclusive (default: 1)")
    parser.add_argument("--count", type=int, default=1000,
                        help="number of stages to emit, max 100000 (default: 1000)")
    args = parser.parse_args()
    total = 10_000_000
    if args.start < 1 or args.start > total:
        parser.error("--start must be between 1 and 10000000")
    if args.count < 1 or args.count > 100_000:
        parser.error("--count must be between 1 and 100000")
    end = min(total, args.start + args.count - 1)
    writer = csv.DictWriter(sys.stdout, fieldnames=[
        "stage_id", "area", "action", "subtask", "status", "evidence"
    ])
    writer.writeheader()
    for stage_id in range(args.start, end + 1):
        writer.writerow(record(stage_id))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
