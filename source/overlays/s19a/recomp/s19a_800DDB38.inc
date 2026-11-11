extern char R_GM_CameraShakeOffset[] __asm__("GM_CameraShakeOffset");
extern char R_GM_CurrentMap[] __asm__("GM_CurrentMap");
extern char R_GM_PlayerPosition[] __asm__("GM_PlayerPosition");
extern char R_GV_DestroyActor[] __asm__("GV_DestroyActor");
extern char R_SquareRoot0[] __asm__("SquareRoot0");
extern char R_rand[] __asm__("rand");
int G_s19a_800DDB38(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s19a_800DDB38");
int G_s19a_800DDB38(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(32)
    r[29] = (u)r[29] + -32;
    *(int *)((u)r[29] + 24) = r[16];
    r[16] = (u)r[4] + (u)0;
    r[4] = 0;
    *(int *)((u)r[29] + 28) = r[31];
    r[3] = *(int *)((u)r[16] + 64);
    r[2] = *(int *)((u)r[16] + 32);
    r[3] = (u)r[3] + -1;
    *(int *)((u)r[4] + (int)R_GM_CurrentMap) = r[2];
    c = (((int)r[3] >= 0)); *(int *)((u)r[16] + 64) = r[3]; if (c) goto L800ddb74;
    r[4] = (u)r[16] + (u)0; CALL(R_GV_DestroyActor);
     goto L800ddca4;
    L800ddb74:;
    r[4] = 0;
    r[2] = *(short *)((u)r[4] + (int)R_GM_PlayerPosition);
    r[3] = *(short *)((u)r[16] + 40);
    r[2] = (u)r[2] - (u)r[3];
    r[2] = (int)r[2] >> 2;
    mul = (long long)(int)r[2] * (int)r[2]; hi_ = mul >> 32; lo_ = mul;
    r[4] = (u)r[4] + (int)R_GM_PlayerPosition;
    *(short *)((u)r[29] + 16) = r[2];
    r[2] = *(short *)((u)r[4] + 2);
    r[3] = *(short *)((u)r[16] + 42);
    r[5] = lo_;
    r[2] = (u)r[2] - (u)r[3];
    r[2] = (int)r[2] >> 2;
    mul = (long long)(int)r[2] * (int)r[2]; hi_ = mul >> 32; lo_ = mul;
    *(short *)((u)r[29] + 18) = r[2];
    r[3] = *(short *)((u)r[16] + 44);
    r[2] = *(short *)((u)r[4] + 4);
    r[6] = lo_;
    r[2] = (u)r[2] - (u)r[3];
    r[2] = (int)r[2] >> 2;
    mul = (long long)(int)r[2] * (int)r[2]; hi_ = mul >> 32; lo_ = mul;
    *(short *)((u)r[29] + 20) = r[2];
    r[5] = (u)r[5] + (u)r[6];
    r[3] = lo_;
    r[4] = (u)r[5] + (u)r[3]; CALL(R_SquareRoot0);
    r[4] = *(int *)((u)r[16] + 48);
    r[5] = (u)r[2] << 2;
    r[2] = (int)r[4] < (int)r[5];
    c = ((r[2] != 0));  if (c) goto L800ddca4;
    r[3] = *(int *)((u)r[16] + 64);
    r[2] = *(int *)((u)r[16] + 52);
    mul = (long long)(int)r[3] * (int)r[2]; hi_ = mul >> 32; lo_ = mul;
    r[3] = lo_;
    r[2] = *(int *)((u)r[16] + 56);
    if (r[2]) { lo_ = (int)r[3] / (int)r[2]; hi_ = (int)r[3] % (int)r[2]; }
    c = ((r[2] != 0));  if (c) goto L800ddc20;
    L800ddc20:;
    r[1] = (u)0 + -1;
    c = ((r[2] != r[1])); r[1] = 0; if (c) goto L800ddc38;
    c = ((r[3] != r[1]));  if (c) goto L800ddc38;
    L800ddc38:;
    r[2] = lo_;
    r[3] = (u)r[4] - (u)r[5];
    mul = (long long)(int)r[3] * (int)r[2]; hi_ = mul >> 32; lo_ = mul;
    r[3] = lo_;
    if (r[4]) { lo_ = (int)r[3] / (int)r[4]; hi_ = (int)r[3] % (int)r[4]; }
    c = ((r[4] != 0));  if (c) goto L800ddc64;
    L800ddc64:;
    r[1] = (u)0 + -1;
    c = ((r[4] != r[1])); r[1] = 0; if (c) goto L800ddc7c;
    c = ((r[3] != r[1]));  if (c) goto L800ddc7c;
    L800ddc7c:;
    r[16] = lo_;
     CALL(R_rand);
    mul = (long long)(int)r[2] * (int)r[16]; hi_ = mul >> 32; lo_ = mul;
    r[4] = 0;
    r[2] = *(int *)((u)r[4] + (int)R_GM_CameraShakeOffset);
    r[3] = lo_;
    r[3] = (int)r[3] >> 15;
    r[2] = (u)r[2] + (u)r[3];
    *(int *)((u)r[4] + (int)R_GM_CameraShakeOffset) = r[2];
    L800ddca4:;
    r[31] = *(int *)((u)r[29] + 28);
    r[16] = *(int *)((u)r[29] + 24);
    r[29] = (u)r[29] + 32; goto out;
out:
    RECOMP_RETURN;
}
int G_s19a_rc_800DDCB4(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s19a_rc_800DDCB4");
int G_s19a_rc_800DDCB4(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
     goto out;
out:
    RECOMP_RETURN;
}
