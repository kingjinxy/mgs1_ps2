extern char R_s15a_dat_800D9278[] __asm__("s15a_dat_800D9278");
int G_s15a_800D07D8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s15a_800D07D8");
int G_s15a_800D07D8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[9] = (u)0 + (u)0;
    r[2] = 0;
    r[8] = (u)r[2] + (int)R_s15a_dat_800D9278;
    r[7] = (u)r[4] + (u)0;
    L800d07e8:;
    r[2] = *(int *)((u)r[4] + 16160);
    c = (((int)r[2] <= 0));  if (c) goto L800d0854;
    r[2] = *(short *)((u)r[7] + 16256);
    r[3] = *(short *)((u)r[5] + 0);
    r[2] = (u)r[2] - (u)r[6];
    r[2] = (int)r[2] < (int)r[3];
    c = ((r[2] == 0));  if (c) goto L800d0868;
    r[2] = *(short *)((u)r[7] + 16260);
    r[2] = (u)r[2] + (u)r[6];
    r[2] = (int)r[3] < (int)r[2];
    c = ((r[2] == 0));  if (c) goto L800d0868;
    r[2] = *(short *)((u)r[7] + 16258);
    r[3] = *(short *)((u)r[5] + 4);
    r[2] = (u)r[2] - (u)r[6];
    r[2] = (int)r[2] < (int)r[3];
    c = ((r[2] == 0));  if (c) goto L800d0868;
    r[2] = *(short *)((u)r[7] + 16262);
    r[2] = (u)r[2] + (u)r[6];
    r[2] = (int)r[3] < (int)r[2]; goto L800d0858;
    L800d0854:;
    r[2] = *(int *)((u)r[4] + 16144);
    L800d0858:;
    c = ((r[2] == 0));  if (c) goto L800d0868;
    *(int *)((u)r[4] + 16176) = 0;
    L800d0868:;
    r[2] = *(int *)((u)r[4] + 16176);
    r[4] = (u)r[4] + 4;
    r[7] = (u)r[7] + 8;
    r[9] = (u)r[9] + 1;
    *(int *)((u)r[8] + 0) = r[2];
    r[2] = (int)r[9] < 4;
    c = ((r[2] != 0)); r[8] = (u)r[8] + 4; if (c) goto L800d07e8;
     goto out;
out:
    RECOMP_RETURN;
}
