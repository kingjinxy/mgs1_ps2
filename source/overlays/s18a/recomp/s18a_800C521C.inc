extern char R_GM_Camera[] __asm__("GM_Camera");
extern char R_s18a_dat_800E3ED8[] __asm__("s18a_dat_800E3ED8");
int G_s18a_800C521C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s18a_800C521C");
int G_s18a_800C521C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[3] = 0;
    r[4] = (u)r[3] + (int)R_GM_Camera;
    r[2] = (u)0 + 2379;
    *(short *)((u)r[4] + 40) = 0;
    *(short *)((u)r[3] + (int)R_GM_Camera) = r[2];
    r[2] = (u)0 + 12461;
    *(short *)((u)r[4] + 2) = r[2];
    r[2] = (u)0 + -156;
    *(short *)((u)r[4] + 4) = r[2];
    r[2] = (u)0 + 2283;
    *(short *)((u)r[4] + 8) = r[2];
    r[2] = (u)0 + 12479;
    r[5] = 0;
    *(short *)((u)r[4] + 10) = r[2];
    r[2] = *(int *)((u)r[5] + (int)R_s18a_dat_800E3ED8);
    r[3] = (u)0 + -147;
    *(short *)((u)r[4] + 12) = r[3];
    r[2] = (u)r[2] + 1;
    *(int *)((u)r[5] + (int)R_s18a_dat_800E3ED8) = r[2]; goto out;
out:
    RECOMP_RETURN;
}
