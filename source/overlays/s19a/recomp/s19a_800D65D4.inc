extern char R_s19a_dat_800E0CC8[] __asm__("s19a_dat_800E0CC8");
extern char R_s19a_dat_800E0DF8[] __asm__("s19a_dat_800E0DF8");
extern char R_s19a_dat_800E0DFC[] __asm__("s19a_dat_800E0DFC");
extern char R_s19a_dat_800E0E00[] __asm__("s19a_dat_800E0E00");
int G_s19a_800D65D4(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s19a_800D65D4");
int G_s19a_800D65D4(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[3] = 0;
    r[2] = 0;
    r[2] = *(int *)((u)r[2] + (int)R_s19a_dat_800E0DF8);
    r[3] = (u)r[3] + (int)R_s19a_dat_800E0CC8;
    *(int *)((u)r[3] + 40) = r[2];
    r[2] = 0;
    r[4] = *(int *)((u)r[2] + (int)R_s19a_dat_800E0DFC);
    r[2] = 0;
    r[8] = (u)r[2] + (int)R_s19a_dat_800E0E00;
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
