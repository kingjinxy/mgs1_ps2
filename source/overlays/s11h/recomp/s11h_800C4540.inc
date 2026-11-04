extern char R_rand[] __asm__("rand");
int G_s11h_800C4540(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s11h_800C4540");
int G_s11h_800C4540(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(32)
    r[29] = (u)r[29] + -32;
    *(int *)((u)r[29] + 24) = r[18];
    r[18] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 20) = r[17];
    r[17] = (u)r[5] + (u)0;
    *(int *)((u)r[29] + 16) = r[16];
    *(int *)((u)r[29] + 28) = r[31];
    r[16] = (u)r[6] + (u)0; CALL(R_rand);
    r[3] = *(short *)((u)r[16] + 0);
    r[2] = r[2] & 255;
    mul = (long long)(int)r[2] * (int)r[3]; hi_ = mul >> 32; lo_ = mul;
    r[3] = lo_;
    c = (((int)r[3] >= 0));  if (c) goto L800c4580;
    r[3] = (u)r[3] + 255;
    L800c4580:;
    r[2] = *(unsigned short *)((u)r[17] + 0);
    r[3] = (int)r[3] >> 8;
    r[2] = (u)r[2] + (u)r[3];
    *(short *)((u)r[18] + 0) = r[2]; CALL(R_rand);
    r[3] = *(short *)((u)r[16] + 2);
    r[2] = r[2] & 255;
    mul = (long long)(int)r[2] * (int)r[3]; hi_ = mul >> 32; lo_ = mul;
    r[3] = lo_;
    c = (((int)r[3] >= 0));  if (c) goto L800c45b0;
    r[3] = (u)r[3] + 255;
    L800c45b0:;
    r[2] = *(unsigned short *)((u)r[17] + 2);
    r[3] = (int)r[3] >> 8;
    r[2] = (u)r[2] + (u)r[3];
    *(short *)((u)r[18] + 2) = r[2]; CALL(R_rand);
    r[3] = *(short *)((u)r[16] + 4);
    r[2] = r[2] & 255;
    mul = (long long)(int)r[2] * (int)r[3]; hi_ = mul >> 32; lo_ = mul;
    r[3] = lo_;
    c = (((int)r[3] >= 0));  if (c) goto L800c45e0;
    r[3] = (u)r[3] + 255;
    L800c45e0:;
    r[2] = *(unsigned short *)((u)r[17] + 4);
    r[3] = (int)r[3] >> 8;
    r[2] = (u)r[2] + (u)r[3];
    *(short *)((u)r[18] + 4) = r[2];
    r[31] = *(int *)((u)r[29] + 28);
    r[18] = *(int *)((u)r[29] + 24);
    r[17] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 32; goto out;
out:
    RECOMP_RETURN;
}
