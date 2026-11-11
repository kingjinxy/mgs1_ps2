extern char R_DG_ZeroVector[] __asm__("DG_ZeroVector");
extern char R_s19a_dat_800C38BA[] __asm__("s19a_dat_800C38BA");
extern char R_GM_ConfigObjectAction[] __asm__("GM_ConfigObjectAction");
int G_s19a_800DACF4(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s19a_800DACF4");
int G_s19a_800DACF4(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    c = ((r[5] != 0)); *(int *)((u)r[29] + 20) = r[31]; if (c) goto L800dad58;
    r[2] = *(int *)((u)r[16] + 2344);
    r[3] = (u)0 + 5;
    c = ((r[2] == r[3])); r[2] = 0; if (c) goto L800dad58;
    r[4] = (u)r[16] + 164;
    r[6] = (u)0 + (u)0;
    *(int *)((u)r[16] + 2344) = r[3];
    r[5] = *(short *)((u)r[2] + (int)R_s19a_dat_800C38BA);
    r[7] = (u)0 + 4; CALL(R_GM_ConfigObjectAction);
    r[2] = 0;
    r[11] = (u)r[2] + (int)R_DG_ZeroVector;
    r[8] = LWL(((u)r[11] + 3), r[8]);
    r[8] = LWR(((u)r[11] + 0), r[8]);
    r[9] = LWL(((u)r[11] + 7), r[9]);
    r[9] = LWR(((u)r[11] + 4), r[9]);
    SWL(((u)r[16] + 2019), r[8]);
    SWR(((u)r[16] + 2016), r[8]);
    SWL(((u)r[16] + 2023), r[9]);
    SWR(((u)r[16] + 2020), r[9]);
    L800dad58:;
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
