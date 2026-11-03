extern char R_s10a_800CA640[] __asm__("s10a_800CA640");
extern char R_s10a_dat_800C3498[] __asm__("s10a_dat_800C3498");
extern char R_s10a_dat_800C364C[] __asm__("s10a_dat_800C364C");
extern char R_GM_ConfigMotionAdjust[] __asm__("GM_ConfigMotionAdjust");
extern char R_GM_ConfigObjectAction[] __asm__("GM_ConfigObjectAction");
extern char R_s10a_800CA358[] __asm__("s10a_800CA358");
int G_s10a_800CAA88(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s10a_800CAA88");
int G_s10a_800CAA88(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(32)
    r[29] = (u)r[29] + -32;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    r[3] = 0;
    *(int *)((u)r[29] + 24) = r[31];
    *(int *)((u)r[29] + 20) = r[17];
    r[4] = *(int *)((u)r[16] + 2304);
    r[17] = (u)r[16] + 32;
    r[2] = *(unsigned short *)((u)r[4] + 0);
    r[3] = *(unsigned short *)((u)r[3] + (int)R_s10a_dat_800C364C);
    r[2] = r[2] | 159;
    *(short *)((u)r[4] + 0) = r[2];
    c = ((r[5] != 0)); *(short *)((u)r[16] + 2956) = r[3]; if (c) goto L800caae0;
    r[4] = (u)r[16] + 156;
    r[2] = (u)0 + 16;
    *(short *)((u)r[16] + 2272) = r[2];
    r[2] = 0;
    r[6] = (u)0 + (u)0;
    r[5] = *(short *)((u)r[2] + (int)R_s10a_dat_800C3498);
    r[7] = (u)0 + 4; CALL(R_GM_ConfigObjectAction);
    L800caae0:;
    r[4] = (u)r[16] + (u)0; CALL(R_s10a_800CA358);
    c = ((r[2] != 0));  if (c) goto L800cab5c;
    r[2] = *(short *)((u)r[16] + 182);
    c = ((r[2] != 0));  if (c) goto L800cab14;
    r[2] = *(int *)((u)r[16] + 2872);
    r[2] = r[2] & 32;
    c = ((r[2] != 0));  if (c) goto L800cab40;
    L800cab14:;
    r[4] = (u)r[16] + 156;
    r[5] = (u)0 + (u)0;
    r[2] = 0;
    r[2] = (u)r[2] + (int)R_s10a_800CA640;
    *(int *)((u)r[16] + 2284) = r[2];
    *(int *)((u)r[16] + 2292) = 0;
    *(short *)((u)r[16] + 112) = 0;
    *(short *)((u)r[16] + 108) = 0; CALL(R_GM_ConfigMotionAdjust);
     goto L800cab5c;
    L800cab40:;
    r[2] = *(unsigned short *)((u)r[16] + 3116);
    *(short *)((u)r[17] + 68) = 0;
    *(short *)((u)r[17] + 72) = 0;
    *(short *)((u)r[17] + 78) = r[2];
    r[2] = *(unsigned short *)((u)r[16] + 42);
    *(short *)((u)r[16] + 2952) = r[2];
    L800cab5c:;
    r[31] = *(int *)((u)r[29] + 24);
    r[17] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 32; goto out;
out:
    return r[2];
}
int G_s10a_rc_800CAB70(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s10a_rc_800CAB70");
int G_s10a_rc_800CAB70(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(0)
     goto out;
out:
    return r[2];
}
