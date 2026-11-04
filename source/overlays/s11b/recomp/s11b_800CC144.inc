extern char R_s11b_800CB080[] __asm__("s11b_800CB080");
extern char R_s11b_800CBB18[] __asm__("s11b_800CBB18");
extern char R_s11b_dat_800DB00C[] __asm__("s11b_dat_800DB00C");
extern char R_GV_DestroyActor[] __asm__("GV_DestroyActor");
extern char R_GV_NewActor[] __asm__("GV_NewActor");
extern char R_GV_SetNamedActor[] __asm__("GV_SetNamedActor");
extern char R_s11b_800CBBAC[] __asm__("s11b_800CBBAC");
int G_s11b_800CC144(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s11b_800CC144");
int G_s11b_800CC144(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(32)
    r[29] = (u)r[29] + -32;
    *(int *)((u)r[29] + 20) = r[17];
    r[17] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 24) = r[18];
    r[18] = (u)r[5] + (u)0;
    r[4] = (u)0 + 4;
    r[5] = (u)0 + 27404;
    *(int *)((u)r[29] + 28) = r[31];
    *(int *)((u)r[29] + 16) = r[16]; CALL(R_GV_NewActor);
    r[16] = (u)r[2] + (u)0;
    c = ((r[16] == 0)); r[4] = (u)r[16] + (u)0; if (c) goto L800cc1bc;
    r[5] = 0;
    r[5] = (u)r[5] + (int)R_s11b_800CB080;
    r[6] = 0;
    r[6] = (u)r[6] + (int)R_s11b_800CBB18;
    r[7] = 0;
    r[7] = (u)r[7] + ((int)R_s11b_dat_800DB00C + 16); CALL(R_GV_SetNamedActor);
    r[4] = (u)r[16] + (u)0;
    r[5] = (u)r[17] + (u)0;
    r[6] = (u)r[18] + (u)0; CALL(R_s11b_800CBBAC);
    c = (((int)r[2] >= 0)); r[2] = (u)r[16] + (u)0; if (c) goto L800cc1c0;
    r[4] = (u)r[16] + (u)0; CALL(R_GV_DestroyActor);
    r[2] = (u)0 + (u)0; goto L800cc1c0;
    L800cc1bc:;
    r[2] = (u)r[16] + (u)0;
    L800cc1c0:;
    r[31] = *(int *)((u)r[29] + 28);
    r[18] = *(int *)((u)r[29] + 24);
    r[17] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 32; goto out;
out:
    RECOMP_RETURN;
}
