extern char R_s18a_800D7EC4[] __asm__("s18a_800D7EC4");
extern char R_s18a_rc_800D9034[] __asm__("s18a_rc_800D9034");
extern char R_GM_ConfigObjectAction[] __asm__("GM_ConfigObjectAction");
extern char R_GM_SeSet[] __asm__("GM_SeSet");
int G_s18a_800D9158(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s18a_800D9158");
int G_s18a_800D9158(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(32)
    r[29] = (u)r[29] + -32;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 20) = r[17];
    r[17] = (u)r[5] + (u)0;
    c = ((r[17] != 0)); *(int *)((u)r[29] + 24) = r[31]; if (c) goto L800d91c0;
    r[4] = (u)r[16] + 32;
    r[5] = (u)0 + 8; CALL(R_GM_SeSet);
    r[2] = 0;
    r[3] = *(int *)((u)r[16] + 2216);
    r[2] = (u)r[2] + (int)R_s18a_rc_800D9034;
    *(short *)((u)r[16] + 2302) = 0;
    *(int *)((u)r[16] + 2236) = r[2];
    *(int *)((u)r[16] + 2240) = r[2];
    r[2] = *(int *)((u)r[3] + 8);
    r[5] = *(unsigned char *)((u)r[2] + 2);
    r[2] = *(short *)((u)r[16] + 170);
    c = ((r[2] == r[5])); r[4] = (u)r[16] + 156; if (c) goto L800d91c0;
    r[6] = (u)0 + (u)0;
    r[7] = (u)0 + 4; CALL(R_GM_ConfigObjectAction);
    L800d91c0:;
    r[2] = (u)0 + 2;
    c = ((r[17] != r[2]));  if (c) goto L800d91d0;
    *(short *)((u)r[16] + 108) = 0;
    L800d91d0:;
    r[2] = *(short *)((u)r[16] + 182);
    c = ((r[2] == 0)); r[2] = 0; if (c) goto L800d91fc;
    r[2] = (u)r[2] + (int)R_s18a_800D7EC4;
    *(int *)((u)r[16] + 2220) = r[2];
    *(int *)((u)r[16] + 2224) = 0;
    *(short *)((u)r[16] + 2322) = 0;
    *(short *)((u)r[16] + 2320) = 0;
    *(short *)((u)r[16] + 112) = 0;
    *(short *)((u)r[16] + 108) = 0;
    L800d91fc:;
    r[31] = *(int *)((u)r[29] + 24);
    r[17] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 32; goto out;
out:
    RECOMP_RETURN;
}
