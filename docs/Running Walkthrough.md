# Running Walkthrough — MGS Integral PS2 port

Dated log of how each change was made and what was tried. The plan is `Planning Doc.md`; HAL work is logged in
`../psx-to-ps2-HAL/docs/Walkthrough.md`.

## Step 1: the main executable compiles for the EE (2026-10-27)

`build/build_ps2.py` compiles the main executable's C files (the objects `linker_command_file.txt` lists before
its overlay sections: 219 files, all C) with ps2dev's GCC under `-DMGS_PORT -DINTEGRAL` into `obj_ps2/` (one
`.log` per file). The matching build (`build.py`, `obj/`) is untouched.

Flags, as the SH1 port settled on for decompiled PS1 code: `-O2 -G0 -std=gnu89 -nostdinc`, NULL reads stay reads
(`-fno-delete-null-pointer-checks -fno-isolate-erroneous-paths-dereference`), loops keep their counts
(`-fno-aggressive-loop-optimizations`), `-fno-toplevel-reorder`, GCC 14's new errors for old C downgraded.
`-fexec-charset=EUC-JP` does what the PS1 build's `convjp.py` step does (string literals UTF-8 -> EUC-JP; checked
byte for byte against Python's encoder).

Include order: `port/include` (the port's shims and generated headers), the HAL's `include`, `source`,
`source/include`, then Sony's stock PSY-Q 4.4 headers (`../psyq_sdk/psyq_4.4/include`), as the PS1 build uses.

**GTE macros.** MGS uses Nugget's no-DMPSX `inline_n.h` and its own `inline_x.h` (raw COP2 inline asm, which the
EE can't run). The SH1 port's generator moved to the HAL (`tools/gen_gte_inline.py`, now with
`<source>=<output>` arguments; SH1's `tools/port/gen_gte_inline.py` is a wrapper; its output is unchanged but for
the comment line) and learned Nugget's `cop2 <command>` form (and `cop2 %0`, for `gte_mvmva_core`):
`port/include/gte_from_inline_n.h` (243 macros), `gte_from_inline_x.h` (10), `gte_from_radar.h` (radar.c's two
local macros). `port/include/inline_n.h`/`inline_x.h` are shims: `#include_next` the game's header, then the
translation. The game's headers have no include guard and are included more than once, so the shim clears the
generated header's guard first: otherwise a second inclusion put the asm versions back (5 files failed on
`mtc2`/`swc2` until then).

**Source changes, all under `MGS_PORT`** (matching build: 80 OK, and the VR executable):
- `mts/mts_new.h`: `mts_assert` takes the existing C99 variant (GCC rejects `printf( ##args )`).
- `mts/mask.c`: `SetExMask`'s `break 1030` left out (the EE assembler has no single-operand break code above
  1023; a debug trap).
- `menu/radioanim.c` (`OFFSET_TO_PTR2`), `takabe/thing.c`: casts as lvalues written as stores through a pointer.
- `libfs/cdstage.c`: the `extern` declarations before the `static` definitions left out.
- `enemy/action.c`: `s00a_off_800C33F4` points to writable arrays (the code writes digits into these strings;
  string literals are shared and read-only to GCC).
- `menu/radar.c`: its two local GTE macros from `gte_from_radar.h`.
- `include/psxdefs.h`: `SetSpadStack`/`ResetSpadStack` are no-ops (they moved the stack into the PS1 scratchpad at
  0x1F8003FC; only a speed trick, and the address isn't the scratchpad on the EE).

Result: 219 of 219 compile. Warnings left: 1118 `-Wbuiltin-declaration-mismatch` (PSY-Q's prototypes of C library
functions), one `-Woverflow` (PSY-Q's `termPrim` storing 0xFFFFFFFF in a 24-bit field, intended).
