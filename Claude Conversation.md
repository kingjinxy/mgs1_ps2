# Claude Conversation

MGS1 PS2 port: the working conversation with Claude Code.

## User

I feel that the approach we’ve taken with porting Silent Hill to PS2 has been rather successful. I realize that this MGS1 repo isn’t quite complete, but given the relative ease of going MIPS to MIPS for code translation, how much work do we really need to do to get started?

## Claude

I'll check the repo's current state so the estimate is based on what's actually here.

- tool `Bash`: Survey repo layout and decomp progress

- tool `Bash`: Compare with the SH1 port and check MGS overlays

## Claude

Let me see how the SH1 port was structured so I can map it onto MGS.

- tool `Bash`: Read SH1 port plan and count MGS PSX-specific code

- tool `Bash`: Check SH1 port progress and MGS main-exe porting hazards

## Claude

**Short answer:** less than SH1 needed, because most of the expensive work is already done in your SH1 port. Expect one to two weeks of setup before game code runs on the EE. The part to be careful with is the build system, not translating the code.

## What carries over from the SH1 port almost unchanged

Your SH1 PS2 port isn't really a SH1 port. It's a **PSY-Q→ps2sdk compatibility layer** (HAL) that SH1 happens to run on, and MGS is built against the same family of libraries:
- **Software GTE** (Step 3) carries over directly. MGS's `libdg` uses `gte_*` all over.
- **libgpu→GS** (Step 4): primitives, OT and DrawOTag are the same API. MGS draws through `libdg/sort.c`, `prim.c` and `trans.c`.
- **Pad, CD sectors, memory card** (Step 5): MGS's `libfs` and `memcard/` sit on top of the same libcd/libmcrd calls.
- **SPU on SPU2, XA, STR** (Steps 6–7): MGS has a custom sound driver in `source/sound`, but it drives the same SPU registers. The XA codec and the STR/MDEC decoder carry over as they are.

Most of the SH1 port's hard engineering (GTE accuracy, GS translation, IOP audio, and what you learned about performance and freezes) should move over, mainly by relinking.

## What's actually new for MGS

1. **Build system (the biggest new task).** MGS builds with the original PSY-Q 4.4 compiler (`cc1psx.exe`) driven by `build/build.py`, with no splat/GCC Makefile like SH1 has. You need a second build target, e.g. `build_ps2.py` or a separate ninja file, that compiles `source/` with ps2sdk's EE GCC behind an `MGS_PORT` define. The matching build has to stay untouched. You'll also hit compiler-dialect differences, since this code was written to match an old GCC.
2. **Overlays.** The main executable is 100% decompiled. The overlays are mostly done, but about **740 `INCLUDE_ASM` stubs remain**, concentrated in a few stages: `s08b` ninja (119), `s07b` psyco and meryl (~157), `s14e`, `d18a`, `rank` and `brf`. You'd do Step 2 (static linking) as with SH1. Stages with leftover asm can't be included until they're finished, so start with a playable path that avoids them, e.g. the dock, then the heliport.
3. **Shiftability (Step 1 again).** The README lists "make it shiftable" as an open goal. About 79 non-overlay files contain `gte_` calls, `0x1F80…` scratchpad addresses or `0x80xxxxxx` literals. I haven't separated how many of those are true fixed addresses. You can reuse the pattern from `psx_mem.h` and `find_fixed_addresses.py`.
4. **GCL script interpreter (`libgcl`).** It is pure C and should port without changes, but it handles pointers and offsets from loaded data, so 32-bit EE pointers work in your favour here again.

## Suggested first milestone

Copy the SH1 HAL into a shared directory and get a PS2 build target compiling `main` + `libgv`/`libdg`/`libgcl`/`libfs` against it. Then aim to boot to the title screen with the overlays stubbed out. If the HAL really is game-agnostic, most of the effort goes into fixing compile errors, not new subsystems. Before you start, check whether any SH1-specific assumptions crept into the HAL, such as SH1's file system or its fixed buffer addresses.

If you'd like, I can draft a planning doc for MGS in the style of your SH1 one, or start on the PS2 build target.

## User

Draft a planning doc and put it in a docs folder in the project directory

- tool `Bash`: Gather per-overlay stub counts and porting hazards

- tool `Write`: /home/alex/Documents/mgs1_ps2/docs/Planning Doc.md

## Claude

I've written the plan to [docs/Planning Doc.md](docs/Planning Doc.md), following the format of your SH1 planning doc. Nothing is committed yet.

It has eight steps, starting from Step 0:

