extern char R_GM_PlayerPosition[] __asm__("GM_PlayerPosition");
extern char R_s17a_800DA9DC[] __asm__("s17a_800DA9DC");
int G_s17a_800DB210(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s17a_800DB210");
int G_s17a_800DB210(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[31];
    r[2] = *(int *)((u)r[4] + 6500);
    r[2] = (int)r[2] < 5;
    c = ((r[2] == 0)); r[2] = 0; if (c) goto L800db250;
    r[7] = (u)r[2] + (int)R_GM_PlayerPosition;
    r[3] = LWL(((u)r[7] + 3), r[3]);
    r[3] = LWR(((u)r[7] + 0), r[3]);
    r[5] = LWL(((u)r[7] + 7), r[5]);
    r[5] = LWR(((u)r[7] + 4), r[5]);
    SWL(((u)r[4] + 6703), r[3]);
    SWR(((u)r[4] + 6700), r[3]);
    SWL(((u)r[4] + 6707), r[5]);
    SWR(((u)r[4] + 6704), r[5]);
    L800db250:;
     CALL(R_s17a_800DA9DC);
    r[31] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
