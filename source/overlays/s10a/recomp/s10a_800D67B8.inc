int G_s10a_800D67B8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s10a_800D67B8");
int G_s10a_800D67B8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    *(char *)((u)r[4] + 4) = r[5];
    c = (((int)r[5] >= 0)); r[2] = (u)r[5] + (u)0; if (c) goto L800d67c8;
    r[2] = (u)r[5] + 3;
    L800d67c8:;
    r[2] = (int)r[2] >> 2;
    *(char *)((u)r[4] + 5) = r[2];
    *(char *)((u)r[4] + 6) = r[2]; goto out;
out:
    RECOMP_RETURN;
}
