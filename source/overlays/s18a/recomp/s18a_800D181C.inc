extern char R_s18a_dat_800E3848[] __asm__("s18a_dat_800E3848");
extern char R_s18a_800D1C54[] __asm__("s18a_800D1C54");
int G_s18a_800D181C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s18a_800D181C");
int G_s18a_800D181C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    r[6] = (u)r[4] + (u)0;
    r[2] = 0x88880000;
    *(int *)((u)r[29] + 16) = r[31];
    r[4] = *(int *)((u)r[6] + 84);
    r[2] = r[2] | 34953;
    mul = (long long)(int)r[4] * (int)r[2]; hi_ = mul >> 32; lo_ = mul;
    r[5] = 0x55550000;
    r[5] = r[5] | 21846;
    r[2] = (int)r[4] >> 31;
    r[7] = hi_;
    r[3] = (u)r[7] + (u)r[4];
    r[3] = (int)r[3] >> 5;
    r[3] = (u)r[3] - (u)r[2];
    r[2] = (u)r[3] << 4;
    r[2] = (u)r[2] - (u)r[3];
    r[2] = (u)r[2] << 2;
    r[4] = (u)r[4] - (u)r[2];
    mul = (long long)(int)r[4] * (int)r[5]; hi_ = mul >> 32; lo_ = mul;
    r[4] = (int)r[4] >> 31;
    r[7] = hi_;
    r[3] = (u)r[7] - (u)r[4];
    r[2] = (u)r[3] < (u)20;
    c = ((r[2] == 0)); r[5] = (u)0 + (u)0; if (c) goto L800d18c4;
    r[2] = 0;
    r[2] = (u)r[2] + (int)R_s18a_dat_800E3848;
    r[3] = (u)r[3] << 2;
    r[3] = (u)r[3] + (u)r[2];
    r[2] = *(int *)((u)r[3] + 0);
    t = r[2];  switch ((u)t) { case 0x800d18a0: goto L800d18a0; case 0x800d18a8: goto L800d18a8; case 0x800d18b0: goto L800d18b0; case 0x800d18b8: goto L800d18b8; case 0x800d18c0: goto L800d18c0; default: goto out; }
    L800d18a0:;
    r[5] = (u)0 + (u)0; goto L800d18c4;
    L800d18a8:;
    r[5] = (u)0 + 1; goto L800d18c4;
    L800d18b0:;
    r[5] = (u)0 + 2; goto L800d18c4;
    L800d18b8:;
    r[5] = (u)0 + 3; goto L800d18c4;
    L800d18c0:;
    r[5] = (u)0 + 4;
    L800d18c4:;
    r[4] = (u)r[5] << 3;
    r[4] = (u)r[4] + 36;
    r[4] = (u)r[6] + (u)r[4]; CALL(R_s18a_800D1C54);
    r[31] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
