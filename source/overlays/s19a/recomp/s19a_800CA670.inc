extern char R_GCL_GetOption[] __asm__("GCL_GetOption");
extern char R_GCL_NextStr[] __asm__("GCL_NextStr");
extern char R_GCL_StrToInt[] __asm__("GCL_StrToInt");
int G_s19a_800CA670(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s19a_800CA670");
int G_s19a_800CA670(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(32)
    r[29] = (u)r[29] + -32;
    *(int *)((u)r[29] + 20) = r[17];
    r[17] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)0 + 15;
    r[2] = (u)r[17] + (u)r[16];
    *(int *)((u)r[29] + 24) = r[31];
    L800ca68c:;
    *(char *)((u)r[2] + 3656) = 0;
    r[16] = (u)r[16] + -1;
    c = (((int)r[16] >= 0)); r[2] = (u)r[2] + -1; if (c) goto L800ca68c;
    r[16] = (u)0 + (u)0;
    r[4] = (u)0 + 110; CALL(R_GCL_GetOption);
    r[4] = (u)r[2] + (u)0;
    c = ((r[4] == 0)); r[2] = (u)r[16] + (u)0; if (c) goto L800ca6e4;
    L800ca6b4:;
    r[2] = (int)r[16] < 16;
    c = ((r[2] == 0)); r[2] = (u)0 + -1; if (c) goto L800ca6e4;
     CALL(R_GCL_StrToInt);
    r[3] = (u)r[17] + (u)r[16];
    *(char *)((u)r[3] + 3656) = r[2]; CALL(R_GCL_NextStr);
    r[4] = (u)r[2] + (u)0;
    c = ((r[4] != 0)); r[16] = (u)r[16] + 1; if (c) goto L800ca6b4;
    r[2] = (u)r[16] + (u)0;
    L800ca6e4:;
    r[31] = *(int *)((u)r[29] + 24);
    r[17] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 32; goto out;
out:
    RECOMP_RETURN;
}
