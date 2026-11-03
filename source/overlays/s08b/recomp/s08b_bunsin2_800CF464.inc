extern char R_GM_GameStatus[] __asm__("GM_GameStatus");
extern char R_s08b_dword_800E3978[] __asm__("s08b_dword_800E3978");
int G_s08b_bunsin2_800CF464(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s08b_bunsin2_800CF464");
int G_s08b_bunsin2_800CF464(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(0)
    r[2] = *(int *)((u)r[4] + 6708);
    c = ((r[2] == 0)); r[3] = (u)r[2] + -1; if (c) goto L800cf504;
    r[2] = (u)r[3] < (u)6;
    c = ((r[2] == 0)); r[2] = 0; if (c) goto L800cf4fc;
    r[2] = (u)r[2] + (int)R_s08b_dword_800E3978;
    r[3] = (u)r[3] << 2;
    r[3] = (u)r[3] + (u)r[2];
    r[2] = *(int *)((u)r[3] + 0);
    t = r[2];  switch ((u)t) { case 0x800cf49c: goto L800cf49c; case 0x800cf4b4: goto L800cf4b4; case 0x800cf4cc: goto L800cf4cc; case 0x800cf4e4: goto L800cf4e4; case 0x800cf4fc: goto L800cf4fc; default: goto out; }
    L800cf49c:;
    r[2] = (u)0 + 4;
    *(int *)((u)r[4] + 6600) = r[2];
    r[2] = (u)0 + 10;
    *(int *)((u)r[4] + 6604) = r[2];
    r[2] = (u)0 + 2; goto L800cf4f8;
    L800cf4b4:;
    r[2] = (u)0 + 7;
    *(int *)((u)r[4] + 6600) = r[2];
    r[2] = (u)0 + 23;
    *(int *)((u)r[4] + 6604) = r[2];
    r[2] = (u)0 + 1; goto L800cf4f8;
    L800cf4cc:;
    r[2] = (u)0 + 7;
    *(int *)((u)r[4] + 6600) = r[2];
    r[2] = (u)0 + 23;
    *(int *)((u)r[4] + 6604) = r[2];
    r[2] = (u)0 + 3; goto L800cf4f8;
    L800cf4e4:;
    r[2] = (u)0 + 7;
    *(int *)((u)r[4] + 6600) = r[2];
    r[2] = (u)0 + 34;
    *(int *)((u)r[4] + 6604) = r[2];
    r[2] = (u)0 + 6;
    L800cf4f8:;
    *(int *)((u)r[4] + 6712) = r[2];
    L800cf4fc:;
    r[2] = (u)0 + 1; goto out;
    L800cf504:;
    r[2] = *(int *)((u)r[4] + 6604);
    r[2] = (u)r[2] + -3;
    r[2] = (u)r[2] < (u)2;
    c = ((r[2] != 0)); r[2] = 0; if (c) goto L800cf544;
    r[2] = *(int *)((u)r[2] + (int)R_GM_GameStatus);
    r[2] = r[2] & 1;
    c = ((r[2] == 0)); r[2] = (u)0 + 1; if (c) goto L800cf544;
    r[3] = (u)0 + 9;
    *(int *)((u)r[4] + 6600) = r[3];
    r[3] = (u)0 + 29;
    *(int *)((u)r[4] + 6604) = r[3]; goto out;
    L800cf544:;
    r[2] = (u)0 + (u)0; goto out;
out:
    return r[2];
}
