int G_s11b_800CD22C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s11b_800CD22C");
int G_s11b_800CD22C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    c = (((int)r[5] <= 0));  if (c) goto L800cd24c;
    L800cd234:;
    c = ((r[6] != r[4])); r[5] = (u)r[5] + -1; if (c) goto L800cd244;
    r[2] = (u)0 + 1; goto out;
    L800cd244:;
    c = (((int)r[5] > 0)); r[6] = (u)r[6] + 16; if (c) goto L800cd234;
    L800cd24c:;
    r[2] = (u)0 + (u)0; goto out;
out:
    RECOMP_RETURN;
}
