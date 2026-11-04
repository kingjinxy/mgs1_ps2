int G_s10a_800D67D8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s10a_800D67D8");
int G_s10a_800D67D8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[2] = (u)0 + 2;
    r[8] = (u)0 + 3;
    r[7] = (u)0 + 96;
    r[6] = (u)0 + 255;
    r[5] = (u)0 + 63;
    r[3] = (u)r[2] + (u)0;
    r[4] = (u)r[4] + 14;
    L800d67f4:;
    *(char *)((u)r[4] + -11) = r[8];
    *(char *)((u)r[4] + -7) = r[7];
    *(char *)((u)r[4] + -10) = r[6];
    *(char *)((u)r[4] + -9) = r[5];
    *(char *)((u)r[4] + -8) = r[5];
    *(short *)((u)r[4] + -2) = r[3];
    *(short *)((u)r[4] + 0) = r[3];
    r[2] = (u)r[2] + -1;
    c = (((int)r[2] > 0)); r[4] = (u)r[4] + 16; if (c) goto L800d67f4;
     goto out;
out:
    RECOMP_RETURN;
}