- **Step 0: share the SH1 compatibility layer.** Move it somewhere both repos can use, and pull out anything specific to SH1 so it stays one shared library rather than a copy for each game.
- **Step 1: PS2 build target.** Add a separate EE GCC build alongside the PSY-Q build, behind an `MGS_PORT` define. The goal is to boot into `main()` with the overlays stubbed out.
- **Step 2: fixed addresses.** Sort out the 156 files containing `0x80xxxxxx` literals (real addresses vs. plain constants) and the 8 files that use scratchpad addresses directly.
- **Step 3: static linking of overlays.** Hook the overlay loader, and leave any overlay that still has `INCLUDE_ASM` stubs out of the port build until it's finished. Start with a playable route that avoids the overlays with the most stubs.
- **Steps 4–7:** software GTE, graphics, pad/CD/memory card and sound, mostly reusing the SH1 code. I've listed the screens likely to need extra graphics checks: codec/radio, goggles and menu overlays.

The doc also includes a current-state snapshot with the stub counts per overlay. It ends with two open questions for you: which executable to target first (the Integral discs or the VR disc), and whether the port should keep the PS1's memory and video-memory limits or raise them.

## User

I've copied various SDKs to this shared folder: /media/sf_VirtualBox_Shared_Folder/ps1_sdks
If necessary, copy the required PSY-Q docs into the Documents folder.

- tool `Bash`: List the shared SDK folder contents

## Claude

I'll check what the SH1 port already has, then look inside the 4.4 archives, since MGS is built against PSY-Q 4.4.

- tool `Bash`: Check for existing docs and list 4.4 archive contents

- tool `Bash`: List PDFs in English 4.3 Technical Reference

- tool `Bash`: Inspect English Technical Reference archives

## Claude

The English Technical Reference 4.3 is the closest English match to the PSY-Q 4.4 toolchain MGS uses. I'll extract it to the scratchpad to find the library docs.

- tool `Bash`: Extract 4.3 Technical Reference and list its disc

## Claude

This 7-Zip build can't decompress RAR archives, so I'll use the English 4.1 Technical Reference (zip) instead. It's the closest English edition I can extract.

- tool `Bash`: Extract 4.1 Technical Reference and list disc files

## Claude

The image is raw Mode 2 sectors, so I'll strip it down to a plain ISO first.

- tool `Bash`: Convert raw BIN to ISO and list files

## Claude

The useful material is under `DEVREFS` (library reference/overview, file formats, hardware, OS) plus the SDK conference papers. I'll copy those PDFs and skip the sample movies.

- tool `Bash`: Copy PSY-Q reference PDFs into Documents

- tool `Edit`: /home/alex/Documents/mgs1_ps2/docs/Planning Doc.md

- tool `Write`: /home/alex/.claude/projects/-home-alex-Documents-mgs1-ps2/memory/psyq-docs-location.md

- tool `Bash`: Add memory index entry

## Claude

I copied the PSY-Q reference PDFs (32 MB) into **`/home/alex/Documents/psyq_docs`**. They come from the English **Technical Reference 4.1** disc. The ones you'll use most for the compatibility layer:

- **`DEVREFS/LIBREF41.PDF`**: the function-by-function reference for libgpu, libgte, libcd, libspu, libetc, libcard and the rest. This is the API the layer has to reimplement.
- **`DEVREFS/LIBOVR41.PDF`**: an overview of how each library is meant to be used.
- **`DEVREFS/FILE41.PDF`**: the TIM, TMD, VAB and STR data formats. **`HARDWARE.PDF`** and **`OS.PDF`** cover the hardware and BIOS.
- **`CONF/`**: Sony's developer-conference papers on the GPU, GTE, CD, sound and memory card. These are handy for edge cases.

I left out the sample movies and the rest of the disc.

**These docs are for 4.1, not 4.4.** MGS is built against PSY-Q 4.4, but the only 4.4 Technical Reference you have is the Japanese edition. The English 4.3 edition is a `.rar`, and this machine's 7-Zip can't open RAR files. If you want it, install `unrar` and I'll extract it. Library behaviour changed little between those versions. The release notes inside `Runtime Library 4.4.7z` (`psx/441chg.txt`) list what did change.

I also added a "Reference material" section to [docs/Planning Doc.md](docs/Planning Doc.md) pointing at these files, and saved the locations to memory for later sessions.

**Separate issue for the matching build:** `build.py` expects a `psyq_sdk` directory at `/home/alex/Documents/psyq_sdk`, and that directory doesn't exist yet. It needs to contain `psyq_4.4/bin/cc1psx.exe` and the matching headers. That's usually the decomp community's prepared `psyq_sdk` repo, not one of these Sony discs. The PS2 build won't need it, but the regression check that the PS1 build still matches will. Tell me if you'd like me to set it up.

