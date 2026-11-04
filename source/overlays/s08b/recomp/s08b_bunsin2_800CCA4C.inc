extern char R_s08b_bunsin2_800C9B38[] __asm__("s08b_bunsin2_800C9B38");
extern char R_s08b_dword_800C33D4[] __asm__("s08b_dword_800C33D4");
extern char R_GM_ConfigObjectAction[] __asm__("GM_ConfigObjectAction");
extern char R_GM_SeSetMode[] __asm__("GM_SeSetMode");
extern char R_s08b_bunsin2_800C9120[] __asm__("s08b_bunsin2_800C9120");
int G_s08b_bunsin2_800CCA4C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s08b_bunsin2_800CCA4C");
int G_s08b_bunsin2_800CCA4C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(32)
    r[29] = (u)r[29] + -32;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 20) = r[17];
    r[17] = (u)r[5] + (u)0;
    c = ((r[17] != 0)); *(int *)((u)r[29] + 24) = r[31]; if (c) goto L800cca88;
    r[4] = (u)r[16] + 156;
    r[6] = (u)0 + (u)0;
    r[2] = (u)0 + 26;
    *(int *)((u)r[16] + 6564) = r[2];
    r[2] = 0;
    r[5] = *(short *)((u)r[2] + (int)R_s08b_dword_800C33D4);
    r[7] = (u)0 + 4; CALL(R_GM_ConfigObjectAction);
    L800cca88:;
    r[2] = (u)0 + 60;
    c = ((r[17] != r[2])); r[4] = (u)r[16] + 32; if (c) goto L800ccaa0;
    r[5] = (u)0 + 51;
    r[6] = (u)0 + 1; CALL(R_GM_SeSetMode);
    L800ccaa0:;
    r[4] = (u)r[16] + (u)0; CALL(R_s08b_bunsin2_800C9120);
    c = ((r[2] != 0));  if (c) goto L800ccadc;
    r[2] = *(short *)((u)r[16] + 182);
    c = ((r[2] == 0)); r[2] = (u)0 + 1; if (c) goto L800ccadc;
    *(int *)((u)r[16] + 6568) = r[2];
    r[2] = 0;
    r[2] = (u)r[2] + (int)R_s08b_bunsin2_800C9B38;
    *(int *)((u)r[16] + 6548) = r[2];
    *(int *)((u)r[16] + 6556) = 0;
    *(short *)((u)r[16] + 112) = 0;
    *(short *)((u)r[16] + 108) = 0;
    L800ccadc:;
    r[31] = *(int *)((u)r[29] + 24);
    r[17] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 32; goto out;
out:
    RECOMP_RETURN;
}
