extern char R_GM_ConfigObjectAction[] __asm__("GM_ConfigObjectAction");
int G_s10a_800D984C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s10a_800D984C");
int G_s10a_800D984C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(32)
    r[29] = (u)r[29] + -32;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 24) = r[31];
    *(int *)((u)r[29] + 20) = r[17];
    r[2] = *(int *)((u)r[16] + 1728);
    c = ((r[2] == r[5])); r[17] = (u)r[7] + (u)0; if (c) goto L800d988c;
    *(int *)((u)r[16] + 1728) = r[5];
    r[4] = (u)r[16] + 160;
    r[6] = (u)0 + (u)0;
    r[7] = (u)0 + 4; CALL(R_GM_ConfigObjectAction);
     goto L800d98b4;
    L800d988c:;
    r[3] = *(short *)((u)r[16] + 186);
    r[2] = (u)0 + 1;
    c = ((r[3] != r[2])); r[4] = (u)r[16] + 160; if (c) goto L800d98b4;
    r[5] = (u)r[6] + (u)0;
    r[6] = (u)0 + (u)0;
    r[7] = (u)0 + 4;
    *(int *)((u)r[16] + 1728) = r[5]; CALL(R_GM_ConfigObjectAction);
    *(int *)((u)r[16] + 1748) = r[17];
    L800d98b4:;
    r[31] = *(int *)((u)r[29] + 24);
    r[17] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 32; goto out;
out:
    RECOMP_RETURN;
}
