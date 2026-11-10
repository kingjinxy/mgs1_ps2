int G_s17a_800D3A60(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s17a_800D3A60");
int G_s17a_800D3A60(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[2] = (u)r[5] << 2;
    r[7] = (u)r[4] + (u)r[2];
    r[3] = *(short *)((u)r[6] + 0);
    r[2] = *(int *)((u)r[7] + 196);
    mul = (long long)(int)r[3] * (int)r[2]; hi_ = mul >> 32; lo_ = mul;
    r[5] = (u)r[5] << 3;
    r[3] = *(unsigned short *)((u)r[6] + 0);
    r[2] = lo_;
    c = (((int)r[2] >= 0)); r[4] = (u)r[4] + (u)r[5]; if (c) goto L800d3a90;
    r[2] = (u)r[2] + 15;
    L800d3a90:;
    r[2] = (int)r[2] >> 4;
    r[2] = (u)r[3] - (u)r[2];
    *(short *)((u)r[4] + 132) = r[2];
    r[3] = *(short *)((u)r[6] + 2);
    r[2] = *(int *)((u)r[7] + 196);
    mul = (long long)(int)r[3] * (int)r[2]; hi_ = mul >> 32; lo_ = mul;
    r[6] = *(unsigned short *)((u)r[6] + 2);
    r[2] = lo_;
    c = (((int)r[2] >= 0));  if (c) goto L800d3ac0;
    r[2] = (u)r[2] + 15;
    L800d3ac0:;
    r[2] = (int)r[2] >> 4;
    r[2] = (u)r[6] - (u)r[2];
    *(short *)((u)r[4] + 134) = r[2];
    r[2] = (u)0 + 320;
    *(short *)((u)r[4] + 136) = r[2]; goto out;
out:
    RECOMP_RETURN;
}
