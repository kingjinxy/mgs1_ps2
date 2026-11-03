int G_s10a_800E2C5C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s10a_800E2C5C");
int G_s10a_800E2C5C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(0)
    r[6] = (u)r[4] + (u)0;
    r[2] = r[6] & 65535;
    c = ((r[2] != 0)); r[5] = r[6] & 31; if (c) goto L800e2c74;
    r[2] = (u)0 + (u)0; goto out;
    L800e2c74:;
    r[4] = 0x55550000;
    r[4] = r[4] | 21846;
    r[2] = r[6] & 992;
    r[2] = (u)r[2] >> 5;
    r[3] = r[6] & 31744;
    r[3] = (u)r[3] >> 10;
    r[2] = (u)r[5] + (u)r[2];
    r[2] = (u)r[2] + (u)r[3];
    mul = (long long)(int)r[2] * (int)r[4]; hi_ = mul >> 32; lo_ = mul;
    r[2] = (int)r[2] >> 31;
    r[4] = r[6] & 32768;
    r[7] = hi_;
    r[5] = (u)r[7] - (u)r[2];
    r[2] = (u)r[5] << 5;
    r[2] = r[5] | r[2];
    r[3] = (u)r[5] << 10;
    r[2] = r[2] | r[3];
    r[3] = r[2] | r[4];
    r[2] = r[3] & 65535;
    c = ((r[2] != 0));  if (c) goto L800e2ccc;
    r[3] = 0 | 32768;
    L800e2ccc:;
    r[2] = r[3] & 65535; goto out;
out:
    RECOMP_RETURN;
}
