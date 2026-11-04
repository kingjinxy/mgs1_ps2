extern char R_GM_GameStatus[] __asm__("GM_GameStatus");
extern char R_GCL_ForceExecProc[] __asm__("GCL_ForceExecProc");
extern char R_GM_FreeControl[] __asm__("GM_FreeControl");
extern char R_GM_FreeObject[] __asm__("GM_FreeObject");
extern char R_GM_FreeTarget[] __asm__("GM_FreeTarget");
extern char R_GV_DestroyOtherActor[] __asm__("GV_DestroyOtherActor");
int G_s11b_800D24D8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s11b_800D24D8");
int G_s11b_800D24D8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    r[4] = 0xbfff0000;
    r[4] = r[4] | 65535;
    r[5] = 0xffb50000;
    r[3] = 0;
    r[2] = *(int *)((u)r[3] + (int)R_GM_GameStatus);
    r[5] = r[5] | 65535;
    *(int *)((u)r[29] + 20) = r[31];
    r[2] = r[2] & r[4];
    r[4] = *(int *)((u)r[16] + 1400);
    r[2] = r[2] & r[5];
    c = (((int)r[4] < 0)); *(int *)((u)r[3] + (int)R_GM_GameStatus) = r[2]; if (c) goto L800d253c;
    r[2] = *(int *)((u)r[16] + 2380);
    r[3] = (u)0 + 1;
    c = ((r[2] == r[3]));  if (c) goto L800d253c;
    r[2] = *(int *)((u)r[16] + 2676);
    c = ((r[2] != r[3]));  if (c) goto L800d253c;
    r[5] = (u)0 + (u)0; CALL(R_GCL_ForceExecProc);
    L800d253c:;
    r[4] = *(int *)((u)r[16] + 2280);
    c = ((r[4] == 0));  if (c) goto L800d2558;
     CALL(R_GV_DestroyOtherActor);
    *(int *)((u)r[16] + 2280) = 0;
    L800d2558:;
    r[4] = *(int *)((u)r[16] + 2276);
    c = ((r[4] == 0));  if (c) goto L800d2574;
     CALL(R_GV_DestroyOtherActor);
    *(int *)((u)r[16] + 2276) = 0;
    L800d2574:;
    r[4] = (u)r[16] + 32; CALL(R_GM_FreeControl);
    r[4] = (u)r[16] + 156; CALL(R_GM_FreeObject);
    r[4] = (u)r[16] + 384; CALL(R_GM_FreeObject);
    r[4] = (u)r[16] + 612; CALL(R_GM_FreeObject);
    r[4] = (u)r[16] + 1660; CALL(R_GM_FreeObject);
    r[4] = *(int *)((u)r[16] + 1032);
     CALL(R_GM_FreeTarget);
    r[4] = *(int *)((u)r[16] + 1036);
     CALL(R_GM_FreeTarget);
    r[4] = *(int *)((u)r[16] + 1040);
     CALL(R_GM_FreeTarget);
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