## User

We looked at this (https://github.com/Xeeynamo/psyz) before for Silent Hill, and I think we concluded that it wouldn’t be that useful because we were already writing something similar for PS2, and psyz doesn’t have PS2 as a target anyways. Is there still anything useful in it?

- tool `Bash`: Find earlier psyz notes and local clones

## Claude

Earlier notes on psyz from the SH1 work are in `PS2 Optimizations.md`. I'll check the current psyz repo against what MGS actually links.

- tool `Bash`: Clone psyz and tally MGS PSY-Q library usage

## Claude

MGS doesn't call libgs at all (no `Gs*` calls), so the biggest psyz lesson from SH1 doesn't apply. Next I'll look at what's changed in psyz.

- tool `Bash`: Read psyz README, porting guide outline, layout

- tool `Bash`: Compare MGS library needs with SH1 HAL and psyz

## Claude

The SH1 compatibility layer already covers most of what MGS uses. I'll look for MGS calls that it doesn't implement.

- tool `Bash`: List PSY-Q functions MGS uses that the SH1 HAL lacks

## Claude

**Short answer:** yes, more for MGS than it was for SH1. You were right not to adopt psyz as the compatibility layer, but MGS uses some PSY-Q libraries that SH1 barely touched, and psyz has decompiled C for most of them.

I compared MGS's PSY-Q calls against the C code in the SH1 layer (`src/port`) and against the current psyz (last commit 2026-10-25). The SH1 port runs some PSY-Q code as recompiled MIPS, so a few of these gaps may already be covered that way. I haven't checked that yet.

## Useful for MGS

1. **Decompiled PSY-Q C (`decomp/src`).** It matches the original binaries, so behaviour should be faithful, which fits your accuracy-first rule. It covers several gaps in the SH1 layer:
   - **libspu** (`SpuMalloc`, the `SpuSetIRQ` family, `SpuSetNoiseVoice`, `SpuSetPitchLFOVoice`, `SpuSetReverbDepth`, `SpuGetAllKeysStatus`). MGS's `sd_*` sound driver goes through libspu, unlike SH1's. psyz has each of these as a small file, so they can be dropped into the SPU2 backend.
   - **libcd callbacks and streaming** (`CdReadyCallback`/`CdSyncCallback`/`CdReadCallback`, `CdGetSector`, `CdRead2`, and the `St*` ring functions). MGS's `libfs` relies on these, so they're the reference for the semantics the layer has to copy.
   - **libpress** (`DecDCTin`/`out`, the callbacks, `DecDCTReset`). These are for MGS's movies. SH1 uses its own `strdec.c`, so expect some API differences.
   - **libgpu helpers** (`MoveImage`, `DrawSyncCallback`, `SetDefDrawEnv`, `GetTPage`, the `SetPoly`/`Sprt`/`SemiTrans` macros): quick wins.
2. **Test assets.** `psyz/tests` has `test_libgte.c` (checked against a real PS1), plus `test_libcd.c`, `test_libspu.c`, `test_mdec.c` and `test_vlc_compat.c` with PSY-Q 4.7 VLC tables. The `ztest` framework also runs on retro consoles, so these tests could run on the EE. Your SH1 notes already planned to reuse the GTE tests.
3. **`psxgen`.** It renders a test program in PCSX-Redux to produce reference framebuffer and VRAM PNGs. It's a cheap way to build the golden images for the GS backend before running MGS's trickier screens (codec, goggles).
4. **The libgte functions (`rsin`/`rcos`, the `RotMatrix*` family, `ReadRotMatrix`).** They're in `psyz/src/psyz/libgte.c`, if the SH1 layer doesn't already have them somewhere I didn't search.

## Not covered by psyz either

- **Threads:** `OpenTh`, `ChangeTh`, `CloseTh` and critical sections. MGS's `mts` task system runs on BIOS threads, and psyz has nothing for it. This needs new work in the compatibility layer, and I've added nothing to the plan for it yet. On the EE it maps naturally onto ps2sdk threads or a small context-switch routine.
- **`DecDCTvlc2` and `DecDCTvlcBuild`.** These are later libpress variants; psyz has `vlc.c` but not these entry points.
- **`LoadImage2`, `MulRotMatrix0`, the `*_gte` variants, `PadInitDirect`, `SetMem` and `SetConf`.** They're small, but each one needs writing.

## Still not useful

The libgs renderer ideas from SH1 don't apply (MGS has its own `libdg`), and neither does the PSP backend as a whole. psyz's licence is worth checking before you copy decomp files in rather than just reading them.

If you want, I can add a "psyz borrowings" list and a thread/`mts` item to Step 0 of the planning doc.

## User

Is there actually something like “psyq_sdk” on GitHub?

- tool `Bash`: Find psyq_sdk setup instructions in the repo

- tool `Bash`: Check the psyq_sdk repo exists

## Claude

Yes. It's **https://github.com/FoxdieTeam/psyq_sdk**, maintained by the same team as `mgs_reversing`, and I confirmed it's live. This repo's own README says to clone it in its build steps ([README.md:2043](README.md#L2043)), and the CI config clones it too (`appveyor.yml:17`).

It contains the PSY-Q 4.4 toolchain (`cc1psx.exe`, `aspsx.exe`, `asmpsx.exe`, the preprocessor) plus the headers and libraries, laid out the way `build.py` expects. `build.py` looks for it in this order:

1. `--psyq_path`, if you pass it
2. the `PSYQ_SDK` environment variable
3. `../../psyq_sdk` relative to `build/`, which is **`/home/alex/Documents/psyq_sdk`**

On Linux it runs those `.exe`s through Wine, and through `wibo` for the assembler steps.

To set it up:

```
git clone https://github.com/FoxdieTeam/psyq_sdk.git /home/alex/Documents/psyq_sdk
```

After that, `cd build && python3 build.py` should rebuild the main executable and print whether it matches. Want me to clone it and run a matching build to confirm that step works?

## User

Yes

- tool `Bash`: Clone psyq_sdk and check build prerequisites

## Claude

I've cloned it. Wine and ninja are installed, but `wibo` isn't, so I'll check how `build.py` gets it.

- tool `Bash`: Check wibo handling and Python deps

## Claude

`wibo` is optional, since `build.py` falls back to Wine. The Python packages are missing, so I'll install them into a virtualenv rather than system Python.

- tool `Bash`: Create venv and install build requirements

- tool `Bash`: Run the matching PS1 build

- tool `Bash`: Check sudo, i386 multiarch, and Wine packages

## Claude

The build is blocked, and fixing it needs root. Installing 32-bit Wine also changes the system, so I'm checking with you first.

## Status

- **`psyq_sdk` is cloned** to `/home/alex/Documents/psyq_sdk`, where `build.py` expects it. It contains the 4.3, 4.4 and 4.5 toolchains.
- **The Python build requirements are installed** in a virtualenv at `/home/alex/.venvs/mgs_reversing`, so system Python is untouched.
- **The build fails at the first compile:** `wine: failed to load ...\syswow64\ntdll.dll`. Debian's Wine is installed as 64-bit only, and `cc1psx.exe` is a 32-bit Windows program. Nothing was compiled, so I haven't checked whether the build matches yet.

## The fix

The standard fix is the one Debian itself suggests. Run it yourself, because `sudo` needs your password:

```
sudo dpkg --add-architecture i386 && sudo apt-get update && sudo apt-get install wine32:i386
```

That adds the i386 architecture system-wide and pulls in roughly a few hundred MB of 32-bit libraries. Your other Wine use stays the same.

**Alternative without root:** `wibo`, a small loader for 32-bit Windows command-line programs that many decomp projects use. I'd download its release binary into `~/.local/bin`. `build.py` already uses it for the assembler and linker when it's found. It doesn't use it for the compiler or preprocessor, though, so those would also need a small change to `build.py` or a shim, which is less standard.

Once you've installed `wine32`, tell me and I'll rerun the build and check the hashes. To run it yourself, the command is `cd build && /home/alex/.venvs/mgs_reversing/bin/python build.py`.

## User

Would psyz work as a drop in replacement here?

## Claude

No, at least not for the build that's failing now. psyz replaces something different from what `psyq_sdk` provides.

**For the matching PS1 build:** the point of that build is to reproduce the original executable byte for byte. That needs the exact toolchain Konami used: the PSY-Q 4.4 `cc1psx.exe` compiler (an old patched GCC), `aspsx`, and the `psylink` linker with its overlay mod. That's what `psyq_sdk` provides. psyz includes no compiler at all. It's a C library you compile your game against with a modern compiler, and the output can never match the original. Its setup does download a PSY-Q SDK, but that's version 4.7, converted for the modern GCC build setup psyz's samples use (nugget). It isn't 4.4, and it isn't the original toolchain. So it wouldn't fix the Wine problem either: the `wine32` install (or `wibo`) is still the way forward.

**For the PS2 port:** this is where a replacement library belongs, but psyz still isn't a drop-in:

- It has no PS2 backend. Its backends are desktop/SDL, web, iOS and PSP, so you'd be writing the whole GS, SPU2 and IOP layer anyway. The SH1 compatibility layer already has all of that.
- It doesn't implement BIOS threads (`OpenTh`/`ChangeTh`), which MGS's `mts` task system depends on.
- It deliberately trades accuracy for compatibility, which is the opposite of the port's "prefer bit-exact" rule.

So the earlier conclusion stands: use the SH1 layer as the base, and borrow from psyz's decompiled libspu, libcd and libpress files and its tests to fill the gaps.

One place psyz could work as a drop-in is a **PC debug build** of MGS on psyz's SDL backend. That would let you check game-code problems (32-bit EE assumptions, uninitialised reads, fixed addresses) natively with a debugger, separately from PS2 hardware problems. It's optional and not on the critical path, but it could be worth adding to the plan as a side tool.

## User

Is there a way to let Claude run sudo temporarily (for just one command)?

## Claude

Not in a clean way. I can't answer a password prompt, and a `sudo` you've already authenticated in your own terminal doesn't carry over. Debian's sudo remembers the login per terminal, and my commands don't run in yours. Your options, best first:

**1. Run it yourself (recommended).** It's one command, so the simplest route is to paste it into VS Code's integrated terminal:

```
sudo dpkg --add-architecture i386 && sudo apt-get update && sudo apt-get install wine32:i386
```

Then tell me it's done and I'll rerun the build.

**2. Temporarily allow sudo without a password, for these commands only, then remove it.** Run `sudo visudo -f /etc/sudoers.d/claude-temp` and add:

```
alex ALL=(root) NOPASSWD: /usr/bin/dpkg --add-architecture i386, /usr/bin/apt-get update, /usr/bin/apt-get install wine32\:i386
```

I'd run those exact commands, and then you'd delete it with `sudo rm /etc/sudoers.d/claude-temp`. This works, but it isn't worth it for a one-off, and it's easy to forget to remove. Any `apt-get install` rule effectively grants root, because packages run install scripts as root, so keep it this narrow and short-lived.

**Avoid:** piping your password into `sudo -S`. It would end up in this conversation's transcript and your shell history.

## User

Ok, let’s just try wibo first

- tool `Bash`: Look up the latest wibo release assets

- tool `Bash`: Install wibo and smoke-test it with cc1psx

- tool `Bash`: Run the matching build with wibo standing in for wine

## Claude

Everything compiled and most of it linked. The one failure is a step that runs `wine cmd /c "...cpe2exe.exe ... > NUL"`, which needs Windows' `cmd` shell. I'll teach the shim to unwrap that.

- tool `Bash`: Handle cmd /c in the shim and rerun the build

- tool `Bash`: Count matches, check failures, VR variant, git status

- tool `Write`: /home/alex/.claude/projects/-home-alex-Documents-mgs1-ps2/memory/matching-build-setup.md

- tool `Bash`: Add memory index entry

## Claude

wibo worked, and you don't need sudo. The matching build now passes: all 80 outputs match their target hashes. That covers the main executable `_mgsi.exe` (`SLPM_862.47`/`.48`) and every overlay, and the VR executable (`--variant=vr_exe`) matches too. The PS2 port now has its regression check.

**What I set up (nothing in the repo changed):**
- **wibo 1.2.0** is at `~/.local/bin/wibo`. It runs the 32-bit PSY-Q tools without 32-bit Wine.
- **A `wine` shim** is at `~/.local/share/wibo-as-wine/wine`. `build.py` hardcodes `wine` for the compiler and for one step that runs `cpe2exe` through Windows' `cmd`, so the shim sends those calls to wibo instead. It only takes effect when that directory is put first on `PATH`, so your real Wine is untouched.
- **The Python requirements** are in the virtualenv at `/home/alex/.venvs/mgs_reversing`.

The command, run from `build/`:

```
PATH=/home/alex/.local/share/wibo-as-wine:$PATH /home/alex/.venvs/mgs_reversing/bin/python build.py
```

I saved it to memory so later sessions can rerun it.

The only uncommitted change in the repo is the new `docs/` folder.

## User

Copy over the agents.md from the Silent Hill port and remind me what’s in it

- tool `Bash`: Locate agents.md in the SH1 port

- tool `Bash`: Search wider for agent instruction files

- tool `Bash`: Read SH1 memory index and agent_ps2.c header

## Claude

I couldn't find an `agents.md` in the Silent Hill port: there's no `AGENTS.md` or `CLAUDE.md` anywhere in it, and none in its git history. So nothing was copied. Two things might be what you're thinking of.

**1. My saved memory notes from the SH1 sessions** (the most likely match). These are the working rules and lessons I kept for that project:

- **Testing in emulators:**
  - PCSX2 test runs use its software renderer.
  - 15 emulated seconds without a new frame means a crash, so close PCSX2.
  - A TLB miss in PCSX2 means the code would crash a real PS2, even though PCSX2 tolerates the bad read.
  - DuckStation runs on its software renderer, muted, without per-frame gdb stops.
  - Check the GS renderer's output against DuckStation's, not against the port's own software renderer.
  - A cutscene test run stops after 30 emulated seconds of uninterrupted gameplay.
- **Real hardware:**
  - When the PS2 is stuck, RESET doesn't bring Neutrino back. You have to hold the power button, then restart Neutrino from uLaunchELF.
  - EE hardware data breakpoints never fire under Neutrino.
- **How you like me to work:**
  - Send you a push notification at questions and when a step is finished.
  - Never fetch The Cutting Room Floor (tcrf.net); ask you to paste the information instead.
  - Don't kill processes with a `pkill -f` pattern, because it can match and kill its own shell.
  - Keep `Claude Conversation.md` updated with the archive script.
- **SH1-specific:** build environment variables, "Docks" = `map6_s00`, which DuckStation save file is which, and the sound plan.

**2. `src/port/ps2/agent_ps2.c` plus `sh1agent.irx`:** the remote-control "agent" for hardware testing, which is code, not a document. The VM sends it UDP commands through `ps2_ctl.py`:
- `RS` restarts the game; `OS` exits to the PS2 browser.
- `MD` prints memory to the log; `PI` pings.
- `WH` shows where a hung main loop is stuck; `NG` starts a New Game.

It runs on a high-priority thread, so it still answers when the game is stuck. It's worth carrying over once MGS boots on the PS2.

If you meant the notes, I can copy the ones that apply beyond SH1 (the emulator, hardware and working-style rules) into this project's memory. I could also write them up as an `AGENTS.md` in the repo, if you want a file other tools can read too. Which would you prefer?

## User

Copy the notes that apply beyond Silent Hill and write them up as CLAUDE.md

- tool `Bash`: Read the SH1 memory notes to carry over

- tool `Bash`: Print memory note bodies without frontmatter

- tool `Write`: /home/alex/Documents/mgs1_ps2/CLAUDE.md

## Claude

The build command is now in `CLAUDE.md`, so the memory note I saved earlier duplicates it. I'll remove that note.

- tool `Bash`: Remove memory now covered by CLAUDE.md

## Claude

I've written [CLAUDE.md](CLAUDE.md) at the repo root with the Silent Hill notes that apply beyond that game:

- **Working with you:**
  - Send you a push notification at questions and when a step is finished.
  - Never access tcrf.net; ask you to paste the section instead.
  - Before trying a debugging technique, check the docs for what's already been tried.
- **Shell:** never use `pkill -f` with a pattern; use TaskStop or kill by process ID instead.
- **Emulators:**
  - PCSX2 runs on its software renderer.
  - 15 emulated seconds with no new frame counts as a crash.
  - Never dismiss PCSX2 "TLB Miss" lines, since they crash a real PS2.
  - DuckStation is the reference: software renderer, muted, few gdb stops.
  - Compare the GS renderer against DuckStation.
- **Real hardware:**
  - A hung PS2 needs a power cycle and a Neutrino restart; RESET doesn't work.
  - EE hardware data breakpoints never fire under Neutrino.

I also put the matching-build command at the top so every session has the regression check. Since it's now in `CLAUDE.md`, I deleted the separate memory note I'd saved for it.

I left out the notes that only apply to Silent Hill:
- the cutscene-run cutoff
- the "Docks" shorthand
- the SH1 save files, build variables and sound plan
- the `Claude Conversation.md` archiving rule, because its script doesn't exist in this repo yet. Say if you want it set up here too.

`CLAUDE.md` and `docs/` are new, uncommitted files in the repo.

## User

To add to the TCRF rule, only access GitHub without asking me. For all other sites, ask me first. Also, let’s have the Claude conversation log in this project too.

- tool `Bash`: Inspect SH1 archive script and this project's sessions

- tool `Bash`: Copy archive script and generate the conversation log

- tool `Edit`: /home/alex/Documents/mgs1_ps2/CLAUDE.md

## Claude

I've made both changes.

**Web access rule:** [CLAUDE.md](CLAUDE.md) now says that GitHub (the site, its API, and raw and release downloads) is fine without asking, and that I ask you before fetching from any other site. TCRF stays fully off-limits, even if you approve or ask for it, and I'll ask you to paste the section instead.

**Conversation log:** I copied the Silent Hill archive script to [tools/port/archive_conversation.py](tools/port/archive_conversation.py), changing only its title line. I then generated [Claude Conversation.md](Claude Conversation.md) from this session: 446 lines, starting with your first question. It covers the conversation up to just before this turn, and the next refresh will pick up the rest. `CLAUDE.md` has the refresh steps, including the SH1 lesson: always rebuild from all sessions combined, not just the newest, or earlier history gets dropped. I'll refresh it at milestones and before commits.

New, uncommitted files: `CLAUDE.md`, `Claude Conversation.md`, `docs/` and `tools/port/`.

## User

How can the executables be made to match their target hashes when the decomp isn’t finished yet?

- tool `Bash`: Check how INCLUDE_ASM and the uninitializer work

## Claude

The build doesn't need every function to be in C to match. Code that hasn't been decompiled yet is pasted in as the original machine code. Two mechanisms make the bytes come out identical.

**1. `INCLUDE_ASM`: the unfinished functions are still the original assembly**

The main executables are 100% C, so they match purely from source. The overlays still have about 740 functions that nobody has rewritten in C yet. Each one is a line like this, from [hindbody.c:980](source/overlays/s11g/kojo/hindbody.c#L980):

```c
#pragma INCLUDE_ASM("asm/overlays/s11g/s11g_hind_800D6848.s")
```

That `.s` file is the function disassembled from the original disc. Before compiling, [include_asm_preprocess.py](build/include_asm_preprocess.py) swaps the pragma for a dummy C function containing the original instructions. The PSY-Q assembler then turns those back into exactly the bytes they came from. The function sits at the right place and size, so everything after it lines up too. This is the standard decomp technique: at any moment the build is part C and part original assembly, and the matching check confirms that the C parts are exact.

**2. The uninitializer: the original memory leftovers are copied back in**

Some bytes in the original files never came from any code. They're uninitialized memory and padding that the original build tools wrote out with whatever happened to be in RAM. No source can reproduce those bytes. So each overlay is linked twice: once with that memory filled with `0x00`, and once with it filled with `0x9E`. Bytes that differ between the two builds must be uninitialized, and [uninitializer.py](build/uninitializer.py) fills them from templates taken from the original discs (`um/stage/*.bin`). That's the "Link (uninitialized)" step you saw in the build output.

**What this means for the port**

A matching hash proves the C is equivalent to the original, not that the game exists entirely as C. On the PS2, `INCLUDE_ASM` functions are a dead end. Their instructions are PS1 MIPS and could be assembled for the EE. But they jump to fixed PS1 addresses, call the PS1 libraries by address and assume the PS1's memory layout, so they won't run as-is. That's why the plan leaves an overlay out of the port until it has no stubs left. The uninitialized bytes don't matter on the PS2: the port just zeroes that memory, unless some game code turns out to read the garbage, which is worth watching for.

## User

It sounds like the MGS1 decomp is not as complete as the Silent Hill one. Given that, how worth it would it be to go through and attempt to decompile the remaining functions?

## Claude

I'll measure the remaining work and how fast upstream is closing it before giving an answer.

- tool `Bash`: Size remaining asm by overlay and upstream activity

- tool `Bash`: Recount asm instructions with the right format

- tool `Bash`: Check what the SH1 recompiler does

## Claude

**Short answer:** not as a separate project before the port. A few targeted pieces are worth doing, and the SH1 recompiler is probably a cheaper way to cover most of the gap.

## How big the gap is

- The **main executables are 100% C**. That's the engine and everything the port needs to boot.
- The ~740 unfinished functions are spread over **12 of the overlays**. They add up to roughly **100,000 instructions**, which is very roughly two-thirds the size of the main executable. The largest are `brf` (21k, the briefing screen), `s07b` (14k), `rank` (12k, the ranking screen), `s08b` (11k), and `camera`, `d18a` and `s19b` (~7k each).
- Judging by names like `psyco`, `ninja` and `hind`, a lot of it looks like boss-fight code and extras screens, not core stages.
- **Upstream is active.** Over the last three months there were about 120 commits to the overlays (for example "Match 10 rank functions" and "Finish zako14com.c"), so the gap is shrinking without you.

Matching 100k instructions by hand is months of work. The port can start long before that.

## Cheaper alternatives for the port

1. **Recompile the stubs.** The SH1 port's `tools/port/recomp.py` already turns PS1 MIPS into C for the EE, keeping delay slots, HI/LO and GTE semantics, and it handled all of libgs. One catch: it reads ELF objects with relocation info. MGS's stub files are raw `dw` words with absolute addresses already baked in. So you'd first need a step that rebuilds the relocations from the overlay's symbol addresses. That's probably a few days of tooling, against months of decomp.
2. **Port the finished stages first** and leave the 12 stub-heavy overlays out until upstream or the recompiler covers them, as the plan already says.
3. **For the port, the C doesn't have to match.** C that only behaves the same is much faster to write than a byte-exact match. The trade-off is that nothing proves it's right. You'd test it by playing the stage and comparing with DuckStation, instead of getting the hash check.

## When decompiling yourself is worth it

- A stub overlay needs **port-specific changes**, such as fixed addresses, graphics tricks or timing. Changing recompiled code is painful, so real C is better there.
- **The recompiler can't handle a function.** It errors out on cases it doesn't understand, such as unknown jump targets, rather than guessing.
- **You want to contribute upstream.** Then the code has to match. Check mgs_reversing's policy on AI-written code first: the SH1 upstream explicitly keeps AI-generated code out of its decomp.

**My recommendation:** keep going with the plan (shared compatibility layer, PS2 build, finished stages first). Then try the recompiler on one small stub overlay, e.g. `s11g` (Hind) or `s03d`. Only decompile by hand where that fails or where you need to change the code. Want me to add this as a step in the planning doc?

## User

Remind me what’s in the planning doc

## Claude

[docs/Planning Doc.md](docs/Planning Doc.md) currently has these sections:

**Strategy and ground rules**
- Compile the decomp's C for the PS2's main processor (the EE) with ps2sdk. Replace PSY-Q with the compatibility layer from the SH1 port.
- The matching PS1 build must keep matching. Port changes go behind `MGS_PORT`.
- One compatibility layer shared by both games.
- 32-bit pointers on the EE keep the original structs valid.
- Prefer bit-exact over fast: use the software GTE first.

**Reference material:** where the PSY-Q 4.1 PDFs and SDK archives are.

**Current state** (as of 2026-10-27)
- The main executables are 100% decompiled.
- About 747 `INCLUDE_ASM` stubs remain, in 12 overlays.
- The build uses the original PSY-Q 4.4 tools.
- Counts of PS1-specific code: `gte_*` in 30 files, scratchpad addresses in 8, `0x80…` literals in 156.

**Steps**
0. **Share the compatibility layer:** move it somewhere common, remove what's specific to SH1, and check the SH1 port still builds.
1. **PS2 build target:** a separate EE GCC build and a header shim. Compile the core libraries and boot to `main()` with the overlays stubbed out.
2. **Fixed addresses:** sort the 156 files of address literals, add a `psx_mem.h`-style abstraction, add a regression script, and do a shift test.
3. **Static linking of overlays:** a loader hook and dispatch table, renaming symbols that clash, and a first playable route (dock, then heliport). Overlays with stubs are left out.
4. **Software GTE:** reuse SH1's, and compare results against PS1 captures.
5. **Graphics:** send `libdg` through the GS backend, and check MGS-specific effects (codec, goggles, menus).
6. **Pad, CD, memory card**
7. **Sound:** the `sd_*` driver on the SPU2, plus the XA and STR code from SH1.

**Open questions**
- Target the Integral discs or the VR disc first?
- Keep the PS1's memory and video-memory limits, or raise them?

**Not in the doc yet**, from what we've discussed since:
- Which psyz pieces to borrow: its libspu, libcd and libpress code and its tests.
- The thread support MGS's `mts` task system needs (`OpenTh`/`ChangeTh`).
- Using the SH1 recompiler for the unfinished functions, rather than decompiling them by hand.
- A possible PC debug build on psyz.
- The working matching-build command (it's in `CLAUDE.md`, not the plan).

Want me to add those?

## User

Open questions:
1. Let’s target the Integral discs first. 
2. For now, we’ll keep the PS1 limits. 
Add the “not in the doc yet items” to the planning doc. Then, commit our initial docs as “initial setup” or something like that. Due to my usage of AI coding, I won’t be contributing to upstream for now.

- tool `Read`: /home/alex/Documents/mgs1_ps2/docs/Planning Doc.md

- tool `Bash`: Add decisions and new items to the planning doc

- tool `Write`: /home/alex/.claude/projects/-home-alex-Documents-mgs1-ps2/memory/no-upstream-contributions.md

- tool `Bash`: Index memory and check remotes and branches

