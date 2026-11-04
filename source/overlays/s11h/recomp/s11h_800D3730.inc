int G_s11h_800D3730(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s11h_800D3730");
int G_s11h_800D3730(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[2] = *(short *)((u)r[4] + 0);
    r[7] = (u)r[6] + -1;
    mul = (long long)(int)r[2] * (int)r[7]; hi_ = mul >> 32; lo_ = mul;
    r[2] = *(short *)((u)r[5] + 0);
    r[3] = lo_;
    r[2] = (u)r[3] + (u)r[2];
    if (r[6]) { lo_ = (int)r[2] / (int)r[6]; hi_ = (int)r[2] % (int)r[6]; }
    c = ((r[6] != 0));  if (c) goto L800d375c;
    L800d375c:;
    r[1] = (u)0 + -1;
    c = ((r[6] != r[1])); r[1] = 0; if (c) goto L800d3774;
    c = ((r[2] != r[1]));  if (c) goto L800d3774;
    L800d3774:;
    r[2] = lo_;
    r[3] = *(short *)((u)r[4] + 2);
    mul = (long long)(int)r[3] * (int)r[7]; hi_ = mul >> 32; lo_ = mul;
    r[3] = lo_;
    *(short *)((u)r[4] + 0) = r[2];
    r[2] = *(short *)((u)r[5] + 2);
    r[2] = (u)r[3] + (u)r[2];
    if (r[6]) { lo_ = (int)r[2] / (int)r[6]; hi_ = (int)r[2] % (int)r[6]; }
    c = ((r[6] != 0));  if (c) goto L800d37a8;
    L800d37a8:;
    r[1] = (u)0 + -1;
    c = ((r[6] != r[1])); r[1] = 0; if (c) goto L800d37c0;
    c = ((r[2] != r[1]));  if (c) goto L800d37c0;
    L800d37c0:;
    r[2] = lo_;
    r[3] = *(short *)((u)r[4] + 4);
    mul = (long long)(int)r[3] * (int)r[7]; hi_ = mul >> 32; lo_ = mul;
    r[3] = lo_;
    *(short *)((u)r[4] + 2) = r[2];
    r[2] = *(short *)((u)r[5] + 4);
    r[2] = (u)r[3] + (u)r[2];
    if (r[6]) { lo_ = (int)r[2] / (int)r[6]; hi_ = (int)r[2] % (int)r[6]; }
    c = ((r[6] != 0));  if (c) goto L800d37f4;
    L800d37f4:;
    r[1] = (u)0 + -1;
    c = ((r[6] != r[1])); r[1] = 0; if (c) goto L800d380c;
    c = ((r[2] != r[1]));  if (c) goto L800d380c;
    L800d380c:;
    r[2] = lo_;
    *(short *)((u)r[4] + 4) = r[2]; goto out;
out:
    RECOMP_RETURN;
}
