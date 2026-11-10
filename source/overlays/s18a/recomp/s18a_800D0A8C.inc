extern char R_s18a_dat_800E32CC[] __asm__("s18a_dat_800E32CC");
extern char R_s18a_800CFDDC[] __asm__("s18a_800CFDDC");
extern char R_s18a_800CFF18[] __asm__("s18a_800CFF18");
extern char R_s18a_800D01B4[] __asm__("s18a_800D01B4");
extern char R_s18a_800D03C0[] __asm__("s18a_800D03C0");
extern char R_s18a_800D069C[] __asm__("s18a_800D069C");
int G_s18a_800D0A8C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s18a_800D0A8C");
int G_s18a_800D0A8C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[31];
    r[3] = *(int *)((u)r[4] + 2400);
    r[2] = (u)r[3] < (u)6;
    c = ((r[2] == 0)); r[2] = 0; if (c) goto L800d0b0c;
    r[2] = (u)r[2] + (int)R_s18a_dat_800E32CC;
    r[3] = (u)r[3] << 2;
    r[3] = (u)r[3] + (u)r[2];
    r[2] = *(int *)((u)r[3] + 0);
    t = r[2];  switch ((u)t) { case 0x800d0ac4: goto L800d0ac4; case 0x800d0ad4: goto L800d0ad4; case 0x800d0ae4: goto L800d0ae4; case 0x800d0af4: goto L800d0af4; case 0x800d0b04: goto L800d0b04; case 0x800d0b0c: goto L800d0b0c; default: goto out; }
    L800d0ac4:;
     CALL(R_s18a_800CFDDC);
     goto L800d0b0c;
    L800d0ad4:;
     CALL(R_s18a_800CFF18);
     goto L800d0b0c;
    L800d0ae4:;
     CALL(R_s18a_800D03C0);
     goto L800d0b0c;
    L800d0af4:;
     CALL(R_s18a_800D01B4);
     goto L800d0b0c;
    L800d0b04:;
     CALL(R_s18a_800D069C);
    L800d0b0c:;
    r[31] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
