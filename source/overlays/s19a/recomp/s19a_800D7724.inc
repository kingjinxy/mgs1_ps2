extern char R_s19a_800D7464[] __asm__("s19a_800D7464");
extern char R_s19a_dat_800E0300[] __asm__("s19a_dat_800E0300");
extern char R_s19a_rc_800D74B0[] __asm__("s19a_rc_800D74B0");
extern char R_GV_NewActor[] __asm__("GV_NewActor");
extern char R_GV_SetNamedActor[] __asm__("GV_SetNamedActor");
extern char R_s19a_800D74FC[] __asm__("s19a_800D74FC");
int G_s19a_800D7724(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s19a_800D7724");
int G_s19a_800D7724(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(32)
    r[29] = (u)r[29] + -32;
    *(int *)((u)r[29] + 20) = r[17];
    r[17] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 24) = r[18];
    r[18] = (u)r[5] + (u)0;
    r[4] = (u)0 + 4;
    r[5] = (u)0 + 36;
    *(int *)((u)r[29] + 28) = r[31];
    *(int *)((u)r[29] + 16) = r[16]; CALL(R_GV_NewActor);
    r[16] = (u)r[2] + (u)0;
    c = ((r[16] == 0)); r[4] = (u)r[16] + (u)0; if (c) goto L800d7784;
    r[5] = 0;
    r[5] = (u)r[5] + (int)R_s19a_800D7464;
    r[6] = 0;
    r[6] = (u)r[6] + (int)R_s19a_rc_800D74B0;
    r[7] = 0;
    r[7] = (u)r[7] + ((int)R_s19a_dat_800E0300 + 12); CALL(R_GV_SetNamedActor);
    r[4] = (u)r[16] + (u)0;
    r[5] = (u)r[17] + (u)0;
    r[6] = (u)r[18] + (u)0; CALL(R_s19a_800D74FC);
    L800d7784:;
    r[2] = (u)r[16] + (u)0;
    r[31] = *(int *)((u)r[29] + 28);
    r[18] = *(int *)((u)r[29] + 24);
    r[17] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 32; goto out;
out:
    RECOMP_RETURN;
}
