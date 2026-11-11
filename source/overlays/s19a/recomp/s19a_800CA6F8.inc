extern char R_s19a_dat_800DFDE0[] __asm__("s19a_dat_800DFDE0");
extern char R_GCL_GetOption[] __asm__("GCL_GetOption");
extern char R_printf[] __asm__("printf");
extern char R_s19a_800CA4BC[] __asm__("s19a_800CA4BC");
int G_s19a_800CA6F8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s19a_800CA6F8");
int G_s19a_800CA6F8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    r[3] = (u)0 + 11;
    r[2] = (u)r[16] + 396;
    *(int *)((u)r[29] + 20) = r[31];
    L800ca710:;
    *(int *)((u)r[2] + 3144) = 0;
    r[3] = (u)r[3] + -1;
    c = (((int)r[3] >= 0)); r[2] = (u)r[2] + -36; if (c) goto L800ca710;
    r[4] = (u)0 + 120; CALL(R_GCL_GetOption);
    c = ((r[2] == 0)); r[4] = (u)r[2] + (u)0; if (c) goto L800ca750;
    r[5] = (u)r[16] + (u)0; CALL(R_s19a_800CA4BC);
    c = (((int)r[2] >= 0)); r[4] = 0; if (c) goto L800ca754;
    r[4] = (u)r[4] + ((int)R_s19a_dat_800DFDE0 + 80); CALL(R_printf);
    r[2] = (u)0 + -1; goto L800ca754;
    L800ca750:;
    r[2] = (u)0 + (u)0;
    L800ca754:;
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
