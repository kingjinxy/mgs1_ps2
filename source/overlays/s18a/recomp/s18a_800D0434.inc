extern char R_s18a_dat_800E319C[] __asm__("s18a_dat_800E319C");
extern char R_s18a_800CD4AC[] __asm__("s18a_800CD4AC");
extern char R_s18a_800CEBC4[] __asm__("s18a_800CEBC4");
extern char R_s18a_800CED40[] __asm__("s18a_800CED40");
extern char R_s18a_800CEDCC[] __asm__("s18a_800CEDCC");
extern char R_s18a_800CEF30[] __asm__("s18a_800CEF30");
extern char R_s18a_800CF138[] __asm__("s18a_800CF138");
int G_s18a_800D0434(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s18a_800D0434");
int G_s18a_800D0434(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 20) = r[31];
    r[2] = *(int *)((u)r[16] + 2404);
    r[3] = (u)r[2] + -8;
    r[2] = (u)r[3] < (u)5;
    c = ((r[2] == 0)); r[2] = 0; if (c) goto L800d04c0;
    r[2] = (u)r[2] + (int)R_s18a_dat_800E319C;
    r[3] = (u)r[3] << 2;
    r[3] = (u)r[3] + (u)r[2];
    r[2] = *(int *)((u)r[3] + 0);
    t = r[2];  switch ((u)t) { case 0x800d0478: goto L800d0478; case 0x800d0488: goto L800d0488; case 0x800d0498: goto L800d0498; case 0x800d04a8: goto L800d04a8; case 0x800d04b8: goto L800d04b8; default: goto out; }
    L800d0478:;
    r[4] = (u)r[16] + (u)0; CALL(R_s18a_800CEBC4);
     goto L800d04c0;
    L800d0488:;
    r[4] = (u)r[16] + (u)0; CALL(R_s18a_800CED40);
     goto L800d04c0;
    L800d0498:;
    r[4] = (u)r[16] + (u)0; CALL(R_s18a_800CEDCC);
     goto L800d04c0;
    L800d04a8:;
    r[4] = (u)r[16] + (u)0; CALL(R_s18a_800CEF30);
     goto L800d04c0;
    L800d04b8:;
    r[4] = (u)r[16] + (u)0; CALL(R_s18a_800CF138);
    L800d04c0:;
    r[4] = (u)r[16] + (u)0; CALL(R_s18a_800CD4AC);
    c = ((r[2] == 0));  if (c) goto L800d04d8;
    *(int *)((u)r[16] + 2428) = 0;
    *(int *)((u)r[16] + 2408) = 0;
    L800d04d8:;
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
