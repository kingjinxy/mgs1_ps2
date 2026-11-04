extern char R_GCL_NextStr[] __asm__("GCL_NextStr");
extern char R_GCL_StrToInt[] __asm__("GCL_StrToInt");
int G_s15a_800C6EC8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s15a_800C6EC8");
int G_s15a_800C6EC8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[5] + (u)0;
    *(int *)((u)r[29] + 20) = r[31];
    L800c6ed8:;
     CALL(R_GCL_NextStr);
    c = ((r[2] == 0));  if (c) goto L800c6efc;
    r[4] = (u)r[2] + (u)0; CALL(R_GCL_StrToInt);
    *(int *)((u)r[16] + 0) = r[2];
    r[16] = (u)r[16] + 4; goto L800c6ed8;
    L800c6efc:;
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
