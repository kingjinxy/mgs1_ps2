extern char R_s18a_dat_800E38E0[] __asm__("s18a_dat_800E38E0");
extern char R_GCL_GetOption[] __asm__("GCL_GetOption");
extern char R_fprintf[] __asm__("fprintf");
extern char R_s18a_800D25F0[] __asm__("s18a_800D25F0");
int G_s18a_800D26B0(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s18a_800D26B0");
int G_s18a_800D26B0(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    r[3] = (u)0 + 4;
    r[2] = (u)r[16] + 16;
    *(int *)((u)r[29] + 20) = r[31];
    L800d26c8:;
    *(int *)((u)r[2] + 3048) = 0;
    r[3] = (u)r[3] + -1;
    c = (((int)r[3] >= 0)); r[2] = (u)r[2] + -4; if (c) goto L800d26c8;
    r[4] = (u)0 + 115; CALL(R_GCL_GetOption);
    c = ((r[2] == 0)); r[4] = (u)r[2] + (u)0; if (c) goto L800d2714;
    r[5] = (u)r[16] + 3048; CALL(R_s18a_800D25F0);
    r[2] = (int)r[2] < 5;
    c = ((r[2] != 0)); r[2] = (u)0 + (u)0; if (c) goto L800d2718;
    r[4] = (u)0 + (u)0;
    r[5] = 0;
    r[5] = (u)r[5] + ((int)R_s18a_dat_800E38E0 + 64); CALL(R_fprintf);
    r[2] = (u)0 + -1; goto L800d2718;
    L800d2714:;
    r[2] = (u)0 + (u)0;
    L800d2718:;
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
