extern char R_s08b_bunsin2_800C9B38[] __asm__("s08b_bunsin2_800C9B38");
extern char R_s08b_dword_800C33E0[] __asm__("s08b_dword_800C33E0");
extern char R_GM_ConfigObjectAction[] __asm__("GM_ConfigObjectAction");
extern char R_s08b_bunsin2_800C9120[] __asm__("s08b_bunsin2_800C9120");
extern char R_s08b_bunsin2_800C9548[] __asm__("s08b_bunsin2_800C9548");
int G_s08b_bunsin2_800CB158(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s08b_bunsin2_800CB158");
int G_s08b_bunsin2_800CB158(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(32)
    r[29] = (u)r[29] + -32;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 20) = r[17];
    r[17] = (u)r[16] + 32;
    c = ((r[5] != 0)); *(int *)((u)r[29] + 24) = r[31]; if (c) goto L800cb194;
    r[4] = (u)r[16] + 156;
    r[2] = (u)0 + 32;
    *(int *)((u)r[16] + 6564) = r[2];
    r[2] = 0;
    r[6] = (u)0 + (u)0;
    r[5] = *(short *)((u)r[2] + (int)R_s08b_dword_800C33E0);
    r[7] = (u)0 + 4; CALL(R_GM_ConfigObjectAction);
    L800cb194:;
    r[4] = (u)r[16] + (u)0; CALL(R_s08b_bunsin2_800C9548);
    c = ((r[2] != 0)); r[2] = (u)0 + 1; if (c) goto L800cb1fc;
    r[3] = *(int *)((u)r[16] + 6576);
    *(int *)((u)r[16] + 6656) = r[2];
    r[2] = (u)0 + 26;
    c = ((r[3] == r[2]));  if (c) goto L800cb1dc;
    r[4] = (u)r[16] + (u)0; CALL(R_s08b_bunsin2_800C9120);
    c = ((r[2] != 0)); r[2] = 0; if (c) goto L800cb1fc;
    r[2] = (u)r[2] + (int)R_s08b_bunsin2_800C9B38;
    *(int *)((u)r[16] + 6548) = r[2];
    *(int *)((u)r[16] + 6556) = 0;
    *(short *)((u)r[16] + 112) = 0;
    *(short *)((u)r[16] + 108) = 0;
    L800cb1dc:;
    *(short *)((u)r[17] + 68) = 0;
    *(short *)((u)r[17] + 72) = 0;
    r[3] = *(int *)((u)r[16] + 2244);
    r[2] = *(unsigned short *)((u)r[3] + 0);
    r[2] = r[2] | 31;
    *(short *)((u)r[3] + 0) = r[2];
    L800cb1fc:;
    r[31] = *(int *)((u)r[29] + 24);
    r[17] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 32; goto out;
out:
    RECOMP_RETURN;
}
