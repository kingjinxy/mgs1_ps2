extern char R_s11b_800CD7FC[] __asm__("s11b_800CD7FC");
extern char R_s11b_dat_800DB028[] __asm__("s11b_dat_800DB028");
extern char R_s11b_rc_800CD450[] __asm__("s11b_rc_800CD450");
extern char R_GV_DestroyActor[] __asm__("GV_DestroyActor");
extern char R_GV_NewActor[] __asm__("GV_NewActor");
extern char R_GV_SetNamedActor[] __asm__("GV_SetNamedActor");
extern char R_s11b_800CCDB0[] __asm__("s11b_800CCDB0");
extern char R_s11b_800CD82C[] __asm__("s11b_800CD82C");
int G_s11b_800CDB84(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s11b_800CDB84");
int G_s11b_800CDB84(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(32)
    r[29] = (u)r[29] + -32;
    *(int *)((u)r[29] + 24) = r[18];
    r[18] = (u)r[4] + (u)0;
    r[4] = (u)0 + 3;
    r[5] = (u)0 + 84;
    *(int *)((u)r[29] + 28) = r[31];
    *(int *)((u)r[29] + 20) = r[17];
    *(int *)((u)r[29] + 16) = r[16]; CALL(R_GV_NewActor);
    r[17] = (u)r[2] + (u)0;
    c = ((r[17] == 0)); r[4] = (u)r[17] + (u)0; if (c) goto L800cdc10;
    r[5] = 0;
    r[5] = (u)r[5] + (int)R_s11b_rc_800CD450;
    r[6] = 0;
    r[6] = (u)r[6] + (int)R_s11b_800CD7FC;
    r[7] = 0;
    r[7] = (u)r[7] + ((int)R_s11b_dat_800DB028 + 32); CALL(R_GV_SetNamedActor);
    r[4] = (u)0 + 116; CALL(R_s11b_800CCDB0);
    r[4] = (u)0 + 101;
    r[16] = (u)r[2] + (u)0; CALL(R_s11b_800CCDB0);
    r[4] = (u)r[17] + (u)0;
    r[5] = (u)r[16] + (u)0;
    r[6] = (u)r[2] + (u)0; CALL(R_s11b_800CD82C);
    c = (((int)r[2] >= 0));  if (c) goto L800cdc0c;
    r[4] = (u)r[17] + (u)0; CALL(R_GV_DestroyActor);
    r[2] = (u)0 + (u)0; goto L800cdc14;
    L800cdc0c:;
    *(int *)((u)r[17] + 32) = r[18];
    L800cdc10:;
    r[2] = (u)r[17] + (u)0;
    L800cdc14:;
    r[31] = *(int *)((u)r[29] + 28);
    r[18] = *(int *)((u)r[29] + 24);
    r[17] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 32; goto out;
out:
    RECOMP_RETURN;
}
