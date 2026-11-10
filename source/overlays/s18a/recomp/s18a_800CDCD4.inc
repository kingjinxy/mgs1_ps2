extern char R_GM_PlayerStatus[] __asm__("GM_PlayerStatus");
int G_s18a_800CDCD4(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s18a_800CDCD4");
int G_s18a_800CDCD4(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[5] = (u)r[4] + (u)0;
    r[2] = 0;
    r[4] = *(int *)((u)r[5] + 2476);
    r[3] = *(int *)((u)r[2] + (int)R_GM_PlayerStatus);
    r[2] = (u)0 + 5;
    *(int *)((u)r[5] + 2384) = r[2];
    r[3] = r[3] & 512;
    c = ((r[3] != 0)); *(int *)((u)r[5] + 2388) = r[4]; if (c) goto L800cdd14;
    r[2] = (u)0 + 2;
    *(int *)((u)r[5] + 2400) = r[2];
    r[2] = (u)0 + 8;
    *(int *)((u)r[5] + 2404) = r[2];
    *(int *)((u)r[5] + 2428) = 0;
    *(int *)((u)r[5] + 2408) = 0; goto out;
    L800cdd14:;
    r[2] = *(int *)((u)r[5] + 2408);
    r[2] = (u)r[2] + 1;
    *(int *)((u)r[5] + 2408) = r[2]; goto out;
out:
    RECOMP_RETURN;
}
