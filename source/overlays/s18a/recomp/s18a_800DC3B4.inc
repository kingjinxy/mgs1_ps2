extern char R_GM_PlayerStatus[] __asm__("GM_PlayerStatus");
extern char R_s18a_800DCF5C[] __asm__("s18a_800DCF5C");
extern char R_s18a_rc_800D9034[] __asm__("s18a_rc_800D9034");
extern char R_GM_ConfigObjectAction[] __asm__("GM_ConfigObjectAction");
int G_s18a_800DC3B4(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s18a_800DC3B4");
int G_s18a_800DC3B4(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[31];
    c = ((r[5] != 0)); r[6] = (u)r[4] + (u)0; if (c) goto L800dc414;
    r[2] = 0;
    r[2] = (u)r[2] + (int)R_s18a_800DCF5C;
    *(int *)((u)r[6] + 2236) = r[2];
    r[2] = 0;
    r[2] = (u)r[2] + (int)R_s18a_rc_800D9034;
    r[3] = *(int *)((u)r[6] + 2216);
    r[4] = 0;
    *(int *)((u)r[6] + 2240) = r[2];
    r[2] = *(int *)((u)r[4] + (int)R_GM_PlayerStatus);
    r[3] = *(int *)((u)r[3] + 4);
    r[2] = r[2] | 16;
    *(int *)((u)r[4] + (int)R_GM_PlayerStatus) = r[2];
    r[2] = *(short *)((u)r[6] + 170);
    r[5] = *(unsigned char *)((u)r[3] + 0);
    c = ((r[2] == r[5])); r[4] = (u)r[6] + 156; if (c) goto L800dc414;
    r[6] = (u)0 + (u)0;
    r[7] = (u)0 + 4; CALL(R_GM_ConfigObjectAction);
    L800dc414:;
    r[31] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
