extern char R_DG_ZeroVector[] __asm__("DG_ZeroVector");
extern char R_s19a_800DAA9C[] __asm__("s19a_800DAA9C");
extern char R_s19a_dat_800C38BA[] __asm__("s19a_dat_800C38BA");
extern char R_s19a_dat_800C38C4[] __asm__("s19a_dat_800C38C4");
extern char R_NewPadVibration[] __asm__("NewPadVibration");
int G_s19a_800DA798(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s19a_800DA798");
int G_s19a_800DA798(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    r[6] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 16) = r[31];
    r[3] = *(int *)((u)r[6] + 2320);
    r[2] = *(unsigned short *)((u)r[3] + 6);
    r[2] = r[2] & 4;
    c = ((r[2] != 0)); r[4] = 0; if (c) goto L800da7c8;
    r[2] = (u)0 + (u)0; goto L800da830;
    L800da7c8:;
    r[4] = (u)r[4] + ((int)R_s19a_dat_800C38BA + 6);
    r[5] = (u)0 + 1;
    r[2] = 0;
    r[10] = (u)r[2] + (int)R_DG_ZeroVector;
    r[7] = LWL(((u)r[10] + 3), r[7]);
    r[7] = LWR(((u)r[10] + 0), r[7]);
    r[8] = LWL(((u)r[10] + 7), r[8]);
    r[8] = LWR(((u)r[10] + 4), r[8]);
    SWL(((u)r[3] + 47), r[7]);
    SWR(((u)r[3] + 44), r[7]);
    SWL(((u)r[3] + 51), r[8]);
    SWR(((u)r[3] + 48), r[8]);
    r[2] = 0;
    r[2] = (u)r[2] + (int)R_s19a_800DAA9C;
    *(int *)((u)r[6] + 2328) = r[2];
    *(int *)((u)r[6] + 2336) = 0;
    *(short *)((u)r[6] + 120) = 0;
    *(short *)((u)r[6] + 116) = 0;
    *(short *)((u)r[3] + 40) = 0;
    *(short *)((u)r[3] + 6) = 0; CALL(R_NewPadVibration);
    r[4] = 0;
    r[4] = (u)r[4] + (int)R_s19a_dat_800C38C4;
    r[5] = (u)0 + 2; CALL(R_NewPadVibration);
    r[2] = (u)0 + 1;
    L800da830:;
    r[31] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
