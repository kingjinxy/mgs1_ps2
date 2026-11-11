extern char R_s19a_dat_800E0DF4[] __asm__("s19a_dat_800E0DF4");
extern char R_GM_ConfigControlAttribute[] __asm__("GM_ConfigControlAttribute");
extern char R_s19a_800CCD5C[] __asm__("s19a_800CCD5C");
int G_s19a_800CCE34(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s19a_800CCE34");
int G_s19a_800CCE34(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 20) = r[31];
    r[2] = *(int *)((u)r[16] + 3120);
    c = ((r[2] == 0)); r[2] = 0; if (c) goto L800cce7c;
    r[2] = *(int *)((u)r[2] + (int)R_s19a_dat_800E0DF4);
    c = (((int)r[2] <= 0)); r[4] = (u)r[16] + 32; if (c) goto L800cce7c;
    r[2] = (u)0 + 1;
    r[5] = (u)0 + 13;
    *(int *)((u)r[16] + 2532) = r[2]; CALL(R_GM_ConfigControlAttribute);
    *(int *)((u)r[16] + 3120) = 0;
    *(int *)((u)r[16] + 2924) = 0;
    L800cce7c:;
    r[4] = (u)r[16] + (u)0; CALL(R_s19a_800CCD5C);
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
