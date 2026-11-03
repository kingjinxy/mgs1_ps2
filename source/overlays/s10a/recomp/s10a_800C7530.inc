extern char R_s10a_800C6654[] __asm__("s10a_800C6654");
extern char R_s10a_800C70A8[] __asm__("s10a_800C70A8");
extern char R_s10a_dat_800E37EC[] __asm__("s10a_dat_800E37EC");
extern char R_GV_DestroyActor[] __asm__("GV_DestroyActor");
extern char R_GV_NewActor[] __asm__("GV_NewActor");
extern char R_GV_SetNamedActor[] __asm__("GV_SetNamedActor");
extern char R_s10a_800C725C[] __asm__("s10a_800C725C");
int G_s10a_800C7530(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s10a_800C7530");
int G_s10a_800C7530(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(32)
    r[29] = (u)r[29] + -32;
    *(int *)((u)r[29] + 20) = r[17];
    r[17] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 24) = r[18];
    r[18] = (u)r[5] + (u)0;
    r[4] = (u)0 + 4;
    r[5] = (u)0 + 3716;
    *(int *)((u)r[29] + 28) = r[31];
    *(int *)((u)r[29] + 16) = r[16]; CALL(R_GV_NewActor);
    r[16] = (u)r[2] + (u)0;
    c = ((r[16] == 0)); r[4] = (u)r[16] + (u)0; if (c) goto L800c75a8;
    r[5] = 0;
    r[5] = (u)r[5] + (int)R_s10a_800C6654;
    r[6] = 0;
    r[6] = (u)r[6] + (int)R_s10a_800C70A8;
    r[7] = 0;
    r[7] = (u)r[7] + ((int)R_s10a_dat_800E37EC + 48); CALL(R_GV_SetNamedActor);
    r[4] = (u)r[16] + (u)0;
    r[5] = (u)r[17] + (u)0;
    r[6] = (u)r[18] + (u)0; CALL(R_s10a_800C725C);
    c = (((int)r[2] >= 0)); r[2] = (u)r[16] + (u)0; if (c) goto L800c75ac;
    r[4] = (u)r[16] + (u)0; CALL(R_GV_DestroyActor);
    r[2] = (u)0 + (u)0; goto L800c75ac;
    L800c75a8:;
    r[2] = (u)r[16] + (u)0;
    L800c75ac:;
    r[31] = *(int *)((u)r[29] + 28);
    r[18] = *(int *)((u)r[29] + 24);
    r[17] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 32; goto out;
out:
    RECOMP_RETURN;
}
int G_s10a_rc_800C75C4(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s10a_rc_800C75C4");
int G_s10a_rc_800C75C4(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(0)
    r[3] = *(int *)((u)r[4] + 32);
    r[2] = *(int *)((u)r[4] + 36);
    r[5] = *(int *)((u)r[2] + 0);
    r[6] = *(int *)((u)r[2] + 4);
    r[7] = *(int *)((u)r[2] + 8);
    r[8] = *(int *)((u)r[2] + 12);
    *(int *)((u)r[3] + 0) = r[5];
    *(int *)((u)r[3] + 4) = r[6];
    *(int *)((u)r[3] + 8) = r[7];
    *(int *)((u)r[3] + 12) = r[8];
    r[5] = *(int *)((u)r[2] + 16);
    r[6] = *(int *)((u)r[2] + 20);
    r[7] = *(int *)((u)r[2] + 24);
    r[8] = *(int *)((u)r[2] + 28);
    *(int *)((u)r[3] + 16) = r[5];
    *(int *)((u)r[3] + 20) = r[6];
    *(int *)((u)r[3] + 24) = r[7];
    *(int *)((u)r[3] + 28) = r[8];
    r[2] = *(int *)((u)r[4] + 40);
    c = ((r[2] == 0));  if (c) goto L800c763c;
    r[2] = *(int *)((u)r[4] + 32);
    r[3] = *(int *)((u)r[2] + 36);
    r[4] = (u)0 + -257;
    r[3] = r[3] & r[4];
    *(int *)((u)r[2] + 36) = r[3]; goto out;
    L800c763c:;
    r[3] = *(int *)((u)r[4] + 32);
    r[2] = *(int *)((u)r[3] + 36);
    r[2] = r[2] | 256;
    *(int *)((u)r[3] + 36) = r[2]; goto out;
out:
    RECOMP_RETURN;
}
