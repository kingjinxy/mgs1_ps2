extern char R_s15a_800D767C[] __asm__("s15a_800D767C");
extern char R_s15a_dat_800D917C[] __asm__("s15a_dat_800D917C");
extern char R_s15a_rc_800D79EC[] __asm__("s15a_rc_800D79EC");
extern char R_GV_DestroyActor[] __asm__("GV_DestroyActor");
extern char R_GV_NewActor[] __asm__("GV_NewActor");
extern char R_GV_SetNamedActor[] __asm__("GV_SetNamedActor");
extern char R_s15a_800D79F4[] __asm__("s15a_800D79F4");
int G_s15a_800D7A20(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s15a_800D7A20");
int G_s15a_800D7A20(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    r[4] = (u)0 + 7;
    r[5] = (u)0 + 36;
    *(int *)((u)r[29] + 20) = r[31];
    *(int *)((u)r[29] + 16) = r[16]; CALL(R_GV_NewActor);
    r[16] = (u)r[2] + (u)0;
    c = ((r[16] == 0)); r[4] = (u)r[16] + (u)0; if (c) goto L800d7a80;
    r[5] = 0;
    r[5] = (u)r[5] + (int)R_s15a_rc_800D79EC;
    r[6] = 0;
    r[7] = 0;
    r[6] = (u)r[6] + (int)R_s15a_800D767C;
    r[7] = (u)r[7] + ((int)R_s15a_dat_800D917C + 88); CALL(R_GV_SetNamedActor);
    r[4] = (u)r[16] + (u)0; CALL(R_s15a_800D79F4);
    c = (((int)r[2] >= 0)); r[2] = (u)r[16] + (u)0; if (c) goto L800d7a84;
    r[4] = (u)r[16] + (u)0; CALL(R_GV_DestroyActor);
    r[2] = (u)0 + (u)0; goto L800d7a84;
    L800d7a80:;
    r[2] = (u)r[16] + (u)0;
    L800d7a84:;
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
