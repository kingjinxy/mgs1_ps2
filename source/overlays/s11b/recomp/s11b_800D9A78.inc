extern char R_GM_CurrentMap[] __asm__("GM_CurrentMap");
extern char R_GV_DestroyActor[] __asm__("GV_DestroyActor");
extern char R_s11b_800D9798[] __asm__("s11b_800D9798");
int G_s11b_800D9A78(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s11b_800D9A78");
int G_s11b_800D9A78(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 20) = r[31];
    r[4] = *(int *)((u)r[16] + 32);
    r[5] = LWL(((u)r[16] + 55), r[5]);
    r[5] = LWR(((u)r[16] + 52), r[5]);
    r[6] = LWL(((u)r[16] + 59), r[6]);
    r[6] = LWR(((u)r[16] + 56), r[6]);
    SWL(((u)r[16] + 47), r[5]);
    SWR(((u)r[16] + 44), r[5]);
    SWL(((u)r[16] + 51), r[6]);
    SWR(((u)r[16] + 48), r[6]);
    r[2] = *(int *)((u)r[16] + 60);
    r[5] = LWL(((u)r[2] + 3), r[5]);
    r[5] = LWR(((u)r[2] + 0), r[5]);
    r[6] = LWL(((u)r[2] + 7), r[6]);
    r[6] = LWR(((u)r[2] + 4), r[6]);
    SWL(((u)r[16] + 55), r[5]);
    SWR(((u)r[16] + 52), r[5]);
    SWL(((u)r[16] + 59), r[6]);
    SWR(((u)r[16] + 56), r[6]);
    r[3] = *(int *)((u)r[16] + 64);
    r[2] = 0;
    c = (((int)r[3] <= 0)); *(int *)((u)r[2] + (int)R_GM_CurrentMap) = r[4]; if (c) goto L800d9af4;
    r[4] = (u)r[16] + (u)0; CALL(R_s11b_800D9798);
     goto L800d9b20;
    L800d9af4:;
    r[4] = (u)r[16] + (u)0; CALL(R_s11b_800D9798);
    r[2] = *(int *)((u)r[16] + 68);
    c = ((r[2] != 0)); r[2] = (u)r[2] + -1; if (c) goto L800d9b1c;
    r[4] = (u)r[16] + (u)0; CALL(R_GV_DestroyActor);
     goto L800d9b30;
    L800d9b1c:;
    *(int *)((u)r[16] + 68) = r[2];
    L800d9b20:;
    r[2] = *(int *)((u)r[16] + 64);
    r[2] = (u)r[2] + -1;
    *(int *)((u)r[16] + 64) = r[2];
    L800d9b30:;
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
