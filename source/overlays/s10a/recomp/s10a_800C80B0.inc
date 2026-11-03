extern char R_s10a_800C7F50[] __asm__("s10a_800C7F50");
extern char R_s10a_dat_800E3824[] __asm__("s10a_dat_800E3824");
extern char R_s10a_rc_800C8030[] __asm__("s10a_rc_800C8030");
extern char R_GV_NewActor[] __asm__("GV_NewActor");
extern char R_GV_SetNamedActor[] __asm__("GV_SetNamedActor");
extern char R_s10a_800C8038[] __asm__("s10a_800C8038");
int G_s10a_800C80B0(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s10a_800C80B0");
int G_s10a_800C80B0(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(40)
    r[29] = (u)r[29] + -40;
    *(int *)((u)r[29] + 20) = r[17];
    r[17] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 24) = r[18];
    r[18] = (u)r[5] + (u)0;
    *(int *)((u)r[29] + 28) = r[19];
    r[19] = (u)r[6] + (u)0;
    *(int *)((u)r[29] + 32) = r[20];
    r[20] = (u)r[7] + (u)0;
    r[4] = (u)0 + 4;
    r[5] = (u)0 + 56;
    *(int *)((u)r[29] + 36) = r[31];
    *(int *)((u)r[29] + 16) = r[16]; CALL(R_GV_NewActor);
    r[16] = (u)r[2] + (u)0;
    c = ((r[16] == 0)); r[4] = (u)r[16] + (u)0; if (c) goto L800c8128;
    r[5] = 0;
    r[5] = (u)r[5] + (int)R_s10a_800C7F50;
    r[6] = 0;
    r[7] = 0;
    r[6] = (u)r[6] + (int)R_s10a_rc_800C8030;
    r[7] = (u)r[7] + ((int)R_s10a_dat_800E3824 + 20); CALL(R_GV_SetNamedActor);
    r[4] = (u)r[16] + (u)0;
    *(int *)((u)r[16] + 32) = r[17];
    *(int *)((u)r[16] + 36) = r[18];
    *(int *)((u)r[16] + 48) = r[19];
    *(int *)((u)r[16] + 52) = r[20]; CALL(R_s10a_800C8038);
    L800c8128:;
    r[2] = (u)r[16] + (u)0;
    r[31] = *(int *)((u)r[29] + 36);
    r[20] = *(int *)((u)r[29] + 32);
    r[19] = *(int *)((u)r[29] + 28);
    r[18] = *(int *)((u)r[29] + 24);
    r[17] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 40; goto out;
out:
    RECOMP_RETURN;
}
