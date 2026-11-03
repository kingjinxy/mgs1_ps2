extern char R_s07b_800CF200[] __asm__("s07b_800CF200");
extern char R_s07b_dword_800C33A8[] __asm__("s07b_dword_800C33A8");
extern char R_GM_ConfigObjectAction[] __asm__("GM_ConfigObjectAction");
extern char R_s07b_800CAD54[] __asm__("s07b_800CAD54");
extern char R_s07b_800CB224[] __asm__("s07b_800CB224");
extern char R_s07b_800CC89C[] __asm__("s07b_800CC89C");
extern char R_s07b_800CC8D4[] __asm__("s07b_800CC8D4");
int G_s07b_800CF130(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s07b_800CF130");
int G_s07b_800CF130(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(32)
    r[29] = (u)r[29] + -32;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 20) = r[17];
    r[17] = (u)r[5] + (u)0;
    c = ((r[17] != 0)); *(int *)((u)r[29] + 24) = r[31]; if (c) goto L800cf1ac;
    r[2] = *(int *)((u)r[16] + 2092);
    r[3] = (u)0 + 1;
    *(int *)((u)r[2] + 8) = r[3];
    r[2] = *(short *)((u)r[16] + 170);
    c = ((r[2] == r[3])); r[4] = (u)r[16] + 156; if (c) goto L800cf178;
    r[5] = (u)r[3] + (u)0;
    r[6] = (u)0 + (u)0;
    r[7] = (u)0 + 4; CALL(R_GM_ConfigObjectAction);
    L800cf178:;
    r[2] = *(int *)((u)r[16] + 2128);
    r[3] = *(short *)((u)r[16] + 2116);
    r[2] = r[2] | 1;
    *(int *)((u)r[16] + 2128) = r[2];
    r[2] = (u)0 + 2;
    c = ((r[3] != r[2]));  if (c) goto L800cf1a0;
    r[4] = (u)r[16] + (u)0;
    r[5] = (u)0 + 128; CALL(R_s07b_800CAD54);
    L800cf1a0:;
    r[4] = (u)r[16] + (u)0;
    r[5] = (u)0 + 3; CALL(R_s07b_800CC89C);
    L800cf1ac:;
    r[4] = (u)r[16] + (u)0; CALL(R_s07b_800CC8D4);
    r[4] = (u)r[16] + (u)0; CALL(R_s07b_800CB224);
    r[2] = 0;
    r[2] = *(unsigned short *)((u)r[2] + (int)R_s07b_dword_800C33A8);
    c = ((r[17] != r[2])); r[2] = 0; if (c) goto L800cf1ec;
    r[2] = (u)r[2] + (int)R_s07b_800CF200;
    *(int *)((u)r[16] + 2132) = r[2];
    *(int *)((u)r[16] + 2136) = 0;
    *(short *)((u)r[16] + 2662) = 0;
    *(short *)((u)r[16] + 2660) = 0;
    *(short *)((u)r[16] + 112) = 0;
    *(short *)((u)r[16] + 108) = 0;
    L800cf1ec:;
    r[31] = *(int *)((u)r[29] + 24);
    r[17] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 32; goto out;
out:
    return r[2];
}
