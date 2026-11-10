extern char R_GM_CurrentMap[] __asm__("GM_CurrentMap");
extern char R_s17a_800C8E70[] __asm__("s17a_800C8E70");
extern char R_s17a_800C9D68[] __asm__("s17a_800C9D68");
int G_s17a_800CA040(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s17a_800CA040");
int G_s17a_800CA040(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(32)
    r[29] = (u)r[29] + -32;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 20) = r[17];
    r[17] = (u)r[5] + (u)0;
    *(int *)((u)r[29] + 24) = r[18];
    r[18] = (u)r[6] + (u)0;
    r[2] = 0;
    r[3] = *(int *)((u)r[2] + (int)R_GM_CurrentMap);
    r[2] = (u)0 + 1;
    *(int *)((u)r[29] + 28) = r[31];
    *(int *)((u)r[16] + 936) = r[2];
    r[2] = (u)0 + 5;
    *(int *)((u)r[16] + 944) = 0;
    *(int *)((u)r[16] + 932) = 0;
    *(int *)((u)r[16] + 32) = r[3];
    r[8] = LWL(((u)r[17] + 3), r[8]);
    r[8] = LWR(((u)r[17] + 0), r[8]);
    r[9] = LWL(((u)r[17] + 7), r[9]);
    r[9] = LWR(((u)r[17] + 4), r[9]);
    SWL(((u)r[16] + 759), r[8]);
    SWR(((u)r[16] + 756), r[8]);
    SWL(((u)r[16] + 763), r[9]);
    SWR(((u)r[16] + 760), r[9]);
    r[8] = LWL(((u)r[18] + 3), r[8]);
    r[8] = LWR(((u)r[18] + 0), r[8]);
    r[9] = LWL(((u)r[18] + 7), r[9]);
    r[9] = LWR(((u)r[18] + 4), r[9]);
    SWL(((u)r[16] + 767), r[8]);
    SWR(((u)r[16] + 764), r[8]);
    SWL(((u)r[16] + 771), r[9]);
    SWR(((u)r[16] + 768), r[9]);
    *(int *)((u)r[16] + 948) = r[7];
    *(int *)((u)r[16] + 956) = 0;
    *(int *)((u)r[16] + 940) = r[2]; CALL(R_s17a_800C9D68);
    c = (((int)r[2] < 0)); r[4] = (u)r[16] + (u)0; if (c) goto L800ca0ec;
    r[5] = (u)r[17] + (u)0;
    r[6] = (u)r[18] + (u)0; CALL(R_s17a_800C8E70);
    r[2] = (u)0 + (u)0; goto L800ca0f0;
    L800ca0ec:;
    r[2] = (u)0 + -1;
    L800ca0f0:;
    r[31] = *(int *)((u)r[29] + 28);
    r[18] = *(int *)((u)r[29] + 24);
    r[17] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 32; goto out;
out:
    RECOMP_RETURN;
}
