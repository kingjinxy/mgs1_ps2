extern char R_s18a_dat_800E3314[] __asm__("s18a_dat_800E3314");
extern char R_s18a_800CD2D8[] __asm__("s18a_800CD2D8");
extern char R_s18a_800D0028[] __asm__("s18a_800D0028");
extern char R_s18a_800D0164[] __asm__("s18a_800D0164");
extern char R_s18a_800D02DC[] __asm__("s18a_800D02DC");
extern char R_s18a_800D059C[] __asm__("s18a_800D059C");
extern char R_s18a_800D066C[] __asm__("s18a_800D066C");
extern char R_s18a_800D08F4[] __asm__("s18a_800D08F4");
int G_s18a_800D0C74(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s18a_800D0C74");
int G_s18a_800D0C74(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 20) = r[31];
    r[2] = *(int *)((u)r[16] + 2400);
    r[3] = (u)r[2] + -1;
    r[2] = (u)r[3] < (u)6;
    c = ((r[2] == 0)); r[2] = 0; if (c) goto L800d0d10;
    r[2] = (u)r[2] + (int)R_s18a_dat_800E3314;
    r[3] = (u)r[3] << 2;
    r[3] = (u)r[3] + (u)r[2];
    r[2] = *(int *)((u)r[3] + 0);
    t = r[2];  switch ((u)t) { case 0x800d0cb8: goto L800d0cb8; case 0x800d0cc8: goto L800d0cc8; case 0x800d0cd8: goto L800d0cd8; case 0x800d0ce8: goto L800d0ce8; case 0x800d0cf8: goto L800d0cf8; case 0x800d0d08: goto L800d0d08; default: goto out; }
    L800d0cb8:;
    r[4] = (u)r[16] + (u)0; CALL(R_s18a_800D0028);
     goto L800d0d10;
    L800d0cc8:;
    r[4] = (u)r[16] + (u)0; CALL(R_s18a_800D059C);
     goto L800d0d10;
    L800d0cd8:;
    r[4] = (u)r[16] + (u)0; CALL(R_s18a_800D02DC);
     goto L800d0d10;
    L800d0ce8:;
    r[4] = (u)r[16] + (u)0; CALL(R_s18a_800D08F4);
     goto L800d0d10;
    L800d0cf8:;
    r[4] = (u)r[16] + (u)0; CALL(R_s18a_800D066C);
     goto L800d0d10;
    L800d0d08:;
    r[4] = (u)r[16] + (u)0; CALL(R_s18a_800D0164);
    L800d0d10:;
    r[4] = (u)r[16] + (u)0; CALL(R_s18a_800CD2D8);
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
