int G_s11h_800D3648(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s11h_800D3648");
int G_s11h_800D3648(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[2] = *(int *)((u)r[4] + 0);
    r[7] = (u)r[6] + -1;
    mul = (long long)(int)r[2] * (int)r[7]; hi_ = mul >> 32; lo_ = mul;
    r[2] = *(int *)((u)r[5] + 0);
    r[3] = lo_;
    r[2] = (u)r[3] + (u)r[2];
    if (r[6]) { lo_ = (int)r[2] / (int)r[6]; hi_ = (int)r[2] % (int)r[6]; }
    c = ((r[6] != 0));  if (c) goto L800d3674;
    L800d3674:;
    r[1] = (u)0 + -1;
    c = ((r[6] != r[1])); r[1] = 0; if (c) goto L800d368c;
    c = ((r[2] != r[1]));  if (c) goto L800d368c;
    L800d368c:;
    r[2] = lo_;
    r[3] = *(int *)((u)r[4] + 4);
    mul = (long long)(int)r[3] * (int)r[7]; hi_ = mul >> 32; lo_ = mul;
    r[3] = lo_;
    *(int *)((u)r[4] + 0) = r[2];
    r[2] = *(int *)((u)r[5] + 4);
    r[2] = (u)r[3] + (u)r[2];
    if (r[6]) { lo_ = (int)r[2] / (int)r[6]; hi_ = (int)r[2] % (int)r[6]; }
    c = ((r[6] != 0));  if (c) goto L800d36c0;
    L800d36c0:;
    r[1] = (u)0 + -1;
    c = ((r[6] != r[1])); r[1] = 0; if (c) goto L800d36d8;
    c = ((r[2] != r[1]));  if (c) goto L800d36d8;
    L800d36d8:;
    r[2] = lo_;
    r[3] = *(int *)((u)r[4] + 8);
    mul = (long long)(int)r[3] * (int)r[7]; hi_ = mul >> 32; lo_ = mul;
    r[3] = lo_;
    *(int *)((u)r[4] + 4) = r[2];
    r[2] = *(int *)((u)r[5] + 8);
    r[2] = (u)r[3] + (u)r[2];
    if (r[6]) { lo_ = (int)r[2] / (int)r[6]; hi_ = (int)r[2] % (int)r[6]; }
    c = ((r[6] != 0));  if (c) goto L800d370c;
    L800d370c:;
    r[1] = (u)0 + -1;
    c = ((r[6] != r[1])); r[1] = 0; if (c) goto L800d3724;
    c = ((r[2] != r[1]));  if (c) goto L800d3724;
    L800d3724:;
    r[2] = lo_;
    *(int *)((u)r[4] + 8) = r[2]; goto out;
out:
    RECOMP_RETURN;
}
