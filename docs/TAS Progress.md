# TAS progress

TASVideos #5139 replayed in the port. The movie is about 313,200 frames, 1:27:05 at 59.94 frames a second. Percentages
are by movie frame. Each row is the point reached once that fix was in. Update this at each new milestone.

Current: loop 59,444 (0:31:17.28), 35.93%.

| In sync to loop | Movie time | % | What fixed it | Commit (2026) |
|---|---:|---:|---|---|
| 4,221 | 0:02:35.57 | 2.98% | `camera.c` out-of-bounds read | Oct 30, 15:53 |
| 5,109 | 0:03:05.34 | 3.55% | `sna_line_check` stack pair | Oct 30, 19:30 |
| 5,750 | 0:03:21.50 | 3.86% | Pad release from raw pads | Oct 30, 19:53 |
| 5,808 | 0:03:24.35 | 3.91% | Stream tick -1 after sound mode | Oct 30, 20:05 |
| 6,276 | 0:03:37.53 | 4.16% | File reads at the PS1 drive's pace | Oct 31, 10:09 |
| 6,662 | 0:03:52.07 | 4.44% | Drive model fitted to the PS1 | Oct 31, 10:57 |
| 6,732 | 0:03:55.00 | 4.50% | Stream data per vertical blank; crashed after this | Oct 31, 11:43 |
| 7,596 | 0:04:21.11 | 5.00% | `lit_mdl.c` model initializer that GCC dropped | Oct 31, 12:06 |
| 11,443 | 0:06:19.66 | 7.27% | File reads follow the PS1's recorded progress | Oct 31, 13:22 |
| 12,101 | 0:06:42.09 | 7.69% | `s03d` guards decompiled; `chafgrnd.c` NULL rect | Oct 31, 15:21 |
| 12,652 | 0:07:00.75 | 8.05% | Stream actor ends on the PS1's loop | Oct 31, 17:24 |
| 12,758 | 0:07:05.19 | 8.14% | Guards' model names and `ZakoComMgr` layout | Oct 31, 17:24 |
| 13,005 | 0:07:13.52 | 8.30% | Guard action table layout, lip sync on the PS1's counter | Nov 2, 09:17 |
| 13,014 | 0:07:13.82 | 8.30% | Disc timeline with exact sound counter | Nov 2, 10:17 |
| 14,030 | 0:07:50.07 | 9.00% | Stream play end from the timeline | Nov 2, 12:51 |
| 15,061 | 0:08:18.40 | 9.54% | Trace clock sampling corrected (harness fix) | Nov 2 |
| 15,114 | 0:08:20.18 | 9.57% | NULL guard read in `zakocom.c`; button press lost under `STATE_PADRELEASE` in `pads.bin` | Nov 2 |
| 17,042 | 0:09:20.38 | 10.72% | play time from the recording each loop | Nov 2 |
| 17,560 | 0:09:35.51 | 11.01% | jimctrl.c ends with the sound on the PS1's loops, from the timeline | Nov 2 |
| 18,261 | 0:09:55.34 | 11.39% | movies skipped in the port, ending on the PS1's loop in TAS replays | Nov 2 |
| 20,842 | 0:11:11.65 | 12.85% | the codec's signal bar draws follow the PS1's seed in TAS replays | Nov 2 |
| 20,980 | 0:11:16.64 | 12.95% | `s05a` linked in: pointer tables and stage table by symbol | Nov 2 |
| 21,126 | 0:11:21.60 | 13.04% | seed resynced at loop 20,980 (shortcut: 5 PS1 draws after the `s05a` reload, source not found) | Nov 2 |
| 22,669 | 0:12:12.48 | 14.02% | the tank tread reads the PS1 stale stack value (M1E1StaleVy) | Nov 2 |
| 23,572 | 0:12:39.38 | 14.53% | NULL read in m1e1sold.c, and a release lost on a two-update loop | Nov 2 |
| 24,704 | 0:13:15.64 | 15.23% | `s07a` linked in (7 pointers by symbol) | Nov 2 |
| 27,191 | 0:14:34.37 | 16.73% | the codec static follows the PS1 seed; NULL read at 0xE5C | Nov 2 |
| 27,232 | 0:14:35.77 | 16.76% | `s08b` translated by mips2c.py and running (jump tables, entry points) | Nov 2 |
| 29,057 | 0:15:36.67 | 17.93% | lip sync holds the counter on a loop the PS1's field_30 held | Nov 2 |
| 35,095 | 0:18:39.13 | 21.42% | the lip sync hold never goes past the counter (a new stream reused the old one's) | Nov 2 |
| 37,813 | 0:20:00.70 | 22.98% | the gun cameras' check phase: overlay `.data`/`.bss` reset on a stage load (`s08a` revisit) | Nov 3 |
| 38,579 | 0:20:26.61 | 23.47% | `s07b` (Psycho Mantis) linked in: 157 stubs through mips2c.py, stage table and state table by symbol; the boss life bar now drawn | Nov 3 |
| 39,732 | 0:21:06.15 | 24.23% | mips2c.py forgets a register's lui at a call (Meryl's turn of Snake read GV_VecDir2() + 0x800 as an address) | Nov 3 |
| 45,078 | 0:23:58.70 | 27.53% | overlay statics read by translated code by name: `chair_alive` etc. were `dword_800C3404`+124 (Psycho Mantis through) | Nov 3 |
| 47,499 | 0:25:21.89 | 29.13% | `s10a` (not split by the decomp) linked in through the new stage_split.py and mips2c.py, with GTE instructions | Nov 3 |
| 47,546 | 0:25:23.46 | 29.16% | loop 47,499 (Wolf's tick burn read mid-loop: trace_to_pads.py's TICK_AT, 90,359 at loop 47,488) | Nov 3 |
| 47,556 | 0:25:23.79 | 29.16% | loop 47,546 (translated calls passed 8 arguments: NewBulletEx's 9th, speed, was garbage; CALL passes 12) | Nov 3 |
| 56,569 | 0:29:45.27 | 34.17% | loop 47,556 (HZD floors tagged with the EE's uncached mirror instead of bit 31: HZD_IS_WALL/HZD_TAG_FLOOR/HZD_UNTAG_FLOOR in libhzd.h) | Nov 3 |
| 57,290 | 0:30:06.47 | 34.57% | the load-end loop has the PS1's number when the stage script runs (s09a's dogs take turns by `GV_Time % 3`) | Nov 4 |
| 59,444 | 0:31:17.28 | 35.93% | Wolf's s10a creation burn reads the tick 2 blanks before the line's (`TICK_AT` 57,275); NULL pad pointer in `sub_8004EB74` | Nov 4 |

The 12,652 and 12,758 rows share one commit time; those stopping points come from run notes.

Nov 3: the post-load deadlock (hit at 6,668, 11,520, 24,537, 26,136, 27,185) fixed in the HAL's thread layer; the code padding shortcut is removed. Still in sync to 35,095 (0:18:39.13, 21.42%).
Nov 3, later: in sync to 45,078 (0:23:58.70, 27.53%), through Psycho Mantis. The next stage, `s10a`, isn't split
by the decomp; the replay waits on a splitter (TAS plan).
