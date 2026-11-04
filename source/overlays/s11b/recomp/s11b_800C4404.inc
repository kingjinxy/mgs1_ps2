extern char R_rand[] __asm__("rand");
int G_s11b_800C4404(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s11b_800C4404");
int G_s11b_800C4404(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(40)
    r[29] = (u)r[29] + -40;
    *(int *)((u)r[29] + 32) = r[20];
    r[20] = *(int *)((u)r[29] + 60);
    *(int *)((u)r[29] + 24) = r[18];
    r[18] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 20) = r[17];
    r[17] = (u)r[5] + (u)0;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[6] + (u)0;
    *(int *)((u)r[29] + 28) = r[19];
    *(int *)((u)r[29] + 36) = r[31];
    r[19] = (u)r[7] + (u)0; CALL(R_rand);
    r[2] = r[2] & 255;
    r[16] = (u)r[16] - (u)r[17];
    mul = (long long)(int)r[2] * (int)r[16]; hi_ = mul >> 32; lo_ = mul;
    r[2] = lo_;
    c = (((int)r[2] >= 0));  if (c) goto L800c4454;
    r[2] = (u)r[2] + 255;
    L800c4454:;
    r[2] = (int)r[2] >> 8;
    r[2] = (u)r[2] + (u)r[17];
    *(short *)((u)r[18] + 0) = r[2]; CALL(R_rand);
    r[3] = *(int *)((u)r[29] + 56);
    r[2] = r[2] & 255;
    r[3] = (u)r[3] - (u)r[19];
    mul = (long long)(int)r[2] * (int)r[3]; hi_ = mul >> 32; lo_ = mul;
    r[2] = lo_;
    c = (((int)r[2] >= 0));  if (c) goto L800c4484;
    r[2] = (u)r[2] + 255;
    L800c4484:;
    r[2] = (int)r[2] >> 8;
    r[2] = (u)r[2] + (u)r[19];
    *(short *)((u)r[18] + 2) = r[2]; CALL(R_rand);
    r[3] = *(int *)((u)r[29] + 64);
    r[2] = r[2] & 255;
    r[3] = (u)r[3] - (u)r[20];
    mul = (long long)(int)r[2] * (int)r[3]; hi_ = mul >> 32; lo_ = mul;
    r[2] = lo_;
    c = (((int)r[2] >= 0));  if (c) goto L800c44b4;
    r[2] = (u)r[2] + 255;
    L800c44b4:;
    r[2] = (int)r[2] >> 8;
    r[2] = (u)r[2] + (u)r[20];
    *(short *)((u)r[18] + 4) = r[2];
    r[31] = *(int *)((u)r[29] + 36);
    r[20] = *(int *)((u)r[29] + 32);
    r[19] = *(int *)((u)r[29] + 28);
    r[18] = *(int *)((u)r[29] + 24);
    r[17] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 40; goto out;
out:
    RECOMP_RETURN;
}
