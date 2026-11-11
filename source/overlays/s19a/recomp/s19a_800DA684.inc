extern char R_s19a_800DA004[] __asm__("s19a_800DA004");
extern char R_s19a_800DA638[] __asm__("s19a_800DA638");
extern char R_s19a_dat_800E0360[] __asm__("s19a_dat_800E0360");
extern char R_s19a_dat_800E0374[] __asm__("s19a_dat_800E0374");
extern char R_GV_DestroyActor[] __asm__("GV_DestroyActor");
extern char R_GV_NewActor[] __asm__("GV_NewActor");
extern char R_GV_SetNamedActor[] __asm__("GV_SetNamedActor");
extern char R_GV_StrCode[] __asm__("GV_StrCode");
extern char R_s19a_800DA480[] __asm__("s19a_800DA480");
int G_s19a_800DA684(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s19a_800DA684");
int G_s19a_800DA684(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(32)
    r[29] = (u)r[29] + -32;
    *(int *)((u)r[29] + 20) = r[17];
    r[17] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 24) = r[18];
    r[18] = (u)r[5] + (u)0;
    r[4] = (u)0 + 6;
    r[5] = (u)0 + 2392;
    *(int *)((u)r[29] + 28) = r[31];
    *(int *)((u)r[29] + 16) = r[16]; CALL(R_GV_NewActor);
    r[16] = (u)r[2] + (u)0;
    c = ((r[16] == 0)); r[4] = (u)r[16] + (u)0; if (c) goto L800da70c;
    r[5] = 0;
    r[5] = (u)r[5] + (int)R_s19a_800DA004;
    r[6] = 0;
    r[7] = 0;
    r[6] = (u)r[6] + (int)R_s19a_800DA638;
    r[7] = (u)r[7] + ((int)R_s19a_dat_800E0360 + 8); CALL(R_GV_SetNamedActor);
    r[4] = 0;
    r[4] = (u)r[4] + (int)R_s19a_dat_800E0374;
    *(int *)((u)r[16] + 32) = r[17];
    *(int *)((u)r[16] + 36) = r[18]; CALL(R_GV_StrCode);
    r[4] = (u)r[16] + (u)0;
    r[5] = (u)r[2] + (u)0; CALL(R_s19a_800DA480);
    c = (((int)r[2] >= 0)); r[2] = (u)r[16] + (u)0; if (c) goto L800da710;
    r[4] = (u)r[16] + (u)0; CALL(R_GV_DestroyActor);
    r[2] = (u)0 + (u)0; goto L800da710;
    L800da70c:;
    r[2] = (u)r[16] + (u)0;
    L800da710:;
    r[31] = *(int *)((u)r[29] + 28);
    r[18] = *(int *)((u)r[29] + 24);
    r[17] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 32; goto out;
out:
    RECOMP_RETURN;
}
