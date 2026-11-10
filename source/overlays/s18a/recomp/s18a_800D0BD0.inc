extern char R_s18a_dat_800E32FC[] __asm__("s18a_dat_800E32FC");
extern char R_s18a_800CFFB8[] __asm__("s18a_800CFFB8");
extern char R_s18a_800D0114[] __asm__("s18a_800D0114");
extern char R_s18a_800D0254[] __asm__("s18a_800D0254");
extern char R_s18a_800D04E8[] __asm__("s18a_800D04E8");
extern char R_s18a_800D063C[] __asm__("s18a_800D063C");
extern char R_s18a_800D07F0[] __asm__("s18a_800D07F0");
int G_s18a_800D0BD0(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s18a_800D0BD0");
int G_s18a_800D0BD0(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[31];
    r[2] = *(int *)((u)r[4] + 2400);
    r[3] = (u)r[2] + -1;
    r[2] = (u)r[3] < (u)6;
    c = ((r[2] == 0)); r[2] = 0; if (c) goto L800d0c64;
    r[2] = (u)r[2] + (int)R_s18a_dat_800E32FC;
    r[3] = (u)r[3] << 2;
    r[3] = (u)r[3] + (u)r[2];
    r[2] = *(int *)((u)r[3] + 0);
    t = r[2];  switch ((u)t) { case 0x800d0c0c: goto L800d0c0c; case 0x800d0c1c: goto L800d0c1c; case 0x800d0c2c: goto L800d0c2c; case 0x800d0c3c: goto L800d0c3c; case 0x800d0c4c: goto L800d0c4c; case 0x800d0c5c: goto L800d0c5c; default: goto out; }
    L800d0c0c:;
     CALL(R_s18a_800CFFB8);
     goto L800d0c64;
    L800d0c1c:;
     CALL(R_s18a_800D04E8);
     goto L800d0c64;
    L800d0c2c:;
     CALL(R_s18a_800D0254);
     goto L800d0c64;
    L800d0c3c:;
     CALL(R_s18a_800D07F0);
     goto L800d0c64;
    L800d0c4c:;
     CALL(R_s18a_800D063C);
     goto L800d0c64;
    L800d0c5c:;
     CALL(R_s18a_800D0114);
    L800d0c64:;
    r[31] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
