int G_s15a_800CAB14(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s15a_800CAB14");
int G_s15a_800CAB14(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[2] = (int)r[4] < 2;
    c = ((r[2] == 0));  if (c) goto L800cab28;
    r[2] = (u)0 + 1;
    r[4] = (u)r[2] - (u)r[4];
    L800cab28:;
    r[2] = (u)r[4] >> 31;
    r[2] = (u)r[4] + (u)r[2];
    r[2] = (int)r[2] >> 1;
    r[2] = (u)r[2] << 1;
    r[2] = (u)r[4] - (u)r[2];
    r[2] = (u)r[2] << 1;
    r[3] = (u)0 + 1;
    r[4] = (u)r[3] - (u)r[2];
    r[2] = (u)r[5] >> 31;
    r[2] = (u)r[5] + (u)r[2];
    r[2] = (int)r[2] >> (r[3] & 31);
    r[2] = (u)r[2] << (r[3] & 31);
    r[2] = (u)r[5] - (u)r[2];
    r[2] = (u)r[2] << (r[3] & 31);
    r[5] = (u)r[3] - (u)r[2];
    mul = (long long)(int)r[4] * (int)r[5]; hi_ = mul >> 32; lo_ = mul;
    r[6] = lo_;
    r[2] = (u)r[6] + (u)r[3];
    r[3] = (u)r[2] >> 31;
    r[2] = (u)r[2] + (u)r[3];
    r[2] = (int)r[2] >> 1;
    r[2] = (u)r[2] + 2; goto out;
out:
    RECOMP_RETURN;
}
