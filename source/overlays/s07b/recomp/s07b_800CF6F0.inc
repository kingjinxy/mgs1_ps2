extern char R_GM_GameOverTimer[] __asm__("GM_GameOverTimer");
extern char R_GM_GameStatus[] __asm__("GM_GameStatus");
extern char R_linkvarbuf[] __asm__("linkvarbuf");
extern char R_s07b_800CC138[] __asm__("s07b_800CC138");
int G_s07b_800CF6F0(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s07b_800CF6F0");
int G_s07b_800CF6F0(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[31];
    c = ((r[5] != 0)); r[6] = (u)r[4] + (u)0; if (c) goto L800cf714;
    r[2] = 0;
    r[3] = *(int *)((u)r[2] + (int)R_GM_GameStatus);
    r[4] = 0x10000000;
    r[3] = r[3] | r[4];
    *(int *)((u)r[2] + (int)R_GM_GameStatus) = r[3];
    L800cf714:;
    r[2] = (u)0 + 48;
    c = ((r[5] != r[2])); r[2] = 0; if (c) goto L800cf758;
    r[2] = *(short *)((u)r[2] + ((int)R_linkvarbuf + 22));
    c = ((r[2] == 0)); r[2] = 0; if (c) goto L800cf758;
    r[2] = *(int *)((u)r[2] + (int)R_GM_GameOverTimer);
    c = ((r[2] != 0)); r[3] = (u)0 + -17; if (c) goto L800cf758;
    r[4] = (u)r[6] + (u)0;
    r[2] = *(int *)((u)r[6] + 2124);
    r[5] = (u)0 + -1;
    r[2] = r[2] & r[3];
    *(int *)((u)r[6] + 2124) = r[2]; CALL(R_s07b_800CC138);
    L800cf758:;
    r[31] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
