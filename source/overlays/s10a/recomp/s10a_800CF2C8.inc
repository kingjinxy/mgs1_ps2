int G_s10a_800CF2C8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s10a_800CF2C8");
int G_s10a_800CF2C8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[5] = (u)r[5] + -1;
    c = (((int)r[5] < 0)); r[2] = (u)r[6] >> 31; if (c) goto L800cf2f8;
    r[2] = (u)r[6] + (u)r[2];
    r[2] = (int)r[2] >> 1;
    r[4] = (u)r[4] + 6;
    L800cf2e0:;
    *(char *)((u)r[4] + -2) = r[2];
    *(char *)((u)r[4] + -1) = r[6];
    *(char *)((u)r[4] + 0) = r[6];
    r[5] = (u)r[5] + -1;
    c = (((int)r[5] >= 0)); r[4] = (u)r[4] + 40; if (c) goto L800cf2e0;
    L800cf2f8:;
     goto out;
out:
    RECOMP_RETURN;
}
