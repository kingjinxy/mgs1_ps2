extern char R_GM_CurrentMap[] __asm__("GM_CurrentMap");
extern char R_s18a_dat_800E42F4[] __asm__("s18a_dat_800E42F4");
extern char R_s18a_dat_800E42F6[] __asm__("s18a_dat_800E42F6");
extern char R_s18a_800D3AA0[] __asm__("s18a_800D3AA0");
extern char R_s18a_800D3C3C[] __asm__("s18a_800D3C3C");
extern char R_s18a_800D3C94[] __asm__("s18a_800D3C94");
int G_s18a_800D3D14(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s18a_800D3D14");
int G_s18a_800D3D14(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(48)
    r[29] = (u)r[29] + -48;
    *(int *)((u)r[29] + 32) = r[16];
    r[16] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 44) = r[31];
    *(int *)((u)r[29] + 40) = r[18];
    *(int *)((u)r[29] + 36) = r[17]; CALL(R_s18a_800D3C3C);
    r[17] = (u)r[2] + (u)0;
    c = ((r[17] == 0)); r[2] = 0; if (c) goto L800d3ddc;
    r[2] = *(short *)((u)r[2] + (int)R_s18a_dat_800E42F6);
    r[2] = (int)r[2] < 128;
    c = ((r[2] == 0)); r[2] = (u)0 + 1; if (c) goto L800d3ddc;
    c = ((r[17] != r[2]));  if (c) goto L800d3d6c;
    r[2] = *(int *)((u)r[16] + 36);
    r[2] = *(int *)((u)r[2] + 0);
    r[18] = (u)r[2] + 1176; goto L800d3d80;
    L800d3d6c:;
    r[2] = *(int *)((u)r[16] + 36);
    r[2] = *(int *)((u)r[2] + 0);
    r[18] = (u)r[2] + 1452;
    L800d3d80:;
    r[4] = (u)r[16] + (u)0; CALL(R_s18a_800D3C94);
    r[2] = *(int *)((u)r[16] + 32);
    r[3] = *(int *)((u)r[16] + 32);
    r[4] = *(int *)((u)r[16] + 40);
    r[2] = *(int *)((u)r[2] + 44);
    r[6] = *(short *)((u)r[3] + 120);
    r[5] = *(int *)((u)r[2] + 0);
    *(int *)((u)r[29] + 16) = r[4];
    r[2] = *(int *)((u)r[16] + 32);
    r[2] = *(short *)((u)r[2] + 10);
    r[4] = (u)r[18] + (u)0;
    *(int *)((u)r[29] + 20) = r[2];
    r[2] = 0;
    *(int *)((u)r[2] + (int)R_GM_CurrentMap) = r[5];
    r[2] = 0;
    r[5] = (u)r[17] + (u)0;
    r[7] = *(short *)((u)r[2] + (int)R_s18a_dat_800E42F4);
    r[3] = *(int *)((u)r[16] + 48);
    r[7] = (u)r[7] + -1;
    *(int *)((u)r[29] + 24) = r[3]; CALL(R_s18a_800D3AA0);
    L800d3ddc:;
    r[31] = *(int *)((u)r[29] + 44);
    r[18] = *(int *)((u)r[29] + 40);
    r[17] = *(int *)((u)r[29] + 36);
    r[16] = *(int *)((u)r[29] + 32);
    r[29] = (u)r[29] + 48; goto out;
out:
    RECOMP_RETURN;
}
int G_s18a_rc_800D3DF4(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s18a_rc_800D3DF4");
int G_s18a_rc_800D3DF4(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
     goto out;
out:
    RECOMP_RETURN;
}
