extern char R_s18a_rc_800D9034[] __asm__("s18a_rc_800D9034");
extern char R_s18a_rc_800DE748[] __asm__("s18a_rc_800DE748");
extern char R_GM_ConfigObjectAction[] __asm__("GM_ConfigObjectAction");
int G_s18a_800DE294(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s18a_800DE294");
int G_s18a_800DE294(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(32)
    r[29] = (u)r[29] + -32;
    *(int *)((u)r[29] + 20) = r[17];
    r[17] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 24) = r[31];
    c = ((r[5] != 0)); *(int *)((u)r[29] + 16) = r[16]; if (c) goto L800de300;
    r[2] = 0;
    r[2] = (u)r[2] + (int)R_s18a_rc_800DE748;
    *(int *)((u)r[17] + 2236) = r[2];
    r[2] = 0;
    r[3] = *(int *)((u)r[17] + 2216);
    r[2] = (u)r[2] + (int)R_s18a_rc_800D9034;
    *(int *)((u)r[17] + 2240) = r[2];
    r[2] = *(int *)((u)r[3] + 24);
    r[16] = *(unsigned char *)((u)r[2] + 0);
    r[2] = *(short *)((u)r[17] + 170);
    c = ((r[2] == r[16])); r[4] = (u)r[17] + 156; if (c) goto L800de2f4;
    r[5] = (u)r[16] + (u)0;
    r[6] = (u)0 + (u)0;
    r[7] = (u)0 + 4; CALL(R_GM_ConfigObjectAction);
    L800de2f4:;
    r[2] = *(int *)((u)r[17] + 2100);
    *(short *)((u)r[2] + 62) = r[16];
    L800de300:;
    r[31] = *(int *)((u)r[29] + 24);
    r[17] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 32; goto out;
out:
    RECOMP_RETURN;
}
