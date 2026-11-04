extern char R_s11b_800CCADC[] __asm__("s11b_800CCADC");
extern char R_s11b_dat_800DB028[] __asm__("s11b_dat_800DB028");
extern char R_s11b_rc_800CC888[] __asm__("s11b_rc_800CC888");
extern char R_GV_DestroyActor[] __asm__("GV_DestroyActor");
extern char R_GV_NewActor[] __asm__("GV_NewActor");
extern char R_GV_SetNamedActor[] __asm__("GV_SetNamedActor");
extern char R_s11b_800CCB0C[] __asm__("s11b_800CCB0C");
int G_s11b_800CCC30(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s11b_800CCC30");
int G_s11b_800CCC30(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(32)
    r[29] = (u)r[29] + -32;
    *(int *)((u)r[29] + 20) = r[17];
    r[17] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 24) = r[18];
    r[18] = (u)r[5] + (u)0;
    r[4] = (u)0 + 3;
    r[5] = (u)0 + 60;
    *(int *)((u)r[29] + 28) = r[31];
    *(int *)((u)r[29] + 16) = r[16]; CALL(R_GV_NewActor);
    r[16] = (u)r[2] + (u)0;
    c = ((r[16] == 0)); r[4] = (u)r[16] + (u)0; if (c) goto L800cccac;
    r[5] = 0;
    r[5] = (u)r[5] + (int)R_s11b_rc_800CC888;
    r[6] = 0;
    r[6] = (u)r[6] + (int)R_s11b_800CCADC;
    r[7] = 0;
    r[7] = (u)r[7] + ((int)R_s11b_dat_800DB028 + 20); CALL(R_GV_SetNamedActor);
    r[4] = (u)r[16] + (u)0;
    r[5] = (u)r[17] + (u)0;
    r[6] = (u)r[18] + (u)0; CALL(R_s11b_800CCB0C);
    c = (((int)r[2] >= 0)); r[2] = (u)0 + 25342; if (c) goto L800ccca8;
    r[4] = (u)r[16] + (u)0; CALL(R_GV_DestroyActor);
    r[2] = (u)0 + (u)0; goto L800cccb0;
    L800ccca8:;
    *(int *)((u)r[16] + 32) = r[2];
    L800cccac:;
    r[2] = (u)r[16] + (u)0;
    L800cccb0:;
    r[31] = *(int *)((u)r[29] + 28);
    r[18] = *(int *)((u)r[29] + 24);
    r[17] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 32; goto out;
out:
    RECOMP_RETURN;
}
