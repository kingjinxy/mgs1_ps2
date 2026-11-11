int G_s19a_800D34A0(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s19a_800D34A0");
int G_s19a_800D34A0(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[2] = (u)0 + 8;
    r[6] = (u)0 + 3;
    r[3] = (u)0 + 66;
    r[4] = (u)r[4] + 7;
    L800d34b0:;
    *(int *)((u)r[4] + -3) = r[5];
    *(char *)((u)r[4] + -4) = r[6];
    *(char *)((u)r[4] + 0) = r[3];
    r[2] = (u)r[2] + -1;
    c = (((int)r[2] > 0)); r[4] = (u)r[4] + 16; if (c) goto L800d34b0;
     goto out;
out:
    RECOMP_RETURN;
}
