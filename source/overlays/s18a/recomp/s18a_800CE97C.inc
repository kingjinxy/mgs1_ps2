extern char R_GM_PlayerAction[] __asm__("GM_PlayerAction");
extern char R_GM_PlayerStatus[] __asm__("GM_PlayerStatus");
int G_s18a_800CE97C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s18a_800CE97C");
int G_s18a_800CE97C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[2] = 0;
    r[3] = *(int *)((u)r[2] + (int)R_GM_PlayerAction);
    r[2] = (u)0 + 2;
    c = ((r[3] == r[2])); r[5] = (u)0 + 5; if (c) goto L800ce9b4;
    c = ((r[3] == r[5])); r[2] = (u)0 + 8; if (c) goto L800ce9b4;
    c = ((r[3] == r[2])); r[2] = 0; if (c) goto L800ce9b4;
    r[2] = *(int *)((u)r[2] + (int)R_GM_PlayerStatus);
    r[2] = r[2] & 4;
    c = ((r[2] != 0));  if (c) goto L800ce9d0;
    L800ce9b4:;
    r[2] = (u)0 + 1;
    *(int *)((u)r[4] + 2400) = r[2];
    r[2] = (u)0 + 3;
    *(int *)((u)r[4] + 2404) = r[2];
    *(int *)((u)r[4] + 2428) = 0;
    *(int *)((u)r[4] + 2408) = 0; goto out;
    L800ce9d0:;
    r[2] = *(int *)((u)r[4] + 2480);
    r[3] = *(int *)((u)r[4] + 2476);
    r[2] = (int)r[2] < 1300;
    c = ((r[2] == 0)); *(int *)((u)r[4] + 2388) = r[3]; if (c) goto L800ce9f8;
    r[2] = (u)0 + 27;
    *(int *)((u)r[4] + 2400) = r[5];
    *(int *)((u)r[4] + 2404) = r[2];
    *(int *)((u)r[4] + 2408) = 0; goto out;
    L800ce9f8:;
    r[2] = *(int *)((u)r[4] + 2408);
    r[2] = (u)r[2] + 1;
    *(int *)((u)r[4] + 2408) = r[2]; goto out;
out:
    RECOMP_RETURN;
}
