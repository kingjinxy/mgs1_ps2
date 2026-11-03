extern char R_s10a_dat_800E43D0[] __asm__("s10a_dat_800E43D0");
int G_s10a_800C4B4C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s10a_800C4B4C");
int G_s10a_800C4B4C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(0)
    r[2] = 0;
    r[2] = *(int *)((u)r[2] + (int)R_s10a_dat_800E43D0);
     goto out;
out:
    return r[2];
}
