int G_s19a_800D3FC0(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s19a_800D3FC0");
int G_s19a_800D3FC0(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[5] = (u)r[4] + (u)0;
    r[2] = 0x88880000;
    r[6] = *(int *)((u)r[5] + 2856);
    r[2] = r[2] | 34953;
    mul = (long long)(int)r[6] * (int)r[2]; hi_ = mul >> 32; lo_ = mul;
    r[4] = *(signed char *)((u)r[5] + 2932);
    r[3] = (int)r[6] >> 31;
    r[7] = hi_;
    r[2] = (u)r[7] + (u)r[6];
    r[2] = (int)r[2] >> 4;
    r[3] = (u)r[2] - (u)r[3];
    r[3] = (u)r[3] + (u)r[4];
    r[2] = (u)0 + 1;
    c = ((r[3] == r[2]));  if (c) goto L800d4008;
    r[2] = (u)0 + 4;
    c = ((r[3] != r[2]));  if (c) goto L800d4014;
    L800d4008:;
    r[2] = *(int *)((u)r[5] + 2872);
    r[2] = r[2] | 2; goto L800d4034;
    L800d4014:;
    r[2] = (u)0 + 2;
    c = ((r[3] == r[2])); r[2] = (u)0 + 5; if (c) goto L800d4028;
    c = ((r[3] != r[2])); r[2] = (int)r[6] < 91; if (c) goto L800d403c;
    L800d4028:;
    r[2] = *(int *)((u)r[5] + 2872);
    r[2] = r[2] | 1;
    L800d4034:;
    *(int *)((u)r[5] + 2872) = r[2];
    r[2] = (int)r[6] < 91;
    L800d403c:;
    c = ((r[2] == 0)); r[2] = (u)0 + (u)0; if (c) goto L800d4058;
    r[3] = *(int *)((u)r[5] + 2856);
    r[3] = (u)r[3] + 1;
    *(int *)((u)r[5] + 2856) = r[3]; goto out;
    L800d4058:;
    r[2] = (u)0 + 1; goto out;
out:
    RECOMP_RETURN;
}
