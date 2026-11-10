extern char R_GM_PlayerStatus[] __asm__("GM_PlayerStatus");
extern char R_s18a_800CCE24[] __asm__("s18a_800CCE24");
int G_s18a_800CFD54(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s18a_800CFD54");
int G_s18a_800CFD54(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 20) = r[31];
    r[2] = *(int *)((u)r[16] + 2408);
    r[2] = (int)r[2] < 4;
    c = ((r[2] != 0)); r[2] = (u)0 + 3; if (c) goto L800cfdb4;
    r[2] = 0;
    r[2] = *(int *)((u)r[2] + (int)R_GM_PlayerStatus);
    r[2] = r[2] & 260;
    c = ((r[2] == 0)); r[2] = (u)0 + 3; if (c) goto L800cfd9c;
    r[5] = (u)0 + (u)0; CALL(R_s18a_800CCE24);
    r[2] = (u)0 + 3;
    L800cfd9c:;
    *(int *)((u)r[16] + 2400) = r[2];
    r[2] = (u)0 + 14;
    *(int *)((u)r[16] + 2404) = r[2];
    *(int *)((u)r[16] + 2428) = 0;
    *(int *)((u)r[16] + 2408) = 0; goto L800cfdcc;
    L800cfdb4:;
    r[4] = *(int *)((u)r[16] + 2476);
    r[3] = *(int *)((u)r[16] + 2408);
    *(int *)((u)r[16] + 2384) = r[2];
    r[3] = (u)r[3] + 1;
    *(int *)((u)r[16] + 2388) = r[4];
    *(int *)((u)r[16] + 2408) = r[3];
    L800cfdcc:;
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
