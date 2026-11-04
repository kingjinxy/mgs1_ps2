int G_s11h_800D1DB0(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s11h_800D1DB0");
int G_s11h_800D1DB0(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[3] = *(int *)((u)r[4] + 0);
    r[2] = (u)r[7] + -1;
    mul = (long long)(int)r[3] * (int)r[2]; hi_ = mul >> 32; lo_ = mul;
    r[2] = *(int *)((u)r[5] + 0);
    r[9] = lo_;
    r[2] = (u)r[9] + (u)r[2];
    if (r[7]) { lo_ = (int)r[2] / (int)r[7]; hi_ = (int)r[2] % (int)r[7]; }
    c = ((r[7] != 0));  if (c) goto L800d1ddc;
    L800d1ddc:;
    r[1] = (u)0 + -1;
    c = ((r[7] != r[1])); r[1] = 0; if (c) goto L800d1df4;
    c = ((r[2] != r[1]));  if (c) goto L800d1df4;
    L800d1df4:;
    r[2] = lo_;
    r[3] = (u)r[3] - (u)r[2];
    *(int *)((u)r[6] + 0) = r[3];
    *(int *)((u)r[4] + 0) = r[2]; goto out;
out:
    RECOMP_RETURN;
}
