extern char R_linkvarbuf[] __asm__("linkvarbuf");
extern char R_s19a_dat_800E0CC8[] __asm__("s19a_dat_800E0CC8");
extern char R_s19a_dat_800E0DF4[] __asm__("s19a_dat_800E0DF4");
extern char R_s19a_800D739C[] __asm__("s19a_800D739C");
int G_s19a_800D73D8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s19a_800D73D8");
int G_s19a_800D73D8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(32)
    r[29] = (u)r[29] + -32;
    *(int *)((u)r[29] + 20) = r[17];
    r[17] = 0;
    r[3] = *(int *)((u)r[17] + (int)R_s19a_dat_800E0DF4);
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)0 + 1;
    c = ((r[3] == r[16])); *(int *)((u)r[29] + 24) = r[31]; if (c) goto L800d7438;
    r[2] = (int)r[3] < 2;
    c = ((r[2] == 0));  if (c) goto L800d7438;
    c = ((r[3] != 0)); r[3] = 0; if (c) goto L800d743c;
     CALL(R_s19a_800D739C);
    r[4] = (u)r[2] + (u)0;
    c = ((r[4] != r[16])); r[3] = 0; if (c) goto L800d743c;
    r[3] = 0;
    r[3] = (u)r[3] + (int)R_linkvarbuf;
    r[2] = *(unsigned short *)((u)r[3] + 156);
    *(int *)((u)r[17] + (int)R_s19a_dat_800E0DF4) = r[4];
    r[2] = (u)r[2] + (u)r[16];
    *(short *)((u)r[3] + 156) = r[2];
    L800d7438:;
    r[3] = 0;
    L800d743c:;
    r[3] = (u)r[3] + (int)R_s19a_dat_800E0CC8;
    r[2] = *(int *)((u)r[3] + 20);
    r[2] = (u)r[2] + 1;
    *(int *)((u)r[3] + 20) = r[2];
    r[31] = *(int *)((u)r[29] + 24);
    r[17] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 32; goto out;
out:
    RECOMP_RETURN;
}
