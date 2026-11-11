extern char R_GV_DestroyActor[] __asm__("GV_DestroyActor");
extern char R_s19a_800CAF6C[] __asm__("s19a_800CAF6C");
int G_s19a_800CAFA8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s19a_800CAFA8");
int G_s19a_800CAFA8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(32)
    r[29] = (u)r[29] + -32;
    *(int *)((u)r[29] + 24) = r[16];
    r[16] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 28) = r[31];
    r[3] = *(int *)((u)r[16] + 72);
    r[2] = *(int *)((u)r[16] + 84);
    r[3] = (u)r[3] + 1;
    r[2] = (u)r[2] + -300;
    r[2] = (int)r[2] < (int)r[3];
    c = ((r[2] == 0)); *(int *)((u)r[16] + 72) = r[3]; if (c) goto L800cafdc;
     CALL(R_GV_DestroyActor);
    L800cafdc:;
    r[2] = *(int *)((u)r[16] + 84);
    r[3] = *(int *)((u)r[16] + 72);
    r[5] = (u)r[2] - (u)r[3];
    r[2] = (int)r[5] < 690;
    c = ((r[2] == 0)); r[4] = 0x5efa0000; if (c) goto L800cb034;
    r[4] = r[4] | 52809;
    r[3] = (u)0 + 690;
    r[3] = (u)r[3] - (u)r[5];
    r[2] = (u)r[3] << 1;
    r[2] = (u)r[2] + (u)r[3];
    r[2] = (u)r[2] << 4;
    mul = (long long)(int)r[2] * (int)r[4]; hi_ = mul >> 32; lo_ = mul;
    r[2] = (int)r[2] >> 31;
    r[6] = (u)0 + 48;
    r[8] = hi_;
    r[3] = (int)r[8] >> 8;
    r[3] = (u)r[3] - (u)r[2];
    r[6] = (u)r[6] - (u)r[3];
    *(int *)((u)r[29] + 16) = r[6]; goto L800cb040;
    L800cb034:;
    r[6] = (u)0 + 48;
    r[2] = (u)r[6] + (u)0;
    *(int *)((u)r[29] + 16) = r[2];
    L800cb040:;
    r[4] = *(int *)((u)r[16] + 32);
    r[5] = *(int *)((u)r[16] + 36);
    r[7] = (u)r[6] + (u)0; CALL(R_s19a_800CAF6C);
    r[31] = *(int *)((u)r[29] + 28);
    r[16] = *(int *)((u)r[29] + 24);
    r[29] = (u)r[29] + 32; goto out;
out:
    RECOMP_RETURN;
}
