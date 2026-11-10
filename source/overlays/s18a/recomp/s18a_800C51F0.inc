int G_s18a_800C51F0(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s18a_800C51F0");
int G_s18a_800C51F0(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    *(short *)((u)r[4] + 0) = r[5];
    *(short *)((u)r[4] + 2) = r[6];
    *(short *)((u)r[4] + 4) = r[7]; goto out;
out:
    RECOMP_RETURN;
}
