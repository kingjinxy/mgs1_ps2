extern char R_GV_RandU[] __asm__("GV_RandU");
int G_s15a_800CB7A0(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s15a_800CB7A0");
int G_s15a_800CB7A0(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[31];
    r[4] = (u)0 + 4096; CALL(R_GV_RandU);
    r[3] = 0x55550000;
    r[3] = r[3] | 21846;
    mul = (long long)(int)r[2] * (int)r[3]; hi_ = mul >> 32; lo_ = mul;
    r[4] = (int)r[2] >> 31;
    r[31] = *(int *)((u)r[29] + 16);
    r[5] = hi_;
    r[4] = (u)r[5] - (u)r[4];
    r[3] = (u)r[4] << 1;
    r[3] = (u)r[3] + (u)r[4];
    r[2] = (u)r[2] - (u)r[3];
    r[2] = (u)r[2] + 1;
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
