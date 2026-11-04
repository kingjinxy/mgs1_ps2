extern char R_GM_PlayerPosition[] __asm__("GM_PlayerPosition");
extern char R_GV_SubVec3[] __asm__("GV_SubVec3");
extern char R_GV_VecDir2[] __asm__("GV_VecDir2");
int G_s07b_800CB224(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s07b_800CB224");
int G_s07b_800CB224(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(32)
    r[29] = (u)r[29] + -32;
    *(int *)((u)r[29] + 24) = r[16];
    r[16] = (u)r[4] + (u)0;
    r[4] = 0;
    r[4] = (u)r[4] + (int)R_GM_PlayerPosition;
    r[5] = (u)r[16] + 32;
    *(int *)((u)r[29] + 28) = r[31];
    r[6] = (u)r[29] + 16; CALL(R_GV_SubVec3);
    r[4] = (u)r[29] + 16; CALL(R_GV_VecDir2);
    *(short *)((u)r[16] + 110) = r[2];
    r[31] = *(int *)((u)r[29] + 28);
    r[16] = *(int *)((u)r[29] + 24);
    r[29] = (u)r[29] + 32; goto out;
out:
    RECOMP_RETURN;
}
