extern char R_s19a_dat_800E0B38[] __asm__("s19a_dat_800E0B38");
extern char R_GV_DiffVec3[] __asm__("GV_DiffVec3");
extern char R_HZD_OnlineHazardCheck[] __asm__("HZD_OnlineHazardCheck");
int G_s19a_800D2B80(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s19a_800D2B80");
int G_s19a_800D2B80(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(48)
    r[29] = (u)r[29] + -48;
    *(int *)((u)r[29] + 36) = r[19];
    r[19] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 24) = r[16];
    r[16] = (u)r[5] + 1;
    *(int *)((u)r[29] + 32) = r[18];
    r[18] = (u)r[6] + (u)0;
    r[2] = (int)r[16] < 48;
    *(int *)((u)r[29] + 40) = r[31];
    c = ((r[2] != 0)); *(int *)((u)r[29] + 28) = r[17]; if (c) goto L800d2bb0;
    r[16] = (u)0 + (u)0;
    L800d2bb0:;
    r[4] = (u)r[18] + (u)0;
    r[2] = (u)r[16] << 3;
    r[3] = 0;
    r[3] = (u)r[3] + (int)R_s19a_dat_800E0B38;
    r[17] = (u)r[2] + (u)r[3];
    r[5] = (u)r[17] + (u)0; CALL(R_GV_DiffVec3);
    r[2] = (int)r[2] < 5000;
    c = ((r[2] == 0)); r[2] = (u)0 + 2; if (c) goto L800d2c08;
    *(int *)((u)r[29] + 16) = r[2];
    r[4] = (u)r[19] + (u)0;
    r[5] = (u)r[18] + (u)0;
    r[6] = (u)r[17] + (u)0;
    r[7] = (u)0 + 15; CALL(R_HZD_OnlineHazardCheck);
    c = ((r[2] != 0)); r[2] = (u)0 + -1; if (c) goto L800d2c0c;
    r[4] = *(short *)((u)r[17] + 6);
    r[3] = (u)0 + 1;
    c = ((r[4] == r[3])); r[2] = (u)r[16] + (u)0; if (c) goto L800d2c0c;
    L800d2c08:;
    r[2] = (u)0 + -1;
    L800d2c0c:;
    r[31] = *(int *)((u)r[29] + 40);
    r[19] = *(int *)((u)r[29] + 36);
    r[18] = *(int *)((u)r[29] + 32);
    r[17] = *(int *)((u)r[29] + 28);
    r[16] = *(int *)((u)r[29] + 24);
    r[29] = (u)r[29] + 48; goto out;
out:
    RECOMP_RETURN;
}
