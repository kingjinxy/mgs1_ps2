extern char R_s10a_800C823C[] __asm__("s10a_800C823C");
extern char R_s10a_800C87B8[] __asm__("s10a_800C87B8");
extern char R_s10a_dat_800C33A8[] __asm__("s10a_dat_800C33A8");
extern char R_GM_ConfigObjectAction[] __asm__("GM_ConfigObjectAction");
extern char R_s10a_800C8184[] __asm__("s10a_800C8184");
int G_s10a_800C8720(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s10a_800C8720");
int G_s10a_800C8720(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(32)
    r[29] = (u)r[29] + -32;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 24) = r[31];
    *(int *)((u)r[29] + 20) = r[17];
    r[17] = *(int *)((u)r[16] + 3068);
    c = ((r[5] != 0)); r[4] = (u)r[16] + 156; if (c) goto L800c8758;
    r[2] = 0;
    r[6] = (u)0 + (u)0;
    *(int *)((u)r[16] + 3040) = 0;
    r[5] = *(short *)((u)r[2] + (int)R_s10a_dat_800C33A8);
    r[7] = (u)0 + 4; CALL(R_GM_ConfigObjectAction);
    L800c8758:;
    r[4] = (u)r[16] + (u)0; CALL(R_s10a_800C8184);
    r[2] = r[17] & 1;
    c = ((r[2] != 0)); r[2] = 0; if (c) goto L800c8774;
    r[2] = (u)r[2] + (int)R_s10a_800C823C; goto L800c8784;
    L800c8774:;
    r[2] = r[17] & 2;
    c = ((r[2] == 0)); r[2] = 0; if (c) goto L800c8798;
    r[2] = (u)r[2] + (int)R_s10a_800C87B8;
    L800c8784:;
    *(int *)((u)r[16] + 3024) = r[2];
    *(int *)((u)r[16] + 3032) = 0;
    *(short *)((u)r[16] + 112) = 0;
    *(short *)((u)r[16] + 108) = 0; goto L800c87a4;
    L800c8798:;
    r[2] = *(unsigned short *)((u)r[16] + 3592);
    *(short *)((u)r[16] + 110) = r[2];
    L800c87a4:;
    r[31] = *(int *)((u)r[29] + 24);
    r[17] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 32; goto out;
out:
    RECOMP_RETURN;
}
