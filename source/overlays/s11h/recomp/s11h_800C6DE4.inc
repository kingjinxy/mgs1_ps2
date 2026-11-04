extern char R_s11h_800C69C4[] __asm__("s11h_800C69C4");
extern char R_s11h_dat_800DAA10[] __asm__("s11h_dat_800DAA10");
extern char R_s11h_rc_800C6B68[] __asm__("s11h_rc_800C6B68");
extern char R_GV_DestroyActor[] __asm__("GV_DestroyActor");
extern char R_GV_NewActor[] __asm__("GV_NewActor");
extern char R_GV_SetNamedActor[] __asm__("GV_SetNamedActor");
extern char R_s11h_800C6B70[] __asm__("s11h_800C6B70");
int G_s11h_800C6DE4(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s11h_800C6DE4");
int G_s11h_800C6DE4(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    r[4] = (u)0 + 4;
    r[5] = (u)0 + 164;
    *(int *)((u)r[29] + 20) = r[31];
    *(int *)((u)r[29] + 16) = r[16]; CALL(R_GV_NewActor);
    r[16] = (u)r[2] + (u)0;
    c = ((r[16] == 0)); r[4] = (u)r[16] + (u)0; if (c) goto L800c6e44;
    r[5] = 0;
    r[5] = (u)r[5] + (int)R_s11h_800C69C4;
    r[6] = 0;
    r[7] = 0;
    r[6] = (u)r[6] + (int)R_s11h_rc_800C6B68;
    r[7] = (u)r[7] + ((int)R_s11h_dat_800DAA10 + 48); CALL(R_GV_SetNamedActor);
    r[4] = (u)r[16] + (u)0; CALL(R_s11h_800C6B70);
    c = (((int)r[2] >= 0)); r[2] = (u)r[16] + (u)0; if (c) goto L800c6e48;
    r[4] = (u)r[16] + (u)0; CALL(R_GV_DestroyActor);
    r[2] = (u)0 + (u)0; goto L800c6e48;
    L800c6e44:;
    r[2] = (u)r[16] + (u)0;
    L800c6e48:;
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
