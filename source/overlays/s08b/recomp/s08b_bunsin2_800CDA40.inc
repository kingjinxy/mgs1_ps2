extern char R_GM_PlayerPosition[] __asm__("GM_PlayerPosition");
extern char R_GV_Time[] __asm__("GV_Time");
extern char R_GM_OnlineTargetCheckAny[] __asm__("GM_OnlineTargetCheckAny");
extern char R_GV_SubVec3[] __asm__("GV_SubVec3");
extern char R_GV_VecDir2[] __asm__("GV_VecDir2");
extern char R_GV_VecLen3[] __asm__("GV_VecLen3");
extern char R_HZD_OnlineHazardCheck[] __asm__("HZD_OnlineHazardCheck");
int G_s08b_bunsin2_800CDA40(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s08b_bunsin2_800CDA40");
int G_s08b_bunsin2_800CDA40(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(56)
    r[29] = (u)r[29] + -56;
    *(int *)((u)r[29] + 32) = r[16];
    r[16] = (u)r[4] + (u)0;
    r[2] = 0;
    *(int *)((u)r[29] + 44) = r[19];
    r[19] = (u)r[2] + (int)R_GM_PlayerPosition;
    r[4] = (u)r[19] + (u)0;
    *(int *)((u)r[29] + 36) = r[17];
    r[17] = (u)r[16] + 32;
    r[5] = (u)r[17] + (u)0;
    r[6] = (u)r[29] + 24;
    *(int *)((u)r[29] + 48) = r[31];
    *(int *)((u)r[29] + 40) = r[18]; CALL(R_GV_SubVec3);
    r[4] = (u)r[29] + 24;
    *(short *)((u)r[29] + 26) = 0; CALL(R_GV_VecDir2);
    r[4] = (u)r[29] + 24;
    *(int *)((u)r[16] + 6696) = r[2]; CALL(R_GV_VecLen3);
    r[3] = 0;
    r[3] = *(int *)((u)r[3] + (int)R_GV_Time);
    *(int *)((u)r[16] + 6700) = r[2];
    r[3] = r[3] & 3;
    c = ((r[3] != 0)); *(int *)((u)r[16] + 6572) = 0; if (c) goto L800cdaf4;
    r[5] = (u)r[19] + (u)0;
    r[6] = (u)r[17] + (u)0;
    r[18] = *(int *)((u)r[16] + 76);
    r[2] = (u)0 + 2;
    *(int *)((u)r[29] + 16) = r[2];
    r[4] = *(int *)((u)r[18] + 8);
    r[7] = (u)0 + 15; CALL(R_HZD_OnlineHazardCheck);
    c = ((r[2] != 0)); r[4] = (u)r[17] + (u)0; if (c) goto L800cdae8;
    r[5] = (u)r[19] + (u)0;
    r[6] = *(int *)((u)r[18] + 0);
    r[7] = (u)r[29] + 24; CALL(R_GM_OnlineTargetCheckAny);
    c = ((r[2] == 0)); r[2] = (u)0 + 1; if (c) goto L800cdaf0;
    L800cdae8:;
    *(int *)((u)r[16] + 6572) = 0; goto L800cdaf4;
    L800cdaf0:;
    *(int *)((u)r[16] + 6572) = r[2];
    L800cdaf4:;
    r[31] = *(int *)((u)r[29] + 48);
    r[19] = *(int *)((u)r[29] + 44);
    r[18] = *(int *)((u)r[29] + 40);
    r[17] = *(int *)((u)r[29] + 36);
    r[16] = *(int *)((u)r[29] + 32);
    r[29] = (u)r[29] + 56; goto out;
out:
    RECOMP_RETURN;
}
