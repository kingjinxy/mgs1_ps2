# Overlay data reset plan

The stage overlays are linked into the executable (Step 3, `build/overlays_ps2.py`). On the PS1,
loading a stage copies its overlay again, so the overlay's `.data` goes back to its initial values and
its `.bss` to zero. In the port, linked-in overlays keep their variables from the last visit. This
plan restores the PS1 behaviour. It is the open Step 3 item "Reset an overlay's `.data`/`.bss` when its
stage loads again" in `Planning Doc.md`.

We chose this over loading overlay code from disc: the RAM cost of linking everything in is small, and
a real loader would need one link per overlay at a shared address, icache flushes and slower stage
changes.

## What SH1 learned (`../silent-hill-1-ps2-port/src/port/overlay.c`)

- SH1 has the same mechanism behind `SH_PORT_OVERLAY_RESET` (off). It copies each overlay's `.data`
  at startup and, when the overlay file is read again, restores `.data` and clears `.bss`. The ranges
  come from markers placed by `port_link.py`.
- It fixed a map loaded twice in a row (map0_s01 in the warp sweep). It also broke the second attract
  demo: map2_s00 loaded again, and its world object lookups then read garbage. The cause wasn't found.
  The PS1 behaviour on reload isn't fully modelled.
- Things to rule out in MGS1 before trusting a reset:
  - **Timing:** does the reset run when the read is queued, or when the PS1 copy would actually
    land? Code may still run, or write overlay variables, between those two points.
  - **Does a reload actually happen?** Check that the game really re-reads the overlay. A path that
    keeps the overlay resident (same stage, or a cached binary) must not be reset.
  - **Pointers kept in resident code:** resident code may keep pointers into the overlay's data that
    remain valid on the PS1 only because the same bytes are reloaded at the same address.

## MGS1 specifics

- **Overlay area:** the stage binary loads at `mts_get_bss_tail()`, which is `PSX_ADDR(0x800C3208)`
  (the PS1's `_bss_orgend`). The port still reads the binary there, unused. Check whether anything
  after the overlay in that area (stage heaps, `StageCharacterEntries`, buffers) shares memory with
  overlay `.data`/`.bss` on the PS1, as SH1's screen overlays share a buffer.
- **Shared objects:** each overlay has its own copy of `enemy/*`, `takabe/*` etc., so a reset only
  touches the overlay being loaded. The planned deduplication must keep writable data per overlay, or
  the reset gets harder.
- **Hook:** `Port_SetStage(id)` (`game/chara.c`), called from `libfs/cdstage.c` (the `.bin` tag of a stage
  read) and `GM_LoadInitBin`. Match the PS1 timing: reset where the PS1 copies the binary.

## Steps

1. **Section ranges.** In `overlays_ps2.py`, put each merged overlay's `.data`/`.sdata` and
   `.bss`/`.sbss` between start/end symbols, e.g. `_ovl_<ovl>_data_start`. Extend `obj_ps2/ovl/stages.c`
   with a table: stage code → data range, bss range. Keep read-only data out of the ranges.
2. **Snapshot.** At startup, before any stage runs, copy each overlay's `.data`. With ~59 overlays,
   measure the total size first. If it's large, store the initial `.data` from the ELF instead of a
   runtime copy.
3. **Reset.** In the stage-load hook, restore `.data` and clear `.bss` of the stage's overlay, behind
   a `MGS_PORT_OVERLAY_RESET` flag (default off until verified).
4. **Debug poison (optional).** In a debug build, fill the `.bss` of overlays that aren't loaded with a
   pattern, and report reads of it from resident code. This catches stale pointers into an unloaded
   overlay that work only because everything is linked in. EE data breakpoints don't fire under
   Neutrino, so check in software.
5. **Verify.**
   - Leave a stage and come back (e.g. dock → heliport → dock), and reload the same stage (death/continue).
     Compare against DuckStation.
   - Run the attract/demo sequences twice, since that's the case that broke SH1.
   - Run the matching build, which must still hash OK.
6. **Turn it on** once the checks pass. Update `Planning Doc.md` and `Running Walkthrough.md`.
