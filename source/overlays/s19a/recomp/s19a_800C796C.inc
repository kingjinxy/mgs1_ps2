extern char R_s19a_dat_800E0438[] __asm__("s19a_dat_800E0438");
extern char R_s19a_dat_800E04C8[] __asm__("s19a_dat_800E04C8");
extern char R_s19a_dat_800E04D0[] __asm__("s19a_dat_800E04D0");
int G_s19a_800C796C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s19a_800C796C");
int G_s19a_800C796C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[6] = 0;
    r[7] = 0;
    r[2] = *(unsigned short *)((u)r[4] + 0);
    r[8] = 0;
    *(short *)((u)r[6] + (int)R_s19a_dat_800E04D0) = r[2];
    r[6] = (u)r[6] + (int)R_s19a_dat_800E04D0;
    r[2] = *(int *)((u)r[7] + (int)R_s19a_dat_800E04C8);
    r[3] = *(unsigned short *)((u)r[4] + 2);
    r[2] = r[2] | 1;
    *(short *)((u)r[6] + 2) = r[3];
    r[3] = *(unsigned short *)((u)r[4] + 4);
    r[4] = *(int *)((u)r[8] + (int)R_s19a_dat_800E0438);
    r[2] = r[2] | r[5];
    *(int *)((u)r[7] + (int)R_s19a_dat_800E04C8) = r[2];
    c = ((r[4] != 0)); *(short *)((u)r[6] + 4) = r[3]; if (c) goto L800c79b4;
    r[2] = (u)0 + 32;
    *(int *)((u)r[8] + (int)R_s19a_dat_800E0438) = r[2];
    L800c79b4:;
     goto out;
out:
    RECOMP_RETURN;
}
