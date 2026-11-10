extern char R_GM_Camera[] __asm__("GM_Camera");
extern char R_GM_PlayerStatus[] __asm__("GM_PlayerStatus");
int G_s18a_800D5BC4(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s18a_800D5BC4");
int G_s18a_800D5BC4(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[3] = 0;
    r[2] = (u)0 + 1;
    r[5] = 0;
    *(short *)((u)r[3] + ((int)R_GM_Camera + 34)) = r[2];
    r[2] = *(int *)((u)r[5] + (int)R_GM_PlayerStatus);
    r[3] = (u)0 + -4;
    *(short *)((u)r[4] + 2342) = 0;
    *(short *)((u)r[4] + 2296) = r[3];
    r[2] = r[2] | 32769;
    *(int *)((u)r[5] + (int)R_GM_PlayerStatus) = r[2]; goto out;
out:
    RECOMP_RETURN;
}
