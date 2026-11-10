extern char R_s17a_800CD11C[] __asm__("s17a_800CD11C");
extern char R_s17a_800CD290[] __asm__("s17a_800CD290");
extern char R_s17a_dat_800E58F8[] __asm__("s17a_dat_800E58F8");
extern char R_GV_DestroyActor[] __asm__("GV_DestroyActor");
extern char R_GV_NewActor[] __asm__("GV_NewActor");
extern char R_GV_SetNamedActor[] __asm__("GV_SetNamedActor");
extern char R_s17a_800CD2C0[] __asm__("s17a_800CD2C0");
int G_s17a_800CD3D8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s17a_800CD3D8");
int G_s17a_800CD3D8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(40)
    r[29] = (u)r[29] + -40;
    *(int *)((u)r[29] + 20) = r[17];
    r[17] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 24) = r[18];
    r[18] = (u)r[5] + (u)0;
    *(int *)((u)r[29] + 28) = r[19];
    r[19] = (u)r[6] + (u)0;
    r[4] = (u)0 + 7;
    r[5] = (u)0 + 128;
    *(int *)((u)r[29] + 32) = r[31];
    *(int *)((u)r[29] + 16) = r[16]; CALL(R_GV_NewActor);
    r[16] = (u)r[2] + (u)0;
    c = ((r[16] == 0)); r[4] = (u)r[16] + (u)0; if (c) goto L800cd460;
    r[5] = 0;
    r[5] = (u)r[5] + (int)R_s17a_800CD11C;
    r[6] = 0;
    r[6] = (u)r[6] + (int)R_s17a_800CD290;
    r[7] = 0;
    r[7] = (u)r[7] + ((int)R_s17a_dat_800E58F8 + 116); CALL(R_GV_SetNamedActor);
    r[4] = (u)r[16] + (u)0;
    r[5] = (u)r[17] + (u)0;
    r[6] = (u)r[18] + (u)0;
    r[7] = (u)r[19] + (u)0; CALL(R_s17a_800CD2C0);
    c = (((int)r[2] >= 0)); r[2] = (u)0 + -1; if (c) goto L800cd45c;
    r[4] = (u)r[16] + (u)0; CALL(R_GV_DestroyActor);
    r[2] = (u)0 + (u)0; goto L800cd464;
    L800cd45c:;
    *(int *)((u)r[16] + 32) = r[2];
    L800cd460:;
    r[2] = (u)r[16] + (u)0;
    L800cd464:;
    r[31] = *(int *)((u)r[29] + 32);
    r[19] = *(int *)((u)r[29] + 28);
    r[18] = *(int *)((u)r[29] + 24);
    r[17] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 40; goto out;
out:
    RECOMP_RETURN;
}
