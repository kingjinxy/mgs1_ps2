extern char R_GM_PlayerPosition[] __asm__("GM_PlayerPosition");
extern char R_s08b_dword_800C34C0[] __asm__("s08b_dword_800C34C0");
extern char R_GV_DiffVec3[] __asm__("GV_DiffVec3");
extern char R_HZD_GetAddress[] __asm__("HZD_GetAddress");
int G_s08b_bunsin2_800CE2E8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s08b_bunsin2_800CE2E8");
int G_s08b_bunsin2_800CE2E8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(32)
    r[29] = (u)r[29] + -32;
    *(int *)((u)r[29] + 24) = r[18];
    r[18] = (u)r[4] + (u)0;
    r[2] = 0;
    *(int *)((u)r[29] + 20) = r[17];
    r[17] = (u)r[2] + (int)R_s08b_dword_800C34C0;
    r[4] = (u)r[17] + (u)0;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = 0;
    r[16] = (u)r[16] + (int)R_GM_PlayerPosition;
    *(int *)((u)r[29] + 28) = r[31];
    r[5] = (u)r[16] + (u)0; CALL(R_GV_DiffVec3);
    r[4] = (u)r[17] + 8;
    r[5] = (u)r[16] + (u)0;
    r[16] = (u)r[2] + (u)0; CALL(R_GV_DiffVec3);
    r[16] = (int)r[16] < (int)r[2];
    c = ((r[16] == 0)); r[4] = (u)0 + 2; if (c) goto L800ce33c;
    r[4] = (u)0 + 3;
    L800ce33c:;
    r[3] = (u)r[17] + -16;
    r[2] = (u)r[4] << 3;
    r[2] = (u)r[2] + (u)r[3];
    r[7] = LWL(((u)r[2] + 3), r[7]);
    r[7] = LWR(((u)r[2] + 0), r[7]);
    r[8] = LWL(((u)r[2] + 7), r[8]);
    r[8] = LWR(((u)r[2] + 4), r[8]);
    SWL(((u)r[18] + 6507), r[7]);
    SWR(((u)r[18] + 6504), r[7]);
    SWL(((u)r[18] + 6511), r[8]);
    SWR(((u)r[18] + 6508), r[8]);
    r[2] = *(int *)((u)r[18] + 76);
    r[5] = (u)r[18] + 6504;
    r[4] = *(int *)((u)r[2] + 8);
    r[6] = (u)0 + -1; CALL(R_HZD_GetAddress);
    *(int *)((u)r[18] + 6512) = r[2];
    r[31] = *(int *)((u)r[29] + 28);
    r[18] = *(int *)((u)r[29] + 24);
    r[17] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 32; goto out;
out:
    return r[2];
}
