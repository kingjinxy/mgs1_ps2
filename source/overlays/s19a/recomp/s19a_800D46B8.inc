extern char R_GM_NoisePosition[] __asm__("GM_NoisePosition");
extern char R_GV_SubVec3[] __asm__("GV_SubVec3");
extern char R_GV_VecDir2[] __asm__("GV_VecDir2");
int G_s19a_800D46B8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s19a_800D46B8");
int G_s19a_800D46B8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(32)
    r[29] = (u)r[29] + -32;
    *(int *)((u)r[29] + 24) = r[16];
    r[16] = (u)r[4] + (u)0;
    r[4] = 0;
    r[4] = (u)r[4] + (int)R_GM_NoisePosition;
    r[5] = (u)r[16] + 32;
    *(int *)((u)r[29] + 28) = r[31];
    r[6] = (u)r[29] + 16; CALL(R_GV_SubVec3);
    r[4] = (u)r[29] + 16; CALL(R_GV_VecDir2);
    *(short *)((u)r[16] + 2888) = r[2];
    r[2] = *(int *)((u)r[16] + 2872);
    r[3] = *(unsigned char *)((u)r[16] + 2974);
    r[2] = r[2] | 32;
    r[3] = r[3] & 1;
    c = ((r[3] == 0)); *(int *)((u)r[16] + 2872) = r[2]; if (c) goto L800d4714;
    r[3] = *(int *)((u)r[16] + 2856);
    r[2] = (u)0 + (u)0;
    r[3] = (u)r[3] + 1;
    *(int *)((u)r[16] + 2856) = r[3]; goto L800d4718;
    L800d4714:;
    r[2] = (u)0 + 1;
    L800d4718:;
    r[31] = *(int *)((u)r[29] + 28);
    r[16] = *(int *)((u)r[29] + 24);
    r[29] = (u)r[29] + 32; goto out;
out:
    RECOMP_RETURN;
}
