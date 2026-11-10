extern char R_s17a_800E1F70[] __asm__("s17a_800E1F70");
extern char R_s17a_800E24B8[] __asm__("s17a_800E24B8");
extern char R_s17a_dat_800E5CE0[] __asm__("s17a_dat_800E5CE0");
extern char R_GV_DestroyActor[] __asm__("GV_DestroyActor");
extern char R_GV_NewActor[] __asm__("GV_NewActor");
extern char R_GV_SetNamedActor[] __asm__("GV_SetNamedActor");
extern char R_s17a_800E25B4[] __asm__("s17a_800E25B4");
int G_s17a_800E27F0(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s17a_800E27F0");
int G_s17a_800E27F0(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(40)
    r[29] = (u)r[29] + -40;
    *(int *)((u)r[29] + 20) = r[17];
    r[17] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 24) = r[18];
    r[18] = (u)r[5] + (u)0;
    *(int *)((u)r[29] + 28) = r[19];
    r[19] = (u)r[6] + (u)0;
    *(int *)((u)r[29] + 32) = r[20];
    r[20] = (u)r[7] + (u)0;
    r[4] = (u)0 + 5;
    r[5] = (u)0 + 2752;
    *(int *)((u)r[29] + 36) = r[31];
    *(int *)((u)r[29] + 16) = r[16]; CALL(R_GV_NewActor);
    r[16] = (u)r[2] + (u)0;
    c = ((r[16] == 0)); r[4] = (u)r[16] + (u)0; if (c) goto L800e2880;
    r[5] = 0;
    r[5] = (u)r[5] + (int)R_s17a_800E1F70;
    r[6] = 0;
    r[6] = (u)r[6] + (int)R_s17a_800E24B8;
    r[7] = 0;
    r[7] = (u)r[7] + ((int)R_s17a_dat_800E5CE0 + 20); CALL(R_GV_SetNamedActor);
    r[4] = (u)r[16] + (u)0;
    r[5] = (u)r[17] + (u)0;
    r[6] = (u)r[18] + (u)0;
    r[7] = (u)r[19] + (u)0; CALL(R_s17a_800E25B4);
    c = (((int)r[2] >= 0));  if (c) goto L800e287c;
    r[4] = (u)r[16] + (u)0; CALL(R_GV_DestroyActor);
    r[2] = (u)0 + (u)0; goto L800e2884;
    L800e287c:;
    *(int *)((u)r[16] + 228) = r[20];
    L800e2880:;
    r[2] = (u)r[16] + (u)0;
    L800e2884:;
    r[31] = *(int *)((u)r[29] + 36);
    r[20] = *(int *)((u)r[29] + 32);
    r[19] = *(int *)((u)r[29] + 28);
    r[18] = *(int *)((u)r[29] + 24);
    r[17] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 40; goto out;
out:
    RECOMP_RETURN;
}
