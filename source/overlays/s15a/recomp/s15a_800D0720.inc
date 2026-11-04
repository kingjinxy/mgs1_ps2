int G_s15a_800D0720(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s15a_800D0720");
int G_s15a_800D0720(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[2] = (u)r[6] << 3;
    r[7] = (u)r[4] + (u)r[2];
    r[6] = (u)r[6] << 2;
    r[6] = (u)r[4] + (u)r[6];
    r[3] = *(short *)((u)r[7] + 16192);
    r[2] = *(int *)((u)r[6] + 16144);
    mul = (long long)(int)r[3] * (int)r[2]; hi_ = mul >> 32; lo_ = mul;
    r[2] = (u)r[5] << 2;
    r[2] = (u)r[2] + (u)r[5];
    r[2] = (u)r[2] << 3;
    r[2] = (u)r[2] - (u)r[5];
    r[2] = (u)r[2] << 2;
    r[3] = lo_;
    c = (((int)r[3] >= 0)); r[4] = (u)r[4] + (u)r[2]; if (c) goto L800d0764;
    r[3] = (u)r[3] + 127;
    L800d0764:;
    r[2] = *(unsigned short *)((u)r[4] + 112);
    r[3] = (int)r[3] >> 7;
    r[2] = (u)r[2] + (u)r[3];
    *(short *)((u)r[4] + 112) = r[2];
    r[3] = *(short *)((u)r[7] + 16194);
    r[2] = *(int *)((u)r[6] + 16144);
    mul = (long long)(int)r[3] * (int)r[2]; hi_ = mul >> 32; lo_ = mul;
    r[3] = lo_;
    c = (((int)r[3] >= 0));  if (c) goto L800d0794;
    r[3] = (u)r[3] + 127;
    L800d0794:;
    r[2] = *(unsigned short *)((u)r[4] + 114);
    r[3] = (int)r[3] >> 7;
    r[2] = (u)r[2] + (u)r[3];
    *(short *)((u)r[4] + 114) = r[2];
    r[3] = *(short *)((u)r[7] + 16196);
    r[2] = *(int *)((u)r[6] + 16144);
    mul = (long long)(int)r[3] * (int)r[2]; hi_ = mul >> 32; lo_ = mul;
    r[3] = lo_;
    c = (((int)r[3] >= 0));  if (c) goto L800d07c4;
    r[3] = (u)r[3] + 127;
    L800d07c4:;
    r[2] = *(unsigned short *)((u)r[4] + 116);
    r[3] = (int)r[3] >> 7;
    r[2] = (u)r[2] + (u)r[3];
    *(short *)((u)r[4] + 116) = r[2]; goto out;
out:
    RECOMP_RETURN;
}
