extern char R_GM_ConfigObjectAction[] __asm__("GM_ConfigObjectAction");
int G_s10a_800D97E8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s10a_800D97E8");
int G_s10a_800D97E8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[31];
    r[3] = *(short *)((u)r[4] + 186);
    r[2] = (u)0 + 1;
    c = ((r[3] != r[2])); r[6] = (u)0 + (u)0; if (c) goto L800d9810;
    *(int *)((u)r[4] + 1728) = r[5];
    r[4] = (u)r[4] + 160;
    r[7] = (u)0 + 4; CALL(R_GM_ConfigObjectAction);
    L800d9810:;
    r[31] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    return r[2];
}
