extern char R_GM_GameStatus[] __asm__("GM_GameStatus");
extern char R_s14e_800C8748[] __asm__("s14e_800C8748");
extern char R_GM_ConfigMotionAdjust[] __asm__("GM_ConfigMotionAdjust");
int G_s14e_800C6DB0(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s14e_800C6DB0");
int G_s14e_800C6DB0(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[2] = 0;
    r[2] = *(int *)((u)r[2] + (int)R_GM_GameStatus);
    r[29] = (u)r[29] + -24;
    r[2] = r[2] & 2;
    c = ((r[2] != 0)); *(int *)((u)r[29] + 16) = r[31]; if (c) goto L800c6dd0;
    r[2] = (u)0 + (u)0; goto L800c6df8;
    L800c6dd0:;
    r[2] = 0;
    r[2] = (u)r[2] + (int)R_s14e_800C8748;
    *(int *)((u)r[4] + 2284) = r[2];
    *(int *)((u)r[4] + 2292) = 0;
    *(short *)((u)r[4] + 112) = 0;
    *(short *)((u)r[4] + 108) = 0;
    r[4] = (u)r[4] + 156;
    r[5] = (u)0 + (u)0; CALL(R_GM_ConfigMotionAdjust);
    r[2] = (u)0 + 1;
    L800c6df8:;
    r[31] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
