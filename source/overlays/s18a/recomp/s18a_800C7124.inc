extern char R_s18a_800C6BDC[] __asm__("s18a_800C6BDC");
extern char R_s18a_800C70F4[] __asm__("s18a_800C70F4");
extern char R_s18a_dat_800E2D60[] __asm__("s18a_dat_800E2D60");
extern char R_s18a_dat_800E3EE0[] __asm__("s18a_dat_800E3EE0");
extern char R_s18a_dat_800E3EE4[] __asm__("s18a_dat_800E3EE4");
extern char R_s18a_dat_800E3EE8[] __asm__("s18a_dat_800E3EE8");
extern char R_s18a_dat_800E3EEC[] __asm__("s18a_dat_800E3EEC");
extern char R_s18a_rc_800C711C[] __asm__("s18a_rc_800C711C");
extern char R_DG_GetTexture[] __asm__("DG_GetTexture");
extern char R_GV_NewActor[] __asm__("GV_NewActor");
extern char R_GV_SetNamedActor[] __asm__("GV_SetNamedActor");
extern char R_MENU_SetRadarFunc[] __asm__("MENU_SetRadarFunc");
int G_s18a_800C7124(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s18a_800C7124");
int G_s18a_800C7124(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    r[2] = 0;
    *(int *)((u)r[2] + (int)R_s18a_dat_800E3EE0) = r[4];
    r[4] = 0 | 41204;
    r[2] = 0;
    *(int *)((u)r[29] + 20) = r[31];
    *(int *)((u)r[29] + 16) = r[16];
    *(int *)((u)r[2] + (int)R_s18a_dat_800E3EE4) = r[5]; CALL(R_DG_GetTexture);
    r[4] = 0 | 41404;
    r[3] = 0;
    *(int *)((u)r[3] + (int)R_s18a_dat_800E3EE8) = r[2]; CALL(R_DG_GetTexture);
    r[4] = (u)0 + 5;
    r[5] = (u)0 + 32;
    r[3] = 0;
    *(int *)((u)r[3] + (int)R_s18a_dat_800E3EEC) = r[2]; CALL(R_GV_NewActor);
    r[16] = (u)r[2] + (u)0;
    c = ((r[16] == 0)); r[5] = 0; if (c) goto L800c71a0;
    r[4] = (u)r[16] + (u)0;
    r[5] = (u)r[5] + (int)R_s18a_rc_800C711C;
    r[6] = 0;
    r[7] = 0;
    r[6] = (u)r[6] + (int)R_s18a_800C70F4;
    r[7] = (u)r[7] + ((int)R_s18a_dat_800E2D60 + 24); CALL(R_GV_SetNamedActor);
    r[4] = 0;
    r[4] = (u)r[4] + (int)R_s18a_800C6BDC; CALL(R_MENU_SetRadarFunc);
    L800c71a0:;
    r[2] = (u)r[16] + (u)0;
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
