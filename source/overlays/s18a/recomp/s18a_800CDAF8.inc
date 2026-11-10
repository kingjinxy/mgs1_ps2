extern char R_GCL_ExecProc[] __asm__("GCL_ExecProc");
extern char R_GM_AlertModeSet[] __asm__("GM_AlertModeSet");
extern char R_GM_StreamPlayStart[] __asm__("GM_StreamPlayStart");
extern char R_GM_StreamStatus[] __asm__("GM_StreamStatus");
extern char R_s18a_800D0E8C[] __asm__("s18a_800D0E8C");
int G_s18a_800CDAF8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s18a_800CDAF8");
int G_s18a_800CDAF8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 20) = r[31];
    r[2] = *(int *)((u)r[16] + 2476);
    r[4] = *(int *)((u)r[16] + 2408);
    r[3] = (u)0 + 3;
    *(int *)((u)r[16] + 2384) = r[3];
    c = ((r[4] != 0)); *(int *)((u)r[16] + 2388) = r[2]; if (c) goto L800cdb40;
     CALL(R_GM_StreamPlayStart);
    r[4] = *(int *)((u)r[16] + 2536);
    c = (((int)r[4] < 0));  if (c) goto L800cdb40;
    r[5] = (u)0 + (u)0; CALL(R_GCL_ExecProc);
    L800cdb40:;
    r[3] = *(int *)((u)r[16] + 2408);
    r[2] = (u)0 + 30;
    c = ((r[3] != r[2]));  if (c) goto L800cdb58;
    r[4] = (u)0 + 4; CALL(R_GM_AlertModeSet);
    L800cdb58:;
    r[2] = *(int *)((u)r[16] + 2408);
    r[2] = (int)r[2] < 31;
    c = ((r[2] != 0));  if (c) goto L800cdb98;
     CALL(R_GM_StreamStatus);
    r[3] = (u)0 + -1;
    c = ((r[2] != r[3]));  if (c) goto L800cdb98;
     CALL(R_s18a_800D0E8C);
    r[2] = (u)0 + 2;
    *(int *)((u)r[16] + 2404) = r[2];
    *(int *)((u)r[16] + 2428) = 0;
    *(int *)((u)r[16] + 2408) = 0;
    L800cdb98:;
    r[2] = *(int *)((u)r[16] + 2408);
    r[2] = (u)r[2] + 1;
    *(int *)((u)r[16] + 2408) = r[2];
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
