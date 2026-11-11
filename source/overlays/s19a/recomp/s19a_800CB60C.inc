extern char R_GM_CurrentMap[] __asm__("GM_CurrentMap");
extern char R_s19a_dat_800E0B28[] __asm__("s19a_dat_800E0B28");
extern char R_s19a_dat_800E0B2A[] __asm__("s19a_dat_800E0B2A");
extern char R_s19a_800CB398[] __asm__("s19a_800CB398");
extern char R_s19a_800CB534[] __asm__("s19a_800CB534");
extern char R_s19a_800CB58C[] __asm__("s19a_800CB58C");
int G_s19a_800CB60C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s19a_800CB60C");
int G_s19a_800CB60C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(48)
    r[29] = (u)r[29] + -48;
    *(int *)((u)r[29] + 32) = r[16];
    r[16] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 44) = r[31];
    *(int *)((u)r[29] + 40) = r[18];
    *(int *)((u)r[29] + 36) = r[17]; CALL(R_s19a_800CB534);
    r[17] = (u)r[2] + (u)0;
    c = ((r[17] == 0)); r[2] = 0; if (c) goto L800cb6d4;
    r[2] = *(short *)((u)r[2] + (int)R_s19a_dat_800E0B2A);
    r[2] = (int)r[2] < 128;
    c = ((r[2] == 0)); r[2] = (u)0 + 1; if (c) goto L800cb6d4;
    c = ((r[17] != r[2]));  if (c) goto L800cb664;
    r[2] = *(int *)((u)r[16] + 36);
    r[2] = *(int *)((u)r[2] + 0);
    r[18] = (u)r[2] + 1176; goto L800cb678;
    L800cb664:;
    r[2] = *(int *)((u)r[16] + 36);
    r[2] = *(int *)((u)r[2] + 0);
    r[18] = (u)r[2] + 1452;
    L800cb678:;
    r[4] = (u)r[16] + (u)0; CALL(R_s19a_800CB58C);
    r[2] = *(int *)((u)r[16] + 32);
    r[3] = *(int *)((u)r[16] + 32);
    r[4] = *(int *)((u)r[16] + 40);
    r[2] = *(int *)((u)r[2] + 44);
    r[6] = *(short *)((u)r[3] + 120);
    r[5] = *(int *)((u)r[2] + 0);
    *(int *)((u)r[29] + 16) = r[4];
    r[2] = *(int *)((u)r[16] + 32);
    r[2] = *(short *)((u)r[2] + 10);
    r[4] = (u)r[18] + (u)0;
    *(int *)((u)r[29] + 20) = r[2];
    r[2] = 0;
    *(int *)((u)r[2] + (int)R_GM_CurrentMap) = r[5];
    r[2] = 0;
    r[5] = (u)r[17] + (u)0;
    r[7] = *(short *)((u)r[2] + (int)R_s19a_dat_800E0B28);
    r[3] = *(int *)((u)r[16] + 48);
    r[7] = (u)r[7] + -1;
    *(int *)((u)r[29] + 24) = r[3]; CALL(R_s19a_800CB398);
    L800cb6d4:;
    r[31] = *(int *)((u)r[29] + 44);
    r[18] = *(int *)((u)r[29] + 40);
    r[17] = *(int *)((u)r[29] + 36);
    r[16] = *(int *)((u)r[29] + 32);
    r[29] = (u)r[29] + 48; goto out;
out:
    RECOMP_RETURN;
}
int G_s19a_rc_800CB6EC(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s19a_rc_800CB6EC");
int G_s19a_rc_800CB6EC(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
     goto out;
out:
    RECOMP_RETURN;
}
