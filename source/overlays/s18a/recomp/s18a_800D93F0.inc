extern char R_GM_PlayerStatus[] __asm__("GM_PlayerStatus");
extern char R_s18a_rc_800DD2F8[] __asm__("s18a_rc_800DD2F8");
extern char R_GM_ConfigObjectOverride[] __asm__("GM_ConfigObjectOverride");
extern char R_s18a_800D6034[] __asm__("s18a_800D6034");
int G_s18a_800D93F0(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s18a_800D93F0");
int G_s18a_800D93F0(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(40)
    r[29] = (u)r[29] + -40;
    *(int *)((u)r[29] + 24) = r[16];
    r[16] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 28) = r[17];
    r[17] = (u)r[5] + (u)0;
    c = ((r[17] != 0)); *(int *)((u)r[29] + 32) = r[31]; if (c) goto L800d9460;
    r[2] = 0;
    r[2] = *(int *)((u)r[2] + (int)R_GM_PlayerStatus);
    r[2] = r[2] & 16;
    c = ((r[2] == 0)); r[3] = 0 | 65535; if (c) goto L800d9428;
    r[3] = (u)0 + 1022;
    L800d9428:;
    r[2] = *(int *)((u)r[16] + 2216);
    r[2] = *(int *)((u)r[2] + 16);
    r[5] = *(unsigned char *)((u)r[2] + 0);
    r[2] = *(short *)((u)r[16] + 172);
    c = ((r[2] == r[5])); r[4] = (u)r[16] + 156; if (c) goto L800d945c;
    *(int *)((u)r[29] + 16) = r[3];
    r[6] = (u)0 + (u)0;
    r[7] = (u)0 + 4; CALL(R_GM_ConfigObjectOverride);
    L800d945c:;
    *(short *)((u)r[16] + 2320) = 0;
    L800d9460:;
    r[2] = *(int *)((u)r[16] + 2212);
    r[2] = *(unsigned short *)((u)r[2] + 4);
    r[2] = r[2] & 128;
    c = ((r[2] == 0)); r[2] = (u)0 + 1; if (c) goto L800d9480;
    *(short *)((u)r[16] + 2320) = r[2];
    L800d9480:;
    r[2] = *(int *)((u)r[16] + 2212);
    r[2] = *(unsigned short *)((u)r[2] + 0);
    r[2] = r[2] & 128;
    c = ((r[2] == 0));  if (c) goto L800d94b0;
    r[2] = *(unsigned short *)((u)r[16] + 2158);
    r[2] = (u)r[2] + 1;
    *(short *)((u)r[16] + 2158) = r[2]; goto L800d94b4;
    L800d94b0:;
    *(short *)((u)r[16] + 2158) = 0;
    L800d94b4:;
    r[2] = (u)0 + 4;
    c = ((r[17] != r[2])); r[4] = (u)r[16] + (u)0; if (c) goto L800d94cc;
    r[5] = 0;
    r[5] = (u)r[5] + (int)R_s18a_rc_800DD2F8; CALL(R_s18a_800D6034);
    L800d94cc:;
    r[31] = *(int *)((u)r[29] + 32);
    r[17] = *(int *)((u)r[29] + 28);
    r[16] = *(int *)((u)r[29] + 24);
    r[29] = (u)r[29] + 40; goto out;
out:
    RECOMP_RETURN;
}
