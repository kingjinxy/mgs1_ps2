int G_s11h_800DA8A4(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s11h_800DA8A4");
int G_s11h_800DA8A4(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[2] = (u)0 + 3;
    *(char *)((u)r[4] + 3) = r[2];
    r[2] = (u)0 + 96;
    *(char *)((u)r[4] + 7) = r[2]; goto out;
out:
    RECOMP_RETURN;
}
