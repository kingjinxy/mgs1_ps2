extern char R_GM_PlayerPosition[] __asm__("GM_PlayerPosition");
extern char R_GV_SubVec3[] __asm__("GV_SubVec3");
extern char R_GV_VecDir2[] __asm__("GV_VecDir2");
extern char R_RotMatrixYXZ[] __asm__("RotMatrixYXZ");
extern char R_SquareRoot0[] __asm__("SquareRoot0");
int G_s07b_800CBE34(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s07b_800CBE34");
int G_s07b_800CBE34(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(56)
    r[29] = (u)r[29] + -56;
    *(int *)((u)r[29] + 40) = r[16];
    r[16] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 44) = r[17];
    r[17] = (u)r[5] + (u)0;
    r[4] = (u)r[16] + 32;
    r[5] = 0;
    r[5] = (u)r[5] + (int)R_GM_PlayerPosition;
    r[6] = (u)r[29] + 16;
    *(int *)((u)r[29] + 48) = r[31];
    *(short *)((u)r[29] + 28) = 0; CALL(R_GV_SubVec3);
    r[4] = (u)r[29] + 16; CALL(R_GV_VecDir2);
    r[3] = *(short *)((u)r[29] + 16);
    mul = (long long)(int)r[3] * (int)r[3]; hi_ = mul >> 32; lo_ = mul;
    r[4] = lo_;
    r[3] = *(short *)((u)r[29] + 20);
    mul = (long long)(int)r[3] * (int)r[3]; hi_ = mul >> 32; lo_ = mul;
    r[3] = *(unsigned short *)((u)r[29] + 18);
    *(short *)((u)r[29] + 26) = r[2];
    *(short *)((u)r[29] + 32) = r[3];
    r[8] = lo_;
    r[4] = (u)r[4] + (u)r[8]; CALL(R_SquareRoot0);
    r[4] = (u)r[29] + 32;
    *(short *)((u)r[29] + 36) = r[2]; CALL(R_GV_VecDir2);
    r[4] = (u)r[29] + 24;
    r[5] = (u)r[17] + (u)0;
    r[2] = (u)0 - (u)r[2];
    r[2] = (u)r[2] + -1024;
    r[2] = r[2] & 4095;
    *(short *)((u)r[29] + 24) = r[2]; CALL(R_RotMatrixYXZ);
    r[2] = *(short *)((u)r[16] + 32);
    *(int *)((u)r[17] + 20) = r[2];
    r[2] = *(short *)((u)r[16] + 34);
    *(int *)((u)r[17] + 24) = r[2];
    r[2] = *(short *)((u)r[16] + 36);
    *(int *)((u)r[17] + 28) = r[2];
    r[31] = *(int *)((u)r[29] + 48);
    r[17] = *(int *)((u)r[29] + 44);
    r[16] = *(int *)((u)r[29] + 40);
    r[29] = (u)r[29] + 56; goto out;
out:
    RECOMP_RETURN;
}
