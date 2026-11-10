extern char R_s18a_800DCD44[] __asm__("s18a_800DCD44");
extern char R_s18a_rc_800D9034[] __asm__("s18a_rc_800D9034");
extern char R_GM_ConfigObjectAction[] __asm__("GM_ConfigObjectAction");
int G_s18a_800DC2E4(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s18a_800DC2E4");
int G_s18a_800DC2E4(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    c = ((r[5] != 0)); *(int *)((u)r[29] + 16) = r[31]; if (c) goto L800dc334;
    r[2] = 0;
    r[2] = (u)r[2] + (int)R_s18a_800DCD44;
    *(int *)((u)r[4] + 2236) = r[2];
    r[2] = 0;
    r[3] = *(int *)((u)r[4] + 2216);
    r[2] = (u)r[2] + (int)R_s18a_rc_800D9034;
    *(int *)((u)r[4] + 2240) = r[2];
    r[2] = *(int *)((u)r[3] + 0);
    r[5] = *(unsigned char *)((u)r[2] + 1);
    r[2] = *(short *)((u)r[4] + 170);
    c = ((r[2] == r[5])); r[4] = (u)r[4] + 156; if (c) goto L800dc334;
    r[6] = (u)0 + (u)0;
    r[7] = (u)0 + 4; CALL(R_GM_ConfigObjectAction);
    L800dc334:;
    r[31] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
