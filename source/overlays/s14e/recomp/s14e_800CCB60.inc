extern char R_ZAKO14_PlayerAddress[] __asm__("ZAKO14_PlayerAddress");
extern char R_ZAKO14_PlayerMap[] __asm__("ZAKO14_PlayerMap");
extern char R_ZAKO14_PlayerPosition[] __asm__("ZAKO14_PlayerPosition");
int G_s14e_800CCB60(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s14e_800CCB60");
int G_s14e_800CCB60(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[2] = 0;
    r[2] = *(int *)((u)r[2] + (int)R_ZAKO14_PlayerAddress);
    *(int *)((u)r[4] + 3060) = r[2];
    r[2] = 0;
    r[3] = *(int *)((u)r[2] + (int)R_ZAKO14_PlayerMap);
    r[2] = 0;
    r[8] = (u)r[2] + (int)R_ZAKO14_PlayerPosition;
    r[5] = LWL(((u)r[8] + 3), r[5]);
    r[5] = LWR(((u)r[8] + 0), r[5]);
    r[6] = LWL(((u)r[8] + 7), r[6]);
    r[6] = LWR(((u)r[8] + 4), r[6]);
    SWL(((u)r[4] + 3043), r[5]);
    SWR(((u)r[4] + 3040), r[5]);
    SWL(((u)r[4] + 3047), r[6]);
    SWR(((u)r[4] + 3044), r[6]);
    *(int *)((u)r[4] + 3064) = r[3]; goto out;
out:
    RECOMP_RETURN;
}
