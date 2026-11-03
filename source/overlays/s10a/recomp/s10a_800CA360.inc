extern char R_GV_DiffDirS[] __asm__("GV_DiffDirS");
int G_s10a_800CA360(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s10a_800CA360");
int G_s10a_800CA360(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    c = (((int)r[5] < 0)); *(int *)((u)r[29] + 16) = r[31]; if (c) goto L800ca3a0;
    c = (((int)r[4] < 0)); r[2] = (u)0 + (u)0; if (c) goto L800ca3a4;
     CALL(R_GV_DiffDirS);
    r[3] = (u)r[2] + (u)0;
    r[2] = (u)r[3] + 896;
    r[2] = (u)r[2] < (u)1793;
    c = ((r[2] == 0)); r[2] = (u)0 + (u)0; if (c) goto L800ca3a4;
    c = (((int)r[3] >= 0)); r[2] = (u)0 + 1; if (c) goto L800ca3a4;
    r[2] = (u)0 + 2; goto L800ca3a4;
    L800ca3a0:;
    r[2] = (u)0 + (u)0;
    L800ca3a4:;
    r[31] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    return r[2];
}
