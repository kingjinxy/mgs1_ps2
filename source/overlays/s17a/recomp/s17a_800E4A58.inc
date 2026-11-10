extern char R_s17a_dat_800C56E4[] __asm__("s17a_dat_800C56E4");
extern char R_GV_RandU[] __asm__("GV_RandU");
int G_s17a_800E4A58(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s17a_800E4A58");
int G_s17a_800E4A58(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    r[8] = (u)0 + (u)0;
    r[7] = 0x7fff0000;
    r[7] = r[7] | 65535;
    r[2] = 0;
    r[6] = (u)r[2] + (int)R_s17a_dat_800C56E4;
    r[4] = (u)r[8] + (u)0;
    *(int *)((u)r[29] + 20) = r[31];
    r[9] = *(short *)((u)r[5] + 0);
    r[5] = *(short *)((u)r[5] + 4);
    L800e4a88:;
    r[2] = *(short *)((u)r[6] + 0);
    r[2] = (u)r[9] - (u)r[2];
    r[2] = (int)r[2] >> 2;
    mul = (long long)(int)r[2] * (int)r[2]; hi_ = mul >> 32; lo_ = mul;
    r[2] = *(short *)((u)r[6] + 4);
    r[3] = lo_;
    r[2] = (u)r[5] - (u)r[2];
    r[2] = (int)r[2] >> 2;
    mul = (long long)(int)r[2] * (int)r[2]; hi_ = mul >> 32; lo_ = mul;
    r[11] = lo_;
    r[3] = (u)r[3] + (u)r[11];
    r[2] = (int)r[7] < (int)r[3];
    c = ((r[2] != 0));  if (c) goto L800e4acc;
    r[7] = (u)r[3] + (u)0;
    r[8] = (u)r[4] + (u)0;
    L800e4acc:;
    r[4] = (u)r[4] + 1;
    r[2] = (int)r[4] < 14;
    c = ((r[2] != 0)); r[6] = (u)r[6] + 8; if (c) goto L800e4a88;
    *(int *)((u)r[16] + 6736) = r[8];
    r[4] = (u)0 + 2; CALL(R_GV_RandU);
    r[2] = r[2] & 1;
    c = ((r[2] == 0)); r[3] = (u)0 + -1; if (c) goto L800e4af8;
    r[3] = (u)0 + 1;
    L800e4af8:;
    *(int *)((u)r[16] + 6740) = r[3];
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
