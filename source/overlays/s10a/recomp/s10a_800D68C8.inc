extern char R_GCL_NextStr[] __asm__("GCL_NextStr");
extern char R_GCL_StrToSV[] __asm__("GCL_StrToSV");
int G_s10a_800D68C8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s10a_800D68C8");
int G_s10a_800D68C8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(32)
    r[29] = (u)r[29] + -32;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[5] + (u)0;
    *(int *)((u)r[29] + 20) = r[17];
    r[17] = (u)0 + (u)0;
    *(int *)((u)r[29] + 24) = r[31];
    L800d68e0:;
     CALL(R_GCL_NextStr);
    c = ((r[2] == 0)); r[4] = (u)r[2] + (u)0; if (c) goto L800d6904;
    r[5] = (u)r[16] + (u)0; CALL(R_GCL_StrToSV);
    r[16] = (u)r[16] + 8;
    r[17] = (u)r[17] + 1; goto L800d68e0;
    L800d6904:;
    r[2] = (u)r[17] + (u)0;
    r[31] = *(int *)((u)r[29] + 24);
    r[17] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 32; goto out;
out:
    return r[2];
}
