extern char R_DG_ZeroVector[] __asm__("DG_ZeroVector");
extern char R_RotMatrixYXZ[] __asm__("RotMatrixYXZ");
extern char R_s08b_bunsin2_800CD2E8[] __asm__("s08b_bunsin2_800CD2E8");
int G_s08b_bunsin2_800CD770(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s08b_bunsin2_800CD770");
int G_s08b_bunsin2_800CD770(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(32)
    r[29] = (u)r[29] + -32;
    *(int *)((u)r[29] + 24) = r[16];
    *(int *)((u)r[29] + 28) = r[31];
    r[16] = (u)r[4] + (u)0; CALL(R_s08b_bunsin2_800CD2E8);
    r[2] = 0;
    r[9] = (u)r[2] + (int)R_DG_ZeroVector;
    r[6] = LWL(((u)r[9] + 3), r[6]);
    r[6] = LWR(((u)r[9] + 0), r[6]);
    r[7] = LWL(((u)r[9] + 7), r[7]);
    r[7] = LWR(((u)r[9] + 4), r[7]);
    SWL(((u)r[29] + 19), r[6]);
    SWR(((u)r[29] + 16), r[6]);
    SWL(((u)r[29] + 23), r[7]);
    SWR(((u)r[29] + 20), r[7]);
    r[2] = *(unsigned short *)((u)r[16] + 42);
    *(short *)((u)r[29] + 18) = r[2];
    r[5] = *(int *)((u)r[16] + 6784);
    r[4] = (u)r[29] + 16; CALL(R_RotMatrixYXZ);
    r[2] = *(int *)((u)r[16] + 156);
    r[3] = *(int *)((u)r[16] + 6784);
    r[2] = *(int *)((u)r[2] + 20);
    *(int *)((u)r[3] + 20) = r[2];
    r[2] = *(short *)((u)r[16] + 152);
    *(int *)((u)r[3] + 24) = r[2];
    r[2] = *(int *)((u)r[16] + 156);
    r[2] = *(int *)((u)r[2] + 28);
    *(int *)((u)r[3] + 28) = r[2];
    r[31] = *(int *)((u)r[29] + 28);
    r[16] = *(int *)((u)r[29] + 24);
    r[29] = (u)r[29] + 32; goto out;
out:
    return r[2];
}
