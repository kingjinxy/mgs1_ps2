extern char R_s08b_dword_800E3C28[] __asm__("s08b_dword_800E3C28");
extern char R_s08b_bunsin2_800D4984[] __asm__("s08b_bunsin2_800D4984");
extern char R_s08b_bunsin2_800D4A34[] __asm__("s08b_bunsin2_800D4A34");
extern char R_s08b_bunsin2_800D4AF4[] __asm__("s08b_bunsin2_800D4AF4");
extern char R_s08b_bunsin2_800D4BD4[] __asm__("s08b_bunsin2_800D4BD4");
extern char R_s08b_bunsin2_800D4C84[] __asm__("s08b_bunsin2_800D4C84");
extern char R_s08b_bunsin2_800D4D18[] __asm__("s08b_bunsin2_800D4D18");
extern char R_s08b_bunsin2_800D4DA8[] __asm__("s08b_bunsin2_800D4DA8");
extern char R_s08b_bunsin2_800D4E3C[] __asm__("s08b_bunsin2_800D4E3C");
int G_s08b_bunsin2_800D4ED0(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s08b_bunsin2_800D4ED0");
int G_s08b_bunsin2_800D4ED0(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 20) = r[31];
    r[3] = *(int *)((u)r[16] + 6596);
    r[2] = (u)0 + -1;
    *(int *)((u)r[16] + 6580) = r[2];
    *(int *)((u)r[16] + 6576) = r[2];
    *(int *)((u)r[16] + 6592) = 0;
    *(int *)((u)r[16] + 6664) = 0;
    *(int *)((u)r[16] + 6944) = r[2];
    r[2] = (u)r[3] < (u)8;
    c = ((r[2] == 0)); r[2] = 0; if (c) goto L800d4f9c;
    r[2] = (u)r[2] + (int)R_s08b_dword_800E3C28;
    r[3] = (u)r[3] << 2;
    r[3] = (u)r[3] + (u)r[2];
    r[2] = *(int *)((u)r[3] + 0);
    t = r[2];  switch ((u)t) { case 0x800d4f24: goto L800d4f24; case 0x800d4f34: goto L800d4f34; case 0x800d4f44: goto L800d4f44; case 0x800d4f54: goto L800d4f54; case 0x800d4f64: goto L800d4f64; case 0x800d4f74: goto L800d4f74; case 0x800d4f84: goto L800d4f84; case 0x800d4f94: goto L800d4f94; default: goto out; }
    L800d4f24:;
    r[4] = (u)r[16] + (u)0; CALL(R_s08b_bunsin2_800D4984);
     goto L800d4f9c;
    L800d4f34:;
    r[4] = (u)r[16] + (u)0; CALL(R_s08b_bunsin2_800D4A34);
     goto L800d4f9c;
    L800d4f44:;
    r[4] = (u)r[16] + (u)0; CALL(R_s08b_bunsin2_800D4AF4);
     goto L800d4f9c;
    L800d4f54:;
    r[4] = (u)r[16] + (u)0; CALL(R_s08b_bunsin2_800D4BD4);
     goto L800d4f9c;
    L800d4f64:;
    r[4] = (u)r[16] + (u)0; CALL(R_s08b_bunsin2_800D4C84);
     goto L800d4f9c;
    L800d4f74:;
    r[4] = (u)r[16] + (u)0; CALL(R_s08b_bunsin2_800D4D18);
     goto L800d4f9c;
    L800d4f84:;
    r[4] = (u)r[16] + (u)0; CALL(R_s08b_bunsin2_800D4DA8);
     goto L800d4f9c;
    L800d4f94:;
    r[4] = (u)r[16] + (u)0; CALL(R_s08b_bunsin2_800D4E3C);
    L800d4f9c:;
    r[2] = *(int *)((u)r[16] + 6612);
    r[2] = (u)r[2] + 1;
    *(int *)((u)r[16] + 6612) = r[2];
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    return r[2];
}
