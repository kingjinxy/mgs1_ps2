int G_s18a_800DB8DC(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s18a_800DB8DC");
int G_s18a_800DB8DC(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[5] = *(int *)((u)r[4] + 2212);
    r[3] = *(unsigned short *)((u)r[5] + 0);
    r[2] = r[3] & 40960;
    c = ((r[2] == 0)); r[8] = (u)r[4] + 2244; if (c) goto L800dba18;
    r[7] = *(short *)((u)r[4] + 110);
    r[2] = r[3] & 32768;
    c = ((r[2] == 0));  if (c) goto L800db990;
    r[2] = *(int *)((u)r[4] + 2020);
    r[2] = r[2] & 16384;
    c = ((r[2] == 0)); r[2] = (u)0 + 80; if (c) goto L800db928;
    r[3] = *(unsigned char *)((u)r[5] + 14);
    r[6] = (u)r[2] - (u)r[3]; goto L800db92c;
    L800db928:;
    r[6] = (u)0 + 1;
    L800db92c:;
    r[2] = *(int *)((u)r[4] + 2020);
    r[2] = r[2] & 16384;
    c = ((r[2] == 0)); r[5] = (u)0 + 1; if (c) goto L800db944;
    r[5] = (u)0 + 80;
    L800db944:;
    r[3] = *(short *)((u)r[8] + 16);
    r[2] = r[6] & 255;
    mul = (long long)(int)r[3] * (int)r[2]; hi_ = mul >> 32; lo_ = mul;
    r[2] = lo_;
    if (r[5]) { lo_ = (int)r[2] / (int)r[5]; hi_ = (int)r[2] % (int)r[5]; }
    c = ((r[5] != 0));  if (c) goto L800db96c;
    L800db96c:;
    r[1] = (u)0 + -1;
    c = ((r[5] != r[1])); r[1] = 0; if (c) goto L800db984;
    c = ((r[2] != r[1]));  if (c) goto L800db984;
    L800db984:;
    r[2] = lo_;
    r[7] = (u)r[7] + (u)r[2]; goto L800dba14;
    L800db990:;
    r[2] = *(int *)((u)r[4] + 2020);
    r[2] = r[2] & 16384;
    c = ((r[2] == 0)); r[6] = (u)0 + 1; if (c) goto L800db9b0;
    r[2] = *(unsigned char *)((u)r[5] + 14);
    r[6] = (u)r[2] + 80;
    L800db9b0:;
    r[2] = *(int *)((u)r[4] + 2020);
    r[2] = r[2] & 16384;
    c = ((r[2] == 0)); r[5] = (u)0 + 1; if (c) goto L800db9c8;
    r[5] = (u)0 + 79;
    L800db9c8:;
    r[3] = *(short *)((u)r[8] + 14);
    r[2] = r[6] & 255;
    mul = (long long)(int)r[3] * (int)r[2]; hi_ = mul >> 32; lo_ = mul;
    r[2] = lo_;
    if (r[5]) { lo_ = (int)r[2] / (int)r[5]; hi_ = (int)r[2] % (int)r[5]; }
    c = ((r[5] != 0));  if (c) goto L800db9f0;
    L800db9f0:;
    r[1] = (u)0 + -1;
    c = ((r[5] != r[1])); r[1] = 0; if (c) goto L800dba08;
    c = ((r[2] != r[1]));  if (c) goto L800dba08;
    L800dba08:;
    r[2] = lo_;
    r[7] = (u)r[7] - (u)r[2];
    L800dba14:;
    *(short *)((u)r[4] + 110) = r[7];
    L800dba18:;
     goto out;
out:
    RECOMP_RETURN;
}
