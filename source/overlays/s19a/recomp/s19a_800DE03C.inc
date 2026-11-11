extern char R_s19a_800DDDC0[] __asm__("s19a_800DDDC0");
extern char R_s19a_dat_800E0402[] __asm__("s19a_dat_800E0402");
extern char R_s19a_rc_800DDE8C[] __asm__("s19a_rc_800DDE8C");
extern char R_GV_NewActor[] __asm__("GV_NewActor");
extern char R_GV_SetNamedActor[] __asm__("GV_SetNamedActor");
extern char R_s19a_800D87B4[] __asm__("s19a_800D87B4");
extern char R_s19a_800DDE9C[] __asm__("s19a_800DDE9C");
int G_s19a_800DE03C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s19a_800DE03C");
int G_s19a_800DE03C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(40)
    r[29] = (u)r[29] + -40;
    *(int *)((u)r[29] + 20) = r[17];
    r[17] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 24) = r[18];
    r[18] = (u)r[5] + (u)0;
    *(int *)((u)r[29] + 28) = r[19];
    r[19] = (u)r[6] + (u)0;
    r[4] = (u)0 + 116;
    r[2] = (u)0 + 1;
    *(int *)((u)r[29] + 32) = r[31];
    *(int *)((u)r[29] + 16) = r[16];
    *(int *)((u)r[17] + 32) = r[18];
    *(int *)((u)r[17] + 40) = r[2]; CALL(R_s19a_800D87B4);
    r[4] = (u)0 + 101;
    *(int *)((u)r[17] + 44) = r[2]; CALL(R_s19a_800D87B4);
    r[4] = (u)0 + 2;
    r[5] = (u)0 + 64;
    *(int *)((u)r[17] + 48) = r[2]; CALL(R_GV_NewActor);
    r[16] = (u)r[2] + (u)0;
    c = ((r[16] == 0)); *(int *)((u)r[17] + 36) = r[16]; if (c) goto L800de0e8;
    r[4] = (u)r[16] + (u)0;
    r[5] = 0;
    r[5] = (u)r[5] + (int)R_s19a_800DDDC0;
    r[6] = 0;
    r[6] = (u)r[6] + (int)R_s19a_rc_800DDE8C;
    r[7] = 0;
    r[7] = (u)r[7] + ((int)R_s19a_dat_800E0402 + 2); CALL(R_GV_SetNamedActor);
    r[4] = (u)r[16] + (u)0;
    r[5] = (u)r[18] + (u)0;
    r[6] = (u)r[19] + (u)0; CALL(R_s19a_800DDE9C);
    r[2] = (u)0 + (u)0;
    r[3] = (u)r[17] + 44;
    *(int *)((u)r[16] + 56) = r[3];
    r[3] = (u)r[17] + 40;
    *(int *)((u)r[16] + 60) = r[3];
    *(int *)((u)r[17] + 40) = 0; goto L800de0ec;
    L800de0e8:;
    r[2] = (u)0 + -1;
    L800de0ec:;
    r[31] = *(int *)((u)r[29] + 32);
    r[19] = *(int *)((u)r[29] + 28);
    r[18] = *(int *)((u)r[29] + 24);
    r[17] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 40; goto out;
out:
    RECOMP_RETURN;
}
