# MGS1 PS2 port — notes for Claude

Port of the `mgs_reversing` decomp to the PS2. Plan: `docs/Planning Doc.md`. Rules below are
carried over from the Silent Hill PS2 port (`../silent-hill-1-ps2-port`), where they were learned.

## Matching build (regression check)

Run from `build/` after every port change; all outputs must print `OK: ... matches target hash`:

```
PATH=/home/alex/.local/share/wibo-as-wine:$PATH /home/alex/.venvs/mgs_reversing/bin/python build.py
```

Add `--variant=vr_exe` for `SLPM_862.49`. The PSY-Q toolchain is `../psyq_sdk`. Wine here is
64-bit only, so the `wine` shim in that directory runs the tools through wibo.

## Working with the user

- **Notify at stopping points.** Send a short push notification at a question that needs the user
  or at a finished step of a multi-step plan; they aren't always watching the session.
- **Web access: GitHub only without asking.** GitHub (github.com, its API, raw/release downloads)
  is fine. Ask the user before fetching or downloading from any other site.
- **Never access tcrf.net** (The Cutting Room Floor) in any way: no fetch, curl or search-result
  fetches, even if the user approves or asks. The site doesn't want Claude scraping it. Ask the
  user to paste the relevant section instead.
- **Keep `docs/Running Walkthrough.md` up to date** at milestones and before commits: append a dated
  `## Step N: ... (date)` section on how each change was made, what was tried and failed, and the state in
  PCSX2 afterwards. Update it together with `docs/Planning Doc.md`'s checkboxes.
- **Keep `Claude Conversation.md` up to date** at milestones and before commits. Concatenate *all*
  session `.jsonl` files in `~/.claude/projects/-home-alex-Documents-mgs1-ps2/` in date order
  (`ls -tr`) into a scratch file, then run
  `python3 tools/port/archive_conversation.py <that file> "Claude Conversation.md"`. The script
  rewrites the whole file, so passing only the newest session drops earlier history; check that
  `git diff` shows no removed lines.
- **Check what was already tried.** Before planning a debugging technique (especially on
  hardware), search `docs/` and the SH1 port's `Running Walkthrough.md`/`Planning Doc.md` for what
  has already been tried and failed.

## Shell

- **No `pkill -f <pattern>`** in a command whose own command line contains the pattern: it kills
  the calling shell and loses the output. Stop background tasks with TaskStop, or kill by a PID
  read first.

## Emulator testing

- **PCSX2 uses the software GS renderer** (`PCSX2.ini` `[EmuCore/GS] Renderer = 13`), enforced by
  any run script. The hardware renderer's host-GPU load distorts performance measurements. Measure
  frame rates in emulated time.
- **A PCSX2 stall is a crash.** 15 emulated seconds without a new frame (at most 15 real seconds
  when emulation is slower): close PCSX2 and end the run, rather than waiting out a long timeout.
- **Never dismiss "TLB Miss" lines in PCSX2.** PCSX2 lets user-mode reads of unmapped addresses
  (e.g. NULL+8) continue, but a real PS2 crashes there. Decompiled PS1 code reads through NULL and
  garbage pointers freely because the PS1 doesn't fault. Collect the unique PCs and fix each one.
- **DuckStation is the reference.** Use its software renderer and keep it muted
  (`OutputMuted = true`). Launch scripts that patch `settings.ini` must not change the renderer.
  Keep gdb stops rare (no per-frame breakpoints).
- **Compare the port's GS renderer against DuckStation**, not against an in-port software renderer
  (too slow to be practical as the main check).

## Real hardware

- **A hung PS2 needs a power cycle.** RESET has never brought Neutrino back on the user's console.
  Ask them to hold power to switch off, turn it on, and restart Neutrino from uLaunchELF. A power
  cycle is a cold boot, which also separates restart-path hangs from build bugs.
- **No EE hardware data breakpoints.** Under Neutrino they never fire, not even for a deliberate
  store. Catch stray writes with software checks in port code linked after the game (SH1 used a
  sentinel in `gte.c`).
