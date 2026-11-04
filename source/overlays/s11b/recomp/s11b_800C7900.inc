extern char R_s11b_800C7060[] __asm__("s11b_800C7060");
extern char R_s11b_800C734C[] __asm__("s11b_800C734C");
extern char R_s11b_dat_800DA8E8[] __asm__("s11b_dat_800DA8E8");
extern char R_GV_DestroyActor[] __asm__("GV_DestroyActor");
extern char R_GV_NewActor[] __asm__("GV_NewActor");
extern char R_GV_SetNamedActor[] __asm__("GV_SetNamedActor");
extern char R_s11b_800C762C[] __asm__("s11b_800C762C");
int G_s11b_800C7900(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s11b_800C7900");
int G_s11b_800C7900(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
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
    c = ((r[16] == 0)); r[4] = (u)r[16] + (u)0; if (c) goto L800c79a0;
    r[5] = 0;
    r[5] = (u)r[5] + (int)R_s11b_800C7060;
    r[6] = 0;
    r[6] = (u)r[6] + (int)R_s11b_800C734C;
    r[7] = 0;
    r[7] = (u)r[7] + ((int)R_s11b_dat_800DA8E8 + 20); CALL(R_GV_SetNamedActor);
    r[4] = (u)r[16] + (u)0;
    r[5] = (u)r[17] + (u)0;
    r[2] = *(int *)((u)r[29] + 72);
    r[6] = (u)r[18] + (u)0;
    *(int *)((u)r[29] + 20) = r[2];
    r[2] = *(int *)((u)r[29] + 76);
    r[7] = (u)r[19] + (u)0;
    *(int *)((u)r[29] + 16) = r[20];
    *(int *)((u)r[29] + 24) = r[2]; CALL(R_s11b_800C762C);
    c = (((int)r[2] >= 0)); r[2] = (u)r[16] + (u)0; if (c) goto L800c79a4;
    r[4] = (u)r[16] + (u)0; CALL(R_GV_DestroyActor);
    r[2] = (u)0 + (u)0; goto L800c79a4;
    L800c79a0:;
    r[2] = (u)r[16] + (u)0;
    L800c79a4:;
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
