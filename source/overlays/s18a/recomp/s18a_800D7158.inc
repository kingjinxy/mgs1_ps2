extern char R_GM_PlayerStatus[] __asm__("GM_PlayerStatus");
int G_s18a_800D7158(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s18a_800D7158");
int G_s18a_800D7158(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[6] = 0xff7f0000;
    r[6] = r[6] | 65535;
    r[5] = 0;
    r[4] = *(int *)((u)r[4] + 2024);
    r[2] = *(int *)((u)r[5] + (int)R_GM_PlayerStatus);
    r[3] = *(unsigned short *)((u)r[4] + 0);
    r[2] = r[2] & r[6];
    *(int *)((u)r[5] + (int)R_GM_PlayerStatus) = r[2];
    r[3] = r[3] | 158;
    *(short *)((u)r[4] + 0) = r[3]; goto out;
out:
    RECOMP_RETURN;
}
