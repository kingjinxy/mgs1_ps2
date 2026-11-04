extern char R_s10a_dat_800E4AA0[] __asm__("s10a_dat_800E4AA0");
extern char R_s10a_dat_800E4AA4[] __asm__("s10a_dat_800E4AA4");
extern char R_s10a_dat_800E4AA8[] __asm__("s10a_dat_800E4AA8");
int G_s10a_800CC480(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s10a_800CC480");
int G_s10a_800CC480(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[2] = 0;
    r[2] = *(int *)((u)r[2] + (int)R_s10a_dat_800E4AA0);
    *(int *)((u)r[4] + 3056) = r[2];
    r[2] = 0;
    r[3] = *(int *)((u)r[2] + (int)R_s10a_dat_800E4AA4);
    r[2] = 0;
    r[8] = (u)r[2] + (int)R_s10a_dat_800E4AA8;
    r[5] = LWL(((u)r[8] + 3), r[5]);
    r[5] = LWR(((u)r[8] + 0), r[5]);
    r[6] = LWL(((u)r[8] + 7), r[6]);
    r[6] = LWR(((u)r[8] + 4), r[6]);
    SWL(((u)r[4] + 3039), r[5]);
    SWR(((u)r[4] + 3036), r[5]);
    SWL(((u)r[4] + 3043), r[6]);
    SWR(((u)r[4] + 3040), r[6]);
    *(int *)((u)r[4] + 3060) = r[3]; goto out;
out:
    RECOMP_RETURN;
}
