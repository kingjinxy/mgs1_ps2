extern char R_s08b_dword_800E3C00[] __asm__("s08b_dword_800E3C00");
extern char R_s08b_bunsin2_800D1DE0[] __asm__("s08b_bunsin2_800D1DE0");
extern char R_s08b_bunsin2_800D29DC[] __asm__("s08b_bunsin2_800D29DC");
extern char R_s08b_bunsin2_800D2AB4[] __asm__("s08b_bunsin2_800D2AB4");
extern char R_s08b_bunsin2_800D2EA0[] __asm__("s08b_bunsin2_800D2EA0");
extern char R_s08b_bunsin2_800D38F0[] __asm__("s08b_bunsin2_800D38F0");
extern char R_s08b_bunsin2_800D3F5C[] __asm__("s08b_bunsin2_800D3F5C");
extern char R_s08b_bunsin2_800D44D0[] __asm__("s08b_bunsin2_800D44D0");
int G_s08b_bunsin2_800D4BD4(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s08b_bunsin2_800D4BD4");
int G_s08b_bunsin2_800D4BD4(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[31];
    r[3] = *(int *)((u)r[4] + 6600);
    r[2] = (u)r[3] < (u)10;
    c = ((r[2] == 0)); r[2] = 0; if (c) goto L800d4c74;
    r[2] = (u)r[2] + (int)R_s08b_dword_800E3C00;
    r[3] = (u)r[3] << 2;
    r[3] = (u)r[3] + (u)r[2];
    r[2] = *(int *)((u)r[3] + 0);
    t = r[2];  switch ((u)t) { case 0x800d4c0c: goto L800d4c0c; case 0x800d4c1c: goto L800d4c1c; case 0x800d4c2c: goto L800d4c2c; case 0x800d4c3c: goto L800d4c3c; case 0x800d4c4c: goto L800d4c4c; case 0x800d4c5c: goto L800d4c5c; case 0x800d4c6c: goto L800d4c6c; case 0x800d4c74: goto L800d4c74; default: goto out; }
    L800d4c0c:;
     CALL(R_s08b_bunsin2_800D1DE0);
     goto L800d4c74;
    L800d4c1c:;
     CALL(R_s08b_bunsin2_800D38F0);
     goto L800d4c74;
    L800d4c2c:;
     CALL(R_s08b_bunsin2_800D3F5C);
     goto L800d4c74;
    L800d4c3c:;
     CALL(R_s08b_bunsin2_800D44D0);
     goto L800d4c74;
    L800d4c4c:;
     CALL(R_s08b_bunsin2_800D2AB4);
     goto L800d4c74;
    L800d4c5c:;
     CALL(R_s08b_bunsin2_800D29DC);
     goto L800d4c74;
    L800d4c6c:;
     CALL(R_s08b_bunsin2_800D2EA0);
    L800d4c74:;
    r[31] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
