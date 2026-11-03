int G_s10a_800E05C0(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s10a_800E05C0");
int G_s10a_800E05C0(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(0)
    c = (((int)r[5] <= 0));  if (c) goto L800e05e0;
    L800e05c8:;
    c = ((r[6] != r[4])); r[5] = (u)r[5] + -1; if (c) goto L800e05d8;
    r[2] = (u)0 + 1; goto out;
    L800e05d8:;
    c = (((int)r[5] > 0)); r[6] = (u)r[6] + 16; if (c) goto L800e05c8;
    L800e05e0:;
    r[2] = (u)0 + (u)0; goto out;
out:
    RECOMP_RETURN;
}
