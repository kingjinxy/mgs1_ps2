extern char R_GM_Camera[] __asm__("GM_Camera");
extern char R_GM_SnakeCamera[] __asm__("GM_SnakeCamera");
extern char R_s19b_dword_800DE5C8[] __asm__("s19b_dword_800DE5C8");
extern char R_GV_NearExp4V[] __asm__("GV_NearExp4V");
extern char R_s19b_jlamp_800D0ABC[] __asm__("s19b_jlamp_800D0ABC");
int G_s19b_jlamp_800D0C44(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s19b_jlamp_800D0C44");
int G_s19b_jlamp_800D0C44(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(32)
    r[29] = (u)r[29] + -32;
    r[2] = 0;
    *(int *)((u)r[29] + 20) = r[17];
    r[17] = (u)r[2] + (int)R_GM_Camera;
    r[4] = (u)r[17] + (u)0;
    r[2] = 0;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[2] + (int)R_s19b_dword_800DE5C8;
    r[5] = (u)r[16] + (u)0;
    *(int *)((u)r[29] + 24) = r[31];
    r[6] = (u)0 + 3; CALL(R_GV_NearExp4V);
    r[2] = *(int *)((u)r[16] + 24);
    c = ((r[2] != 0)); r[4] = (u)r[17] + 8; if (c) goto L800d0cb4;
    r[5] = 0;
    r[5] = (u)r[5] + (int)R_GM_SnakeCamera;
    r[3] = LWL(((u)r[5] + 11), r[3]);
    r[3] = LWR(((u)r[5] + 8), r[3]);
    r[7] = LWL(((u)r[5] + 15), r[7]);
    r[7] = LWR(((u)r[5] + 12), r[7]);
    SWL(((u)r[17] + 11), r[3]);
    SWR(((u)r[17] + 8), r[3]);
    SWL(((u)r[17] + 15), r[7]);
    SWR(((u)r[17] + 12), r[7]);
     goto L800d0cb8;
    L800d0cb4:;
    r[5] = (u)r[16] + 28;
    L800d0cb8:;
    r[6] = (u)0 + 3; CALL(R_GV_NearExp4V);
    r[2] = 0;
    *(short *)((u)r[2] + ((int)R_GM_Camera + 40)) = 0; CALL(R_s19b_jlamp_800D0ABC);
    r[31] = *(int *)((u)r[29] + 24);
    r[17] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 32; goto out;
out:
    RECOMP_RETURN;
}
