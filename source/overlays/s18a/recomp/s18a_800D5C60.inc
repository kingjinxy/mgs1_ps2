extern char R_GM_Camera[] __asm__("GM_Camera");
extern char R_s18a_dat_800C39EC[] __asm__("s18a_dat_800C39EC");
int G_s18a_800D5C60(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s18a_800D5C60");
int G_s18a_800D5C60(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[2] = *(int *)((u)r[4] + 2020);
    r[3] = (u)0 + 450;
    *(short *)((u)r[4] + 2304) = r[3];
    r[3] = 0;
    r[2] = r[2] | 2048;
    *(int *)((u)r[4] + 2020) = r[2];
    r[2] = (u)0 + 1;
    *(short *)((u)r[3] + ((int)R_GM_Camera + 34)) = r[2];
    r[2] = 0;
    r[3] = *(unsigned short *)((u)r[2] + (int)R_s18a_dat_800C39EC);
    r[2] = (u)0 + -4;
    *(short *)((u)r[4] + 2296) = r[2];
    r[2] = (u)0 + 320;
    *(short *)((u)r[4] + 2248) = r[2];
    *(short *)((u)r[4] + 2252) = r[3];
    *(short *)((u)r[4] + 2256) = r[3]; goto out;
out:
    RECOMP_RETURN;
}
