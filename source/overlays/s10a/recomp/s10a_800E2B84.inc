extern char R_s10a_800E2A58[] __asm__("s10a_800E2A58");
extern char R_s10a_dat_800E4354[] __asm__("s10a_dat_800E4354");
extern char R_s10a_rc_800E29AC[] __asm__("s10a_rc_800E29AC");
extern char R_GV_DestroyActor[] __asm__("GV_DestroyActor");
extern char R_GV_NewActor[] __asm__("GV_NewActor");
extern char R_GV_SetNamedActor[] __asm__("GV_SetNamedActor");
extern char R_s10a_800E2A94[] __asm__("s10a_800E2A94");
int G_s10a_800E2B84(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s10a_800E2B84");
int G_s10a_800E2B84(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(40)
    r[29] = (u)r[29] + -40;
    *(int *)((u)r[29] + 20) = r[17];
    r[17] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 24) = r[18];
    r[18] = (u)r[5] + (u)0;
    *(int *)((u)r[29] + 28) = r[19];
    r[19] = (u)r[6] + (u)0;
    r[4] = (u)0 + 7;
    r[5] = (u)0 + 36;
    *(int *)((u)r[29] + 32) = r[31];
    *(int *)((u)r[29] + 16) = r[16]; CALL(R_GV_NewActor);
    r[16] = (u)r[2] + (u)0;
    c = ((r[16] == 0)); r[4] = (u)r[16] + (u)0; if (c) goto L800e2c14;
    r[5] = 0;
    r[5] = (u)r[5] + (int)R_s10a_rc_800E29AC;
    r[6] = 0;
    r[6] = (u)r[6] + (int)R_s10a_800E2A58;
    r[7] = 0;
    r[7] = (u)r[7] + ((int)R_s10a_dat_800E4354 + 72); CALL(R_GV_SetNamedActor);
    r[4] = (u)r[16] + (u)0;
    r[5] = (u)r[17] << 16;
    r[5] = (int)r[5] >> 16;
    r[6] = (u)r[18] << 16;
    r[6] = (int)r[6] >> 16;
    r[7] = (u)r[19] << 16;
    r[7] = (int)r[7] >> 16; CALL(R_s10a_800E2A94);
    c = (((int)r[2] >= 0)); r[2] = (u)r[16] + (u)0; if (c) goto L800e2c18;
    r[4] = (u)r[16] + (u)0; CALL(R_GV_DestroyActor);
    r[2] = (u)0 + (u)0; goto L800e2c18;
    L800e2c14:;
    r[2] = (u)r[16] + (u)0;
    L800e2c18:;
    r[31] = *(int *)((u)r[29] + 32);
    r[19] = *(int *)((u)r[29] + 28);
    r[18] = *(int *)((u)r[29] + 24);
    r[17] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 40; goto out;
out:
    RECOMP_RETURN;
}
