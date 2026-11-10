extern char R_s17a_800CB074[] __asm__("s17a_800CB074");
extern char R_s17a_dat_800E57A8[] __asm__("s17a_dat_800E57A8");
extern char R_s17a_rc_800CB2D4[] __asm__("s17a_rc_800CB2D4");
extern char R_GV_NewActor[] __asm__("GV_NewActor");
extern char R_GV_SetNamedActor[] __asm__("GV_SetNamedActor");
extern char R_s17a_800CB2DC[] __asm__("s17a_800CB2DC");
int G_s17a_800CB34C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s17a_800CB34C");
int G_s17a_800CB34C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(48)
    r[29] = (u)r[29] + -48;
    *(int *)((u)r[29] + 28) = r[17];
    r[17] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 32) = r[18];
    r[18] = (u)r[5] + (u)0;
    *(int *)((u)r[29] + 36) = r[19];
    r[19] = (u)r[6] + (u)0;
    *(int *)((u)r[29] + 40) = r[20];
    r[20] = (u)r[7] + (u)0;
    r[4] = (u)0 + 4;
    r[5] = (u)0 + 72;
    *(int *)((u)r[29] + 44) = r[31];
    *(int *)((u)r[29] + 24) = r[16]; CALL(R_GV_NewActor);
    r[16] = (u)r[2] + (u)0;
    c = ((r[16] == 0)); r[4] = (u)r[16] + (u)0; if (c) goto L800cb3cc;
    r[5] = 0;
    r[5] = (u)r[5] + (int)R_s17a_800CB074;
    r[6] = 0;
    r[6] = (u)r[6] + (int)R_s17a_rc_800CB2D4;
    r[7] = 0;
    r[7] = (u)r[7] + ((int)R_s17a_dat_800E57A8 + 24); CALL(R_GV_SetNamedActor);
    r[4] = (u)r[16] + (u)0;
    r[5] = (u)r[17] + (u)0;
    r[6] = (u)r[18] + (u)0;
    r[2] = *(int *)((u)r[29] + 64);
    r[7] = (u)r[19] + (u)0;
    *(int *)((u)r[29] + 16) = r[20];
    *(int *)((u)r[29] + 20) = r[2]; CALL(R_s17a_800CB2DC);
    L800cb3cc:;
    r[2] = (u)r[16] + (u)0;
    r[31] = *(int *)((u)r[29] + 44);
    r[20] = *(int *)((u)r[29] + 40);
    r[19] = *(int *)((u)r[29] + 36);
    r[18] = *(int *)((u)r[29] + 32);
    r[17] = *(int *)((u)r[29] + 28);
    r[16] = *(int *)((u)r[29] + 24);
    r[29] = (u)r[29] + 48; goto out;
out:
    RECOMP_RETURN;
}
