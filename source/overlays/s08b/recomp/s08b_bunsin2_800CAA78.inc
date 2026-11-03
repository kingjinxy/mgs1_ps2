extern char R_s08b_bunsin2_800C9B38[] __asm__("s08b_bunsin2_800C9B38");
extern char R_s08b_dword_800C33B0[] __asm__("s08b_dword_800C33B0");
extern char R_GM_ConfigObjectAction[] __asm__("GM_ConfigObjectAction");
extern char R_GM_SeSetMode[] __asm__("GM_SeSetMode");
extern char R_s08b_bunsin2_800C9514[] __asm__("s08b_bunsin2_800C9514");
int G_s08b_bunsin2_800CAA78(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s08b_bunsin2_800CAA78");
int G_s08b_bunsin2_800CAA78(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(32)
    r[29] = (u)r[29] + -32;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 20) = r[17];
    r[17] = (u)r[16] + 32;
    c = ((r[5] != 0)); *(int *)((u)r[29] + 24) = r[31]; if (c) goto L800caab4;
    r[4] = (u)r[16] + 156;
    r[6] = (u)0 + (u)0;
    r[2] = (u)0 + 8;
    *(int *)((u)r[16] + 6564) = r[2];
    r[2] = 0;
    r[5] = *(short *)((u)r[2] + (int)R_s08b_dword_800C33B0);
    r[7] = (u)0 + 4; CALL(R_GM_ConfigObjectAction);
    L800caab4:;
    r[2] = *(int *)((u)r[16] + 6580);
    c = (((int)r[2] < 0));  if (c) goto L800caad0;
    r[2] = *(unsigned short *)((u)r[16] + 6580);
    *(short *)((u)r[17] + 78) = r[2];
    L800caad0:;
    r[4] = (u)r[16] + (u)0; CALL(R_s08b_bunsin2_800C9514);
    r[3] = (u)r[2] + (u)0;
    c = (((int)r[3] <= 0)); r[2] = (int)r[3] < 5; if (c) goto L800cab00;
    c = ((r[2] == 0)); r[2] = (int)r[3] < 3; if (c) goto L800cab00;
    c = ((r[2] != 0)); r[4] = (u)r[17] + (u)0; if (c) goto L800cab00;
    r[5] = (u)0 + 189;
    r[6] = (u)0 + 1; CALL(R_GM_SeSetMode);
    L800cab00:;
    r[3] = *(int *)((u)r[16] + 6576);
    r[2] = (u)0 + 7;
    c = ((r[3] == r[2])); r[2] = 0; if (c) goto L800cab24;
    r[2] = (u)r[2] + (int)R_s08b_bunsin2_800C9B38;
    *(int *)((u)r[16] + 6548) = r[2];
    *(int *)((u)r[16] + 6556) = 0;
    *(short *)((u)r[16] + 112) = 0;
    *(short *)((u)r[16] + 108) = 0;
    L800cab24:;
    r[3] = *(int *)((u)r[16] + 2244);
    r[2] = *(unsigned short *)((u)r[3] + 0);
    r[2] = r[2] | 31;
    *(short *)((u)r[3] + 0) = r[2];
    r[31] = *(int *)((u)r[29] + 24);
    r[17] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 32; goto out;
out:
    RECOMP_RETURN;
}
