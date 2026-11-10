extern char R_GM_PlayerStatus[] __asm__("GM_PlayerStatus");
int G_s18a_800CE4CC(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s18a_800CE4CC");
int G_s18a_800CE4CC(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[2] = 0;
    r[2] = *(int *)((u)r[2] + (int)R_GM_PlayerStatus);
    r[3] = (u)0 + 8;
    r[2] = r[2] & 2048;
    c = ((r[2] != 0)); *(int *)((u)r[4] + 2384) = r[3]; if (c) goto L800ce4f4;
    r[2] = *(int *)((u)r[4] + 2408);
    r[2] = (u)r[2] + 1;
    *(int *)((u)r[4] + 2408) = r[2];
    L800ce4f4:;
    r[2] = *(int *)((u)r[4] + 2408);
    r[2] = (int)r[2] < 5;
    c = ((r[2] != 0));  if (c) goto L800ce528;
    r[2] = *(int *)((u)r[4] + 2480);
    r[2] = (int)r[2] < 1001;
    c = ((r[2] != 0)); r[2] = (u)0 + 28; if (c) goto L800ce520;
    r[2] = (u)0 + 25;
    L800ce520:;
    *(int *)((u)r[4] + 2404) = r[2];
    *(int *)((u)r[4] + 2408) = 0;
    L800ce528:;
     goto out;
out:
    RECOMP_RETURN;
}
