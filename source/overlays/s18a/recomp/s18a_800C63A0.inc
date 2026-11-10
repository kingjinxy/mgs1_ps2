extern char R_s18a_dat_800E2C9C[] __asm__("s18a_dat_800E2C9C");
extern char R_GCL_GetOption[] __asm__("GCL_GetOption");
extern char R_fprintf[] __asm__("fprintf");
extern char R_printf[] __asm__("printf");
extern char R_s18a_800C6348[] __asm__("s18a_800C6348");
int G_s18a_800C63A0(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s18a_800C63A0");
int G_s18a_800C63A0(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 20) = r[31];
    r[4] = (u)0 + 118; CALL(R_GCL_GetOption);
    c = ((r[2] == 0)); r[4] = (u)r[2] + (u)0; if (c) goto L800c6400;
    r[5] = (u)r[16] + 2540; CALL(R_s18a_800C6348);
    r[4] = 0;
    r[4] = (u)r[4] + (int)R_s18a_dat_800E2C9C;
    r[16] = (u)r[2] + (u)0;
    r[5] = (u)r[16] + (u)0; CALL(R_printf);
    r[16] = (int)r[16] < 20;
    c = ((r[16] != 0)); r[2] = (u)0 + (u)0; if (c) goto L800c6404;
    r[4] = (u)0 + (u)0;
    r[5] = 0;
    r[5] = (u)r[5] + ((int)R_s18a_dat_800E2C9C + 16); CALL(R_fprintf);
    r[2] = (u)0 + -1; goto L800c6404;
    L800c6400:;
    r[2] = (u)0 + (u)0;
    L800c6404:;
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
