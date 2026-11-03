extern char R_s07b_800C6B8C[] __asm__("s07b_800C6B8C");
extern char R_s07b_800C6E54[] __asm__("s07b_800C6E54");
extern char R_GM_ConfigObjectAction[] __asm__("GM_ConfigObjectAction");
extern char R_GM_SeSetMode[] __asm__("GM_SeSetMode");
extern char R_s07b_800C5490[] __asm__("s07b_800C5490");
extern char R_s07b_800C6AA4[] __asm__("s07b_800C6AA4");
int G_s07b_800C6D80(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s07b_800C6D80");
int G_s07b_800C6D80(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    c = ((r[5] != 0)); *(int *)((u)r[29] + 20) = r[31]; if (c) goto L800c6dc8;
    r[3] = *(short *)((u)r[16] + 170);
    r[2] = (u)0 + 16;
    c = ((r[3] == r[2])); r[4] = (u)r[16] + 156; if (c) goto L800c6db4;
    r[5] = (u)r[2] + (u)0;
    r[6] = (u)0 + (u)0;
    r[7] = (u)0 + 4; CALL(R_GM_ConfigObjectAction);
    L800c6db4:;
    r[4] = (u)r[16] + 32;
    r[5] = (u)0 + 190;
    r[6] = (u)0 + 1; CALL(R_GM_SeSetMode);
    *(int *)((u)r[16] + 2092) = 0;
    L800c6dc8:;
    r[2] = *(short *)((u)r[16] + 182);
    c = ((r[2] == 0)); r[4] = (u)r[16] + (u)0; if (c) goto L800c6e3c;
    r[2] = *(int *)((u)r[16] + 2012);
    r[2] = *(short *)((u)r[2] + 38);
    c = (((int)r[2] > 0)); r[2] = 0; if (c) goto L800c6e1c;
     CALL(R_s07b_800C5490);
    r[2] = 0;
    r[2] = (u)r[2] + (int)R_s07b_800C6E54;
    *(int *)((u)r[16] + 2132) = r[2];
    *(int *)((u)r[16] + 2144) = 0;
    *(short *)((u)r[16] + 2246) = 0;
    *(short *)((u)r[16] + 2244) = 0;
    *(short *)((u)r[16] + 112) = 0;
    *(short *)((u)r[16] + 108) = 0; goto L800c6e44;
    L800c6e1c:;
    r[2] = (u)r[2] + (int)R_s07b_800C6B8C;
    *(int *)((u)r[16] + 2132) = r[2];
    *(int *)((u)r[16] + 2144) = 0;
    *(short *)((u)r[16] + 2246) = 0;
    *(short *)((u)r[16] + 2244) = 0;
    *(short *)((u)r[16] + 112) = 0;
    *(short *)((u)r[16] + 108) = 0;
    r[4] = (u)r[16] + (u)0;
    L800c6e3c:;
    r[5] = (u)0 + 38; CALL(R_s07b_800C6AA4);
    L800c6e44:;
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    return r[2];
}
