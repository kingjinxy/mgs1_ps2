extern char R_GV_DiffDirS[] __asm__("GV_DiffDirS");
int G_s18a_800D5AA0(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s18a_800D5AA0");
int G_s18a_800D5AA0(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    r[4] = (u)r[5] + (u)0;
    *(int *)((u)r[29] + 20) = r[31];
    r[5] = *(short *)((u)r[16] + 42);
     CALL(R_GV_DiffDirS);
    r[3] = (u)r[2] + (u)0;
    r[2] = (int)r[3] < 129;
    c = ((r[2] != 0)); r[2] = (int)r[3] < -128; if (c) goto L800d5ad8;
    r[3] = (u)0 + 128; goto L800d5ae4;
    L800d5ad8:;
    c = ((r[2] == 0));  if (c) goto L800d5ae4;
    r[3] = (u)0 + -128;
    L800d5ae4:;
    *(short *)((u)r[16] + 112) = r[3];
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
