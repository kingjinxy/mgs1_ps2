extern char R_GM_SnakeCamera[] __asm__("GM_SnakeCamera");
extern char R_GV_LenVec3[] __asm__("GV_LenVec3");
extern char R_GV_SubVec3[] __asm__("GV_SubVec3");
extern char R_GV_VecLen3[] __asm__("GV_VecLen3");
int G_s07b_800CC970(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s07b_800CC970");
int G_s07b_800CC970(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(48)
    r[29] = (u)r[29] + -48;
    *(int *)((u)r[29] + 32) = r[16];
    r[16] = (u)r[5] + (u)0;
    *(int *)((u)r[29] + 36) = r[17];
    r[17] = (u)r[6] + (u)0;
    *(int *)((u)r[29] + 40) = r[31];
    r[6] = (u)r[29] + 16; CALL(R_GV_SubVec3);
    r[4] = (u)r[29] + 16; CALL(R_GV_VecLen3);
    r[4] = (u)r[29] + 16;
    r[5] = (u)r[29] + 24;
    r[6] = (u)r[2] + (u)0;
    r[7] = (u)r[17] + (u)0; CALL(R_GV_LenVec3);
    r[2] = *(unsigned short *)((u)r[16] + 0);
    r[4] = *(unsigned short *)((u)r[29] + 24);
    r[3] = 0;
    r[2] = (u)r[2] + (u)r[4];
    *(short *)((u)r[3] + (int)R_GM_SnakeCamera) = r[2];
    r[2] = *(unsigned short *)((u)r[16] + 4);
    r[4] = *(unsigned short *)((u)r[29] + 28);
    r[3] = (u)r[3] + (int)R_GM_SnakeCamera;
    r[2] = (u)r[2] + (u)r[4];
    *(short *)((u)r[3] + 4) = r[2];
    r[31] = *(int *)((u)r[29] + 40);
    r[17] = *(int *)((u)r[29] + 36);
    r[16] = *(int *)((u)r[29] + 32);
    r[29] = (u)r[29] + 48; goto out;
out:
    return r[2];
}
