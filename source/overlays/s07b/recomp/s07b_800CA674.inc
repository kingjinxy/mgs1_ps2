extern char R_GCL_GetOption[] __asm__("GCL_GetOption");
extern char R_GCL_NextStr[] __asm__("GCL_NextStr");
extern char R_GCL_StrToInt[] __asm__("GCL_StrToInt");
int G_s07b_800CA674(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s07b_800CA674");
int G_s07b_800CA674(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(32)
    r[29] = (u)r[29] + -32;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    r[4] = (u)0 + 102;
    *(int *)((u)r[29] + 28) = r[31];
    *(int *)((u)r[29] + 24) = r[18];
    *(int *)((u)r[29] + 20) = r[17]; CALL(R_GCL_GetOption);
    c = ((r[2] == 0)); r[17] = (u)0 + (u)0; if (c) goto L800ca6d4;
    r[16] = (u)r[16] + 2396;
    r[18] = (u)0 + 8;
    L800ca6a4:;
     CALL(R_GCL_NextStr);
    c = ((r[2] == 0));  if (c) goto L800ca6d4;
    c = ((r[17] == r[18]));  if (c) goto L800ca6d4;
    r[4] = (u)r[2] + (u)0; CALL(R_GCL_StrToInt);
    *(int *)((u)r[16] + 0) = r[2];
    r[16] = (u)r[16] + 4;
    r[17] = (u)r[17] + 1; goto L800ca6a4;
    L800ca6d4:;
    r[31] = *(int *)((u)r[29] + 28);
    r[18] = *(int *)((u)r[29] + 24);
    r[17] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 32; goto out;
out:
    return r[2];
}
