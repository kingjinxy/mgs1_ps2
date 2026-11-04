extern char R_s14e_800CCCC4[] __asm__("s14e_800CCCC4");
int G_s14e_800CD08C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s14e_800CD08C");
int G_s14e_800CD08C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 20) = r[31];
    r[2] = *(int *)((u)r[16] + 2856);
    r[2] = r[2] & 31;
    c = ((r[2] != 0)); r[2] = (u)0 + -1; if (c) goto L800cd0bc;
    *(int *)((u)r[16] + 3084) = r[2];
    *(int *)((u)r[16] + 3056) = r[2]; CALL(R_s14e_800CCCC4);
    L800cd0bc:;
    r[4] = (u)r[16] + (u)0; CALL(R_s14e_800CCCC4);
    *(short *)((u)r[16] + 2888) = r[2];
    r[2] = (u)r[2] << 16;
    c = (((int)r[2] < 0)); r[2] = (u)0 + (u)0; if (c) goto L800cd0e8;
    r[3] = *(int *)((u)r[16] + 2856);
    r[3] = (u)r[3] + 1;
    *(int *)((u)r[16] + 2856) = r[3]; goto L800cd0ec;
    L800cd0e8:;
    r[2] = (u)0 + 1;
    L800cd0ec:;
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
