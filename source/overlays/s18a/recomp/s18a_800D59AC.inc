extern char R_s18a_dat_800E4348[] __asm__("s18a_dat_800E4348");
extern char R_GV_DiffDirAbs[] __asm__("GV_DiffDirAbs");
extern char R_GV_VecDir2[] __asm__("GV_VecDir2");
int G_s18a_800D59AC(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s18a_800D59AC");
int G_s18a_800D59AC(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(32)
    r[29] = (u)r[29] + -32;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 24) = r[31];
    *(int *)((u)r[29] + 20) = r[17];
    r[2] = *(signed char *)((u)r[16] + 120);
    r[2] = (int)r[2] < 2;
    c = ((r[2] != 0)); r[2] = (u)0 + (u)0; if (c) goto L800d5a2c;
    r[4] = (u)r[16] + 128; CALL(R_GV_VecDir2);
    r[4] = (u)r[16] + 136;
    r[16] = (u)r[2] + (u)0; CALL(R_GV_VecDir2);
    r[5] = (u)r[16] + (u)0;
    r[17] = 0;
    r[4] = *(int *)((u)r[17] + (int)R_s18a_dat_800E4348);
    r[16] = (u)r[2] + (u)0; CALL(R_GV_DiffDirAbs);
    r[5] = (u)r[16] + (u)0;
    r[4] = *(int *)((u)r[17] + (int)R_s18a_dat_800E4348);
    r[16] = (u)r[2] + (u)0; CALL(R_GV_DiffDirAbs);
    r[2] = (u)r[2] + 896;
    r[2] = (u)r[2] < (u)1793;
    c = ((r[2] == 0)); r[3] = (u)r[16] + 896; if (c) goto L800d5a28;
    r[3] = (u)r[3] < (u)1793;
    c = ((r[3] != 0)); r[2] = (u)0 + 1; if (c) goto L800d5a2c;
    L800d5a28:;
    r[2] = (u)0 + (u)0;
    L800d5a2c:;
    r[31] = *(int *)((u)r[29] + 24);
    r[17] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 32; goto out;
out:
    RECOMP_RETURN;
}
