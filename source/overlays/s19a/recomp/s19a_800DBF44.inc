extern char R_s19a_800DBA10[] __asm__("s19a_800DBA10");
extern char R_GM_ConfigObjectAction[] __asm__("GM_ConfigObjectAction");
extern char R_s19a_800DB950[] __asm__("s19a_800DB950");
int G_s19a_800DBF44(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s19a_800DBF44");
int G_s19a_800DBF44(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    c = ((r[5] != 0)); *(int *)((u)r[29] + 20) = r[31]; if (c) goto L800dbf74;
    r[2] = (u)0 + 3;
    *(int *)((u)r[16] + 2044) = r[2];
    r[4] = (u)r[16] + 164;
    r[5] = (u)r[2] + (u)0;
    r[6] = (u)0 + (u)0;
    r[7] = (u)0 + 4; CALL(R_GM_ConfigObjectAction);
    L800dbf74:;
    r[4] = (u)r[16] + (u)0; CALL(R_s19a_800DB950);
    c = ((r[2] != 0));  if (c) goto L800dbfa8;
    r[2] = *(short *)((u)r[16] + 190);
    c = ((r[2] == 0)); r[2] = 0; if (c) goto L800dbfa8;
    r[2] = (u)r[2] + (int)R_s19a_800DBA10;
    *(int *)((u)r[16] + 2028) = r[2];
    *(int *)((u)r[16] + 2036) = 0;
    *(short *)((u)r[16] + 120) = 0;
    *(short *)((u)r[16] + 116) = 0;
    L800dbfa8:;
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
