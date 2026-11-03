extern char R_s10a_800C85BC[] __asm__("s10a_800C85BC");
int G_s10a_800C8950(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s10a_800C8950");
int G_s10a_800C8950(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(0)
    r[2] = 0;
    r[2] = (u)r[2] + (int)R_s10a_800C85BC;
    *(int *)((u)r[4] + 3024) = r[2];
    *(int *)((u)r[4] + 3032) = 0;
    *(short *)((u)r[4] + 112) = 0;
    *(short *)((u)r[4] + 108) = 0; goto out;
out:
    RECOMP_RETURN;
}
