extern char R_s10a_800C5074[] __asm__("s10a_800C5074");
extern char R_s10a_dat_800E3628[] __asm__("s10a_dat_800E3628");
extern char R_s10a_rc_800C5140[] __asm__("s10a_rc_800C5140");
extern char R_GV_NewActor[] __asm__("GV_NewActor");
extern char R_GV_SetNamedActor[] __asm__("GV_SetNamedActor");
extern char R_s10a_800C5148[] __asm__("s10a_800C5148");
int G_s10a_800C51C0(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s10a_800C51C0");
int G_s10a_800C51C0(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    r[4] = (u)0 + 4;
    r[5] = (u)0 + 40;
    *(int *)((u)r[29] + 20) = r[31];
    *(int *)((u)r[29] + 16) = r[16]; CALL(R_GV_NewActor);
    r[16] = (u)r[2] + (u)0;
    c = ((r[16] == 0)); r[5] = 0; if (c) goto L800c5208;
    r[4] = (u)r[16] + (u)0;
    r[5] = (u)r[5] + (int)R_s10a_800C5074;
    r[6] = 0;
    r[7] = 0;
    r[6] = (u)r[6] + (int)R_s10a_rc_800C5140;
    r[7] = (u)r[7] + ((int)R_s10a_dat_800E3628 + 64); CALL(R_GV_SetNamedActor);
    r[4] = (u)r[16] + (u)0; CALL(R_s10a_800C5148);
    L800c5208:;
    r[2] = (u)r[16] + (u)0;
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    return r[2];
}
