extern char R_s18a_dat_800C3A74[] __asm__("s18a_dat_800C3A74");
extern char R_HZD_GetOnlineVector[] __asm__("HZD_GetOnlineVector");
extern char R_HZD_OnlineHazardCheck[] __asm__("HZD_OnlineHazardCheck");
int G_s18a_800D6C88(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s18a_800D6C88");
int G_s18a_800D6C88(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(40)
    r[29] = (u)r[29] + -40;
    r[5] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 32) = r[31];
    r[3] = *(short *)((u)r[5] + 134);
    r[2] = (u)0 + 1;
    c = ((r[3] == r[2])); r[3] = (u)0 + 4; if (c) goto L800d6cf8;
    r[6] = 0;
    r[2] = *(int *)((u)r[5] + 76);
    r[5] = (u)r[5] + 32;
    r[6] = (u)r[6] + (int)R_s18a_dat_800C3A74;
    *(int *)((u)r[29] + 16) = r[3];
    r[4] = *(int *)((u)r[2] + 8);
    r[7] = (u)r[3] + (u)0; CALL(R_HZD_OnlineHazardCheck);
    c = ((r[2] == 0)); r[2] = (u)0 + (u)0; if (c) goto L800d6cf8;
    r[4] = (u)r[29] + 24; CALL(R_HZD_GetOnlineVector);
    r[2] = *(short *)((u)r[29] + 24);
    c = ((r[2] != 0)); r[2] = (u)0 + 1; if (c) goto L800d6cf8;
    r[3] = *(short *)((u)r[29] + 28);
    c = ((r[3] == 0)); r[2] = (u)0 + (u)0; if (c) goto L800d6cf8;
    r[2] = (u)0 + 1;
    L800d6cf8:;
    r[31] = *(int *)((u)r[29] + 32);
    r[29] = (u)r[29] + 40; goto out;
out:
    RECOMP_RETURN;
}
