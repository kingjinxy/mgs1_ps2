extern char R_GM_PlayerStatus[] __asm__("GM_PlayerStatus");
int G_s18a_800CDD68(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s18a_800CDD68");
int G_s18a_800CDD68(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[5] = (u)r[4] + (u)0;
    r[2] = 0;
    r[4] = *(int *)((u)r[5] + 2476);
    r[3] = *(int *)((u)r[2] + (int)R_GM_PlayerStatus);
    r[2] = (u)0 + 5;
    *(int *)((u)r[5] + 2384) = r[2];
    r[3] = r[3] & 4;
    c = ((r[3] == 0)); *(int *)((u)r[5] + 2388) = r[4]; if (c) goto L800cdd90;
    *(int *)((u)r[5] + 2408) = 0;
    L800cdd90:;
    r[3] = *(int *)((u)r[5] + 2408);
    r[2] = (int)r[3] < 181;
    c = ((r[2] == 0)); r[2] = (u)0 + 2; if (c) goto L800cddb8;
    r[2] = *(int *)((u)r[5] + 2480);
    r[2] = (int)r[2] < 3000;
    c = ((r[2] == 0)); r[2] = (u)0 + 2; if (c) goto L800cddd4;
    L800cddb8:;
    *(int *)((u)r[5] + 2400) = r[2];
    r[2] = (u)0 + 8;
    *(int *)((u)r[5] + 2404) = r[2];
    *(int *)((u)r[5] + 2432) = 0;
    *(int *)((u)r[5] + 2428) = 0;
    *(int *)((u)r[5] + 2408) = 0; goto out;
    L800cddd4:;
    r[2] = (u)r[3] + 1;
    *(int *)((u)r[5] + 2408) = r[2]; goto out;
out:
    RECOMP_RETURN;
}
