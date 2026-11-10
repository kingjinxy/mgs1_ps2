extern char R_GM_SnakeCamera[] __asm__("GM_SnakeCamera");
extern char R_GV_RandU[] __asm__("GV_RandU");
extern char R_s18a_800D5BF0[] __asm__("s18a_800D5BF0");
int G_s18a_800DC204(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s18a_800DC204");
int G_s18a_800DC204(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 20) = r[31];
    *(int *)((u)r[29] + 16) = r[16];
    r[2] = *(int *)((u)r[4] + 2212);
    r[2] = *(unsigned short *)((u)r[2] + 0);
    r[2] = r[2] & 16;
    c = ((r[2] != 0)); r[16] = (u)r[5] + (u)0; if (c) goto L800dc234;
     CALL(R_s18a_800D5BF0);
    L800dc234:;
    r[2] = (int)r[16] < 33;
    c = ((r[2] == 0)); r[2] = (u)0 + 32; if (c) goto L800dc248;
    r[16] = (u)r[2] - (u)r[16]; goto L800dc24c;
    L800dc248:;
    r[16] = (u)0 + (u)0;
    L800dc24c:;
    r[4] = (u)0 + 16; CALL(R_GV_RandU);
    mul = (long long)(int)r[2] * (int)r[16]; hi_ = mul >> 32; lo_ = mul;
    r[3] = 0;
    r[3] = (u)r[3] + (int)R_GM_SnakeCamera;
    r[2] = *(unsigned short *)((u)r[3] + 2);
    r[6] = lo_;
    r[2] = (u)r[2] + (u)r[6];
    *(short *)((u)r[3] + 2) = r[2];
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
