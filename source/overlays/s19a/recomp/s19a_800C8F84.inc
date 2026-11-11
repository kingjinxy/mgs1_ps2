extern char R_s19a_dat_800E0530[] __asm__("s19a_dat_800E0530");
extern char R_GM_CheckMessage[] __asm__("GM_CheckMessage");
extern char R_GV_DestroyActor[] __asm__("GV_DestroyActor");
extern char R_s19a_800C79BC[] __asm__("s19a_800C79BC");
extern char R_s19a_800C7A20[] __asm__("s19a_800C7A20");
extern char R_s19a_800C87C0[] __asm__("s19a_800C87C0");
extern char R_s19a_800C8BD4[] __asm__("s19a_800C8BD4");
extern char R_s19a_800C8EB8[] __asm__("s19a_800C8EB8");
extern char R_s19a_800C8F44[] __asm__("s19a_800C8F44");
extern char R_s19a_800C9070[] __asm__("s19a_800C9070");
int G_s19a_800C8F84(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s19a_800C8F84");
int G_s19a_800C8F84(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 20) = r[31];
    r[5] = *(int *)((u)r[16] + 36);
    r[6] = (u)0 + 12835; CALL(R_GM_CheckMessage);
    c = ((r[2] == 0));  if (c) goto L800c8fb8;
    r[4] = (u)r[16] + (u)0; CALL(R_GV_DestroyActor);
     goto L800c9008;
    L800c8fb8:;
    r[4] = (u)r[16] + (u)0; CALL(R_s19a_800C8EB8);
     CALL(R_s19a_800C9070);
     CALL(R_s19a_800C8BD4);
     CALL(R_s19a_800C8F44);
    r[4] = (u)r[16] + (u)0; CALL(R_s19a_800C87C0);
     CALL(R_s19a_800C79BC);
     CALL(R_s19a_800C7A20);
    r[3] = 0;
    r[3] = (u)r[3] + (int)R_s19a_dat_800E0530;
    r[2] = *(int *)((u)r[3] + 12);
    r[2] = (u)r[2] + 1;
    *(int *)((u)r[3] + 12) = r[2];
    L800c9008:;
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
int G_s19a_rc_800C9018(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s19a_rc_800C9018");
int G_s19a_rc_800C9018(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
     goto out;
out:
    RECOMP_RETURN;
}
extern char R_GM_Camera[] __asm__("GM_Camera");
extern char R_GM_PlayerBody[] __asm__("GM_PlayerBody");
extern char R_GV_NearExp8[] __asm__("GV_NearExp8");
int G_s19a_rc_800C9020(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s19a_rc_800C9020");
int G_s19a_rc_800C9020(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[2] = 0;
    r[2] = *(int *)((u)r[2] + (int)R_GM_PlayerBody);
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 20) = r[31];
    *(int *)((u)r[29] + 16) = r[16];
    r[2] = *(int *)((u)r[2] + 0);
    r[3] = *(short *)((u)r[2] + 50);
    r[2] = (u)0 + 2;
    c = ((r[3] != r[2])); r[16] = 0; if (c) goto L800c9060;
    r[16] = (u)r[16] + (int)R_GM_Camera;
    r[4] = *(int *)((u)r[16] + 28);
    r[5] = (u)0 + 4000; CALL(R_GV_NearExp8);
    *(int *)((u)r[16] + 28) = r[2];
    L800c9060:;
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
