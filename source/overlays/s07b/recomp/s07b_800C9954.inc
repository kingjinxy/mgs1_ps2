extern char R_GM_GameOverTimer[] __asm__("GM_GameOverTimer");
extern char R_linkvarbuf[] __asm__("linkvarbuf");
extern char R_s07b_800C4B58[] __asm__("s07b_800C4B58");
int G_s07b_800C9954(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s07b_800C9954");
int G_s07b_800C9954(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[2] = 0;
    r[2] = *(short *)((u)r[2] + ((int)R_linkvarbuf + 22));
    r[29] = (u)r[29] + -24;
    c = ((r[2] == 0)); *(int *)((u)r[29] + 16) = r[31]; if (c) goto L800c9984;
    r[2] = 0;
    r[2] = *(int *)((u)r[2] + (int)R_GM_GameOverTimer);
    c = ((r[2] != 0));  if (c) goto L800c9984;
     CALL(R_s07b_800C4B58);
    L800c9984:;
    r[31] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
