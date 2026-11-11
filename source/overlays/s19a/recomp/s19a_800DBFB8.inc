extern char R_s19a_800DBA10[] __asm__("s19a_800DBA10");
extern char R_GM_ConfigObjectAction[] __asm__("GM_ConfigObjectAction");
extern char R_GM_SeSet[] __asm__("GM_SeSet");
int G_s19a_800DBFB8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s19a_800DBFB8");
int G_s19a_800DBFB8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    c = ((r[5] != 0)); *(int *)((u)r[29] + 20) = r[31]; if (c) goto L800dbff4;
    r[4] = (u)r[16] + 164;
    r[5] = (u)0 + 13;
    r[2] = (u)r[5] + (u)0;
    r[6] = (u)0 + (u)0;
    r[7] = (u)0 + 4;
    *(int *)((u)r[16] + 2044) = r[2]; CALL(R_GM_ConfigObjectAction);
    r[5] = *(short *)((u)r[16] + 2072);
    r[4] = (u)r[16] + 40; CALL(R_GM_SeSet);
    L800dbff4:;
    r[2] = *(short *)((u)r[16] + 190);
    c = ((r[2] == 0)); r[2] = 0; if (c) goto L800dc018;
    r[2] = (u)r[2] + (int)R_s19a_800DBA10;
    *(int *)((u)r[16] + 2028) = r[2];
    *(int *)((u)r[16] + 2036) = 0;
    *(short *)((u)r[16] + 120) = 0;
    *(short *)((u)r[16] + 116) = 0;
    L800dc018:;
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
