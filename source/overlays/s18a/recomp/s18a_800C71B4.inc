extern char R_GCL_GetNextInt[] __asm__("GCL_GetNextInt");
extern char R_GCL_GetOption[] __asm__("GCL_GetOption");
extern char R_s18a_800C7124[] __asm__("s18a_800C7124");
int G_s18a_800C71B4(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s18a_800C71B4");
int G_s18a_800C71B4(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(32)
    r[29] = (u)r[29] + -32;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)0 + 10000;
    *(int *)((u)r[29] + 20) = r[17];
    r[17] = (u)0 + -1;
    *(int *)((u)r[29] + 24) = r[31];
    r[4] = (u)0 + 116; CALL(R_GCL_GetOption);
    c = ((r[2] == 0));  if (c) goto L800c71f0;
     CALL(R_GCL_GetNextInt);
    r[3] = (u)r[2] << 4;
    r[3] = (u)r[3] - (u)r[2];
    r[16] = (u)r[3] << 1;
    L800c71f0:;
    r[4] = (u)0 + 112; CALL(R_GCL_GetOption);
    c = ((r[2] == 0)); r[4] = (u)r[16] + (u)0; if (c) goto L800c7210;
     CALL(R_GCL_GetNextInt);
    r[17] = (u)r[2] + (u)0;
    r[4] = (u)r[16] + (u)0;
    L800c7210:;
    r[5] = (u)r[17] + (u)0; CALL(R_s18a_800C7124);
    r[31] = *(int *)((u)r[29] + 24);
    r[17] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 32; goto out;
out:
    RECOMP_RETURN;
}
