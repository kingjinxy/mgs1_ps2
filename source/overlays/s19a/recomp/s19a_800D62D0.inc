extern char R_s19a_dat_800E0CE8[] __asm__("s19a_dat_800E0CE8");
extern char R_s19a_800D3DD8[] __asm__("s19a_800D3DD8");
extern char R_s19a_800D59B8[] __asm__("s19a_800D59B8");
extern char R_s19a_800D5AB0[] __asm__("s19a_800D5AB0");
extern char R_s19a_800D5CB4[] __asm__("s19a_800D5CB4");
extern char R_s19a_800D5DAC[] __asm__("s19a_800D5DAC");
int G_s19a_800D62D0(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s19a_800D62D0");
int G_s19a_800D62D0(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 20) = r[31];
    r[3] = *(short *)((u)r[16] + 2850);
    r[2] = (u)0 + 8;
    c = ((r[3] == r[2])); r[2] = (int)r[3] < 9; if (c) goto L800d6324;
    c = ((r[2] == 0)); r[2] = (u)0 + 7; if (c) goto L800d6308;
    c = ((r[3] == r[2])); r[2] = 0; if (c) goto L800d6354;
     goto L800d6360;
    L800d6308:;
    r[2] = (u)0 + 9;
    c = ((r[3] == r[2])); r[2] = (u)0 + 10; if (c) goto L800d6334;
    c = ((r[3] == r[2])); r[2] = 0; if (c) goto L800d6344;
     goto L800d6360;
    L800d6324:;
    r[4] = (u)r[16] + (u)0; CALL(R_s19a_800D5CB4);
    r[2] = 0; goto L800d6360;
    L800d6334:;
    r[4] = (u)r[16] + (u)0; CALL(R_s19a_800D5AB0);
    r[2] = 0; goto L800d6360;
    L800d6344:;
    r[4] = (u)r[16] + (u)0; CALL(R_s19a_800D5DAC);
    r[2] = 0; goto L800d6360;
    L800d6354:;
    r[4] = (u)r[16] + (u)0; CALL(R_s19a_800D59B8);
    r[2] = 0;
    L800d6360:;
    r[3] = *(int *)((u)r[2] + (int)R_s19a_dat_800E0CE8);
    r[2] = (u)0 + 1;
    c = ((r[3] == r[2]));  if (c) goto L800d6378;
    r[4] = (u)r[16] + (u)0; CALL(R_s19a_800D3DD8);
    L800d6378:;
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
