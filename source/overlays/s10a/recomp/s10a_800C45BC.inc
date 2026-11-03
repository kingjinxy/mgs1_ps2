extern char R_GV_DestroyActor[] __asm__("GV_DestroyActor");
extern char R_s10a_800C4580[] __asm__("s10a_800C4580");
int G_s10a_800C45BC(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s10a_800C45BC");
int G_s10a_800C45BC(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(32)
    r[29] = (u)r[29] + -32;
    *(int *)((u)r[29] + 24) = r[16];
    r[16] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 28) = r[31];
    r[2] = *(int *)((u)r[16] + 72);
    r[2] = (u)r[2] + 1;
    *(int *)((u)r[16] + 72) = r[2];
    r[2] = (int)r[2] < 391;
    c = ((r[2] != 0));  if (c) goto L800c45f0;
     CALL(R_GV_DestroyActor);
    L800c45f0:;
    r[4] = 0x5efa0000;
    r[3] = *(int *)((u)r[16] + 72);
    r[4] = r[4] | 52809;
    r[2] = (u)r[3] << 1;
    r[2] = (u)r[2] + (u)r[3];
    r[2] = (u)r[2] << 4;
    mul = (long long)(int)r[2] * (int)r[4]; hi_ = mul >> 32; lo_ = mul;
    r[6] = (u)0 + 48;
    r[2] = (int)r[2] >> 31;
    r[8] = hi_;
    r[3] = (int)r[8] >> 8;
    r[3] = (u)r[3] - (u)r[2];
    r[6] = (u)r[6] - (u)r[3];
    *(int *)((u)r[29] + 16) = r[6];
    r[4] = *(int *)((u)r[16] + 32);
    r[5] = *(int *)((u)r[16] + 36);
    r[7] = (u)r[6] + (u)0; CALL(R_s10a_800C4580);
    r[31] = *(int *)((u)r[29] + 28);
    r[16] = *(int *)((u)r[29] + 24);
    r[29] = (u)r[29] + 32; goto out;
out:
    return r[2];
}
