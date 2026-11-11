extern char R_GCL_ExecProc[] __asm__("GCL_ExecProc");
extern char R_GCL_NextStr[] __asm__("GCL_NextStr");
extern char R_GCL_StrToInt[] __asm__("GCL_StrToInt");
int G_s19a_800D7338(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s19a_800D7338");
int G_s19a_800D7338(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(32)
    r[29] = (u)r[29] + -32;
    *(int *)((u)r[29] + 20) = r[17];
    r[17] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 24) = r[18];
    r[18] = (u)0 + (u)0;
    *(int *)((u)r[29] + 28) = r[31];
    c = ((r[17] == 0)); *(int *)((u)r[29] + 16) = r[16]; if (c) goto L800d7380;
    L800d7358:;
    r[4] = (u)r[17] + (u)0; CALL(R_GCL_StrToInt);
    r[16] = (u)r[2] + (u)0; CALL(R_GCL_NextStr);
    r[17] = (u)r[2] + (u)0;
    r[4] = (u)r[16] + (u)0;
    r[5] = (u)0 + (u)0; CALL(R_GCL_ExecProc);
    c = ((r[17] != 0)); r[18] = (u)r[18] + 1; if (c) goto L800d7358;
    L800d7380:;
    r[2] = (u)r[18] + (u)0;
    r[31] = *(int *)((u)r[29] + 28);
    r[18] = *(int *)((u)r[29] + 24);
    r[17] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 32; goto out;
out:
    RECOMP_RETURN;
}
