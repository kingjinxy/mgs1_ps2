extern char R_s19b_dword_800C3A14[] __asm__("s19b_dword_800C3A14");
extern char R_s19b_dword_800C3A18[] __asm__("s19b_dword_800C3A18");
extern char R_s19b_jlamp2_800D55E8[] __asm__("s19b_jlamp2_800D55E8");
extern char R_GV_RandS[] __asm__("GV_RandS");
extern char R_NewPadVibration[] __asm__("NewPadVibration");
extern char R_s19b_jlamp2_800D50F4[] __asm__("s19b_jlamp2_800D50F4");
int G_s19b_jlamp2_800D519C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s19b_jlamp2_800D519C");
int G_s19b_jlamp2_800D519C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[16];
    *(int *)((u)r[29] + 20) = r[31];
    r[16] = (u)r[4] + (u)0; CALL(R_s19b_jlamp2_800D50F4);
    c = ((r[2] == 0)); r[4] = (u)0 + 512; if (c) goto L800d51d0;
    r[3] = *(int *)((u)r[16] + 2320);
    r[2] = (u)0 + 1;
    *(short *)((u)r[3] + 0) = r[2];
    r[2] = (u)0 + 4;
    *(int *)((u)r[16] + 2372) = r[2]; goto L800d5234;
    L800d51d0:;
    r[2] = *(int *)((u)r[16] + 2372);
    c = ((r[2] == 0));  if (c) goto L800d51e8;
    L800d51e0:;
    r[2] = (u)0 + (u)0; goto L800d5250;
    L800d51e8:;
    r[2] = *(int *)((u)r[16] + 2348);
    r[2] = r[2] & 8;
    c = ((r[2] == 0)); r[4] = 0; if (c) goto L800d51e0;
    r[4] = (u)r[4] + (int)R_s19b_dword_800C3A14;
    r[5] = (u)0 + 1;
    r[2] = 0;
    r[2] = (u)r[2] + (int)R_s19b_jlamp2_800D55E8;
    *(int *)((u)r[16] + 2328) = r[2];
    *(int *)((u)r[16] + 2336) = 0;
    *(short *)((u)r[16] + 120) = 0;
    *(short *)((u)r[16] + 116) = 0; CALL(R_NewPadVibration);
    r[4] = 0;
    r[4] = (u)r[4] + (int)R_s19b_dword_800C3A18;
    r[5] = (u)0 + 2; CALL(R_NewPadVibration);
    r[4] = (u)0 + 256;
    L800d5234:;
     CALL(R_GV_RandS);
    r[3] = *(int *)((u)r[16] + 2312);
    r[3] = (u)r[3] + (u)r[2];
    r[2] = (u)0 + 1;
    *(int *)((u)r[16] + 2312) = r[3];
    L800d5250:;
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
