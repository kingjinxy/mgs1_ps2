extern char R_GM_ZoneNavi[] __asm__("GM_ZoneNavi");
extern char R_HZD_GetAddress[] __asm__("HZD_GetAddress");
extern char R_NavigateSetTarget[] __asm__("NavigateSetTarget");
int G_s07b_800CB6B0(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s07b_800CB6B0");
int G_s07b_800CB6B0(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(40)
    r[29] = (u)r[29] + -40;
    *(int *)((u)r[29] + 32) = r[18];
    r[18] = (u)r[4] + (u)0;
    r[2] = (u)r[7] << 16;
    *(int *)((u)r[29] + 36) = r[31];
    *(int *)((u)r[29] + 28) = r[17];
    *(int *)((u)r[29] + 24) = r[16];
    *(short *)((u)r[18] + 2160) = r[5];
    c = (((int)r[2] <= 0)); *(short *)((u)r[18] + 2164) = r[6]; if (c) goto L800cb6dc;
    *(short *)((u)r[18] + 2158) = r[7];
    L800cb6dc:;
    r[17] = (u)r[18] + 2708;
    *(short *)((u)r[29] + 16) = r[5];
    *(short *)((u)r[29] + 18) = 0;
    *(short *)((u)r[29] + 20) = r[6];
    r[2] = *(int *)((u)r[18] + 76);
    r[4] = (u)r[17] + (u)0;
    r[5] = *(int *)((u)r[2] + 8);
    r[6] = (u)r[29] + 16; CALL(R_NavigateSetTarget);
    r[8] = LWL(((u)r[18] + 35), r[8]);
    r[8] = LWR(((u)r[18] + 32), r[8]);
    r[9] = LWL(((u)r[18] + 39), r[9]);
    r[9] = LWR(((u)r[18] + 36), r[9]);
    SWL(((u)r[29] + 19), r[8]);
    SWR(((u)r[29] + 16), r[8]);
    SWL(((u)r[29] + 23), r[9]);
    SWR(((u)r[29] + 20), r[9]);
    r[2] = *(unsigned short *)((u)r[29] + 18);
    r[3] = *(unsigned short *)((u)r[18] + 82);
    r[5] = (u)r[29] + 16;
    r[2] = (u)r[2] - (u)r[3];
    *(short *)((u)r[29] + 18) = r[2];
    r[2] = *(int *)((u)r[18] + 76);
    r[6] = *(int *)((u)r[18] + 2708);
    r[4] = *(int *)((u)r[2] + 8);
    r[16] = (u)r[18] + 32; CALL(R_HZD_GetAddress);
    r[4] = (u)r[17] + (u)0;
    r[5] = (u)r[16] + (u)0;
    *(int *)((u)r[18] + 2708) = r[2]; CALL(R_GM_ZoneNavi);
    r[31] = *(int *)((u)r[29] + 36);
    r[18] = *(int *)((u)r[29] + 32);
    r[17] = *(int *)((u)r[29] + 28);
    r[16] = *(int *)((u)r[29] + 24);
    r[29] = (u)r[29] + 40; goto out;
out:
    return r[2];
}
