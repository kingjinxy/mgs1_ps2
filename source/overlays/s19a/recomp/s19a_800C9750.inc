extern char R_GM_PlayerStatus[] __asm__("GM_PlayerStatus");
int G_s19a_800C9750(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s19a_800C9750");
int G_s19a_800C9750(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[3] = 0x10000;
    r[2] = 0;
    r[2] = *(int *)((u)r[2] + (int)R_GM_PlayerStatus);
    r[3] = r[3] | 80;
    r[2] = r[2] & r[3];
    r[2] = r[2] ^ 16;
    r[2] = (u)r[2] < (u)1; goto out;
out:
    RECOMP_RETURN;
}
