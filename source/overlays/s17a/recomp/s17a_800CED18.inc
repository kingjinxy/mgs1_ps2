extern char R_GM_CurrentMap[] __asm__("GM_CurrentMap");
extern char R_DG_MakeObjs[] __asm__("DG_MakeObjs");
extern char R_DG_MakePreshade[] __asm__("DG_MakePreshade");
extern char R_DG_PutObjs[] __asm__("DG_PutObjs");
extern char R_DG_QueueObjs[] __asm__("DG_QueueObjs");
extern char R_GV_CacheID[] __asm__("GV_CacheID");
extern char R_GV_GetCache[] __asm__("GV_GetCache");
int G_s17a_800CED18(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s17a_800CED18");
int G_s17a_800CED18(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(32)
    r[29] = (u)r[29] + -32;
    *(int *)((u)r[29] + 20) = r[17];
    r[17] = (u)r[5] + (u)0;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[6] + (u)0;
    *(int *)((u)r[29] + 24) = r[31];
    r[5] = (u)0 + 107; CALL(R_GV_CacheID);
    r[4] = (u)r[2] + (u)0; CALL(R_GV_GetCache);
    r[4] = (u)r[2] + (u)0;
    r[5] = (u)r[16] + (u)0;
    r[6] = (u)0 + (u)0; CALL(R_DG_MakeObjs);
    r[16] = (u)r[2] + (u)0;
    r[4] = (u)r[16] + (u)0; CALL(R_DG_PutObjs);
    c = ((r[17] == 0)); r[5] = (u)r[17] + 4; if (c) goto L800ced70;
    r[6] = *(int *)((u)r[17] + 0);
    r[4] = (u)r[16] + (u)0; goto L800ced7c;
    L800ced70:;
    r[4] = (u)r[16] + (u)0;
    r[5] = (u)0 + (u)0;
    r[6] = (u)r[5] + (u)0;
    L800ced7c:;
     CALL(R_DG_MakePreshade);
    r[4] = (u)r[16] + (u)0; CALL(R_DG_QueueObjs);
    r[2] = 0;
    r[3] = *(int *)((u)r[2] + (int)R_GM_CurrentMap);
    r[2] = (u)r[16] + (u)0;
    *(short *)((u)r[2] + 44) = r[3];
    r[31] = *(int *)((u)r[29] + 24);
    r[17] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 32; goto out;
out:
    RECOMP_RETURN;
}
