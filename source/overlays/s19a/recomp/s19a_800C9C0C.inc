extern char R_s19a_800C97EC[] __asm__("s19a_800C97EC");
extern char R_s19a_dat_800DFD2C[] __asm__("s19a_dat_800DFD2C");
extern char R_s19a_rc_800C9990[] __asm__("s19a_rc_800C9990");
extern char R_GV_DestroyActor[] __asm__("GV_DestroyActor");
extern char R_GV_NewActor[] __asm__("GV_NewActor");
extern char R_GV_SetNamedActor[] __asm__("GV_SetNamedActor");
extern char R_s19a_800C9998[] __asm__("s19a_800C9998");
int G_s19a_800C9C0C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s19a_800C9C0C");
int G_s19a_800C9C0C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    r[4] = (u)0 + 4;
    r[5] = (u)0 + 164;
    *(int *)((u)r[29] + 20) = r[31];
    *(int *)((u)r[29] + 16) = r[16]; CALL(R_GV_NewActor);
    r[16] = (u)r[2] + (u)0;
    c = ((r[16] == 0)); r[4] = (u)r[16] + (u)0; if (c) goto L800c9c6c;
    r[5] = 0;
    r[5] = (u)r[5] + (int)R_s19a_800C97EC;
    r[6] = 0;
    r[7] = 0;
    r[6] = (u)r[6] + (int)R_s19a_rc_800C9990;
    r[7] = (u)r[7] + ((int)R_s19a_dat_800DFD2C + 48); CALL(R_GV_SetNamedActor);
    r[4] = (u)r[16] + (u)0; CALL(R_s19a_800C9998);
    c = (((int)r[2] >= 0)); r[2] = (u)r[16] + (u)0; if (c) goto L800c9c70;
    r[4] = (u)r[16] + (u)0; CALL(R_GV_DestroyActor);
    r[2] = (u)0 + (u)0; goto L800c9c70;
    L800c9c6c:;
    r[2] = (u)r[16] + (u)0;
    L800c9c70:;
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
