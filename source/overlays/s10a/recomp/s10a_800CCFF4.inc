extern char R_HZD_GetAddress[] __asm__("HZD_GetAddress");
extern char R_HZD_ReachTo[] __asm__("HZD_ReachTo");
extern char R_s10a_800CC480[] __asm__("s10a_800CC480");
extern char R_s10a_800CCF6C[] __asm__("s10a_800CCF6C");
int G_s10a_800CCFF4(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s10a_800CCFF4");
int G_s10a_800CCFF4(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[16];
    *(int *)((u)r[29] + 20) = r[31];
    r[16] = (u)r[4] + (u)0; CALL(R_s10a_800CC480);
    r[4] = *(int *)((u)r[16] + 76);
    r[2] = *(int *)((u)r[16] + 3060);
    r[3] = *(int *)((u)r[4] + 0);
    c = ((r[3] != r[2])); r[2] = (u)0 + -1; if (c) goto L800cd078;
    r[2] = *(int *)((u)r[16] + 2856);
    r[2] = r[2] & 16;
    c = ((r[2] == 0)); r[5] = (u)r[16] + 32; if (c) goto L800cd06c;
    r[4] = *(int *)((u)r[4] + 8);
    r[6] = (u)0 + -1; CALL(R_HZD_GetAddress);
    r[6] = *(int *)((u)r[16] + 3056);
    r[3] = *(int *)((u)r[16] + 76);
    *(int *)((u)r[16] + 3080) = r[2];
    r[4] = *(int *)((u)r[3] + 8);
    r[5] = (u)r[2] + (u)0; CALL(R_HZD_ReachTo);
    r[2] = (int)r[2] < 2;
    c = ((r[2] != 0)); r[4] = (u)r[16] + (u)0; if (c) goto L800cd070;
    r[2] = (u)0 + -1; goto L800cd078;
    L800cd06c:;
    r[4] = (u)r[16] + (u)0;
    L800cd070:;
    r[5] = (u)0 + 1500; CALL(R_s10a_800CCF6C);
    L800cd078:;
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    return r[2];
}
