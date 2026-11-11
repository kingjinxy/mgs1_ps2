extern char R_GCL_NextStr[] __asm__("GCL_NextStr");
extern char R_GCL_StrToInt[] __asm__("GCL_StrToInt");
int G_s19a_800CD64C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s19a_800CD64C");
int G_s19a_800CD64C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(32)
    r[29] = (u)r[29] + -32;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[5] + (u)0;
    *(int *)((u)r[29] + 20) = r[17];
    r[17] = (u)0 + (u)0;
    *(int *)((u)r[29] + 24) = r[31];
    L800cd664:;
     CALL(R_GCL_NextStr);
    c = ((r[2] == 0));  if (c) goto L800cd68c;
    r[4] = (u)r[2] + (u)0; CALL(R_GCL_StrToInt);
    *(short *)((u)r[16] + 0) = r[2];
    r[16] = (u)r[16] + 2;
    r[17] = (u)r[17] + 1; goto L800cd664;
    L800cd68c:;
    r[2] = (u)r[17] + (u)0;
    r[31] = *(int *)((u)r[29] + 24);
    r[17] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 32; goto out;
out:
    RECOMP_RETURN;
}
