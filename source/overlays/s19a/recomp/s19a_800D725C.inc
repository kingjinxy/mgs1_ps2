extern char R_s19a_dat_800E0CC8[] __asm__("s19a_dat_800E0CC8");
extern char R_s19a_800D6CA4[] __asm__("s19a_800D6CA4");
extern char R_s19a_800D6FFC[] __asm__("s19a_800D6FFC");
extern char R_s19a_800D7060[] __asm__("s19a_800D7060");
int G_s19a_800D725C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s19a_800D725C");
int G_s19a_800D725C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[5] = (u)r[17] + (u)0;
    r[18] = (u)r[18] + 16;
    r[2] = *(int *)((u)r[20] + 12);
    r[17] = (u)r[17] + 1;
    r[2] = (int)r[17] < (int)r[2];
    c = ((r[2] != 0)); r[16] = (u)r[16] + 16; if (c) goto L800d7224;
    r[4] = (u)r[19] + (u)0;
    r[16] = 0;
    r[16] = (u)r[16] + (int)R_s19a_dat_800E0CC8;
    r[5] = (u)r[16] + (u)0; CALL(R_s19a_800D6FFC);
    r[4] = (u)r[16] + (u)0; CALL(R_s19a_800D7060);
    r[4] = (u)r[16] + (u)0; CALL(R_s19a_800D6CA4);
    *(int *)((u)r[16] + 272) = 0;
    r[31] = *(int *)((u)r[29] + 40);
    r[21] = *(int *)((u)r[29] + 36);
    r[20] = *(int *)((u)r[29] + 32);
    r[19] = *(int *)((u)r[29] + 28);
    r[18] = *(int *)((u)r[29] + 24);
    r[17] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 48; goto out;
    L800d7224: goto out;
out:
    RECOMP_RETURN;
}
