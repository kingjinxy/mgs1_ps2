int G_s11b_800D9B7C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s11b_800D9B7C");
int G_s11b_800D9B7C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(8)
    r[29] = (u)r[29] + -8;
    c = ((r[6] == 0)); r[7] = (u)r[6] + -1; if (c) goto L800d9c44;
    r[10] = (u)0 + 9;
    r[9] = (u)0 + 46;
    r[8] = 0x92490000;
    r[8] = r[8] | 9363;
    r[4] = (u)r[4] + 6;
    L800d9b9c:;
    *(char *)((u)r[4] + -3) = r[10];
    *(char *)((u)r[4] + 1) = r[9];
    r[6] = *(unsigned char *)((u)r[5] + 10);
    r[3] = *(unsigned char *)((u)r[5] + 8);
    r[2] = (u)r[6] + 1;
    *(char *)((u)r[4] + 22) = r[3];
    c = (((int)r[2] >= 0)); *(char *)((u)r[4] + 6) = r[3]; if (c) goto L800d9bc0;
    r[2] = (u)r[6] + 4;
    L800d9bc0:;
    r[2] = (int)r[2] >> 2;
    r[2] = (u)r[3] + (u)r[2];
    r[2] = (u)r[2] + -1;
    *(char *)((u)r[4] + 30) = r[2];
    *(char *)((u)r[4] + 14) = r[2];
    r[2] = *(unsigned char *)((u)r[5] + 11);
    r[2] = (u)r[2] + 1;
    mul = (long long)(int)r[2] * (int)r[8]; hi_ = mul >> 32; lo_ = mul;
    r[3] = *(unsigned char *)((u)r[5] + 9);
    r[7] = (u)r[7] + -1;
    *(char *)((u)r[4] + 15) = r[3];
    *(char *)((u)r[4] + 7) = r[3];
    r[11] = hi_;
    r[2] = (u)r[11] + (u)r[2];
    r[2] = (int)r[2] >> 2;
    r[2] = (u)r[2] + (u)r[3];
    r[2] = (u)r[2] + -1;
    *(char *)((u)r[4] + 31) = r[2];
    *(char *)((u)r[4] + 23) = r[2];
    r[2] = *(unsigned short *)((u)r[5] + 4);
    *(short *)((u)r[4] + 16) = r[2];
    r[3] = *(unsigned short *)((u)r[5] + 6);
    r[2] = r[2] | 96;
    *(short *)((u)r[4] + 16) = r[2];
    r[2] = (u)0 + -1;
    *(char *)((u)r[4] + -2) = 0;
    *(char *)((u)r[4] + -1) = 0;
    *(char *)((u)r[4] + 0) = 0;
    *(short *)((u)r[4] + 8) = r[3];
    c = ((r[7] != r[2])); r[4] = (u)r[4] + 40; if (c) goto L800d9b9c;
    L800d9c44:;
    r[29] = (u)r[29] + 8; goto out;
out:
    RECOMP_RETURN;
}
