extern char R_GM_ConfigObjectAction[] __asm__("GM_ConfigObjectAction");
extern char R_GM_ConfigObjectOverride[] __asm__("GM_ConfigObjectOverride");
int G_s07b_800CDA90(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s07b_800CDA90");
int G_s07b_800CDA90(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(32)
    r[29] = (u)r[29] + -32;
    *(int *)((u)r[29] + 24) = r[16];
    r[16] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 28) = r[31];
    r[3] = *(short *)((u)r[16] + 170);
    r[2] = (u)0 + 1;
    c = ((r[3] == r[2])); *(int *)((u)r[16] + 2208) = 0; if (c) goto L800cdac4;
    r[4] = (u)r[16] + 156;
    r[5] = (u)r[2] + (u)0;
    r[6] = (u)0 + (u)0;
    r[7] = (u)0 + 4; CALL(R_GM_ConfigObjectAction);
    L800cdac4:;
    r[2] = *(short *)((u)r[16] + 172);
    r[3] = (u)0 + 19;
    c = ((r[2] == r[3])); r[2] = (u)0 + 1022; if (c) goto L800cdaec;
    *(int *)((u)r[29] + 16) = r[2];
    r[4] = (u)r[16] + 156;
    r[5] = (u)r[3] + (u)0;
    r[6] = (u)0 + (u)0;
    r[7] = (u)0 + 4; CALL(R_GM_ConfigObjectOverride);
    L800cdaec:;
    r[31] = *(int *)((u)r[29] + 28);
    r[16] = *(int *)((u)r[29] + 24);
    r[29] = (u)r[29] + 32; goto out;
out:
    return r[2];
}
