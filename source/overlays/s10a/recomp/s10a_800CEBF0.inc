extern char R_s10a_dat_800E4970[] __asm__("s10a_dat_800E4970");
extern char R_s10a_800CE8EC[] __asm__("s10a_800CE8EC");
extern char R_s10a_800CE9E0[] __asm__("s10a_800CE9E0");
extern char R_s10a_800CEAF4[] __asm__("s10a_800CEAF4");
int G_s10a_800CEBF0(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s10a_800CEBF0");
int G_s10a_800CEBF0(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[16];
    *(int *)((u)r[29] + 20) = r[31];
    r[16] = (u)r[4] + (u)0; CALL(R_s10a_800CEAF4);
     CALL(R_s10a_800CE9E0);
    r[4] = (u)r[16] + (u)0; CALL(R_s10a_800CE8EC);
    r[3] = 0;
    r[3] = (u)r[3] + (int)R_s10a_dat_800E4970;
    r[2] = *(int *)((u)r[3] + 16);
    r[2] = (u)r[2] + 1;
    *(int *)((u)r[3] + 16) = r[2];
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    return r[2];
}
extern char R_GM_Camera[] __asm__("GM_Camera");
extern char R_s10a_dat_800E4968[] __asm__("s10a_dat_800E4968");
int G_s10a_rc_800CEC3C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s10a_rc_800CEC3C");
int G_s10a_rc_800CEC3C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(0)
     goto out;
    r[2] = 0;
    r[8] = (u)r[2] + (int)R_s10a_dat_800E4968;
    r[5] = LWL(((u)r[4] + 3), r[5]);
    r[5] = LWR(((u)r[4] + 0), r[5]);
    r[6] = LWL(((u)r[4] + 7), r[6]);
    r[6] = LWR(((u)r[4] + 4), r[6]);
    SWL(((u)r[8] + 3), r[5]);
    SWR(((u)r[8] + 0), r[5]);
    SWL(((u)r[8] + 7), r[6]);
    SWR(((u)r[8] + 4), r[6]);
    r[2] = 0;
    r[2] = (u)r[2] + (int)R_GM_Camera;
    r[3] = (u)0 + 2;
    *(short *)((u)r[2] + 42) = r[3];
    r[3] = (u)0 + 4;
    *(short *)((u)r[2] + 38) = r[3]; goto out;
out:
    return r[2];
}
