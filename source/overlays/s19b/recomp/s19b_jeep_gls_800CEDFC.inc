extern char R_s19b_dword_800DE5B0[] __asm__("s19b_dword_800DE5B0");
int G_s19b_jeep_gls_800CEDFC(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s19b_jeep_gls_800CEDFC");
int G_s19b_jeep_gls_800CEDFC(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[2] = 0;
    r[6] = *(int *)((u)r[2] + (int)R_s19b_dword_800DE5B0);
    r[3] = *(int *)((u)r[6] + 3180);
    r[7] = 0x10620000;
    r[2] = (u)r[3] << 1;
    r[2] = (u)r[2] + (u)r[3];
    r[2] = (u)r[2] << 2;
    r[2] = (u)r[2] - (u)r[3];
    r[2] = (u)r[2] << 2;
    r[2] = (u)r[6] + (u)r[2];
    r[2] = *(short *)((u)r[2] + 440);
    r[7] = r[7] | 19923;
    r[2] = (u)r[2] + -2000;
    r[4] = (u)r[4] - (u)r[2];
    r[4] = (u)r[4] - (u)r[5];
    mul = (long long)(int)r[4] * (int)r[7]; hi_ = mul >> 32; lo_ = mul;
    r[4] = (int)r[4] >> 31;
    r[8] = hi_;
    r[2] = (int)r[8] >> 8;
    r[2] = (u)r[2] - (u)r[4];
    r[3] = (u)r[3] + (u)r[2];
    r[3] = r[3] & 15;
    r[2] = (u)r[3] << 1;
    r[2] = (u)r[2] + (u)r[3];
    r[2] = (u)r[2] << 2;
    r[2] = (u)r[2] - (u)r[3];
    r[2] = (u)r[2] << 2;
    r[2] = (u)r[2] + (u)r[6];
    r[2] = *(int *)((u)r[2] + 476);
     goto out;
out:
    RECOMP_RETURN;
}
