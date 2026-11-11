extern char R_s19a_800DBA54[] __asm__("s19a_800DBA54");
extern char R_GM_ConfigObjectAction[] __asm__("GM_ConfigObjectAction");
int G_s19a_800DC028(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s19a_800DC028");
int G_s19a_800DC028(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(32)
    r[29] = (u)r[29] + -32;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 28) = r[31];
    *(int *)((u)r[29] + 24) = r[18];
    *(int *)((u)r[29] + 20) = r[17];
    r[18] = *(int *)((u)r[16] + 2036);
    r[17] = *(int *)((u)r[16] + 2028);
    r[2] = (u)r[18] + 1;
    c = ((r[17] != 0)); *(int *)((u)r[16] + 2036) = r[2]; if (c) goto L800dc07c;
    r[2] = 0;
    r[17] = (u)r[2] + (int)R_s19a_800DBA54;
    r[4] = (u)r[16] + 164;
    r[5] = (u)0 + 14;
    r[2] = (u)r[5] + (u)0;
    r[6] = (u)0 + (u)0;
    r[7] = (u)r[6] + (u)0;
    *(int *)((u)r[16] + 2028) = r[17];
    *(int *)((u)r[16] + 2044) = r[2]; CALL(R_GM_ConfigObjectAction);
    L800dc07c:;
    r[4] = (u)r[16] + (u)0;
    t = r[17]; r[5] = (u)r[18] + (u)0; CALL((int (*)())t);
    r[31] = *(int *)((u)r[29] + 28);
    r[18] = *(int *)((u)r[29] + 24);
    r[17] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 32; goto out;
out:
    RECOMP_RETURN;
}
