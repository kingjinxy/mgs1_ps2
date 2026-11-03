int G_s10a_800C45AC(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s10a_800C45AC");
int G_s10a_800C45AC(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(0)
    *(short *)((u)r[4] + 0) = r[5];
    *(short *)((u)r[4] + 2) = r[6];
    *(short *)((u)r[4] + 4) = r[7]; goto out;
out:
    RECOMP_RETURN;
}
