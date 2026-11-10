extern char R_SquareRoot0[] __asm__("SquareRoot0");
extern char R_ratan2[] __asm__("ratan2");
int G_s17a_800E1668(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s17a_800E1668");
int G_s17a_800E1668(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(40)
    r[29] = (u)r[29] + -40;
    *(int *)((u)r[29] + 28) = r[19];
    r[19] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 24) = r[18];
    r[18] = (u)r[5] + (u)0;
    *(int *)((u)r[29] + 32) = r[31];
    *(int *)((u)r[29] + 20) = r[17];
    *(int *)((u)r[29] + 16) = r[16];
    r[2] = *(unsigned short *)((u)r[19] + 2);
    r[3] = *(unsigned short *)((u)r[19] + 14);
    r[2] = (u)0 - (u)r[2];
    r[16] = (u)r[2] + (u)0;
    r[3] = (u)0 - (u)r[3];
    r[2] = (u)r[2] << 16;
    c = ((r[2] != 0)); r[17] = (u)r[3] + (u)0; if (c) goto L800e16bc;
    r[2] = (u)r[3] << 16;
    c = ((r[2] != 0)); r[4] = (u)r[16] << 16; if (c) goto L800e16c0;
    *(short *)((u)r[18] + 2) = 0; goto L800e16d8;
    L800e16bc:;
    r[4] = (u)r[16] << 16;
    L800e16c0:;
    r[4] = (int)r[4] >> 16;
    r[5] = (u)r[17] << 16;
    r[5] = (int)r[5] >> 16; CALL(R_ratan2);
    r[2] = r[2] & 4095;
    *(short *)((u)r[18] + 2) = r[2];
    L800e16d8:;
    r[2] = (u)r[16] << 16;
    r[2] = (int)r[2] >> 16;
    mul = (long long)(int)r[2] * (int)r[2]; hi_ = mul >> 32; lo_ = mul;
    r[3] = lo_;
    r[2] = (u)r[17] << 16;
    r[2] = (int)r[2] >> 16;
    mul = (long long)(int)r[2] * (int)r[2]; hi_ = mul >> 32; lo_ = mul;
    r[7] = lo_;
    r[4] = (u)r[3] + (u)r[7]; CALL(R_SquareRoot0);
    r[4] = *(short *)((u)r[19] + 8);
    r[5] = (u)r[2] + (u)0; CALL(R_ratan2);
    r[2] = r[2] & 4095;
    *(short *)((u)r[18] + 0) = r[2];
    *(short *)((u)r[18] + 4) = 0;
    r[31] = *(int *)((u)r[29] + 32);
    r[19] = *(int *)((u)r[29] + 28);
    r[18] = *(int *)((u)r[29] + 24);
    r[17] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 40; goto out;
out:
    RECOMP_RETURN;
}
