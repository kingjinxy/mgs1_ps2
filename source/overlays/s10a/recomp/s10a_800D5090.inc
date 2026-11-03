extern char R_s10a_800D4FA0[] __asm__("s10a_800D4FA0");
extern char R_s10a_800D5018[] __asm__("s10a_800D5018");
extern char R_s10a_dat_800E4034[] __asm__("s10a_dat_800E4034");
extern char R_GV_DestroyActor[] __asm__("GV_DestroyActor");
extern char R_GV_NewActor[] __asm__("GV_NewActor");
extern char R_GV_SetNamedActor[] __asm__("GV_SetNamedActor");
extern char R_s10a_800D5048[] __asm__("s10a_800D5048");
int G_s10a_800D5090(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s10a_800D5090");
int G_s10a_800D5090(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    r[4] = (u)0 + 7;
    r[5] = (u)0 + 44;
    *(int *)((u)r[29] + 20) = r[31];
    *(int *)((u)r[29] + 16) = r[16]; CALL(R_GV_NewActor);
    r[16] = (u)r[2] + (u)0;
    c = ((r[16] == 0)); r[4] = (u)r[16] + (u)0; if (c) goto L800d50f4;
    r[5] = 0;
    r[5] = (u)r[5] + (int)R_s10a_800D4FA0;
    r[6] = 0;
    r[7] = 0;
    r[6] = (u)r[6] + (int)R_s10a_800D5018;
    r[7] = (u)r[7] + ((int)R_s10a_dat_800E4034 + 32); CALL(R_GV_SetNamedActor);
    r[4] = (u)r[16] + (u)0; CALL(R_s10a_800D5048);
    c = (((int)r[2] >= 0)); r[2] = (u)0 + -1; if (c) goto L800d50f0;
    r[4] = (u)r[16] + (u)0; CALL(R_GV_DestroyActor);
    r[2] = (u)0 + (u)0; goto L800d50f8;
    L800d50f0:;
    *(int *)((u)r[16] + 40) = r[2];
    L800d50f4:;
    r[2] = (u)r[16] + (u)0;
    L800d50f8:;
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    return r[2];
}
