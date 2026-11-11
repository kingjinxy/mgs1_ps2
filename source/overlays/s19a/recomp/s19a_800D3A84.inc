extern char R_s19a_dat_800E0DF8[] __asm__("s19a_dat_800E0DF8");
extern char R_s19a_dat_800E0DFC[] __asm__("s19a_dat_800E0DFC");
extern char R_s19a_dat_800E0E00[] __asm__("s19a_dat_800E0E00");
int G_s19a_800D3A84(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s19a_800D3A84");
int G_s19a_800D3A84(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[2] = 0;
    r[2] = *(int *)((u)r[2] + (int)R_s19a_dat_800E0DF8);
    *(int *)((u)r[4] + 3056) = r[2];
    r[2] = 0;
    r[3] = *(int *)((u)r[2] + (int)R_s19a_dat_800E0DFC);
    r[2] = 0;
    r[8] = (u)r[2] + (int)R_s19a_dat_800E0E00;
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
