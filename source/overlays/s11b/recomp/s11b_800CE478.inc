extern char R_s11b_800CE1D0[] __asm__("s11b_800CE1D0");
extern char R_s11b_800CE318[] __asm__("s11b_800CE318");
extern char R_s11b_dat_800DB028[] __asm__("s11b_dat_800DB028");
extern char R_GV_DestroyActor[] __asm__("GV_DestroyActor");
extern char R_GV_NewActor[] __asm__("GV_NewActor");
extern char R_GV_SetNamedActor[] __asm__("GV_SetNamedActor");
extern char R_s11b_800CE354[] __asm__("s11b_800CE354");
int G_s11b_800CE478(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s11b_800CE478");
int G_s11b_800CE478(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(32)
    r[29] = (u)r[29] + -32;
    *(int *)((u)r[29] + 24) = r[18];
    r[18] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 20) = r[17];
    r[17] = (u)r[5] + (u)0;
    r[4] = (u)0 + 5;
    r[5] = (u)0 + 1116;
    *(int *)((u)r[29] + 28) = r[31];
    *(int *)((u)r[29] + 16) = r[16]; CALL(R_GV_NewActor);
    r[16] = (u)r[2] + (u)0;
    c = ((r[16] == 0)); r[4] = (u)r[16] + (u)0; if (c) goto L800ce524;
    r[5] = 0;
    r[5] = (u)r[5] + (int)R_s11b_800CE1D0;
    r[6] = 0;
    r[6] = (u)r[6] + (int)R_s11b_800CE318;
    r[7] = 0;
    r[7] = (u)r[7] + ((int)R_s11b_dat_800DB028 + 68); CALL(R_GV_SetNamedActor);
    r[4] = 0x66660000;
    r[4] = r[4] | 26215;
    r[3] = (u)r[17] >> 31;
    r[3] = (u)r[17] + (u)r[3];
    r[2] = (int)r[3] >> 1;
    mul = (long long)(int)r[2] * (int)r[4]; hi_ = mul >> 32; lo_ = mul;
    r[4] = (u)r[16] + (u)0;
    r[5] = (u)r[18] + (u)0;
    r[6] = (u)r[17] + (u)0;
    r[3] = (int)r[3] >> 31;
    *(int *)((u)r[16] + 1096) = r[2];
    r[8] = hi_;
    r[2] = (int)r[8] >> 1;
    r[2] = (u)r[2] - (u)r[3];
    *(int *)((u)r[16] + 1100) = r[2];
    *(int *)((u)r[16] + 1104) = r[2]; CALL(R_s11b_800CE354);
    c = (((int)r[2] >= 0)); r[2] = (u)r[16] + (u)0; if (c) goto L800ce528;
    r[4] = (u)r[16] + (u)0; CALL(R_GV_DestroyActor);
    r[2] = (u)0 + (u)0; goto L800ce528;
    L800ce524:;
    r[2] = (u)r[16] + (u)0;
    L800ce528:;
    r[31] = *(int *)((u)r[29] + 28);
    r[18] = *(int *)((u)r[29] + 24);
    r[17] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 32; goto out;
out:
    RECOMP_RETURN;
}
