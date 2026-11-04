extern char R_s11b_800D9A78[] __asm__("s11b_800D9A78");
extern char R_s11b_800D9B40[] __asm__("s11b_800D9B40");
extern char R_s11b_dat_800DB26C[] __asm__("s11b_dat_800DB26C");
extern char R_GV_DestroyActor[] __asm__("GV_DestroyActor");
extern char R_GV_NewActor[] __asm__("GV_NewActor");
extern char R_GV_SetNamedActor[] __asm__("GV_SetNamedActor");
extern char R_s11b_800D9D5C[] __asm__("s11b_800D9D5C");
int G_s11b_800D9DEC(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s11b_800D9DEC");
int G_s11b_800D9DEC(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(48)
    r[29] = (u)r[29] + -48;
    *(int *)((u)r[29] + 32) = r[18];
    r[18] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 36) = r[19];
    r[19] = (u)r[5] + (u)0;
    *(int *)((u)r[29] + 40) = r[20];
    r[20] = (u)r[6] + (u)0;
    *(int *)((u)r[29] + 28) = r[17];
    r[17] = (u)r[7] + (u)0;
    r[4] = (u)0 + 5;
    r[5] = (u)0 + 208;
    *(int *)((u)r[29] + 44) = r[31];
    *(int *)((u)r[29] + 24) = r[16]; CALL(R_GV_NewActor);
    r[16] = (u)r[2] + (u)0;
    c = ((r[16] == 0)); r[4] = (u)r[16] + (u)0; if (c) goto L800d9e7c;
    r[5] = 0;
    r[5] = (u)r[5] + (int)R_s11b_800D9A78;
    r[6] = 0;
    r[6] = (u)r[6] + (int)R_s11b_800D9B40;
    r[7] = 0;
    r[7] = (u)r[7] + ((int)R_s11b_dat_800DB26C + 12); CALL(R_GV_SetNamedActor);
    *(int *)((u)r[29] + 16) = r[17];
    r[4] = (u)r[16] + (u)0;
    r[5] = (u)r[18] + (u)0;
    r[6] = (u)r[19] + (u)0;
    r[7] = (u)r[20] + (u)0; CALL(R_s11b_800D9D5C);
    c = (((int)r[2] >= 0)); r[2] = (u)r[16] + (u)0; if (c) goto L800d9e80;
    r[4] = (u)r[16] + (u)0; CALL(R_GV_DestroyActor);
    r[2] = (u)0 + (u)0; goto L800d9e80;
    L800d9e7c:;
    r[2] = (u)r[16] + (u)0;
    L800d9e80:;
    r[31] = *(int *)((u)r[29] + 44);
    r[20] = *(int *)((u)r[29] + 40);
    r[19] = *(int *)((u)r[29] + 36);
    r[18] = *(int *)((u)r[29] + 32);
    r[17] = *(int *)((u)r[29] + 28);
    r[16] = *(int *)((u)r[29] + 24);
    r[29] = (u)r[29] + 48; goto out;
out:
    RECOMP_RETURN;
}
