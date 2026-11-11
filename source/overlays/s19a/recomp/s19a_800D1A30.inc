extern char R_GM_PlayerPosition[] __asm__("GM_PlayerPosition");
extern char R_s19a_800D35DC[] __asm__("s19a_800D35DC");
int G_s19a_800D1A30(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s19a_800D1A30");
int G_s19a_800D1A30(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    r[5] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 16) = r[31];
    r[3] = *(short *)((u)r[5] + 2958);
    r[2] = (u)0 + 2;
    c = ((r[3] != r[2])); r[4] = 0; if (c) goto L800d1a5c;
    r[4] = (u)r[4] + (int)R_GM_PlayerPosition;
    r[5] = (u)r[5] + 32;
    r[6] = (u)0 + 143; CALL(R_s19a_800D35DC);
    L800d1a5c:;
    r[31] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
