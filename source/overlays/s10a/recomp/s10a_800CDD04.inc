int G_s10a_800CDD04(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s10a_800CDD04");
int G_s10a_800CDD04(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(8)
    r[6] = 0x55550000;
    r[2] = (u)0 + 9;
    *(char *)((u)r[4] + 3) = r[2];
    r[2] = (u)0 + 44;
    *(char *)((u)r[4] + 7) = r[2];
    r[3] = (u)r[2] + (u)0;
    r[2] = (u)0 + 100;
    r[3] = r[3] | 2;
    *(char *)((u)r[4] + 4) = r[2];
    *(char *)((u)r[4] + 5) = r[2];
    *(char *)((u)r[4] + 6) = r[2];
    *(char *)((u)r[4] + 7) = r[3];
    r[2] = *(unsigned char *)((u)r[5] + 10);
    r[6] = r[6] | 21846;
    r[2] = (u)r[2] + 1;
    mul = (long long)(int)r[2] * (int)r[6]; hi_ = mul >> 32; lo_ = mul;
    r[2] = *(unsigned char *)((u)r[5] + 8);
    *(char *)((u)r[4] + 28) = r[2];
    *(char *)((u)r[4] + 12) = r[2];
    r[7] = hi_;
    r[2] = (u)r[7] + (u)r[2];
    r[2] = (u)r[2] + -1;
    *(char *)((u)r[4] + 36) = r[2];
    *(char *)((u)r[4] + 20) = r[2];
    r[2] = *(unsigned char *)((u)r[5] + 9);
    r[3] = *(unsigned char *)((u)r[5] + 11);
    r[3] = (u)r[3] + (u)r[2];
    *(char *)((u)r[4] + 21) = r[2];
    *(char *)((u)r[4] + 13) = r[2];
    *(char *)((u)r[4] + 37) = r[3];
    *(char *)((u)r[4] + 29) = r[3];
    r[2] = *(unsigned short *)((u)r[5] + 4);
    *(short *)((u)r[4] + 22) = r[2];
    r[2] = *(unsigned short *)((u)r[5] + 6);
    r[29] = (u)r[29] + -8;
    *(short *)((u)r[4] + 14) = r[2];
    r[29] = (u)r[29] + 8; goto out;
out:
    RECOMP_RETURN;
}
