int G_s10a_800D0ECC(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s10a_800D0ECC");
int G_s10a_800D0ECC(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[3] = *(int *)((u)r[4] + 64);
    r[2] = *(int *)((u)r[29] + 16);
    *(char *)((u)r[3] + 4) = r[6];
    *(char *)((u)r[3] + 5) = r[7];
    *(char *)((u)r[3] + 6) = r[2];
    r[3] = *(int *)((u)r[4] + 68);
    *(char *)((u)r[3] + 4) = r[6];
    *(char *)((u)r[3] + 5) = r[7];
    *(char *)((u)r[3] + 6) = r[2]; goto out;
out:
    RECOMP_RETURN;
}
