extern char R_s07b_800C6634[] __asm__("s07b_800C6634");
extern char R_GM_ConfigObjectAction[] __asm__("GM_ConfigObjectAction");
extern char R_GM_SeSetMode[] __asm__("GM_SeSetMode");
extern char R_s07b_800C54C0[] __asm__("s07b_800C54C0");
int G_s07b_800C61D8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s07b_800C61D8");
int G_s07b_800C61D8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(32)
    r[29] = (u)r[29] + -32;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 20) = r[17];
    r[17] = (u)r[5] + (u)0;
    c = ((r[17] != 0)); *(int *)((u)r[29] + 24) = r[31]; if (c) goto L800c621c;
    r[5] = (u)0 + (u)0; CALL(R_s07b_800C54C0);
    r[3] = *(short *)((u)r[16] + 170);
    r[2] = (u)0 + 7;
    c = ((r[3] == r[2])); r[4] = (u)r[16] + 156; if (c) goto L800c621c;
    r[5] = (u)r[2] + (u)0;
    r[6] = (u)0 + (u)0;
    r[7] = (u)0 + 4; CALL(R_GM_ConfigObjectAction);
    L800c621c:;
    r[2] = (u)0 + 36;
    c = ((r[17] != r[2])); r[4] = (u)r[16] + 32; if (c) goto L800c6234;
    r[5] = (u)0 + 51;
    r[6] = (u)0 + 1; CALL(R_GM_SeSetMode);
    L800c6234:;
    r[2] = *(short *)((u)r[16] + 182);
    c = ((r[2] == 0)); r[2] = (u)0 + 3; if (c) goto L800c6268;
    *(short *)((u)r[16] + 2248) = r[2];
    r[2] = 0;
    r[2] = (u)r[2] + (int)R_s07b_800C6634;
    *(int *)((u)r[16] + 2132) = r[2];
    *(int *)((u)r[16] + 2144) = 0;
    *(short *)((u)r[16] + 2246) = 0;
    *(short *)((u)r[16] + 2244) = 0;
    *(short *)((u)r[16] + 112) = 0;
    *(short *)((u)r[16] + 108) = 0;
    L800c6268:;
    r[31] = *(int *)((u)r[29] + 24);
    r[17] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 32; goto out;
out:
    RECOMP_RETURN;
}
