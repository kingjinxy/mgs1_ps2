extern char R_GM_ConfigObjectAction[] __asm__("GM_ConfigObjectAction");
int G_s15a_800CCBF8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s15a_800CCBF8");
int G_s15a_800CCBF8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[31];
    r[2] = *(int *)((u)r[4] + 1648);
    c = ((r[2] == r[5])); r[2] = (u)0 + 1; if (c) goto L800ccc30;
    *(int *)((u)r[4] + 2336) = 0;
    *(int *)((u)r[4] + 1648) = r[5];
    r[4] = (u)r[4] + 160;
    r[6] = (u)0 + (u)0;
    r[7] = (u)0 + 4; CALL(R_GM_ConfigObjectAction);
     goto L800ccc44;
    L800ccc30:;
    r[3] = *(short *)((u)r[4] + 186);
    c = ((r[3] != r[2]));  if (c) goto L800ccc44;
    *(int *)((u)r[4] + 1672) = r[6];
    L800ccc44:;
    r[31] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
