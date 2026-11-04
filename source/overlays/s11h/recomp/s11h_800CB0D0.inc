int G_s11h_800CB0D0(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s11h_800CB0D0");
int G_s11h_800CB0D0(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    c = (((int)r[5] <= 0));  if (c) goto L800cb0f0;
    L800cb0d8:;
    c = ((r[6] != r[4])); r[5] = (u)r[5] + -1; if (c) goto L800cb0e8;
    r[2] = (u)0 + 1; goto out;
    L800cb0e8:;
    c = (((int)r[5] > 0)); r[6] = (u)r[6] + 16; if (c) goto L800cb0d8;
    L800cb0f0:;
    r[2] = (u)0 + (u)0; goto out;
out:
    RECOMP_RETURN;
}
