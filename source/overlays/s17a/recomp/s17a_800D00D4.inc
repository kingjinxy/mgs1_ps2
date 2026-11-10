extern char R_s17a_800CFD4C[] __asm__("s17a_800CFD4C");
extern char R_s17a_dat_800E59B0[] __asm__("s17a_dat_800E59B0");
extern char R_s17a_rc_800CF9A0[] __asm__("s17a_rc_800CF9A0");
extern char R_GV_DestroyActor[] __asm__("GV_DestroyActor");
extern char R_GV_NewActor[] __asm__("GV_NewActor");
extern char R_GV_SetNamedActor[] __asm__("GV_SetNamedActor");
extern char R_s17a_800CE678[] __asm__("s17a_800CE678");
extern char R_s17a_800CFD7C[] __asm__("s17a_800CFD7C");
int G_s17a_800D00D4(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s17a_800D00D4");
int G_s17a_800D00D4(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
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
    c = ((r[17] == 0)); r[4] = (u)r[17] + (u)0; if (c) goto L800d0160;
    r[5] = 0;
    r[5] = (u)r[5] + (int)R_s17a_rc_800CF9A0;
    r[6] = 0;
    r[6] = (u)r[6] + (int)R_s17a_800CFD4C;
    r[7] = 0;
    r[7] = (u)r[7] + ((int)R_s17a_dat_800E59B0 + 52); CALL(R_GV_SetNamedActor);
    r[4] = (u)0 + 116; CALL(R_s17a_800CE678);
    r[4] = (u)0 + 101;
    r[16] = (u)r[2] + (u)0; CALL(R_s17a_800CE678);
    r[4] = (u)r[17] + (u)0;
    r[5] = (u)r[16] + (u)0;
    r[6] = (u)r[2] + (u)0; CALL(R_s17a_800CFD7C);
    c = (((int)r[2] >= 0));  if (c) goto L800d015c;
    r[4] = (u)r[17] + (u)0; CALL(R_GV_DestroyActor);
    r[2] = (u)0 + (u)0; goto L800d0164;
    L800d015c:;
    *(int *)((u)r[17] + 32) = r[18];
    L800d0160:;
    r[2] = (u)r[17] + (u)0;
    L800d0164:;
    r[31] = *(int *)((u)r[29] + 28);
    r[18] = *(int *)((u)r[29] + 24);
    r[17] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 32; goto out;
out:
    RECOMP_RETURN;
}
