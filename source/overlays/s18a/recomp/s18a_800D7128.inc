extern char R_GM_PlayerStatus[] __asm__("GM_PlayerStatus");
int G_s18a_800D7128(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s18a_800D7128");
int G_s18a_800D7128(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[6] = 0x800000;
    r[3] = 0;
    r[2] = *(int *)((u)r[3] + (int)R_GM_PlayerStatus);
    r[7] = *(int *)((u)r[4] + 2024);
    r[2] = r[2] | r[6];
    *(int *)((u)r[3] + (int)R_GM_PlayerStatus) = r[2];
    *(char *)((u)r[4] + 2300) = r[5];
    r[2] = *(unsigned short *)((u)r[7] + 0);
    r[2] = r[2] & 65377;
    *(short *)((u)r[7] + 0) = r[2]; goto out;
out:
    RECOMP_RETURN;
}
