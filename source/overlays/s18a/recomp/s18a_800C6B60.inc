extern char R_s18a_dat_800E3EE0[] __asm__("s18a_dat_800E3EE0");
extern char R_s18a_dat_800E3EE4[] __asm__("s18a_dat_800E3EE4");
extern char R_GCL_ForceExecProc[] __asm__("GCL_ForceExecProc");
int G_s18a_800C6B60(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s18a_800C6B60");
int G_s18a_800C6B60(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(40)
    r[29] = (u)r[29] + -40;
    *(int *)((u)r[29] + 32) = r[16];
    r[16] = 0;
    r[5] = *(int *)((u)r[16] + (int)R_s18a_dat_800E3EE4);
    c = (((int)r[5] < 0)); *(int *)((u)r[29] + 36) = r[31]; if (c) goto L800c6bcc;
    r[4] = 0x88880000;
    r[2] = 0;
    r[3] = *(int *)((u)r[2] + (int)R_s18a_dat_800E3EE0);
    r[4] = r[4] | 34953;
    mul = (long long)(int)r[3] * (int)r[4]; hi_ = mul >> 32; lo_ = mul;
    r[2] = (u)0 + 1;
    *(short *)((u)r[29] + 16) = r[2];
    r[2] = (u)r[29] + 24;
    *(int *)((u)r[29] + 20) = r[2];
    r[4] = (u)r[5] + (u)0;
    r[5] = (u)r[29] + 16;
    r[6] = hi_;
    r[2] = (u)r[6] + (u)r[3];
    r[2] = (int)r[2] >> 4;
    r[3] = (int)r[3] >> 31;
    r[2] = (u)r[2] - (u)r[3];
    *(int *)((u)r[29] + 24) = r[2]; CALL(R_GCL_ForceExecProc);
    r[2] = (u)0 + -1;
    *(int *)((u)r[16] + (int)R_s18a_dat_800E3EE4) = r[2];
    L800c6bcc:;
    r[31] = *(int *)((u)r[29] + 36);
    r[16] = *(int *)((u)r[29] + 32);
    r[29] = (u)r[29] + 40; goto out;
out:
    RECOMP_RETURN;
}
