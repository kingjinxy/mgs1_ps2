extern char R_s19a_800DB53C[] __asm__("s19a_800DB53C");
extern char R_s19a_800DB860[] __asm__("s19a_800DB860");
extern char R_s19a_dat_800E0380[] __asm__("s19a_dat_800E0380");
extern char R_s19a_dat_800E0388[] __asm__("s19a_dat_800E0388");
extern char R_GV_DestroyActor[] __asm__("GV_DestroyActor");
extern char R_GV_NewActor[] __asm__("GV_NewActor");
extern char R_GV_SetNamedActor[] __asm__("GV_SetNamedActor");
extern char R_GV_StrCode[] __asm__("GV_StrCode");
extern char R_s19a_800DB668[] __asm__("s19a_800DB668");
int G_s19a_800DB89C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s19a_800DB89C");
int G_s19a_800DB89C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(40)
    r[29] = (u)r[29] + -40;
    *(int *)((u)r[29] + 20) = r[17];
    r[17] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 24) = r[18];
    r[18] = (u)r[5] + (u)0;
    *(int *)((u)r[29] + 28) = r[19];
    r[19] = (u)r[6] + (u)0;
    r[4] = (u)0 + 6;
    r[5] = (u)0 + 2080;
    *(int *)((u)r[29] + 32) = r[31];
    *(int *)((u)r[29] + 16) = r[16]; CALL(R_GV_NewActor);
    r[16] = (u)r[2] + (u)0;
    c = ((r[16] == 0)); r[4] = (u)r[16] + (u)0; if (c) goto L800db930;
    r[5] = 0;
    r[5] = (u)r[5] + (int)R_s19a_800DB53C;
    r[6] = 0;
    r[6] = (u)r[6] + (int)R_s19a_800DB860;
    r[7] = 0;
    r[7] = (u)r[7] + ((int)R_s19a_dat_800E0388 + 24); CALL(R_GV_SetNamedActor);
    r[4] = 0;
    r[4] = (u)r[4] + (int)R_s19a_dat_800E0380;
    *(int *)((u)r[16] + 32) = r[17];
    *(int *)((u)r[16] + 36) = r[18]; CALL(R_GV_StrCode);
    r[4] = (u)r[16] + (u)0;
    r[5] = (u)r[2] + (u)0;
    r[6] = (u)r[19] + (u)0; CALL(R_s19a_800DB668);
    c = (((int)r[2] >= 0)); r[2] = (u)r[16] + (u)0; if (c) goto L800db934;
    r[4] = (u)r[16] + (u)0; CALL(R_GV_DestroyActor);
    r[2] = (u)0 + (u)0; goto L800db934;
    L800db930:;
    r[2] = (u)r[16] + (u)0;
    L800db934:;
    r[31] = *(int *)((u)r[29] + 32);
    r[19] = *(int *)((u)r[29] + 28);
    r[18] = *(int *)((u)r[29] + 24);
    r[17] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 40; goto out;
out:
    RECOMP_RETURN;
}
