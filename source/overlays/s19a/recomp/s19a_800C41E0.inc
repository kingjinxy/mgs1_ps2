extern char R_GCL_GetOption[] __asm__("GCL_GetOption");
extern char R_GCL_NextStr[] __asm__("GCL_NextStr");
extern char R_GCL_StrToInt[] __asm__("GCL_StrToInt");
extern char R_GV_Malloc[] __asm__("GV_Malloc");
int G_s19a_800C41E0(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s19a_800C41E0");
int G_s19a_800C41E0(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(32)
    r[29] = (u)r[29] + -32;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    r[4] = (u)0 + 109;
    *(int *)((u)r[29] + 28) = r[31];
    *(int *)((u)r[29] + 24) = r[18];
    *(int *)((u)r[29] + 20) = r[17]; CALL(R_GCL_GetOption);
    r[4] = (u)r[2] + (u)0; CALL(R_GCL_StrToInt);
    r[4] = (u)0 + 110;
    *(int *)((u)r[16] + 32) = r[2]; CALL(R_GCL_GetOption);
    r[4] = (u)r[2] + (u)0; CALL(R_GCL_StrToInt);
    r[18] = (u)r[2] + (u)0;
    r[4] = (u)r[18] << 3;
    *(int *)((u)r[16] + 36) = r[18]; CALL(R_GV_Malloc);
    r[17] = (u)r[2] + (u)0;
    r[4] = (u)0 + 115;
    *(int *)((u)r[16] + 40) = r[17]; CALL(R_GCL_GetOption);
    r[16] = (u)0 + (u)0;
    L800c4240:;
     CALL(R_GCL_NextStr);
    c = ((r[2] == 0));  if (c) goto L800c4280;
    c = ((r[16] == r[18]));  if (c) goto L800c4280;
    r[4] = (u)r[2] + (u)0; CALL(R_GCL_StrToInt);
    *(int *)((u)r[17] + 0) = r[2]; CALL(R_GCL_NextStr);
    r[4] = (u)r[2] + (u)0; CALL(R_GCL_StrToInt);
    r[16] = (u)r[16] + 1;
    *(int *)((u)r[17] + 4) = r[2];
    r[17] = (u)r[17] + 8; goto L800c4240;
    L800c4280:;
    r[31] = *(int *)((u)r[29] + 28);
    r[18] = *(int *)((u)r[29] + 24);
    r[17] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[2] = (u)0 + (u)0;
    r[29] = (u)r[29] + 32; goto out;
out:
    RECOMP_RETURN;
}
