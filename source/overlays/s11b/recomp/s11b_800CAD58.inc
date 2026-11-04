int G_s11b_800CAD58(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s11b_800CAD58");
int G_s11b_800CAD58(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[2] = *(short *)((u)r[4] + 0);
    r[7] = (u)r[6] + -1;
    mul = (long long)(int)r[2] * (int)r[7]; hi_ = mul >> 32; lo_ = mul;
    r[2] = *(short *)((u)r[5] + 0);
    r[3] = lo_;
    r[2] = (u)r[3] + (u)r[2];
    if (r[6]) { lo_ = (int)r[2] / (int)r[6]; hi_ = (int)r[2] % (int)r[6]; }
    c = ((r[6] != 0));  if (c) goto L800cad84;
    L800cad84:;
    r[1] = (u)0 + -1;
    c = ((r[6] != r[1])); r[1] = 0; if (c) goto L800cad9c;
    c = ((r[2] != r[1]));  if (c) goto L800cad9c;
    L800cad9c:;
    r[2] = lo_;
    r[3] = *(short *)((u)r[4] + 2);
    mul = (long long)(int)r[3] * (int)r[7]; hi_ = mul >> 32; lo_ = mul;
    r[3] = lo_;
    *(short *)((u)r[4] + 0) = r[2];
    r[2] = *(short *)((u)r[5] + 2);
    r[2] = (u)r[3] + (u)r[2];
    if (r[6]) { lo_ = (int)r[2] / (int)r[6]; hi_ = (int)r[2] % (int)r[6]; }
    c = ((r[6] != 0));  if (c) goto L800cadd0;
    L800cadd0:;
    r[1] = (u)0 + -1;
    c = ((r[6] != r[1])); r[1] = 0; if (c) goto L800cade8;
    c = ((r[2] != r[1]));  if (c) goto L800cade8;
    L800cade8:;
    r[2] = lo_;
    r[3] = *(short *)((u)r[4] + 4);
    mul = (long long)(int)r[3] * (int)r[7]; hi_ = mul >> 32; lo_ = mul;
    r[3] = lo_;
    *(short *)((u)r[4] + 2) = r[2];
    r[2] = *(short *)((u)r[5] + 4);
    r[2] = (u)r[3] + (u)r[2];
    if (r[6]) { lo_ = (int)r[2] / (int)r[6]; hi_ = (int)r[2] % (int)r[6]; }
    c = ((r[6] != 0));  if (c) goto L800cae1c;
    L800cae1c:;
    r[1] = (u)0 + -1;
    c = ((r[6] != r[1])); r[1] = 0; if (c) goto L800cae34;
    c = ((r[2] != r[1]));  if (c) goto L800cae34;
    L800cae34:;
    r[2] = lo_;
    *(short *)((u)r[4] + 4) = r[2]; goto out;
out:
    RECOMP_RETURN;
}
