extern char R_GM_ConfigObjectAction[] __asm__("GM_ConfigObjectAction");
extern char R_GM_ConfigObjectOverride[] __asm__("GM_ConfigObjectOverride");
int G_s07b_800CF684(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s07b_800CF684");
int G_s07b_800CF684(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(32)
    r[29] = (u)r[29] + -32;
    *(int *)((u)r[29] + 24) = r[16];
    r[16] = (u)r[4] + (u)0;
    c = ((r[5] != 0)); *(int *)((u)r[29] + 28) = r[31]; if (c) goto L800cf6e0;
    r[2] = *(short *)((u)r[16] + 172);
    c = ((r[2] == 0)); r[4] = (u)r[16] + 156; if (c) goto L800cf6bc;
    *(int *)((u)r[29] + 16) = 0;
    r[5] = (u)0 + (u)0;
    r[6] = (u)r[5] + (u)0;
    r[7] = (u)0 + 4; CALL(R_GM_ConfigObjectOverride);
    L800cf6bc:;
    r[3] = *(short *)((u)r[16] + 170);
    r[2] = (u)0 + 1;
    c = ((r[3] == r[2])); r[4] = (u)r[16] + 156; if (c) goto L800cf6dc;
    r[5] = (u)r[2] + (u)0;
    r[6] = (u)0 + (u)0;
    r[7] = (u)0 + 4; CALL(R_GM_ConfigObjectAction);
    L800cf6dc:;
    *(int *)((u)r[16] + 2208) = 0;
    L800cf6e0:;
    r[31] = *(int *)((u)r[29] + 28);
    r[16] = *(int *)((u)r[29] + 24);
    r[29] = (u)r[29] + 32; goto out;
out:
    return r[2];
}
