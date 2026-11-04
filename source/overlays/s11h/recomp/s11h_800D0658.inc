extern char R_s11h_dat_800DB16C[] __asm__("s11h_dat_800DB16C");
extern char R_s11h_dat_800DB3D0[] __asm__("s11h_dat_800DB3D0");
int G_s11h_800D0658(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s11h_800D0658");
int G_s11h_800D0658(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[2] = 0;
    r[3] = 0;
    r[8] = (u)r[3] + (int)R_s11h_dat_800DB16C;
    r[7] = (u)r[2] + (int)R_s11h_dat_800DB3D0;
    r[5] = LWL(((u)r[8] + 3), r[5]);
    r[5] = LWR(((u)r[8] + 0), r[5]);
    r[6] = *(signed char *)((u)r[8] + 4);
    SWL(((u)r[7] + 3), r[5]);
    SWR(((u)r[7] + 0), r[5]);
    *(char *)((u)r[7] + 4) = r[6];
    r[2] = (u)r[2] + (int)R_s11h_dat_800DB3D0;
    *(int *)((u)r[4] + 2024) = r[2];
    r[4] = (u)r[4] + 2024;
    r[2] = (u)0 + 16;
    *(char *)((u)r[4] + 4) = r[2];
    r[2] = (u)0 + 111;
    *(char *)((u)r[4] + 5) = r[2];
    r[2] = (u)0 + 159;
    *(char *)((u)r[4] + 6) = r[2];
    r[2] = (u)0 + 31;
    *(char *)((u)r[4] + 7) = r[2];
    r[2] = (u)0 + 223;
    *(char *)((u)r[4] + 8) = r[2];
    r[2] = (u)0 + 127;
    *(char *)((u)r[4] + 9) = r[2]; goto out;
out:
    RECOMP_RETURN;
}
