extern char R_GM_GameOverTimer[] __asm__("GM_GameOverTimer");
extern char R_GM_GameOver[] __asm__("GM_GameOver");
int G_s18a_800D9F90(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s18a_800D9F90");
int G_s18a_800D9F90(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    r[2] = (u)0 + 600;
    c = ((r[5] != r[2])); *(int *)((u)r[29] + 16) = r[31]; if (c) goto L800d9fac;
    r[2] = 0;
    *(int *)((u)r[2] + (int)R_GM_GameOverTimer) = 0; CALL(R_GM_GameOver);
    L800d9fac:;
    r[31] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
