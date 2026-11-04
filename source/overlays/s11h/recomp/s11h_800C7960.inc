extern char R_s11h_800C70C0[] __asm__("s11h_800C70C0");
extern char R_s11h_800C73AC[] __asm__("s11h_800C73AC");
extern char R_s11h_dat_800DAA74[] __asm__("s11h_dat_800DAA74");
extern char R_GV_DestroyActor[] __asm__("GV_DestroyActor");
extern char R_GV_NewActor[] __asm__("GV_NewActor");
extern char R_GV_SetNamedActor[] __asm__("GV_SetNamedActor");
extern char R_s11h_800C768C[] __asm__("s11h_800C768C");
int G_s11h_800C7960(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s11h_800C7960");
int G_s11h_800C7960(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(56)
    r[29] = (u)r[29] + -56;
    *(int *)((u)r[29] + 36) = r[17];
    r[17] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 40) = r[18];
    r[18] = (u)r[5] + (u)0;
    *(int *)((u)r[29] + 44) = r[19];
    r[19] = (u)r[6] + (u)0;
    *(int *)((u)r[29] + 48) = r[20];
    r[20] = (u)r[7] + (u)0;
    r[4] = (u)0 + 3;
    r[5] = (u)0 + 112;
    *(int *)((u)r[29] + 52) = r[31];
    *(int *)((u)r[29] + 32) = r[16]; CALL(R_GV_NewActor);
    r[16] = (u)r[2] + (u)0;
    c = ((r[16] == 0)); r[4] = (u)r[16] + (u)0; if (c) goto L800c7a00;
    r[5] = 0;
    r[5] = (u)r[5] + (int)R_s11h_800C70C0;
    r[6] = 0;
    r[6] = (u)r[6] + (int)R_s11h_800C73AC;
    r[7] = 0;
    r[7] = (u)r[7] + ((int)R_s11h_dat_800DAA74 + 20); CALL(R_GV_SetNamedActor);
    r[4] = (u)r[16] + (u)0;
    r[5] = (u)r[17] + (u)0;
    r[2] = *(int *)((u)r[29] + 72);
    r[6] = (u)r[18] + (u)0;
    *(int *)((u)r[29] + 20) = r[2];
    r[2] = *(int *)((u)r[29] + 76);
    r[7] = (u)r[19] + (u)0;
    *(int *)((u)r[29] + 16) = r[20];
    *(int *)((u)r[29] + 24) = r[2]; CALL(R_s11h_800C768C);
    c = (((int)r[2] >= 0)); r[2] = (u)r[16] + (u)0; if (c) goto L800c7a04;
    r[4] = (u)r[16] + (u)0; CALL(R_GV_DestroyActor);
    r[2] = (u)0 + (u)0; goto L800c7a04;
    L800c7a00:;
    r[2] = (u)r[16] + (u)0;
    L800c7a04:;
    r[31] = *(int *)((u)r[29] + 52);
    r[20] = *(int *)((u)r[29] + 48);
    r[19] = *(int *)((u)r[29] + 44);
    r[18] = *(int *)((u)r[29] + 40);
    r[17] = *(int *)((u)r[29] + 36);
    r[16] = *(int *)((u)r[29] + 32);
    r[29] = (u)r[29] + 56; goto out;
out:
    RECOMP_RETURN;
}
