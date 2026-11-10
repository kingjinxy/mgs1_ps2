extern char R_MENU_SetRadarFunc[] __asm__("MENU_SetRadarFunc");
extern char R_s18a_800C6B60[] __asm__("s18a_800C6B60");
int G_s18a_800C70F4(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s18a_800C70F4");
int G_s18a_800C70F4(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[31];
    r[4] = (u)0 + (u)0; CALL(R_MENU_SetRadarFunc);
     CALL(R_s18a_800C6B60);
    r[31] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
int G_s18a_rc_800C711C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s18a_rc_800C711C");
int G_s18a_rc_800C711C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
     goto out;
out:
    RECOMP_RETURN;
}
