extern char R_GM_Camera[] __asm__("GM_Camera");
extern char R_GM_PlayerPosition[] __asm__("GM_PlayerPosition");
extern char R_s18a_dat_800E3ED0[] __asm__("s18a_dat_800E3ED0");
extern char R_s18a_dat_800E3ED8[] __asm__("s18a_dat_800E3ED8");
int G_s18a_800C5698(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s18a_800C5698");
int G_s18a_800C5698(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[3] = 0;
    r[3] = (u)r[3] + (int)R_GM_Camera;
    r[2] = (u)0 + 440;
    *(short *)((u)r[3] + 16) = r[2];
    r[2] = (u)0 + 2048;
    *(short *)((u)r[3] + 18) = r[2];
    r[2] = (u)0 + 6600;
    *(int *)((u)r[3] + 28) = r[2];
    r[2] = 0;
    r[4] = (u)r[2] + (int)R_GM_PlayerPosition;
    *(short *)((u)r[3] + 20) = 0;
    r[5] = *(unsigned short *)((u)r[2] + (int)R_GM_PlayerPosition);
    r[6] = *(unsigned short *)((u)r[4] + 4);
    r[4] = *(unsigned short *)((u)r[4] + 2);
    r[2] = (u)0 + 2;
    *(short *)((u)r[3] + 40) = r[2];
    r[2] = 0;
    *(short *)((u)r[3] + 8) = r[5];
    *(short *)((u)r[3] + 12) = r[6];
    *(short *)((u)r[3] + 10) = r[4];
    r[3] = *(int *)((u)r[2] + (int)R_s18a_dat_800E3ED0);
    r[2] = (u)0 + 6;
    *(int *)((u)r[3] + 0) = r[2];
    r[2] = 0;
    *(int *)((u)r[2] + (int)R_s18a_dat_800E3ED8) = 0; goto out;
out:
    RECOMP_RETURN;
}
