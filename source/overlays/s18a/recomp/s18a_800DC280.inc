extern char R_GM_PlayerStatus[] __asm__("GM_PlayerStatus");
int G_s18a_800DC280(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s18a_800DC280");
int G_s18a_800DC280(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[31];
    r[2] = *(int *)((u)r[4] + 2152);
    r[2] = r[2] & 64;
    c = ((r[2] == 0)); r[2] = 0; if (c) goto L800dc2d4;
    r[2] = *(int *)((u)r[2] + (int)R_GM_PlayerStatus);
    r[2] = r[2] & 2048;
    c = ((r[2] == 0));  if (c) goto L800dc2d4;
    r[3] = *(int *)((u)r[4] + 2132);
    c = ((r[3] == 0));  if (c) goto L800dc2d4;
    r[5] = *(int *)((u)r[4] + 2136);
    r[2] = (u)r[5] + 1;
    t = r[3]; *(int *)((u)r[4] + 2136) = r[2]; CALL((int (*)())t);
    L800dc2d4:;
    r[31] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
