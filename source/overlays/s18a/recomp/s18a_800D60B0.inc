extern char R_GM_PlayerStatus[] __asm__("GM_PlayerStatus");
int G_s18a_800D60B0(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s18a_800D60B0");
int G_s18a_800D60B0(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[2] = *(int *)((u)r[4] + 2152);
    r[2] = r[2] & 4;
    c = ((r[2] != 0)); r[2] = 0; if (c) goto L800d60f8;
    r[2] = *(int *)((u)r[2] + (int)R_GM_PlayerStatus);
    r[2] = r[2] & 2048;
    c = ((r[2] == 0)); r[2] = (u)0 + 3; if (c) goto L800d60f8;
    r[3] = *(short *)((u)r[4] + 2156);
    c = ((r[3] == r[2]));  if (c) goto L800d60f8;
    r[2] = *(int *)((u)r[4] + 2140);
    r[2] = r[2] | 9;
    *(int *)((u)r[4] + 2140) = r[2];
    L800d60f8:;
     goto out;
out:
    RECOMP_RETURN;
}
