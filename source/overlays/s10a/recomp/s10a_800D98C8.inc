extern char R_GM_GameOverTimer[] __asm__("GM_GameOverTimer");
extern char R_GM_SetSong[] __asm__("GM_SetSong");
int G_s10a_800D98C8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s10a_800D98C8");
int G_s10a_800D98C8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[31];
    r[2] = *(int *)((u)r[4] + 2572);
    c = ((r[2] != 0));  if (c) goto L800d990c;
    r[2] = *(int *)((u)r[4] + 2664);
    c = ((r[2] != 0)); r[2] = 0; if (c) goto L800d990c;
    r[3] = *(int *)((u)r[2] + (int)R_GM_GameOverTimer);
    r[2] = (u)0 + 1;
    c = ((r[3] != 0)); *(int *)((u)r[4] + 2572) = r[2]; if (c) goto L800d990c;
    r[4] = 0x1000000;
    r[4] = r[4] | 2; CALL(R_GM_SetSong);
    L800d990c:;
    r[31] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
