extern char R_GM_PlayerStatus[] __asm__("GM_PlayerStatus");
extern char R_linkvarbuf[] __asm__("linkvarbuf");
int G_s18a_800CF554(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s18a_800CF554");
int G_s18a_800CF554(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[5] = (u)r[4] + (u)0;
    r[2] = *(int *)((u)r[5] + 2368);
    c = ((r[2] == 0)); r[2] = 0; if (c) goto L800cf5bc;
    r[2] = *(int *)((u)r[2] + (int)R_GM_PlayerStatus);
    r[2] = r[2] & 4;
    c = ((r[2] == 0)); r[2] = 0; if (c) goto L800cf59c;
    r[2] = *(short *)((u)r[2] + ((int)R_linkvarbuf + 22));
    r[2] = (int)r[2] < 41;
    c = ((r[2] != 0)); r[2] = (u)0 + 3; if (c) goto L800cf59c;
    *(int *)((u)r[5] + 2400) = r[2];
    r[2] = (u)0 + 17; goto L800cf5a8;
    L800cf59c:;
    r[2] = (u)0 + 3;
    *(int *)((u)r[5] + 2400) = r[2];
    r[2] = (u)0 + 14;
    L800cf5a8:;
    *(int *)((u)r[5] + 2404) = r[2];
    *(int *)((u)r[5] + 2428) = 0;
    *(int *)((u)r[5] + 2408) = 0;
    *(int *)((u)r[5] + 2392) = 0; goto out;
    L800cf5bc:;
    r[4] = *(int *)((u)r[5] + 2476);
    r[3] = *(int *)((u)r[5] + 2408);
    r[2] = (u)0 + 23;
    *(int *)((u)r[5] + 2384) = r[2];
    r[3] = (u)r[3] + 1;
    *(int *)((u)r[5] + 2388) = r[4];
    *(int *)((u)r[5] + 2408) = r[3]; goto out;
out:
    RECOMP_RETURN;
}
