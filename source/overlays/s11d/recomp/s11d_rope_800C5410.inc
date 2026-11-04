extern char R_GM_PlayerAction[] __asm__("GM_PlayerAction");
extern char R_GM_PlayerPosition[] __asm__("GM_PlayerPosition");
extern char R_dword_800AB9D4[] __asm__("dword_800AB9D4");
extern char R_s11d_dword_800D1D64[] __asm__("s11d_dword_800D1D64");
extern char R_GM_SeSetMode[] __asm__("GM_SeSetMode");
int G_s11d_rope_800C5410(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s11d_rope_800C5410");
int G_s11d_rope_800C5410(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    r[2] = 0;
    r[3] = 0;
    r[2] = *(int *)((u)r[2] + (int)R_GM_PlayerAction);
    r[4] = *(int *)((u)r[3] + (int)R_dword_800AB9D4);
    r[5] = (u)0 + (u)0;
    r[6] = (u)r[2] + -2;
    r[2] = (u)r[6] < (u)16;
    c = ((r[2] == 0)); *(int *)((u)r[29] + 16) = r[31]; if (c) goto L800c54a8;
    r[2] = 0;
    r[2] = (u)r[2] + (int)R_s11d_dword_800D1D64;
    r[3] = (u)r[6] << 2;
    r[3] = (u)r[3] + (u)r[2];
    r[2] = *(int *)((u)r[3] + 0);
    t = r[2];  switch ((u)t) { case 0x800c5458: goto L800c5458; case 0x800c5478: goto L800c5478; case 0x800c548c: goto L800c548c; case 0x800c54a8: goto L800c54a8; default: goto out; }
    L800c5458:;
    r[2] = (u)0 + 9;
    c = ((r[4] != r[2])); r[2] = (u)0 + 17; if (c) goto L800c5468;
    r[5] = (u)0 + 2;
    L800c5468:;
    c = ((r[4] != r[2]));  if (c) goto L800c54a8;
    r[5] = (u)0 + 3; goto L800c54a8;
    L800c5478:;
    r[2] = (u)0 + 8;
    c = ((r[4] != r[2])); r[2] = (u)0 + 16; if (c) goto L800c549c;
    r[5] = (u)0 + 3; goto L800c549c;
    L800c548c:;
    r[2] = (u)0 + 14;
    c = ((r[4] != r[2])); r[2] = (u)0 + 27; if (c) goto L800c549c;
    r[5] = (u)0 + 3;
    L800c549c:;
    c = ((r[4] != r[2]));  if (c) goto L800c54a8;
    r[5] = (u)0 + 2;
    L800c54a8:;
    c = ((r[5] == 0)); r[4] = 0; if (c) goto L800c54bc;
    r[4] = (u)r[4] + (int)R_GM_PlayerPosition;
    r[6] = (u)0 + 1; CALL(R_GM_SeSetMode);
    L800c54bc:;
    r[31] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
