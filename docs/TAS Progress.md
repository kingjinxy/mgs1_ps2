# TAS progress

TASVideos #5139 replayed in the port. The movie is about 313,200 frames, 1:27:05 at 59.94 frames a second. Percentages
are by movie frame. Each row is the point reached once that fix was in. Update this at each new milestone.

Current: loop 17,560 (0:09:35.51), 11.01%.

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

The 12,652 and 12,758 rows share one commit time; those stopping points come from run notes.
