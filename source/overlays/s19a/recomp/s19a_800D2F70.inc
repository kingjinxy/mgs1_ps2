extern char R_s19a_dat_800E0CBA[] __asm__("s19a_dat_800E0CBA");
extern char R_s19a_800D2E88[] __asm__("s19a_800D2E88");
int G_s19a_800D2F70(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s19a_800D2F70");
int G_s19a_800D2F70(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[2] = 0;
    r[2] = *(short *)((u)r[2] + (int)R_s19a_dat_800E0CBA);
    r[29] = (u)r[29] + -24;
    c = (((int)r[2] <= 0)); *(int *)((u)r[29] + 16) = r[31]; if (c) goto L800d2f94;
     CALL(R_s19a_800D2E88);
     goto L800d2f98;
    L800d2f94:;
    r[2] = (u)0 + (u)0;
    L800d2f98:;
    r[31] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
