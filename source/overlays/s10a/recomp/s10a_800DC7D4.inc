extern char R_s10a_dat_800E4280[] __asm__("s10a_dat_800E4280");
extern char R_s10a_dat_800E4B20[] __asm__("s10a_dat_800E4B20");
int G_s10a_800DC7D4(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s10a_800DC7D4");
int G_s10a_800DC7D4(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(0)
    r[2] = 0;
    r[3] = 0;
    r[9] = (u)r[3] + (int)R_s10a_dat_800E4280;
    r[8] = (u)r[2] + (int)R_s10a_dat_800E4B20;
    r[6] = LWL(((u)r[9] + 3), r[6]);
    r[6] = LWR(((u)r[9] + 0), r[6]);
    r[7] = *(signed char *)((u)r[9] + 4);
    SWL(((u)r[8] + 3), r[6]);
    SWR(((u)r[8] + 0), r[6]);
    *(char *)((u)r[8] + 4) = r[7];
    r[6] = *(signed char *)((u)r[9] + 5);
    *(char *)((u)r[8] + 5) = r[6];
    r[2] = (u)r[2] + (int)R_s10a_dat_800E4B20;
    *(int *)((u)r[4] + 1936) = r[2];
    r[4] = (u)r[4] + 1936;
    r[5] = (u)0 + 31;
    r[3] = (u)0 + 191;
    r[2] = (u)0 + 95;
    *(char *)((u)r[4] + 6) = r[2];
    *(char *)((u)r[4] + 9) = r[2];
    r[2] = (u)0 + 1;
    *(char *)((u)r[4] + 4) = r[5];
    *(char *)((u)r[4] + 5) = r[3];
    *(char *)((u)r[4] + 7) = r[5];
    *(char *)((u)r[4] + 8) = r[3];
    *(short *)((u)r[4] + 10) = r[2]; goto out;
out:
    RECOMP_RETURN;
}
