extern char R_s10a_800C4378[] __asm__("s10a_800C4378");
extern char R_s10a_dat_800E3628[] __asm__("s10a_dat_800E3628");
extern char R_s10a_rc_800C4484[] __asm__("s10a_rc_800C4484");
extern char R_GV_DestroyActor[] __asm__("GV_DestroyActor");
extern char R_GV_NewActor[] __asm__("GV_NewActor");
extern char R_GV_SetNamedActor[] __asm__("GV_SetNamedActor");
extern char R_s10a_800C448C[] __asm__("s10a_800C448C");
int G_s10a_800C44F4(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s10a_800C44F4");
int G_s10a_800C44F4(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(32)
    r[29] = (u)r[29] + -32;
    *(int *)((u)r[29] + 20) = r[17];
    r[17] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 24) = r[18];
    r[18] = (u)r[5] + (u)0;
    r[4] = (u)0 + 5;
    r[5] = (u)0 + 40;
    *(int *)((u)r[29] + 28) = r[31];
    *(int *)((u)r[29] + 16) = r[16]; CALL(R_GV_NewActor);
    r[16] = (u)r[2] + (u)0;
    c = ((r[16] == 0)); r[5] = 0; if (c) goto L800c4564;
    r[4] = (u)r[16] + (u)0;
    r[5] = (u)r[5] + (int)R_s10a_800C4378;
    r[6] = 0;
    r[6] = (u)r[6] + (int)R_s10a_rc_800C4484;
    r[7] = 0;
    r[7] = (u)r[7] + ((int)R_s10a_dat_800E3628 + 52); CALL(R_GV_SetNamedActor);
    r[4] = (u)r[16] + (u)0;
    r[5] = (u)r[17] + (u)0;
    r[6] = (u)r[18] + (u)0; CALL(R_s10a_800C448C);
    c = (((int)r[2] >= 0)); r[2] = (u)r[16] + (u)0; if (c) goto L800c4568;
    r[4] = (u)r[16] + (u)0; CALL(R_GV_DestroyActor);
    L800c4564:;
    r[2] = (u)0 + (u)0;
    L800c4568:;
    r[31] = *(int *)((u)r[29] + 28);
    r[18] = *(int *)((u)r[29] + 24);
    r[17] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 32; goto out;
out:
    return r[2];
}
