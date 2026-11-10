extern char R_GCL_GetOption[] __asm__("GCL_GetOption");
extern char R_s18a_800D0FCC[] __asm__("s18a_800D0FCC");
int G_s18a_800D102C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s18a_800D102C");
int G_s18a_800D102C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 20) = r[31];
    r[4] = (u)0 + 112; CALL(R_GCL_GetOption);
    c = ((r[2] == 0)); r[4] = (u)r[2] + (u)0; if (c) goto L800d105c;
    r[5] = (u)r[16] + 32; CALL(R_s18a_800D0FCC);
    c = (((int)r[2] >= 0)); *(int *)((u)r[16] + 68) = r[2]; if (c) goto L800d1064;
    L800d105c:;
    r[2] = (u)0 + -1; goto L800d10d4;
    L800d1064:;
    c = (((int)r[2] <= 0)); r[4] = (u)0 + (u)0; if (c) goto L800d10d0;
    r[5] = (u)0 + 8;
    L800d1070:;
    r[2] = *(int *)((u)r[16] + 68);
    if (r[2]) { lo_ = (int)r[5] / (int)r[2]; hi_ = (int)r[5] % (int)r[2]; }
    c = ((r[2] != 0));  if (c) goto L800d1088;
    L800d1088:;
    r[1] = (u)0 + -1;
    c = ((r[2] != r[1])); r[1] = 0; if (c) goto L800d10a0;
    c = ((r[5] != r[1]));  if (c) goto L800d10a0;
    L800d10a0:;
    r[2] = lo_;
    mul = (long long)(int)r[4] * (int)r[2]; hi_ = mul >> 32; lo_ = mul;
    r[2] = (u)r[16] + (u)r[4];
    r[3] = lo_;
    *(char *)((u)r[2] + 64) = r[3];
    r[2] = *(int *)((u)r[16] + 68);
    r[4] = (u)r[4] + 1;
    r[2] = (int)r[4] < (int)r[2];
    c = ((r[2] != 0));  if (c) goto L800d1070;
    L800d10d0:;
    r[2] = (u)0 + (u)0;
    L800d10d4:;
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
