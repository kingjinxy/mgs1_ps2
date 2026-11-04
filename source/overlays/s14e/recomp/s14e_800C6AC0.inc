int G_s14e_800C6AC0(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s14e_800C6AC0");
int G_s14e_800C6AC0(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[2] = *(int *)((u)r[4] + 2304);
    r[2] = *(unsigned short *)((u)r[2] + 6);
    r[2] = r[2] & 32;
    r[2] = (u)0 < (u)r[2]; goto out;
out:
    RECOMP_RETURN;
}
