int G_s10a_800D0EF8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s10a_800D0EF8");
int G_s10a_800D0EF8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(0)
    *(short *)((u)r[4] + 1012) = r[5];
    *(short *)((u)r[4] + 1014) = r[6];
    *(short *)((u)r[4] + 1016) = r[7]; goto out;
out:
    return r[2];
}
