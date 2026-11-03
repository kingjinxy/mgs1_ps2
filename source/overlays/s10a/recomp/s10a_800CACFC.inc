extern char R_s10a_800CAB78[] __asm__("s10a_800CAB78");
extern char R_s10a_dat_800C3480[] __asm__("s10a_dat_800C3480");
extern char R_s10a_dat_800C364C[] __asm__("s10a_dat_800C364C");
extern char R_GM_ConfigMotionAdjust[] __asm__("GM_ConfigMotionAdjust");
extern char R_GM_ConfigObjectAction[] __asm__("GM_ConfigObjectAction");
extern char R_s10a_800CA358[] __asm__("s10a_800CA358");
extern char R_s10a_800CA3B4[] __asm__("s10a_800CA3B4");
extern char R_s10a_800CB370[] __asm__("s10a_800CB370");
int G_s10a_800CACFC(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s10a_800CACFC");
int G_s10a_800CACFC(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(32)
    r[29] = (u)r[29] + -32;
    *(int *)((u)r[29] + 20) = r[17];
    r[17] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 24) = r[31];
    *(int *)((u)r[29] + 16) = r[16];
    r[4] = *(int *)((u)r[17] + 2304);
    r[3] = 0;
    r[2] = *(unsigned short *)((u)r[4] + 0);
    r[3] = *(unsigned short *)((u)r[3] + (int)R_s10a_dat_800C364C);
    r[2] = r[2] | 159;
    *(short *)((u)r[4] + 0) = r[2];
    c = ((r[5] != 0)); *(short *)((u)r[17] + 2956) = r[3]; if (c) goto L800cad6c;
    r[16] = (u)r[17] + 156;
    r[4] = (u)r[16] + (u)0;
    r[2] = (u)0 + 4;
    *(short *)((u)r[17] + 2272) = r[2];
    r[2] = 0;
    r[6] = (u)0 + (u)0;
    r[5] = *(short *)((u)r[2] + (int)R_s10a_dat_800C3480);
    r[7] = (u)r[6] + (u)0; CALL(R_GM_ConfigObjectAction);
    r[4] = (u)r[17] + (u)0;
    r[5] = (u)0 + 3; CALL(R_s10a_800CB370);
    r[4] = (u)r[16] + (u)0;
    r[5] = (u)r[17] + 1828; CALL(R_GM_ConfigMotionAdjust);
    L800cad6c:;
    r[4] = (u)r[17] + (u)0; CALL(R_s10a_800CA3B4);
    r[4] = (u)r[17] + (u)0; CALL(R_s10a_800CA358);
    c = ((r[2] != 0)); r[2] = 0; if (c) goto L800cad98;
    r[2] = (u)r[2] + (int)R_s10a_800CAB78;
    *(int *)((u)r[17] + 2284) = r[2];
    *(int *)((u)r[17] + 2292) = 0;
    *(short *)((u)r[17] + 112) = 0;
    *(short *)((u)r[17] + 108) = 0;
    L800cad98:;
    r[31] = *(int *)((u)r[29] + 24);
    r[17] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 32; goto out;
out:
    RECOMP_RETURN;
}
int G_s10a_rc_800CADAC(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s10a_rc_800CADAC");
int G_s10a_rc_800CADAC(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(0)
     goto out;
out:
    RECOMP_RETURN;
}
int G_s10a_rc_800CADB4(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s10a_rc_800CADB4");
int G_s10a_rc_800CADB4(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(0)
     goto out;
out:
    RECOMP_RETURN;
}
int G_s10a_rc_800CADBC(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s10a_rc_800CADBC");
int G_s10a_rc_800CADBC(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(0)
     goto out;
out:
    RECOMP_RETURN;
}
