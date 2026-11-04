int G_s11h_800C3B94(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s11h_800C3B94");
int G_s11h_800C3B94(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    if (r[7]) { lo_ = (int)r[5] / (int)r[7]; hi_ = (int)r[5] % (int)r[7]; }
    c = ((r[7] != 0));  if (c) goto L800c3ba4;
    L800c3ba4:;
    r[1] = (u)0 + -1;
    c = ((r[7] != r[1])); r[1] = 0; if (c) goto L800c3bbc;
    c = ((r[5] != r[1]));  if (c) goto L800c3bbc;
    L800c3bbc:;
    r[13] = lo_;
    r[2] = (u)r[6] >> 31;
    r[2] = (u)r[6] + (u)r[2];
    r[11] = (int)r[2] >> 1;
    r[14] = *(int *)((u)r[29] + 16);
    if (r[14]) { lo_ = (int)r[6] / (int)r[14]; hi_ = (int)r[6] % (int)r[14]; }
    c = ((r[14] != 0));  if (c) goto L800c3be4;
    L800c3be4:;
    r[1] = (u)0 + -1;
    c = ((r[14] != r[1])); r[1] = 0; if (c) goto L800c3bfc;
    c = ((r[6] != r[1]));  if (c) goto L800c3bfc;
    L800c3bfc:;
    r[6] = lo_;
    c = (((int)r[14] <= 0)); r[12] = (u)0 + (u)0; if (c) goto L800c3c74;
    r[3] = (u)0 - (u)r[5];
    r[2] = (u)r[3] >> 31;
    r[3] = (u)r[3] + (u)r[2];
    L800c3c14:;
    r[8] = (int)r[3] >> 1;
    c = (((int)r[7] <= 0)); r[9] = (u)0 + (u)0; if (c) goto L800c3c64;
    r[10] = (u)r[11] - (u)r[6];
    r[5] = (u)r[4] + 26;
    L800c3c28:;
    r[2] = (u)r[8] + (u)r[13];
    *(short *)((u)r[4] + 0) = r[8];
    *(short *)((u)r[5] + -10) = r[8];
    r[8] = (u)r[2] + (u)0;
    *(short *)((u)r[5] + -18) = r[8];
    *(short *)((u)r[5] + -2) = r[8];
    *(short *)((u)r[5] + -24) = r[11];
    *(short *)((u)r[5] + -16) = r[11];
    *(short *)((u)r[5] + -8) = r[10];
    *(short *)((u)r[5] + 0) = r[10];
    r[5] = (u)r[5] + 32;
    r[9] = (u)r[9] + 1;
    r[2] = (int)r[9] < (int)r[7];
    c = ((r[2] != 0)); r[4] = (u)r[4] + 32; if (c) goto L800c3c28;
    L800c3c64:;
    r[12] = (u)r[12] + 1;
    r[2] = (int)r[12] < (int)r[14];
    c = ((r[2] != 0)); r[11] = (u)r[11] - (u)r[6]; if (c) goto L800c3c14;
    L800c3c74:;
     goto out;
out:
    RECOMP_RETURN;
}
