extern char R_s08b_dword_800E3AE8[] __asm__("s08b_dword_800E3AE8");
extern char R_s08b_bunsin2_800D0688[] __asm__("s08b_bunsin2_800D0688");
extern char R_s08b_bunsin2_800D1014[] __asm__("s08b_bunsin2_800D1014");
extern char R_s08b_bunsin2_800D10C4[] __asm__("s08b_bunsin2_800D10C4");
extern char R_s08b_bunsin2_800D1138[] __asm__("s08b_bunsin2_800D1138");
extern char R_s08b_bunsin2_800D11A8[] __asm__("s08b_bunsin2_800D11A8");
extern char R_s08b_bunsin2_800D1218[] __asm__("s08b_bunsin2_800D1218");
extern char R_s08b_bunsin2_800D125C[] __asm__("s08b_bunsin2_800D125C");
extern char R_s08b_bunsin2_800D12A0[] __asm__("s08b_bunsin2_800D12A0");
int G_s08b_bunsin2_800D42D8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s08b_bunsin2_800D42D8");
int G_s08b_bunsin2_800D42D8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 20) = r[31];
    r[2] = *(int *)((u)r[16] + 6604);
    r[3] = (u)r[2] + -13;
    r[2] = (u)r[3] < (u)11;
    c = ((r[2] == 0)); r[2] = 0; if (c) goto L800d43c4;
    r[2] = (u)r[2] + (int)R_s08b_dword_800E3AE8;
    r[3] = (u)r[3] << 2;
    r[3] = (u)r[3] + (u)r[2];
    r[2] = *(int *)((u)r[3] + 0);
    t = r[2];  switch ((u)t) { case 0x800d431c: goto L800d431c; case 0x800d432c: goto L800d432c; case 0x800d433c: goto L800d433c; case 0x800d434c: goto L800d434c; case 0x800d435c: goto L800d435c; case 0x800d436c: goto L800d436c; case 0x800d437c: goto L800d437c; case 0x800d43a0: goto L800d43a0; case 0x800d43c4: goto L800d43c4; default: goto out; }
    L800d431c:;
    r[4] = (u)r[16] + (u)0; CALL(R_s08b_bunsin2_800D1014);
     goto L800d4384;
    L800d432c:;
    r[4] = (u)r[16] + (u)0; CALL(R_s08b_bunsin2_800D10C4);
     goto L800d4384;
    L800d433c:;
    r[4] = (u)r[16] + (u)0; CALL(R_s08b_bunsin2_800D1138);
     goto L800d4384;
    L800d434c:;
    r[4] = (u)r[16] + (u)0; CALL(R_s08b_bunsin2_800D11A8);
     goto L800d4384;
    L800d435c:;
    r[4] = (u)r[16] + (u)0; CALL(R_s08b_bunsin2_800D1218);
     goto L800d4384;
    L800d436c:;
    r[4] = (u)r[16] + (u)0; CALL(R_s08b_bunsin2_800D125C);
     goto L800d4384;
    L800d437c:;
    r[4] = (u)r[16] + (u)0; CALL(R_s08b_bunsin2_800D12A0);
    L800d4384:;
    c = ((r[2] == 0)); r[2] = (u)0 + -1; if (c) goto L800d43c4;
    *(int *)((u)r[16] + 6576) = r[2];
    r[2] = (u)0 + 23;
    *(int *)((u)r[16] + 6604) = r[2];
    *(int *)((u)r[16] + 6608) = 0; goto L800d43c4;
    L800d43a0:;
    r[4] = (u)r[16] + (u)0; CALL(R_s08b_bunsin2_800D0688);
    r[2] = (int)r[2] < 6;
    c = ((r[2] != 0)); r[2] = (u)0 + 8; if (c) goto L800d43c0;
    *(int *)((u)r[16] + 6608) = 0;
    r[2] = (u)0 + 1; goto L800d43c8;
    L800d43c0:;
    *(int *)((u)r[16] + 6576) = r[2];
    L800d43c4:;
    r[2] = (u)0 + (u)0;
    L800d43c8:;
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
