extern char R_GM_PlayerPosition[] __asm__("GM_PlayerPosition");
extern char R_GM_SnakeCamera[] __asm__("GM_SnakeCamera");
extern char R_s07b_dword_800E5BB0[] __asm__("s07b_dword_800E5BB0");
extern char R_GV_NearExp8[] __asm__("GV_NearExp8");
extern char R_GV_SubVec3[] __asm__("GV_SubVec3");
extern char R_GV_VecLen3[] __asm__("GV_VecLen3");
int G_s07b_800CC468(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s07b_800CC468");
int G_s07b_800CC468(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(32)
    r[2] = 0;
    r[2] = *(int *)((u)r[2] + (int)R_s07b_dword_800E5BB0);
    r[29] = (u)r[29] + -32;
    *(int *)((u)r[29] + 28) = r[31];
    *(int *)((u)r[29] + 24) = r[16];
    r[2] = *(int *)((u)r[2] + 0);
    r[2] = r[2] & 8;
    c = ((r[2] != 0)); r[16] = (u)r[4] + (u)0; if (c) goto L800cc4fc;
    r[4] = (u)r[16] + 32;
    r[5] = 0;
    r[5] = (u)r[5] + (int)R_GM_PlayerPosition;
    r[6] = (u)r[29] + 16; CALL(R_GV_SubVec3);
    r[4] = (u)r[29] + 16; CALL(R_GV_VecLen3);
    r[3] = (u)r[2] + (u)0;
    r[2] = (int)r[3] < 3501;
    c = ((r[2] != 0)); r[5] = (u)0 + 7000; if (c) goto L800cc4d4;
    r[2] = (u)r[3] + (u)0;
    c = (((int)r[2] >= 0));  if (c) goto L800cc4cc;
    r[2] = (u)r[2] + 7;
    L800cc4cc:;
    r[2] = (int)r[2] >> 3;
    r[5] = (u)r[2] << 4;
    L800cc4d4:;
    r[2] = (int)r[5] < 10001;
    c = ((r[2] != 0));  if (c) goto L800cc4e4;
    r[5] = (u)0 + 10000;
    L800cc4e4:;
    r[4] = *(int *)((u)r[16] + 2740);
     CALL(R_GV_NearExp8);
    r[3] = 0;
    *(int *)((u)r[16] + 2740) = r[2];
    *(int *)((u)r[3] + ((int)R_GM_SnakeCamera + 24)) = r[2];
    L800cc4fc:;
    r[31] = *(int *)((u)r[29] + 28);
    r[16] = *(int *)((u)r[29] + 24);
    r[29] = (u)r[29] + 32; goto out;
out:
    return r[2];
}
