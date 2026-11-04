int G_s15a_800D0470(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s15a_800D0470");
int G_s15a_800D0470(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[2] = *(short *)((u)r[4] + 0);
    r[7] = (u)r[6] + -1;
    mul = (long long)(int)r[2] * (int)r[7]; hi_ = mul >> 32; lo_ = mul;
    r[2] = *(short *)((u)r[5] + 0);
    r[3] = lo_;
    r[2] = (u)r[3] + (u)r[2];
    if (r[6]) { lo_ = (int)r[2] / (int)r[6]; hi_ = (int)r[2] % (int)r[6]; }
    c = ((r[6] != 0));  if (c) goto L800d049c;
    L800d049c:;
    r[1] = (u)0 + -1;
    c = ((r[6] != r[1])); r[1] = 0; if (c) goto L800d04b4;
    c = ((r[2] != r[1]));  if (c) goto L800d04b4;
    L800d04b4:;
    r[2] = lo_;
    r[3] = *(short *)((u)r[4] + 2);
    mul = (long long)(int)r[3] * (int)r[7]; hi_ = mul >> 32; lo_ = mul;
    r[3] = lo_;
    *(short *)((u)r[4] + 0) = r[2];
    r[2] = *(short *)((u)r[5] + 2);
    r[2] = (u)r[3] + (u)r[2];
    if (r[6]) { lo_ = (int)r[2] / (int)r[6]; hi_ = (int)r[2] % (int)r[6]; }
    c = ((r[6] != 0));  if (c) goto L800d04e8;
    L800d04e8:;
    r[1] = (u)0 + -1;
    c = ((r[6] != r[1])); r[1] = 0; if (c) goto L800d0500;
    c = ((r[2] != r[1]));  if (c) goto L800d0500;
    L800d0500:;
    r[2] = lo_;
    r[3] = *(short *)((u)r[4] + 4);
    mul = (long long)(int)r[3] * (int)r[7]; hi_ = mul >> 32; lo_ = mul;
    r[3] = lo_;
    *(short *)((u)r[4] + 2) = r[2];
    r[2] = *(short *)((u)r[5] + 4);
    r[2] = (u)r[3] + (u)r[2];
    if (r[6]) { lo_ = (int)r[2] / (int)r[6]; hi_ = (int)r[2] % (int)r[6]; }
    c = ((r[6] != 0));  if (c) goto L800d0534;
    L800d0534:;
    r[1] = (u)0 + -1;
    c = ((r[6] != r[1])); r[1] = 0; if (c) goto L800d054c;
    c = ((r[2] != r[1]));  if (c) goto L800d054c;
    L800d054c:;
    r[2] = lo_;
    *(short *)((u)r[4] + 4) = r[2]; goto out;
out:
    RECOMP_RETURN;
}
