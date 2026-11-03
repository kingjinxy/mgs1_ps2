extern char R_s10a_dat_800E42FC[] __asm__("s10a_dat_800E42FC");
extern char R_s10a_rc_800E0CCC[] __asm__("s10a_rc_800E0CCC");
extern char R_s10a_rc_800E0E3C[] __asm__("s10a_rc_800E0E3C");
extern char R_GV_DestroyActor[] __asm__("GV_DestroyActor");
extern char R_GV_NewActor[] __asm__("GV_NewActor");
extern char R_GV_SetNamedActor[] __asm__("GV_SetNamedActor");
extern char R_s10a_800E0E58[] __asm__("s10a_800E0E58");
int G_s10a_800E0F4C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s10a_800E0F4C");
int G_s10a_800E0F4C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(32)
    r[29] = (u)r[29] + -32;
    *(int *)((u)r[29] + 20) = r[17];
    r[17] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 24) = r[18];
    r[18] = (u)r[5] + (u)0;
    r[4] = (u)0 + 2;
    r[5] = (u)0 + 60;
    *(int *)((u)r[29] + 28) = r[31];
    *(int *)((u)r[29] + 16) = r[16]; CALL(R_GV_NewActor);
    r[16] = (u)r[2] + (u)0;
    c = ((r[16] == 0)); r[4] = (u)r[16] + (u)0; if (c) goto L800e0fc4;
    r[5] = 0;
    r[5] = (u)r[5] + (int)R_s10a_rc_800E0CCC;
    r[6] = 0;
    r[6] = (u)r[6] + (int)R_s10a_rc_800E0E3C;
    r[7] = 0;
    r[7] = (u)r[7] + ((int)R_s10a_dat_800E42FC + 76); CALL(R_GV_SetNamedActor);
    r[4] = (u)r[16] + (u)0;
    r[5] = (u)r[17] + (u)0;
    r[6] = (u)r[18] + (u)0; CALL(R_s10a_800E0E58);
    c = (((int)r[2] >= 0)); r[2] = (u)r[16] + (u)0; if (c) goto L800e0fc8;
    r[4] = (u)r[16] + (u)0; CALL(R_GV_DestroyActor);
    r[2] = (u)0 + (u)0; goto L800e0fc8;
    L800e0fc4:;
    r[2] = (u)r[16] + (u)0;
    L800e0fc8:;
    r[31] = *(int *)((u)r[29] + 28);
    r[18] = *(int *)((u)r[29] + 24);
    r[17] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 32; goto out;
out:
    return r[2];
}
