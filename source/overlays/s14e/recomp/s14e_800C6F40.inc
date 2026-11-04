extern char R_GV_DiffDirS[] __asm__("GV_DiffDirS");
int G_s14e_800C6F40(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s14e_800C6F40");
int G_s14e_800C6F40(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    c = (((int)r[5] < 0)); *(int *)((u)r[29] + 16) = r[31]; if (c) goto L800c6f80;
    c = (((int)r[4] < 0)); r[2] = (u)0 + (u)0; if (c) goto L800c6f84;
     CALL(R_GV_DiffDirS);
    r[3] = (u)r[2] + (u)0;
    r[2] = (u)r[3] + 896;
    r[2] = (u)r[2] < (u)1793;
    c = ((r[2] == 0)); r[2] = (u)0 + (u)0; if (c) goto L800c6f84;
    c = (((int)r[3] >= 0)); r[2] = (u)0 + 1; if (c) goto L800c6f84;
    r[2] = (u)0 + 2; goto L800c6f84;
    L800c6f80:;
    r[2] = (u)0 + (u)0;
    L800c6f84:;
    r[31] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
