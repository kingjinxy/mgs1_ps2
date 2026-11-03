extern char R_GM_CurrentMap[] __asm__("GM_CurrentMap");
extern char R_GM_PlayerBody[] __asm__("GM_PlayerBody");
extern char R_GM_WhereList[] __asm__("GM_WhereList");
extern char R_s10a_dat_800E4558[] __asm__("s10a_dat_800E4558");
extern char R_s10a_dat_800E455A[] __asm__("s10a_dat_800E455A");
extern char R_s10a_800C4988[] __asm__("s10a_800C4988");
extern char R_s10a_800C4F68[] __asm__("s10a_800C4F68");
extern char R_s10a_800C4FF0[] __asm__("s10a_800C4FF0");
int G_s10a_800C5074(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s10a_800C5074");
int G_s10a_800C5074(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(40)
    r[29] = (u)r[29] + -40;
    *(int *)((u)r[29] + 32) = r[18];
    r[18] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 36) = r[31];
    *(int *)((u)r[29] + 28) = r[17];
    *(int *)((u)r[29] + 24) = r[16]; CALL(R_s10a_800C4F68);
    r[17] = (u)r[2] + (u)0;
    c = ((r[17] == 0)); r[2] = 0; if (c) goto L800c5128;
    r[2] = *(short *)((u)r[2] + (int)R_s10a_dat_800E455A);
    r[2] = (int)r[2] < 48;
    c = ((r[2] == 0)); r[2] = (u)0 + 1; if (c) goto L800c5128;
    c = ((r[17] != r[2])); r[2] = 0; if (c) goto L800c50cc;
    r[2] = *(int *)((u)r[2] + (int)R_GM_PlayerBody);
    r[2] = *(int *)((u)r[2] + 0);
    r[16] = (u)r[2] + 1176; goto L800c50e0;
    L800c50cc:;
    r[2] = *(int *)((u)r[2] + (int)R_GM_PlayerBody);
    r[2] = *(int *)((u)r[2] + 0);
    r[16] = (u)r[2] + 1452;
    L800c50e0:;
     CALL(R_s10a_800C4FF0);
    r[2] = 0;
    r[3] = *(int *)((u)r[2] + (int)R_GM_WhereList);
    r[2] = *(int *)((u)r[3] + 44);
    r[6] = *(short *)((u)r[3] + 120);
    r[5] = *(int *)((u)r[2] + 0);
    r[2] = *(int *)((u)r[18] + 32);
    r[4] = (u)r[16] + (u)0;
    *(int *)((u)r[29] + 16) = r[2];
    r[2] = 0;
    *(int *)((u)r[2] + (int)R_GM_CurrentMap) = r[5];
    r[2] = 0;
    r[7] = *(short *)((u)r[2] + (int)R_s10a_dat_800E4558);
    r[5] = (u)r[17] + (u)0;
    r[7] = (u)r[7] + -1; CALL(R_s10a_800C4988);
    L800c5128:;
    r[31] = *(int *)((u)r[29] + 36);
    r[18] = *(int *)((u)r[29] + 32);
    r[17] = *(int *)((u)r[29] + 28);
    r[16] = *(int *)((u)r[29] + 24);
    r[29] = (u)r[29] + 40; goto out;
out:
    RECOMP_RETURN;
}
int G_s10a_rc_800C5140(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s10a_rc_800C5140");
int G_s10a_rc_800C5140(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(0)
     goto out;
out:
    RECOMP_RETURN;
}
