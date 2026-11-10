extern char R_s18a_dat_800E32E4[] __asm__("s18a_dat_800E32E4");
extern char R_s18a_800CCF48[] __asm__("s18a_800CCF48");
extern char R_s18a_800CFF48[] __asm__("s18a_800CFF48");
extern char R_s18a_800D00C4[] __asm__("s18a_800D00C4");
extern char R_s18a_800D01E4[] __asm__("s18a_800D01E4");
extern char R_s18a_800D0434[] __asm__("s18a_800D0434");
extern char R_s18a_800D060C[] __asm__("s18a_800D060C");
extern char R_s18a_800D06EC[] __asm__("s18a_800D06EC");
int G_s18a_800D0B1C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s18a_800D0B1C");
int G_s18a_800D0B1C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 20) = r[31];
    r[2] = *(int *)((u)r[16] + 2400);
    r[3] = (u)r[2] + -1;
    r[2] = (u)r[3] < (u)6;
    c = ((r[2] == 0)); r[2] = 0; if (c) goto L800d0bb8;
    r[2] = (u)r[2] + (int)R_s18a_dat_800E32E4;
    r[3] = (u)r[3] << 2;
    r[3] = (u)r[3] + (u)r[2];
    r[2] = *(int *)((u)r[3] + 0);
    t = r[2];  switch ((u)t) { case 0x800d0b60: goto L800d0b60; case 0x800d0b70: goto L800d0b70; case 0x800d0b80: goto L800d0b80; case 0x800d0b90: goto L800d0b90; case 0x800d0ba0: goto L800d0ba0; case 0x800d0bb0: goto L800d0bb0; default: goto out; }
    L800d0b60:;
    r[4] = (u)r[16] + (u)0; CALL(R_s18a_800CFF48);
     goto L800d0bb8;
    L800d0b70:;
    r[4] = (u)r[16] + (u)0; CALL(R_s18a_800D01E4);
     goto L800d0bb8;
    L800d0b80:;
    r[4] = (u)r[16] + (u)0; CALL(R_s18a_800D0434);
     goto L800d0bb8;
    L800d0b90:;
    r[4] = (u)r[16] + (u)0; CALL(R_s18a_800D06EC);
     goto L800d0bb8;
    L800d0ba0:;
    r[4] = (u)r[16] + (u)0; CALL(R_s18a_800D060C);
     goto L800d0bb8;
    L800d0bb0:;
    r[4] = (u)r[16] + (u)0; CALL(R_s18a_800D00C4);
    L800d0bb8:;
    r[4] = (u)r[16] + (u)0; CALL(R_s18a_800CCF48);
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
