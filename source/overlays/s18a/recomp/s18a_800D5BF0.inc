extern char R_GM_Camera[] __asm__("GM_Camera");
extern char R_GM_PlayerStatus[] __asm__("GM_PlayerStatus");
int G_s18a_800D5BF0(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s18a_800D5BF0");
int G_s18a_800D5BF0(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[5] = (u)r[4] + (u)0;
    r[2] = 0;
    *(short *)((u)r[2] + ((int)R_GM_Camera + 34)) = 0;
    r[2] = (u)0 + 4;
    r[4] = 0;
    *(short *)((u)r[5] + 2296) = r[2];
    r[2] = *(int *)((u)r[4] + (int)R_GM_PlayerStatus);
    r[6] = *(int *)((u)r[5] + 2020);
    r[3] = (u)0 + -2;
    *(short *)((u)r[5] + 2342) = 0;
    r[2] = r[2] & r[3];
    *(int *)((u)r[4] + (int)R_GM_PlayerStatus) = r[2];
    r[2] = r[6] & 32768;
    c = ((r[2] == 0)); r[2] = 0xffff0000; if (c) goto L800d5c58;
    r[2] = r[2] | 32767;
    r[2] = r[6] & r[2];
    *(int *)((u)r[5] + 2020) = r[2];
    r[7] = LWL(((u)r[5] + 2335), r[7]);
    r[7] = LWR(((u)r[5] + 2332), r[7]);
    r[8] = LWL(((u)r[5] + 2339), r[8]);
    r[8] = LWR(((u)r[5] + 2336), r[8]);
    SWL(((u)r[5] + 35), r[7]);
    SWR(((u)r[5] + 32), r[7]);
    SWL(((u)r[5] + 39), r[8]);
    SWR(((u)r[5] + 36), r[8]);
    L800d5c58:;
     goto out;
out:
    RECOMP_RETURN;
}
