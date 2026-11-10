extern char R_s18a_dat_800E3120[] __asm__("s18a_dat_800E3120");
extern char R_printf[] __asm__("printf");
int G_s18a_800CEEBC(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s18a_800CEEBC");
int G_s18a_800CEEBC(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 20) = r[31];
    r[4] = *(int *)((u)r[16] + 2476);
    r[3] = *(int *)((u)r[16] + 2480);
    r[2] = (u)0 + 12;
    *(int *)((u)r[16] + 2384) = r[2];
    r[3] = (int)r[3] < 2000;
    c = ((r[3] == 0)); *(int *)((u)r[16] + 2388) = r[4]; if (c) goto L800cef10;
    r[4] = 0;
    r[4] = (u)r[4] + ((int)R_s18a_dat_800E3120 + 12); CALL(R_printf);
    r[2] = (u)0 + 5;
    *(int *)((u)r[16] + 2400) = r[2];
    r[2] = (u)0 + 19;
    *(int *)((u)r[16] + 2404) = r[2];
    *(int *)((u)r[16] + 2428) = 0;
    *(int *)((u)r[16] + 2408) = 0; goto L800cef20;
    L800cef10:;
    r[2] = *(int *)((u)r[16] + 2408);
    r[2] = (u)r[2] + 1;
    *(int *)((u)r[16] + 2408) = r[2];
    L800cef20:;
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
