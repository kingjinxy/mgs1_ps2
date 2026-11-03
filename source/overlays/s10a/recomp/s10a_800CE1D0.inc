extern char R_s10a_dat_800E4970[] __asm__("s10a_dat_800E4970");
extern char R_s10a_dat_800E4AA0[] __asm__("s10a_dat_800E4AA0");
extern char R_s10a_dat_800E4AA4[] __asm__("s10a_dat_800E4AA4");
extern char R_s10a_dat_800E4AA8[] __asm__("s10a_dat_800E4AA8");
int G_s10a_800CE1D0(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s10a_800CE1D0");
int G_s10a_800CE1D0(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(0)
    r[3] = 0;
    r[2] = 0;
    r[2] = *(int *)((u)r[2] + (int)R_s10a_dat_800E4AA0);
    r[3] = (u)r[3] + (int)R_s10a_dat_800E4970;
    *(int *)((u)r[3] + 40) = r[2];
    r[2] = 0;
    r[4] = *(int *)((u)r[2] + (int)R_s10a_dat_800E4AA4);
    r[2] = 0;
    r[8] = (u)r[2] + (int)R_s10a_dat_800E4AA8;
    r[5] = LWL(((u)r[8] + 3), r[5]);
    r[5] = LWR(((u)r[8] + 0), r[5]);
    r[6] = LWL(((u)r[8] + 7), r[6]);
    r[6] = LWR(((u)r[8] + 4), r[6]);
    SWL(((u)r[3] + 51), r[5]);
    SWR(((u)r[3] + 48), r[5]);
    SWL(((u)r[3] + 55), r[6]);
    SWR(((u)r[3] + 52), r[6]);
    *(int *)((u)r[3] + 44) = r[4]; goto out;
out:
    RECOMP_RETURN;
}
