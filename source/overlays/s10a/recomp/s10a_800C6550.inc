extern char R_s10a_800C6130[] __asm__("s10a_800C6130");
extern char R_s10a_dat_800E36CC[] __asm__("s10a_dat_800E36CC");
extern char R_s10a_rc_800C62D4[] __asm__("s10a_rc_800C62D4");
extern char R_GV_DestroyActor[] __asm__("GV_DestroyActor");
extern char R_GV_NewActor[] __asm__("GV_NewActor");
extern char R_GV_SetNamedActor[] __asm__("GV_SetNamedActor");
extern char R_s10a_800C62DC[] __asm__("s10a_800C62DC");
int G_s10a_800C6550(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s10a_800C6550");
int G_s10a_800C6550(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    r[4] = (u)0 + 4;
    r[5] = (u)0 + 164;
    *(int *)((u)r[29] + 20) = r[31];
    *(int *)((u)r[29] + 16) = r[16]; CALL(R_GV_NewActor);
    r[16] = (u)r[2] + (u)0;
    c = ((r[16] == 0)); r[4] = (u)r[16] + (u)0; if (c) goto L800c65b0;
    r[5] = 0;
    r[5] = (u)r[5] + (int)R_s10a_800C6130;
    r[6] = 0;
    r[7] = 0;
    r[6] = (u)r[6] + (int)R_s10a_rc_800C62D4;
    r[7] = (u)r[7] + ((int)R_s10a_dat_800E36CC + 48); CALL(R_GV_SetNamedActor);
    r[4] = (u)r[16] + (u)0; CALL(R_s10a_800C62DC);
    c = (((int)r[2] >= 0)); r[2] = (u)r[16] + (u)0; if (c) goto L800c65b4;
    r[4] = (u)r[16] + (u)0; CALL(R_GV_DestroyActor);
    r[2] = (u)0 + (u)0; goto L800c65b4;
    L800c65b0:;
    r[2] = (u)r[16] + (u)0;
    L800c65b4:;
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
