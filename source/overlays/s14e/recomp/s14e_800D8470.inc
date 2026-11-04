extern char R_GM_Camera[] __asm__("GM_Camera");
extern char R_GM_CurrentMap[] __asm__("GM_CurrentMap");
extern char R_s14e_800D87D0[] __asm__("s14e_800D87D0");
int G_s14e_800D8470(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s14e_800D8470");
int G_s14e_800D8470(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    r[3] = (u)0 + 255;
    r[2] = 0;
    *(int *)((u)r[29] + 16) = r[31];
    r[5] = *(int *)((u)r[4] + 40);
    r[2] = *(short *)((u)r[2] + ((int)R_GM_Camera + 32));
    r[3] = (u)r[3] - (u)r[5];
    r[2] = (u)r[2] + -360;
    mul = (long long)(int)r[3] * (int)r[2]; hi_ = mul >> 32; lo_ = mul;
    r[3] = lo_;
    r[2] = 0x90090000;
    r[2] = r[2] | 145;
    mul = (long long)(int)r[3] * (int)r[2]; hi_ = mul >> 32; lo_ = mul;
    r[4] = *(int *)((u)r[4] + 32);
    r[2] = 0;
    *(int *)((u)r[2] + (int)R_GM_CurrentMap) = r[4];
    r[7] = hi_;
    r[4] = (u)r[7] + (u)r[3];
    r[4] = (int)r[4] >> 11;
    r[3] = (int)r[3] >> 31;
    r[4] = (u)r[4] - (u)r[3];
    r[4] = (u)r[5] + (u)r[4]; CALL(R_s14e_800D87D0);
    r[31] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
