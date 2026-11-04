extern char R_s11h_dat_800DB33C[] __asm__("s11h_dat_800DB33C");
extern char R_s11h_dat_800DB34C[] __asm__("s11h_dat_800DB34C");
extern char R_GV_VecDir2[] __asm__("GV_VecDir2");
extern char R_SquareRoot0[] __asm__("SquareRoot0");
int G_s11h_800C51A4(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s11h_800C51A4");
int G_s11h_800C51A4(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(40)
    r[29] = (u)r[29] + -40;
    *(int *)((u)r[29] + 28) = r[17];
    r[17] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 36) = r[31];
    *(int *)((u)r[29] + 32) = r[18];
    *(int *)((u)r[29] + 24) = r[16];
    r[16] = *(short *)((u)r[17] + 10);
    mul = (long long)(int)r[16] * (int)r[16]; hi_ = mul >> 32; lo_ = mul;
    r[2] = 0x1000000;
    r[6] = lo_;
    r[4] = (u)r[2] - (u)r[6];
    c = (((int)r[4] > 0)); r[18] = (u)r[5] + (u)0; if (c) goto L800c51e0;
    r[4] = (u)0 + 1;
    L800c51e0:;
     CALL(R_SquareRoot0);
    r[4] = (u)0 - (u)r[16];
    r[3] = (u)r[4] << 3;
    r[3] = (u)r[3] + (u)r[4];
    r[3] = (u)r[3] << 3;
    r[3] = (u)r[3] - (u)r[4];
    r[3] = (u)r[3] << 2;
    r[3] = (u)r[3] + (u)r[4];
    if (r[2]) { lo_ = (int)r[3] / (int)r[2]; hi_ = (int)r[3] % (int)r[2]; }
    c = ((r[2] != 0));  if (c) goto L800c5214;
    L800c5214:;
    r[1] = (u)0 + -1;
    c = ((r[2] != r[1])); r[1] = 0; if (c) goto L800c522c;
    c = ((r[3] != r[1]));  if (c) goto L800c522c;
    L800c522c:;
    r[3] = lo_;
    *(short *)((u)r[18] + 2) = r[3];
    r[2] = *(unsigned short *)((u)r[17] + 4);
    *(short *)((u)r[29] + 16) = r[2];
    r[2] = *(unsigned short *)((u)r[17] + 16);
    r[4] = (u)r[29] + 16;
    *(short *)((u)r[29] + 20) = r[2]; CALL(R_GV_VecDir2);
    r[4] = 0;
    r[3] = *(short *)((u)r[4] + (int)R_s11h_dat_800DB33C);
    mul = (long long)(int)r[2] * (int)r[3]; hi_ = mul >> 32; lo_ = mul;
    r[5] = *(unsigned short *)((u)r[4] + (int)R_s11h_dat_800DB33C);
    r[2] = lo_;
    c = (((int)r[2] >= 0));  if (c) goto L800c5278;
    r[2] = (u)r[2] + 4095;
    L800c5278:;
    r[2] = (int)r[2] >> 12;
    r[2] = (u)r[2] + 1;
    r[4] = 0;
    r[3] = *(unsigned short *)((u)r[18] + 2);
    r[4] = *(unsigned short *)((u)r[4] + (int)R_s11h_dat_800DB34C);
    r[2] = (u)r[5] - (u)r[2];
    *(short *)((u)r[18] + 0) = r[2];
    r[3] = (u)r[3] - (u)r[4];
    *(short *)((u)r[18] + 2) = r[3];
    r[31] = *(int *)((u)r[29] + 36);
    r[18] = *(int *)((u)r[29] + 32);
    r[17] = *(int *)((u)r[29] + 28);
    r[16] = *(int *)((u)r[29] + 24);
    r[29] = (u)r[29] + 40; goto out;
out:
    RECOMP_RETURN;
}
