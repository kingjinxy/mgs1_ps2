extern char R_GV_Time[] __asm__("GV_Time");
extern char R_s08b_dword_800C3490[] __asm__("s08b_dword_800C3490");
extern char R_HZD_GetAddress[] __asm__("HZD_GetAddress");
int G_s08b_bunsin2_800CE180(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s08b_bunsin2_800CE180");
int G_s08b_bunsin2_800CE180(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(24)
    r[2] = 0;
    r[5] = *(int *)((u)r[2] + (int)R_GV_Time);
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 20) = r[31];
    c = (((int)r[5] >= 0)); r[2] = (u)r[5] + (u)0; if (c) goto L800ce1a4;
    r[2] = (u)r[5] + 3;
    L800ce1a4:;
    r[4] = (int)r[2] >> 2;
    r[2] = (u)r[4] << 2;
    r[3] = *(int *)((u)r[16] + 2008);
    r[4] = (u)r[5] - (u)r[2];
    r[4] = (u)r[4] + (u)r[3];
    r[2] = (int)r[4] < 4;
    c = ((r[2] != 0)); r[3] = 0; if (c) goto L800ce1c8;
    r[4] = (u)r[4] + -4;
    L800ce1c8:;
    r[3] = (u)r[3] + (int)R_s08b_dword_800C3490;
    r[2] = (u)r[4] << 3;
    r[2] = (u)r[2] + (u)r[3];
    r[7] = LWL(((u)r[2] + 3), r[7]);
    r[7] = LWR(((u)r[2] + 0), r[7]);
    r[8] = LWL(((u)r[2] + 7), r[8]);
    r[8] = LWR(((u)r[2] + 4), r[8]);
    SWL(((u)r[16] + 6507), r[7]);
    SWR(((u)r[16] + 6504), r[7]);
    SWL(((u)r[16] + 6511), r[8]);
    SWR(((u)r[16] + 6508), r[8]);
    r[2] = *(int *)((u)r[16] + 76);
    r[5] = (u)r[16] + 6504;
    r[4] = *(int *)((u)r[2] + 8);
    r[6] = (u)0 + -1; CALL(R_HZD_GetAddress);
    *(int *)((u)r[16] + 6512) = r[2];
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
