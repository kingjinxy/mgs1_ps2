extern char R_GCL_GetOption[] __asm__("GCL_GetOption");
extern char R_GCL_NextStr[] __asm__("GCL_NextStr");
extern char R_GCL_StrToSV[] __asm__("GCL_StrToSV");
extern char R_s10a_800E0104[] __asm__("s10a_800E0104");
extern char R_s10a_800E0144[] __asm__("s10a_800E0144");
int G_s10a_800DFB84(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s10a_800DFB84");
int G_s10a_800DFB84(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 20) = r[31];
    r[4] = (u)0 + 99; CALL(R_GCL_GetOption);
    c = ((r[2] == 0)); r[4] = (u)0 + 115; if (c) goto L800dfbd0;
     CALL(R_GCL_NextStr);
    r[4] = (u)r[2] + (u)0;
    r[5] = (u)r[16] + 44; CALL(R_GCL_StrToSV);
     CALL(R_GCL_NextStr);
    r[4] = (u)r[2] + (u)0;
    r[5] = (u)r[16] + 52; CALL(R_GCL_StrToSV);
    r[4] = (u)0 + 115;
    L800dfbd0:;
    r[5] = (u)0 + 4096; CALL(R_s10a_800E0104);
    r[4] = (u)0 + 119;
    r[5] = (u)0 + 410;
    *(int *)((u)r[16] + 72) = r[2]; CALL(R_s10a_800E0104);
    r[4] = (u)0 + 102;
    r[5] = (u)0 + 128;
    *(int *)((u)r[16] + 80) = r[2]; CALL(R_s10a_800E0104);
    r[4] = (u)0 + 98;
    r[5] = (u)0 + 1;
    *(int *)((u)r[16] + 84) = r[2]; CALL(R_s10a_800E0104);
    r[4] = (u)0 + 114;
    *(int *)((u)r[16] + 88) = r[2]; CALL(R_s10a_800E0144);
    r[4] = (u)0 + 97;
    r[5] = (u)0 + 3205;
    *(int *)((u)r[16] + 92) = r[2]; CALL(R_s10a_800E0104);
    *(int *)((u)r[16] + 100) = r[2];
    *(int *)((u)r[16] + 64) = 0;
    *(int *)((u)r[16] + 68) = 0;
    *(int *)((u)r[16] + 60) = 0;
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[2] = (u)0 + (u)0;
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
