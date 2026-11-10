extern char R_GM_PlayerStatus[] __asm__("GM_PlayerStatus");
int G_s18a_800CEFE4(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s18a_800CEFE4");
int G_s18a_800CEFE4(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[2] = *(int *)((u)r[4] + 2480);
    r[3] = *(int *)((u)r[4] + 2476);
    r[2] = (int)r[2] < 6000;
    c = ((r[2] == 0)); *(int *)((u)r[4] + 2388) = r[3]; if (c) goto L800cf000;
    r[2] = (u)0 + 12;
    *(int *)((u)r[4] + 2384) = r[2];
    L800cf000:;
    r[2] = 0;
    r[2] = *(int *)((u)r[2] + (int)R_GM_PlayerStatus);
    r[2] = r[2] & 96;
    c = ((r[2] == 0));  if (c) goto L800cf044;
    r[2] = *(int *)((u)r[4] + 2480);
    r[2] = (int)r[2] < 1500;
    c = ((r[2] == 0)); r[2] = (u)0 + 5; if (c) goto L800cf064;
    *(int *)((u)r[4] + 2400) = r[2];
    r[2] = (u)0 + 27;
    L800cf034:;
    *(int *)((u)r[4] + 2404) = r[2];
    *(int *)((u)r[4] + 2428) = 0;
    *(int *)((u)r[4] + 2408) = 0; goto out;
    L800cf044:;
    r[2] = *(int *)((u)r[4] + 2480);
    r[2] = (int)r[2] < 1500;
    c = ((r[2] == 0)); r[2] = (u)0 + 5; if (c) goto L800cf064;
    *(int *)((u)r[4] + 2400) = r[2];
    r[2] = (u)0 + 21; goto L800cf034;
    L800cf064:;
    r[3] = *(int *)((u)r[4] + 2408);
    r[2] = (int)r[3] < 601;
    c = ((r[2] != 0)); r[2] = (u)0 + 1; if (c) goto L800cf084;
    *(int *)((u)r[4] + 2400) = r[2];
    r[2] = (u)0 + 3; goto L800cf034;
    L800cf084:;
    r[2] = (u)r[3] + 1;
    *(int *)((u)r[4] + 2408) = r[2]; goto out;
out:
    RECOMP_RETURN;
}
