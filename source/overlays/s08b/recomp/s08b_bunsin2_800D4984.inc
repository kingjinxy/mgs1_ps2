extern char R_s08b_dword_800E3B88[] __asm__("s08b_dword_800E3B88");
extern char R_s08b_bunsin2_800D1CF4[] __asm__("s08b_bunsin2_800D1CF4");
extern char R_s08b_bunsin2_800D21B8[] __asm__("s08b_bunsin2_800D21B8");
extern char R_s08b_bunsin2_800D231C[] __asm__("s08b_bunsin2_800D231C");
extern char R_s08b_bunsin2_800D30E0[] __asm__("s08b_bunsin2_800D30E0");
extern char R_s08b_bunsin2_800D31EC[] __asm__("s08b_bunsin2_800D31EC");
extern char R_s08b_bunsin2_800D3BD4[] __asm__("s08b_bunsin2_800D3BD4");
extern char R_s08b_bunsin2_800D468C[] __asm__("s08b_bunsin2_800D468C");
int G_s08b_bunsin2_800D4984(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s08b_bunsin2_800D4984");
int G_s08b_bunsin2_800D4984(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[31];
    r[3] = *(int *)((u)r[4] + 6600);
    r[2] = (u)r[3] < (u)10;
    c = ((r[2] == 0)); r[2] = 0; if (c) goto L800d4a24;
    r[2] = (u)r[2] + (int)R_s08b_dword_800E3B88;
    r[3] = (u)r[3] << 2;
    r[3] = (u)r[3] + (u)r[2];
    r[2] = *(int *)((u)r[3] + 0);
    t = r[2];  switch ((u)t) { case 0x800d49bc: goto L800d49bc; case 0x800d49cc: goto L800d49cc; case 0x800d49dc: goto L800d49dc; case 0x800d49ec: goto L800d49ec; case 0x800d49fc: goto L800d49fc; case 0x800d4a0c: goto L800d4a0c; case 0x800d4a1c: goto L800d4a1c; case 0x800d4a24: goto L800d4a24; default: goto out; }
    L800d49bc:;
     CALL(R_s08b_bunsin2_800D1CF4);
     goto L800d4a24;
    L800d49cc:;
     CALL(R_s08b_bunsin2_800D31EC);
     goto L800d4a24;
    L800d49dc:;
     CALL(R_s08b_bunsin2_800D468C);
     goto L800d4a24;
    L800d49ec:;
     CALL(R_s08b_bunsin2_800D3BD4);
     goto L800d4a24;
    L800d49fc:;
     CALL(R_s08b_bunsin2_800D21B8);
     goto L800d4a24;
    L800d4a0c:;
     CALL(R_s08b_bunsin2_800D231C);
     goto L800d4a24;
    L800d4a1c:;
     CALL(R_s08b_bunsin2_800D30E0);
    L800d4a24:;
    r[31] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
