int G_s19a_800C4320(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s19a_800C4320");
int G_s19a_800C4320(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[2] = *(int *)((u)r[4] + 72);
    mul = (long long)(int)r[2] * (int)r[6]; hi_ = mul >> 32; lo_ = mul;
    r[3] = lo_;
    if (r[7]) { lo_ = (int)r[3] / (int)r[7]; hi_ = (int)r[3] % (int)r[7]; }
    c = ((r[7] != 0));  if (c) goto L800c4348;
    L800c4348:;
    r[1] = (u)0 + -1;
    c = ((r[7] != r[1])); r[1] = 0; if (c) goto L800c4360;
    c = ((r[3] != r[1]));  if (c) goto L800c4360;
    L800c4360:;
    r[8] = lo_;
    r[6] = (u)r[6] + 1;
    mul = (long long)(int)r[2] * (int)r[6]; hi_ = mul >> 32; lo_ = mul;
    r[2] = lo_;
    if (r[7]) { lo_ = (int)r[2] / (int)r[7]; hi_ = (int)r[2] % (int)r[7]; }
    c = ((r[7] != 0));  if (c) goto L800c438c;
    L800c438c:;
    r[1] = (u)0 + -1;
    c = ((r[7] != r[1])); r[1] = 0; if (c) goto L800c43a4;
    c = ((r[2] != r[1]));  if (c) goto L800c43a4;
    L800c43a4:;
    r[7] = lo_;
    r[3] = *(int *)((u)r[4] + 68);
    r[2] = *(int *)((u)r[4] + 76);
    r[4] = *(int *)((u)r[4] + 80);
    *(char *)((u)r[5] + 13) = r[2];
    *(char *)((u)r[5] + 21) = r[2];
    r[2] = (u)r[2] + (u)r[4];
    *(char *)((u)r[5] + 29) = r[2];
    *(char *)((u)r[5] + 37) = r[2];
    r[8] = (u)r[3] + (u)r[8];
    *(char *)((u)r[5] + 12) = r[8];
    *(char *)((u)r[5] + 28) = r[8];
    r[3] = (u)r[3] + (u)r[7];
    *(char *)((u)r[5] + 20) = r[3];
    *(char *)((u)r[5] + 36) = r[3]; goto out;
out:
    RECOMP_RETURN;
}
