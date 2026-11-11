extern char R_s19a_dat_800E0CE8[] __asm__("s19a_dat_800E0CE8");
extern char R_s19a_800D1CB0[] __asm__("s19a_800D1CB0");
extern char R_s19a_800D1D94[] __asm__("s19a_800D1D94");
extern char R_s19a_800D1F14[] __asm__("s19a_800D1F14");
extern char R_s19a_800D203C[] __asm__("s19a_800D203C");
int G_s19a_800D20E8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s19a_800D20E8");
int G_s19a_800D20E8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 20) = r[31];
    *(char *)((u)r[16] + 2974) = 0; CALL(R_s19a_800D1D94);
    r[2] = 0;
    r[3] = *(int *)((u)r[2] + (int)R_s19a_dat_800E0CE8);
    r[2] = (u)0 + 1;
    c = ((r[3] == r[2]));  if (c) goto L800d212c;
    r[4] = (u)r[16] + (u)0; CALL(R_s19a_800D1CB0);
    r[4] = (u)r[16] + (u)0; CALL(R_s19a_800D1F14);
    r[4] = (u)r[16] + (u)0; CALL(R_s19a_800D203C);
    L800d212c:;
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
