extern char R_s18a_800CC8B0[] __asm__("s18a_800CC8B0");
extern char R_s18a_800CC8F0[] __asm__("s18a_800CC8F0");
extern char R_s18a_800CCC0C[] __asm__("s18a_800CCC0C");
int G_s18a_800CE858(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s18a_800CE858");
int G_s18a_800CE858(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(32)
    r[29] = (u)r[29] + -32;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 24) = r[31];
    *(int *)((u)r[29] + 20) = r[17];
    r[2] = *(int *)((u)r[16] + 2408);
    c = ((r[2] != 0));  if (c) goto L800ce8d4;
     CALL(R_s18a_800CCC0C);
    r[3] = 0x55550000;
    r[4] = *(int *)((u)r[16] + 2432);
    r[3] = r[3] | 21846;
    mul = (long long)(int)r[4] * (int)r[3]; hi_ = mul >> 32; lo_ = mul;
    r[17] = (u)r[2] + (u)0;
    r[3] = (int)r[4] >> 31;
    r[7] = hi_;
    r[3] = (u)r[7] - (u)r[3];
    r[2] = (u)r[3] << 1;
    r[2] = (u)r[2] + (u)r[3];
    c = ((r[4] == r[2])); r[2] = (u)0 + 1; if (c) goto L800ce8bc;
    *(int *)((u)r[16] + 2460) = 0; goto L800ce8c0;
    L800ce8bc:;
    *(int *)((u)r[16] + 2460) = r[2];
    L800ce8c0:;
    r[4] = (u)r[16] + (u)0;
    r[6] = *(int *)((u)r[16] + 2460);
    r[5] = (u)r[17] + (u)0; CALL(R_s18a_800CC8B0);
    *(int *)((u)r[16] + 2464) = r[17];
    L800ce8d4:;
    r[2] = *(short *)((u)r[16] + 36);
    r[2] = (int)r[2] < 2251;
    c = ((r[2] != 0)); r[4] = (u)r[16] + (u)0; if (c) goto L800ce8f4;
    r[2] = (u)0 + 2048;
    *(int *)((u)r[16] + 2388) = r[2]; goto L800ce918;
    L800ce8f4:;
    r[5] = (u)0 + 300; CALL(R_s18a_800CC8F0);
    c = ((r[2] == 0)); r[2] = (u)0 + 1; if (c) goto L800ce918;
    *(int *)((u)r[16] + 2400) = r[2];
    r[2] = (u)0 + 3;
    *(int *)((u)r[16] + 2404) = r[2];
    *(int *)((u)r[16] + 2408) = 0; goto L800ce928;
    L800ce918:;
    r[2] = *(int *)((u)r[16] + 2408);
    r[2] = (u)r[2] + 1;
    *(int *)((u)r[16] + 2408) = r[2];
    L800ce928:;
    r[31] = *(int *)((u)r[29] + 24);
    r[17] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 32; goto out;
out:
    RECOMP_RETURN;
}
