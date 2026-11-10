extern char R_DG_ZeroMatrix[] __asm__("DG_ZeroMatrix");
extern char R_s17a_800E1D50[] __asm__("s17a_800E1D50");
int G_s17a_800E1DE4(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s17a_800E1DE4");
int G_s17a_800E1DE4(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(32)
    r[29] = (u)r[29] + -32;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 20) = r[17];
    r[17] = (u)r[5] + (u)0;
    *(int *)((u)r[29] + 24) = r[31];
    r[4] = *(int *)((u)r[16] + 64);
    r[6] = (u)0 + 8; CALL(R_s17a_800E1D50);
    r[5] = (u)r[17] + (u)0;
    r[4] = *(int *)((u)r[16] + 68);
    r[6] = (u)0 + 8; CALL(R_s17a_800E1D50);
    r[2] = 0;
    r[9] = (u)r[2] + (int)R_DG_ZeroMatrix;
    r[3] = *(int *)((u)r[9] + 0);
    r[7] = *(int *)((u)r[9] + 4);
    r[8] = *(int *)((u)r[9] + 8);
    *(int *)((u)r[16] + 0) = r[3];
    *(int *)((u)r[16] + 4) = r[7];
    *(int *)((u)r[16] + 8) = r[8];
    r[3] = *(int *)((u)r[9] + 12);
    r[7] = *(int *)((u)r[9] + 16);
    r[8] = *(int *)((u)r[9] + 20);
    *(int *)((u)r[16] + 12) = r[3];
    *(int *)((u)r[16] + 16) = r[7];
    *(int *)((u)r[16] + 20) = r[8];
    r[3] = *(int *)((u)r[9] + 24);
    r[7] = *(int *)((u)r[9] + 28);
    *(int *)((u)r[16] + 24) = r[3];
    *(int *)((u)r[16] + 28) = r[7];
    r[2] = (u)0 + 1000;
    *(short *)((u)r[16] + 46) = r[2];
    r[31] = *(int *)((u)r[29] + 24);
    r[17] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 32; goto out;
out:
    RECOMP_RETURN;
}
