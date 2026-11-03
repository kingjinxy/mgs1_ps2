extern char R_s08b_bunsin2_800C9BF8[] __asm__("s08b_bunsin2_800C9BF8");
extern char R_s08b_dword_800C33A0[] __asm__("s08b_dword_800C33A0");
extern char R_GM_ConfigObjectAction[] __asm__("GM_ConfigObjectAction");
extern char R_GM_ConfigObjectOverride[] __asm__("GM_ConfigObjectOverride");
extern char R_s08b_bunsin2_800C9120[] __asm__("s08b_bunsin2_800C9120");
extern char R_s08b_bunsin2_800C9548[] __asm__("s08b_bunsin2_800C9548");
int G_s08b_bunsin2_800C9B38(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s08b_bunsin2_800C9B38");
int G_s08b_bunsin2_800C9B38(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(32)
    r[29] = (u)r[29] + -32;
    *(int *)((u)r[29] + 24) = r[16];
    r[16] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 28) = r[31];
    r[3] = *(int *)((u)r[16] + 2244);
    r[2] = *(unsigned short *)((u)r[3] + 0);
    r[2] = r[2] | 31;
    c = ((r[5] != 0)); *(short *)((u)r[3] + 0) = r[2]; if (c) goto L800c9b80;
    r[4] = (u)r[16] + 156;
    r[6] = (u)0 + (u)0;
    r[2] = 0;
    *(int *)((u)r[16] + 6564) = 0;
    r[5] = *(short *)((u)r[2] + (int)R_s08b_dword_800C33A0);
    r[7] = (u)0 + 4; CALL(R_GM_ConfigObjectAction);
    L800c9b80:;
    r[4] = (u)r[16] + (u)0; CALL(R_s08b_bunsin2_800C9548);
    c = ((r[2] != 0));  if (c) goto L800c9be8;
    r[4] = (u)r[16] + (u)0; CALL(R_s08b_bunsin2_800C9120);
    c = ((r[2] == 0)); r[4] = (u)r[16] + 156; if (c) goto L800c9bc4;
    r[6] = (u)0 + (u)0;
    r[2] = 0;
    r[5] = *(short *)((u)r[2] + (int)R_s08b_dword_800C33A0);
    r[7] = (u)0 + 4;
    *(int *)((u)r[29] + 16) = 0; CALL(R_GM_ConfigObjectOverride);
    *(int *)((u)r[16] + 6552) = 0;
    *(int *)((u)r[16] + 6560) = 0; goto L800c9be0;
    L800c9bc4:;
    r[2] = *(int *)((u)r[16] + 6580);
    c = (((int)r[2] < 0)); r[2] = 0; if (c) goto L800c9be8;
    r[2] = (u)r[2] + ((int)R_s08b_bunsin2_800C9BF8 + 124);
    *(int *)((u)r[16] + 6548) = r[2];
    *(int *)((u)r[16] + 6556) = 0;
    L800c9be0:;
    *(short *)((u)r[16] + 112) = 0;
    *(short *)((u)r[16] + 108) = 0;
    L800c9be8:;
    r[31] = *(int *)((u)r[29] + 28);
    r[16] = *(int *)((u)r[29] + 24);
    r[29] = (u)r[29] + 32; goto out;
out:
    return r[2];
}
