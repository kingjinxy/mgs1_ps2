extern char R_s19a_dat_800C3310[] __asm__("s19a_dat_800C3310");
extern char R_s19a_dat_800C3314[] __asm__("s19a_dat_800C3314");
extern char R_NewPadVibration[] __asm__("NewPadVibration");
int G_s19a_800C5638(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s19a_800C5638");
int G_s19a_800C5638(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 20) = r[31];
    r[2] = *(int *)((u)r[16] + 704);
    c = (((int)r[2] <= 0)); r[4] = 0; if (c) goto L800c5688;
    r[4] = (u)r[4] + (int)R_s19a_dat_800C3310;
    r[5] = (u)0 + 1; CALL(R_NewPadVibration);
    r[4] = 0;
    r[4] = (u)r[4] + (int)R_s19a_dat_800C3314;
    r[5] = (u)0 + 2; CALL(R_NewPadVibration);
    r[2] = *(int *)((u)r[16] + 704);
    r[2] = (u)r[2] + -1;
    *(int *)((u)r[16] + 704) = r[2]; goto L800c568c;
    L800c5688:;
    *(int *)((u)r[16] + 704) = 0;
    L800c568c:;
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
