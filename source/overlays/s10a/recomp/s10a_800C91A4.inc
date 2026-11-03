int G_s10a_800C91A4(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s10a_800C91A4");
int G_s10a_800C91A4(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(0)
    r[2] = *(int *)((u)r[4] + 3100);
    r[2] = (u)r[2] + 1;
    *(int *)((u)r[4] + 3100) = r[2]; goto out;
out:
    RECOMP_RETURN;
}
