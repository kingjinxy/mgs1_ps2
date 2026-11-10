extern char R_s18a_800D45EC[] __asm__("s18a_800D45EC");
extern char R_s18a_800D4730[] __asm__("s18a_800D4730");
extern char R_s18a_800D53CC[] __asm__("s18a_800D53CC");
int G_s18a_800D4780(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s18a_800D4780");
int G_s18a_800D4780(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[16];
    *(int *)((u)r[29] + 20) = r[31];
    r[16] = (u)r[4] + (u)0; CALL(R_s18a_800D4730);
    r[4] = (u)r[16] + (u)0; CALL(R_s18a_800D53CC);
    r[4] = (u)r[16] + (u)0; CALL(R_s18a_800D45EC);
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
