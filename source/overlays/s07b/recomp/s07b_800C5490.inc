extern char R_GM_GameOverTimer[] __asm__("GM_GameOverTimer");
extern char R_linkvarbuf[] __asm__("linkvarbuf");
int G_s07b_800C5490(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s07b_800C5490");
int G_s07b_800C5490(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(0)
    r[3] = 0;
    r[2] = *(int *)((u)r[3] + (int)R_GM_GameOverTimer);
    c = ((r[2] != 0)); r[2] = 0; if (c) goto L800c54b8;
    r[2] = *(short *)((u)r[2] + ((int)R_linkvarbuf + 22));
    c = ((r[2] == 0)); r[2] = (u)0 + -2; if (c) goto L800c54b8;
    *(int *)((u)r[3] + (int)R_GM_GameOverTimer) = r[2];
    L800c54b8:;
     goto out;
out:
    return r[2];
}
