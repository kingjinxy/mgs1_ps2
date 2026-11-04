extern char R_GM_PlayerControl[] __asm__("GM_PlayerControl");
extern char R_s07b_dword_800C3304[] __asm__("s07b_dword_800C3304");
extern char R_GM_ConfigObjectAction[] __asm__("GM_ConfigObjectAction");
extern char R_GM_SeSetMode[] __asm__("GM_SeSetMode");
extern char R_NewPadVibration[] __asm__("NewPadVibration");
extern char R_s07b_800C6AA4[] __asm__("s07b_800C6AA4");
int G_s07b_800C6B8C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s07b_800C6B8C");
int G_s07b_800C6B8C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    c = ((r[5] != 0)); *(int *)((u)r[29] + 20) = r[31]; if (c) goto L800c6be0;
    r[3] = *(short *)((u)r[16] + 170);
    r[2] = (u)0 + 15;
    c = ((r[3] == r[2])); r[4] = (u)r[16] + 156; if (c) goto L800c6bc0;
    r[5] = (u)r[2] + (u)0;
    r[6] = (u)0 + (u)0;
    r[7] = (u)0 + 4; CALL(R_GM_ConfigObjectAction);
    L800c6bc0:;
    r[4] = (u)r[16] + 32;
    r[2] = 0;
    r[2] = *(int *)((u)r[2] + (int)R_GM_PlayerControl);
    r[5] = (u)0 + 190;
    r[2] = *(unsigned short *)((u)r[2] + 78);
    r[6] = (u)0 + 1;
    *(short *)((u)r[16] + 110) = r[2]; CALL(R_GM_SeSetMode);
    L800c6be0:;
    r[2] = *(int *)((u)r[16] + 2092);
    r[2] = (u)r[2] + 1;
    *(int *)((u)r[16] + 2092) = r[2];
    r[2] = (int)r[2] < 51;
    c = ((r[2] != 0)); r[4] = (u)r[16] + (u)0; if (c) goto L800c6c44;
    r[3] = *(short *)((u)r[16] + 170);
    r[2] = (u)0 + 35;
    c = ((r[3] == r[2])); r[4] = (u)r[16] + 156; if (c) goto L800c6c1c;
    r[5] = (u)r[2] + (u)0;
    r[6] = (u)0 + (u)0;
    r[7] = (u)0 + 4; CALL(R_GM_ConfigObjectAction);
    L800c6c1c:;
    r[2] = *(int *)((u)r[16] + 2092);
    r[2] = r[2] & 7;
    c = ((r[2] != 0)); r[4] = (u)r[16] + (u)0; if (c) goto L800c6c44;
    r[4] = 0;
    r[4] = (u)r[4] + (int)R_s07b_dword_800C3304;
    r[5] = (u)0 + 2; CALL(R_NewPadVibration);
    r[4] = (u)r[16] + (u)0;
    L800c6c44:;
    r[5] = (u)0 + -1; CALL(R_s07b_800C6AA4);
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
