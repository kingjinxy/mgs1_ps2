extern char R_GM_PlayerAction[] __asm__("GM_PlayerAction");
extern char R_GM_PlayerStatus[] __asm__("GM_PlayerStatus");
int G_s18a_800CE0F8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s18a_800CE0F8");
int G_s18a_800CE0F8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[3] = *(int *)((u)r[4] + 2476);
    r[2] = (u)0 + 3;
    *(int *)((u)r[4] + 2384) = r[2];
    r[2] = 0;
    *(int *)((u)r[4] + 2388) = r[3];
    r[3] = *(int *)((u)r[2] + (int)R_GM_PlayerAction);
    r[2] = (u)0 + 2;
    c = ((r[3] == r[2])); r[2] = (u)0 + 5; if (c) goto L800ce140;
    c = ((r[3] == r[2])); r[2] = (u)0 + 8; if (c) goto L800ce140;
    c = ((r[3] == r[2])); r[2] = 0; if (c) goto L800ce140;
    r[2] = *(int *)((u)r[2] + (int)R_GM_PlayerStatus);
    r[2] = r[2] & 4;
    c = ((r[2] != 0));  if (c) goto L800ce15c;
    L800ce140:;
    r[2] = (u)0 + 3;
    *(int *)((u)r[4] + 2400) = r[2];
    r[2] = (u)0 + 14;
    *(int *)((u)r[4] + 2404) = r[2];
    *(int *)((u)r[4] + 2428) = 0;
    *(int *)((u)r[4] + 2408) = 0; goto out;
    L800ce15c:;
    r[2] = *(int *)((u)r[4] + 2408);
    r[2] = (u)r[2] + 1;
    *(int *)((u)r[4] + 2408) = r[2]; goto out;
out:
    RECOMP_RETURN;
}
