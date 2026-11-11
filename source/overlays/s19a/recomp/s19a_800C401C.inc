extern char R_s19a_800C3AD4[] __asm__("s19a_800C3AD4");
extern char R_s19a_800C3FEC[] __asm__("s19a_800C3FEC");
extern char R_s19a_dat_800DF584[] __asm__("s19a_dat_800DF584");
extern char R_s19a_dat_800E0428[] __asm__("s19a_dat_800E0428");
extern char R_s19a_dat_800E042C[] __asm__("s19a_dat_800E042C");
extern char R_s19a_dat_800E0430[] __asm__("s19a_dat_800E0430");
extern char R_s19a_dat_800E0434[] __asm__("s19a_dat_800E0434");
extern char R_s19a_rc_800C4014[] __asm__("s19a_rc_800C4014");
extern char R_DG_GetTexture[] __asm__("DG_GetTexture");
extern char R_GV_NewActor[] __asm__("GV_NewActor");
extern char R_GV_SetNamedActor[] __asm__("GV_SetNamedActor");
extern char R_MENU_SetRadarFunc[] __asm__("MENU_SetRadarFunc");
int G_s19a_800C401C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s19a_800C401C");
int G_s19a_800C401C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    r[2] = 0;
    *(int *)((u)r[2] + (int)R_s19a_dat_800E0428) = r[4];
    r[4] = 0 | 41204;
    r[2] = 0;
    *(int *)((u)r[29] + 20) = r[31];
    *(int *)((u)r[29] + 16) = r[16];
    *(int *)((u)r[2] + (int)R_s19a_dat_800E042C) = r[5]; CALL(R_DG_GetTexture);
    r[4] = 0 | 41404;
    r[3] = 0;
    *(int *)((u)r[3] + (int)R_s19a_dat_800E0430) = r[2]; CALL(R_DG_GetTexture);
    r[4] = (u)0 + 5;
    r[5] = (u)0 + 32;
    r[3] = 0;
    *(int *)((u)r[3] + (int)R_s19a_dat_800E0434) = r[2]; CALL(R_GV_NewActor);
    r[16] = (u)r[2] + (u)0;
    c = ((r[16] == 0)); r[5] = 0; if (c) goto L800c4098;
    r[4] = (u)r[16] + (u)0;
    r[5] = (u)r[5] + (int)R_s19a_rc_800C4014;
    r[6] = 0;
    r[7] = 0;
    r[6] = (u)r[6] + (int)R_s19a_800C3FEC;
    r[7] = (u)r[7] + ((int)R_s19a_dat_800DF584 + 4); CALL(R_GV_SetNamedActor);
    r[4] = 0;
    r[4] = (u)r[4] + (int)R_s19a_800C3AD4; CALL(R_MENU_SetRadarFunc);
    L800c4098:;
    r[2] = (u)r[16] + (u)0;
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
