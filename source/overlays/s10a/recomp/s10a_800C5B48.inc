extern char R_DG_ZeroVector[] __asm__("DG_ZeroVector");
extern char R_RotMatrixYXZ[] __asm__("RotMatrixYXZ");
int G_s10a_800C5B48(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s10a_800C5B48");
int G_s10a_800C5B48(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(32)
    r[29] = (u)r[29] + -32;
    *(int *)((u)r[29] + 24) = r[16];
    r[16] = (u)r[4] + (u)0;
    r[2] = 0;
    *(int *)((u)r[29] + 28) = r[31];
    r[9] = (u)r[2] + (int)R_DG_ZeroVector;
    r[6] = LWL(((u)r[9] + 3), r[6]);
    r[6] = LWR(((u)r[9] + 0), r[6]);
    r[7] = LWL(((u)r[9] + 7), r[7]);
    r[7] = LWR(((u)r[9] + 4), r[7]);
    SWL(((u)r[29] + 19), r[6]);
    SWR(((u)r[29] + 16), r[6]);
    SWL(((u)r[29] + 23), r[7]);
    SWR(((u)r[29] + 20), r[7]);
    r[2] = *(int *)((u)r[16] + 80);
    r[2] = *(unsigned short *)((u)r[2] + 0);
    *(short *)((u)r[29] + 18) = r[2];
    r[5] = *(int *)((u)r[16] + 36);
    r[4] = (u)r[29] + 16; CALL(R_RotMatrixYXZ);
    r[2] = *(int *)((u)r[16] + 32);
    r[2] = *(int *)((u)r[2] + 0);
    r[3] = *(int *)((u)r[16] + 36);
    r[2] = *(int *)((u)r[2] + 20);
    *(int *)((u)r[3] + 20) = r[2];
    r[2] = *(int *)((u)r[16] + 32);
    r[2] = *(int *)((u)r[2] + 0);
    r[3] = *(int *)((u)r[16] + 36);
    r[2] = *(int *)((u)r[2] + 28);
    *(int *)((u)r[3] + 28) = r[2];
    r[2] = *(int *)((u)r[16] + 84);
    r[3] = *(int *)((u)r[16] + 36);
    r[2] = *(int *)((u)r[2] + 0);
    *(int *)((u)r[3] + 24) = r[2];
    r[31] = *(int *)((u)r[29] + 28);
    r[16] = *(int *)((u)r[29] + 24);
    r[29] = (u)r[29] + 32; goto out;
out:
    RECOMP_RETURN;
}
