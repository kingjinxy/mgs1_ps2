extern char R_GV_Clock[] __asm__("GV_Clock");
int G_s11b_800CAB84(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s11b_800CAB84");
int G_s11b_800CAB84(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[6] = (u)0 + (u)0;
    r[7] = 0x66660000;
    r[2] = 0;
    r[2] = *(int *)((u)r[2] + (int)R_GV_Clock);
    r[3] = *(int *)((u)r[4] + 40);
    r[2] = (u)r[2] << 2;
    r[3] = (u)r[3] + (u)r[2];
    r[2] = *(int *)((u)r[3] + 64);
    r[7] = r[7] | 26215;
    r[5] = (u)r[2] + 6;
    L800cabac:;
    r[2] = *(int *)((u)r[4] + 24748);
    c = (((int)r[2] > 0)); r[3] = (u)r[2] << 8; if (c) goto L800cabc8;
    *(int *)((u)r[4] + 24748) = 0;
    r[2] = (u)0 + (u)0; goto L800cabe8;
    L800cabc8:;
    r[3] = (u)r[3] - (u)r[2];
    mul = (long long)(int)r[3] * (int)r[7]; hi_ = mul >> 32; lo_ = mul;
    r[2] = (u)r[2] + -1;
    *(int *)((u)r[4] + 24748) = r[2];
    r[3] = (int)r[3] >> 31;
    r[8] = hi_;
    r[2] = (int)r[8] >> 4;
    r[2] = (u)r[2] - (u)r[3];
    L800cabe8:;
    *(char *)((u)r[5] + -2) = r[2];
    *(char *)((u)r[5] + -1) = r[2];
    *(char *)((u)r[5] + 0) = r[2];
    r[5] = (u)r[5] + 40;
    r[6] = (u)r[6] + 1;
    r[2] = (int)r[6] < 640;
    c = ((r[2] != 0)); r[4] = (u)r[4] + 4; if (c) goto L800cabac;
     goto out;
out:
    RECOMP_RETURN;
}
