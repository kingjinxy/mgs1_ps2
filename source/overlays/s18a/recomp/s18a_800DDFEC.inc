extern char R_GM_PlayerStatus[] __asm__("GM_PlayerStatus");
extern char R_s18a_800DE584[] __asm__("s18a_800DE584");
extern char R_s18a_rc_800D9034[] __asm__("s18a_rc_800D9034");
extern char R_GM_ConfigObjectAction[] __asm__("GM_ConfigObjectAction");
int G_s18a_800DDFEC(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s18a_800DDFEC");
int G_s18a_800DDFEC(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    c = ((r[5] != 0)); *(int *)((u)r[29] + 20) = r[31]; if (c) goto L800de064;
    r[2] = 0;
    r[2] = (u)r[2] + (int)R_s18a_800DE584;
    *(int *)((u)r[16] + 2236) = r[2];
    r[2] = 0;
    r[2] = (u)r[2] + (int)R_s18a_rc_800D9034;
    r[4] = 0;
    r[3] = *(int *)((u)r[16] + 2216);
    r[5] = (u)0 + -17;
    *(int *)((u)r[16] + 2240) = r[2];
    r[2] = *(int *)((u)r[4] + (int)R_GM_PlayerStatus);
    r[3] = *(int *)((u)r[3] + 16);
    r[2] = r[2] & r[5];
    *(int *)((u)r[4] + (int)R_GM_PlayerStatus) = r[2];
    r[2] = *(short *)((u)r[16] + 170);
    r[5] = *(unsigned char *)((u)r[3] + 2);
    c = ((r[2] == r[5])); r[4] = (u)r[16] + 156; if (c) goto L800de054;
    r[6] = (u)0 + (u)0;
    r[7] = (u)0 + 1; CALL(R_GM_ConfigObjectAction);
    L800de054:;
    r[2] = *(int *)((u)r[16] + 2020);
    *(short *)((u)r[16] + 2320) = 0;
    r[2] = r[2] | 4;
    *(int *)((u)r[16] + 2020) = r[2];
    L800de064:;
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
