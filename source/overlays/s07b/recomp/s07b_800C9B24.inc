extern char R_GM_GameOverTimer[] __asm__("GM_GameOverTimer");
extern char R_linkvarbuf[] __asm__("linkvarbuf");
extern char R_s07b_800C8F9C[] __asm__("s07b_800C8F9C");
extern char R_s07b_800C54C0[] __asm__("s07b_800C54C0");
int G_s07b_800C9B24(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s07b_800C9B24");
int G_s07b_800C9B24(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(24)
    r[2] = 0;
    r[2] = *(short *)((u)r[2] + ((int)R_linkvarbuf + 22));
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    c = ((r[2] == 0)); *(int *)((u)r[29] + 20) = r[31]; if (c) goto L800c9b84;
    r[2] = 0;
    r[2] = *(int *)((u)r[2] + (int)R_GM_GameOverTimer);
    c = ((r[2] != 0));  if (c) goto L800c9b84;
    c = ((r[5] != 0));  if (c) goto L800c9b84;
    r[5] = (u)0 + (u)0; CALL(R_s07b_800C54C0);
    r[2] = 0;
    r[2] = (u)r[2] + (int)R_s07b_800C8F9C;
    *(int *)((u)r[16] + 2132) = r[2];
    *(int *)((u)r[16] + 2144) = 0;
    *(short *)((u)r[16] + 2246) = 0;
    *(short *)((u)r[16] + 2244) = 0;
    *(short *)((u)r[16] + 112) = 0;
    *(short *)((u)r[16] + 108) = 0;
    L800c9b84:;
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
