extern char R_GM_PlayerPosition[] __asm__("GM_PlayerPosition");
int G_s18a_800CC800(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s18a_800CC800");
int G_s18a_800CC800(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[2] = 0;
    r[7] = (u)r[2] + (int)R_GM_PlayerPosition;
    r[3] = LWL(((u)r[7] + 3), r[3]);
    r[3] = LWR(((u)r[7] + 0), r[3]);
    r[5] = LWL(((u)r[7] + 7), r[5]);
    r[5] = LWR(((u)r[7] + 4), r[5]);
    SWL(((u)r[4] + 2419), r[3]);
    SWR(((u)r[4] + 2416), r[3]);
    SWL(((u)r[4] + 2423), r[5]);
    SWR(((u)r[4] + 2420), r[5]);
     goto out;
out:
    RECOMP_RETURN;
}
