extern char R_s18a_dat_800E38E0[] __asm__("s18a_dat_800E38E0");
extern char R_GCL_GetOption[] __asm__("GCL_GetOption");
extern char R_fprintf[] __asm__("fprintf");
extern char R_s18a_800D2540[] __asm__("s18a_800D2540");
int G_s18a_800D2648(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s18a_800D2648");
int G_s18a_800D2648(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    r[4] = (u)0 + 114;
    *(int *)((u)r[29] + 20) = r[31];
    *(char *)((u)r[16] + 2700) = 0;
    *(short *)((u)r[16] + 2694) = 0; CALL(R_GCL_GetOption);
    c = ((r[2] == 0)); r[4] = (u)r[2] + (u)0; if (c) goto L800d269c;
    r[5] = (u)r[16] + 2700; CALL(R_s18a_800D2540);
    r[2] = (int)r[2] < 4;
    c = ((r[2] != 0)); r[2] = (u)0 + (u)0; if (c) goto L800d26a0;
    r[4] = (u)0 + (u)0;
    r[5] = 0;
    r[5] = (u)r[5] + ((int)R_s18a_dat_800E38E0 + 24); CALL(R_fprintf);
    r[2] = (u)0 + -1; goto L800d26a0;
    L800d269c:;
    r[2] = (u)0 + (u)0;
    L800d26a0:;
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
