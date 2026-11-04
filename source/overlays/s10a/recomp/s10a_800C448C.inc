extern char R_GCL_GetOption[] __asm__("GCL_GetOption");
extern char R_GCL_NextStr[] __asm__("GCL_NextStr");
extern char R_GCL_StrToInt[] __asm__("GCL_StrToInt");
int G_s10a_800C448C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s10a_800C448C");
int G_s10a_800C448C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(32)
    r[29] = (u)r[29] + -32;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 20) = r[17];
    r[17] = (u)r[5] + (u)0;
    *(int *)((u)r[29] + 24) = r[31];
    r[4] = (u)0 + 116; CALL(R_GCL_GetOption);
    c = ((r[2] == 0)); r[2] = (u)0 + 64; if (c) goto L800c44cc;
     CALL(R_GCL_NextStr);
    r[4] = (u)r[2] + (u)0; CALL(R_GCL_StrToInt);
    *(int *)((u)r[16] + 36) = r[2]; goto L800c44d0;
    L800c44cc:;
    *(int *)((u)r[16] + 36) = r[2];
    L800c44d0:;
    r[3] = (u)0 + 1;
    *(short *)((u)r[16] + 32) = r[17];
    *(short *)((u)r[16] + 34) = r[3];
    r[31] = *(int *)((u)r[29] + 24);
    r[17] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[2] = (u)0 + (u)0;
    r[29] = (u)r[29] + 32; goto out;
out:
    RECOMP_RETURN;
}
