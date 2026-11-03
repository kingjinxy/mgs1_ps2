int G_s10a_800CE72C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s10a_800CE72C");
int G_s10a_800CE72C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(0)
    r[2] = (int)r[4] < (int)r[5];
    c = ((r[2] == 0));  if (c) goto L800ce73c;
    r[4] = (u)r[5] + (u)0;
    L800ce73c:;
    r[2] = (u)r[4] + (u)0; goto out;
out:
    return r[2];
}
