extern char R_s19a_dat_800C37B8[] __asm__("s19a_dat_800C37B8");
extern char R_GM_SeSet2[] __asm__("GM_SeSet2");
extern char R_s19a_800D6BE0[] __asm__("s19a_800D6BE0");
int G_s19a_800D6DF4(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s19a_800D6DF4");
int G_s19a_800D6DF4(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    r[3] = 0;
    r[2] = *(int *)((u)r[3] + (int)R_s19a_dat_800C37B8);
    r[10] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 16) = r[31];
    r[2] = (u)r[2] + -1;
    c = (((int)r[2] >= 0)); *(int *)((u)r[3] + (int)R_s19a_dat_800C37B8) = r[2]; if (c) goto L800d6e18;
    *(int *)((u)r[3] + (int)R_s19a_dat_800C37B8) = 0;
    L800d6e18:;
    r[2] = *(int *)((u)r[3] + (int)R_s19a_dat_800C37B8);
    c = (((int)r[2] > 0)); r[9] = 0x10000; if (c) goto L800d6ec8;
    r[9] = r[9] | 34464;
    r[8] = (u)0 + (u)0;
    r[2] = *(int *)((u)r[10] + 12);
    c = (((int)r[2] <= 0)); r[4] = (u)r[8] + (u)0; if (c) goto L800d6ea4;
    r[11] = (u)0 + 2;
    r[7] = (u)r[10] + (u)0;
    L800d6e48:;
    r[2] = *(int *)((u)r[7] + 148);
    c = ((r[2] != r[11]));  if (c) goto L800d6e90;
    r[3] = *(int *)((u)r[7] + 156);
    r[6] = *(short *)((u)r[3] + 2890);
    c = ((r[6] == 0));  if (c) goto L800d6e8c;
    r[5] = *(int *)((u)r[3] + 3112);
    r[2] = (int)r[5] < (int)r[9];
    c = ((r[2] == 0));  if (c) goto L800d6e8c;
    r[4] = (u)r[6] + (u)0;
    r[9] = (u)r[5] + (u)0;
    L800d6e8c:;
    *(short *)((u)r[3] + 2890) = 0;
    L800d6e90:;
    r[2] = *(int *)((u)r[10] + 12);
    r[8] = (u)r[8] + 1;
    r[2] = (int)r[8] < (int)r[2];
    c = ((r[2] != 0)); r[7] = (u)r[7] + 16; if (c) goto L800d6e48;
    L800d6ea4:;
    c = ((r[4] == 0)); r[3] = 0; if (c) goto L800d6ec8;
    r[2] = (u)0 + 30;
    *(int *)((u)r[3] + (int)R_s19a_dat_800C37B8) = r[2]; CALL(R_s19a_800D6BE0);
    r[4] = (u)0 + (u)0;
    r[5] = (u)0 + 48;
    r[6] = (u)r[2] + (u)0; CALL(R_GM_SeSet2);
    L800d6ec8:;
    r[31] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
