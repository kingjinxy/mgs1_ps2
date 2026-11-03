extern char R_HZD_GetAddress[] __asm__("HZD_GetAddress");
extern char R_HZD_ReachTo[] __asm__("HZD_ReachTo");
extern char R_s08b_bunsin2_800CDF68[] __asm__("s08b_bunsin2_800CDF68");
int G_s08b_bunsin2_800D0784(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s08b_bunsin2_800D0784");
int G_s08b_bunsin2_800D0784(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[16];
    *(int *)((u)r[29] + 20) = r[31];
    r[16] = (u)r[4] + (u)0; CALL(R_s08b_bunsin2_800CDF68);
    r[2] = *(int *)((u)r[16] + 6608);
    r[2] = r[2] & 16;
    c = ((r[2] == 0)); r[5] = (u)r[16] + 32; if (c) goto L800d07ec;
    r[2] = *(int *)((u)r[16] + 76);
    r[4] = *(int *)((u)r[2] + 8);
    r[6] = (u)0 + -1; CALL(R_HZD_GetAddress);
    r[6] = *(int *)((u)r[16] + 6512);
    r[3] = *(int *)((u)r[16] + 76);
    *(int *)((u)r[16] + 6520) = r[2];
    r[4] = *(int *)((u)r[3] + 8);
    r[5] = (u)r[2] + (u)0; CALL(R_HZD_ReachTo);
    r[2] = (int)r[2] < 2;
    c = ((r[2] != 0)); r[2] = (u)0 + (u)0; if (c) goto L800d07f0;
    r[2] = (u)0 + 1; goto L800d0804;
    L800d07ec:;
    r[2] = (u)0 + (u)0;
    L800d07f0:;
    r[3] = *(int *)((u)r[16] + 6608);
    r[4] = *(int *)((u)r[16] + 6696);
    r[3] = (u)r[3] + 1;
    *(int *)((u)r[16] + 6580) = r[4];
    *(int *)((u)r[16] + 6608) = r[3];
    L800d0804:;
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    return r[2];
}
