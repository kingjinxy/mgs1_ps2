extern char R_GCL_GetOption[] __asm__("GCL_GetOption");
extern char R_GCL_StrToInt[] __asm__("GCL_StrToInt");
int G_s10a_800E0168(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s10a_800E0168");
int G_s10a_800E0168(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[5] + (u)0;
    *(int *)((u)r[29] + 20) = r[31];
    r[4] = r[4] & 255; CALL(R_GCL_GetOption);
    c = ((r[2] != 0));  if (c) goto L800e0190;
    r[2] = r[16] & 65535; goto L800e019c;
    L800e0190:;
    r[4] = (u)r[2] + (u)0; CALL(R_GCL_StrToInt);
    r[2] = r[2] & 65535;
    L800e019c:;
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    return r[2];
}
