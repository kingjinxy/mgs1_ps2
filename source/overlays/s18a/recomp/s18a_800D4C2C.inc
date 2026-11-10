extern char R_s18a_dat_800E3A84[] __asm__("s18a_dat_800E3A84");
extern char R_GM_StreamPlayStart[] __asm__("GM_StreamPlayStart");
extern char R_GM_StreamStatus[] __asm__("GM_StreamStatus");
extern char R_GM_VoxStream[] __asm__("GM_VoxStream");
extern char R_printf[] __asm__("printf");
int G_s18a_800D4C2C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s18a_800D4C2C");
int G_s18a_800D4C2C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    r[4] = 0;
    r[5] = (u)r[5] + -16;
    r[2] = (u)r[5] << 2;
    r[2] = (u)r[16] + (u)r[2];
    *(int *)((u)r[29] + 20) = r[31];
    r[6] = *(int *)((u)r[2] + 3608);
    r[4] = (u)r[4] + ((int)R_s18a_dat_800E3A84 + 52); CALL(R_printf);
     CALL(R_GM_StreamStatus);
    r[3] = (u)0 + -1;
    c = ((r[2] != r[3]));  if (c) goto L800d4c98;
    r[2] = *(int *)((u)r[16] + 3640);
    r[2] = (u)r[2] + 1;
    *(int *)((u)r[16] + 3640) = r[2];
    r[2] = (u)r[2] << 2;
    r[2] = (u)r[16] + (u)r[2];
    r[4] = *(int *)((u)r[2] + 3608);
    r[5] = (u)0 + (u)0; CALL(R_GM_VoxStream);
     goto L800d4ca0;
    L800d4c98:;
     CALL(R_GM_StreamPlayStart);
    L800d4ca0:;
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
