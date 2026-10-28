#!/usr/bin/env python3
"""Report raw PS1 RAM/scratchpad address literals in C sources.

Fixed addresses must go through `PSX_ADDR()` (source/include/psx_mem.h) so the port build can
redirect them. This script flags literals outside comments, not wrapped in `PSX_ADDR(...)`, of two kinds:
  - buffers: the scratchpad (0x1F800000-0x1F800400, its end address included) and main RAM from MEM_ADDR (0x80117000) up, the
    game's heap, load buffers and stack. These belong in the arenas: reported by default.
  - symbols: main RAM below that, the addresses of the executable's and overlays' code and data
    (jump tables, NEWCHARA tables). They need real symbols when the overlays are linked in
    (Step 3 of the plan): reported with --symbols.

Exit status is 1 if anything is reported, so it can be used as a check.
"""

import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
SCAN_DIRS = ["source"]
SKIP_DIRS = []

BUFFER_BOTTOM = 0x80117000  # MEM_ADDR (libgv.h)

# Known literals that are values, not addresses, or are handled by a later step.
# Format: (path relative to repo root, literal).
ALLOWLIST = {
    # The abstraction itself.
    ("source/include/psx_mem.h", "0x1F800000"),
}

LITERAL_RE = re.compile(r"(?<![\w])0x([0-9A-Fa-f]{8})\b")
WRAPPED_RE = re.compile(r"PSX_ADDR\(\s*0x[0-9A-Fa-f]+\s*\)")


def strip_comments(text):
    """Replace comments with spaces, keeping line structure."""
    def repl(m):
        return re.sub(r"[^\n]", " ", m.group(0))
    return re.sub(r"//[^\n]*|/\*.*?\*/", repl, text, flags=re.S)


def is_fixed_address(value, symbols):
    if 0x1F800000 <= value <= 0x1F800400 or BUFFER_BOTTOM <= value <= 0x801FFFFF:
        return True
    return symbols and 0x80010000 <= value < BUFFER_BOTTOM


def scan_file(path, symbols):
    rel = path.relative_to(ROOT).as_posix()
    text = strip_comments(path.read_text(encoding="utf-8", errors="replace"))
    hits = []
    for lineno, line in enumerate(text.splitlines(), 1):
        line = WRAPPED_RE.sub("", line)
        for m in LITERAL_RE.finditer(line):
            literal = "0x" + m.group(1).upper()
            if not is_fixed_address(int(m.group(1), 16), symbols):
                continue
            if (rel, literal) in ALLOWLIST:
                continue
            hits.append((rel, lineno, literal, line.strip()))
    return hits


def main():
    symbols = "--symbols" in sys.argv[1:]
    hits = []
    for d in SCAN_DIRS:
        for path in sorted((ROOT / d).rglob("*")):
            if path.suffix not in (".c", ".h", ".inc"):
                continue
            rel = path.relative_to(ROOT).as_posix()
            if any(rel.startswith(s + "/") for s in SKIP_DIRS):
                continue
            hits.extend(scan_file(path, symbols))

    for rel, lineno, literal, line in hits:
        print(f"{rel}:{lineno}: {literal}: {line}")

    if hits:
        print(f"\n{len(hits)} raw fixed address literal(s) found; wrap them in PSX_ADDR().")
        return 1

    print("No raw fixed address literals found.")
    return 0


if __name__ == "__main__":
    sys.exit(main())
