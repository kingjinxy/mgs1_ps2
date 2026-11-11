extern char R_s19a_800CBC78[] __asm__("s19a_800CBC78");
int G_s19a_800CC00C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s19a_800CC00C");
int G_s19a_800CC00C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[2] = 0;
    r[2] = (u)r[2] + (int)R_s19a_800CBC78;
    *(int *)((u)r[4] + 3024) = r[2];
    *(int *)((u)r[4] + 3032) = 0;
    *(short *)((u)r[4] + 112) = 0;
    *(short *)((u)r[4] + 108) = 0; goto out;
out:
    RECOMP_RETURN;
}
