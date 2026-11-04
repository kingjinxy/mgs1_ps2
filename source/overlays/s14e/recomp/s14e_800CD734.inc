extern char R_s14e_800CD714[] __asm__("s14e_800CD714");
int G_s14e_800CD734(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s14e_800CD734");
int G_s14e_800CD734(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[31];
    r[2] = *(short *)((u)r[4] + 2852);
    c = ((r[2] != 0));  if (c) goto L800cd754;
     CALL(R_s14e_800CD714);
    L800cd754:;
    r[31] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
