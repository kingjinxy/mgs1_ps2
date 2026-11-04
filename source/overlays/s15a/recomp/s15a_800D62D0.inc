extern char R_GM_GameStatus[] __asm__("GM_GameStatus");
extern char R_linkvarbuf[] __asm__("linkvarbuf");
extern char R_GCL_GetOption[] __asm__("GCL_GetOption");
extern char R_GCL_NextStr[] __asm__("GCL_NextStr");
extern char R_GCL_StrToInt[] __asm__("GCL_StrToInt");
int G_s15a_800D62D0(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s15a_800D62D0");
int G_s15a_800D62D0(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 20) = r[31];
    r[4] = (u)0 + 109; CALL(R_GCL_GetOption);
    c = ((r[2] == 0));  if (c) goto L800d6304;
     CALL(R_GCL_NextStr);
    r[4] = (u)r[2] + (u)0; CALL(R_GCL_StrToInt);
    *(int *)((u)r[16] + 32) = r[2];
    L800d6304:;
    r[4] = (u)0 + 101; CALL(R_GCL_GetOption);
    c = ((r[2] == 0));  if (c) goto L800d6328;
     CALL(R_GCL_NextStr);
    r[4] = (u)r[2] + (u)0; CALL(R_GCL_StrToInt);
    *(int *)((u)r[16] + 44) = r[2];
    L800d6328:;
    r[4] = (u)0 + 99; CALL(R_GCL_GetOption);
    c = ((r[2] == 0)); r[2] = (u)0 + 8; if (c) goto L800d6350;
     CALL(R_GCL_NextStr);
    r[4] = (u)r[2] + (u)0; CALL(R_GCL_StrToInt);
    *(int *)((u)r[16] + 36) = r[2]; goto L800d6354;
    L800d6350:;
    *(int *)((u)r[16] + 36) = r[2];
    L800d6354:;
    r[4] = (u)0 + 108; CALL(R_GCL_GetOption);
    c = ((r[2] == 0)); r[2] = 0; if (c) goto L800d637c;
     CALL(R_GCL_NextStr);
    r[4] = (u)r[2] + (u)0; CALL(R_GCL_StrToInt);
    *(int *)((u)r[16] + 52) = r[2]; goto L800d6390;
    L800d637c:;
    r[3] = *(short *)((u)r[2] + ((int)R_linkvarbuf + 22));
    r[2] = *(int *)((u)r[16] + 32);
    r[2] = (u)r[2] - (u)r[3];
    *(int *)((u)r[16] + 52) = r[2];
    L800d6390:;
    r[6] = 0x10000000;
    r[6] = r[6] | 32768;
    r[5] = 0;
    r[4] = *(int *)((u)r[16] + 36);
    r[3] = *(int *)((u)r[5] + (int)R_GM_GameStatus);
    r[2] = (u)0 + (u)0;
    *(int *)((u)r[16] + 40) = r[4];
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[3] = r[3] | r[6];
    *(int *)((u)r[5] + (int)R_GM_GameStatus) = r[3];
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
