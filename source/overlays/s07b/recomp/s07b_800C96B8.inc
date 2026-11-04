extern char R_GM_GameStatus[] __asm__("GM_GameStatus");
extern char R_s07b_800C77A8[] __asm__("s07b_800C77A8");
extern char R_s07b_800C473C[] __asm__("s07b_800C473C");
extern char R_s07b_800C54C0[] __asm__("s07b_800C54C0");
extern char R_s07b_800C5554[] __asm__("s07b_800C5554");
int G_s07b_800C96B8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s07b_800C96B8");
int G_s07b_800C96B8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[16];
    *(int *)((u)r[29] + 20) = r[31];
    r[16] = (u)r[4] + (u)0; CALL(R_s07b_800C473C);
    c = ((r[2] == 0)); r[4] = 0; if (c) goto L800c9728;
    r[2] = *(int *)((u)r[4] + (int)R_GM_GameStatus);
    r[3] = 0x10000000;
    r[2] = r[2] | r[3];
    r[3] = *(short *)((u)r[16] + 170);
    *(int *)((u)r[4] + (int)R_GM_GameStatus) = r[2];
    r[2] = (u)0 + 24;
    c = ((r[3] != r[2])); r[4] = (u)r[16] + (u)0; if (c) goto L800c9728;
    r[5] = (u)0 + (u)0; CALL(R_s07b_800C54C0);
    r[4] = *(int *)((u)r[16] + 2012);
     CALL(R_s07b_800C5554);
    r[2] = 0;
    r[2] = (u)r[2] + (int)R_s07b_800C77A8;
    *(int *)((u)r[16] + 2132) = r[2];
    *(int *)((u)r[16] + 2144) = 0;
    *(short *)((u)r[16] + 2246) = 0;
    *(short *)((u)r[16] + 2244) = 0;
    *(short *)((u)r[16] + 112) = 0;
    *(short *)((u)r[16] + 108) = 0;
    L800c9728:;
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
