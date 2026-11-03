extern char R_s07b_800C7D88[] __asm__("s07b_800C7D88");
extern char R_GM_ConfigObjectAction[] __asm__("GM_ConfigObjectAction");
extern char R_GM_ZoneNavi[] __asm__("GM_ZoneNavi");
extern char R_NavigateSetTargetPlayer[] __asm__("NavigateSetTargetPlayer");
extern char R_s07b_800C4854[] __asm__("s07b_800C4854");
extern char R_s07b_800C4974[] __asm__("s07b_800C4974");
int G_s07b_800C7E98(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s07b_800C7E98");
int G_s07b_800C7E98(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(32)
    r[29] = (u)r[29] + -32;
    *(int *)((u)r[29] + 20) = r[17];
    r[17] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 24) = r[31];
    c = ((r[5] != 0)); *(int *)((u)r[29] + 16) = r[16]; if (c) goto L800c7ed8;
    r[3] = *(short *)((u)r[17] + 170);
    r[2] = (u)0 + 25;
    c = ((r[3] == r[2])); r[4] = (u)r[17] + 156; if (c) goto L800c7ed0;
    r[5] = (u)r[2] + (u)0;
    r[6] = (u)0 + (u)0;
    r[7] = (u)0 + 4; CALL(R_GM_ConfigObjectAction);
    L800c7ed0:;
    r[2] = (u)0 + -1;
    *(int *)((u)r[17] + 2180) = r[2];
    L800c7ed8:;
    r[2] = *(int *)((u)r[17] + 2168);
    r[2] = (int)r[2] < 2001;
    c = ((r[2] == 0)); r[2] = 0; if (c) goto L800c7f0c;
    r[2] = (u)r[2] + (int)R_s07b_800C7D88;
    *(int *)((u)r[17] + 2132) = r[2];
    *(int *)((u)r[17] + 2144) = 0;
    *(short *)((u)r[17] + 2246) = 0;
    *(short *)((u)r[17] + 2244) = 0;
    *(short *)((u)r[17] + 112) = 0;
    *(short *)((u)r[17] + 108) = 0; goto L800c7f34;
    L800c7f0c:;
    r[4] = (u)r[17] + (u)0; CALL(R_s07b_800C4854);
    r[16] = (u)r[17] + 2172;
    r[4] = (u)r[16] + (u)0; CALL(R_NavigateSetTargetPlayer);
    r[4] = (u)r[16] + (u)0;
    r[5] = (u)r[17] + 32; CALL(R_GM_ZoneNavi);
    r[4] = (u)r[17] + (u)0; CALL(R_s07b_800C4974);
    L800c7f34:;
    r[31] = *(int *)((u)r[29] + 24);
    r[17] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 32; goto out;
out:
    return r[2];
}
