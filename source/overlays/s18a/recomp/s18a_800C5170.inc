int G_s18a_800C5170(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s18a_800C5170");
int G_s18a_800C5170(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[9] = *(int *)((u)r[29] + 16);
    r[8] = (u)0 + (u)0;
    L800c5178:;
    r[2] = *(short *)((u)r[6] + 0);
    r[3] = *(short *)((u)r[5] + 0);
    r[2] = (u)r[2] - (u)r[3];
    if (r[7]) { lo_ = (int)r[2] / (int)r[7]; hi_ = (int)r[2] % (int)r[7]; }
    c = ((r[7] != 0));  if (c) goto L800c5198;
    L800c5198:;
    r[1] = (u)0 + -1;
    c = ((r[7] != r[1])); r[1] = 0; if (c) goto L800c51b0;
    c = ((r[2] != r[1]));  if (c) goto L800c51b0;
    L800c51b0:;
    r[2] = lo_;
    mul = (long long)(int)r[2] * (int)r[9]; hi_ = mul >> 32; lo_ = mul;
    r[6] = (u)r[6] + 2;
    r[8] = (u)r[8] + 1;
    r[2] = *(unsigned short *)((u)r[5] + 0);
    r[5] = (u)r[5] + 2;
    r[3] = lo_;
    r[2] = (u)r[2] + (u)r[3];
    *(short *)((u)r[4] + 0) = r[2];
    r[2] = (int)r[8] < 3;
    c = ((r[2] != 0)); r[4] = (u)r[4] + 2; if (c) goto L800c5178;
     goto out;
out:
    RECOMP_RETURN;
}
