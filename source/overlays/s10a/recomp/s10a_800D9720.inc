extern char R_SquareRoot0[] __asm__("SquareRoot0");
int G_s10a_800D9720(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s10a_800D9720");
int G_s10a_800D9720(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[31];
    r[2] = *(short *)((u)r[5] + 0);
    r[3] = *(short *)((u)r[4] + 2556);
    r[2] = (u)r[2] - (u)r[3];
    r[2] = (int)r[2] >> 4;
    mul = (long long)(int)r[2] * (int)r[2]; hi_ = mul >> 32; lo_ = mul;
    r[2] = *(short *)((u)r[5] + 2);
    r[3] = *(short *)((u)r[4] + 2558);
    r[7] = lo_;
    r[2] = (u)r[2] - (u)r[3];
    r[2] = (int)r[2] >> 4;
    mul = (long long)(int)r[2] * (int)r[2]; hi_ = mul >> 32; lo_ = mul;
    r[3] = *(short *)((u)r[4] + 2560);
    r[2] = *(short *)((u)r[5] + 4);
    r[6] = lo_;
    r[2] = (u)r[2] - (u)r[3];
    r[2] = (int)r[2] >> 4;
    mul = (long long)(int)r[2] * (int)r[2]; hi_ = mul >> 32; lo_ = mul;
    r[4] = (u)r[7] + (u)r[6];
    r[3] = lo_;
    r[4] = (u)r[4] + (u)r[3]; CALL(R_SquareRoot0);
    r[31] = *(int *)((u)r[29] + 16);
    r[2] = (u)r[2] << 4;
    r[29] = (u)r[29] + 24; goto out;
out:
    return r[2];
}
