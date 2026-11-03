extern char R_GCL_GetOption[] __asm__("GCL_GetOption");
extern char R_GCL_NextStr[] __asm__("GCL_NextStr");
extern char R_GCL_StrToInt[] __asm__("GCL_StrToInt");
int G_s10a_800C6F2C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s10a_800C6F2C");
int G_s10a_800C6F2C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(32)
    r[29] = (u)r[29] + -32;
    *(int *)((u)r[29] + 20) = r[17];
    r[17] = (u)r[4] + (u)0;
    r[3] = (u)0 + -1;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)0 + 7;
    r[2] = (u)r[17] + 28;
    *(int *)((u)r[29] + 24) = r[31];
    L800c6f4c:;
    *(int *)((u)r[2] + 3680) = r[3];
    r[16] = (u)r[16] + -1;
    c = (((int)r[16] >= 0)); r[2] = (u)r[2] + -4; if (c) goto L800c6f4c;
    r[16] = (u)0 + (u)0;
    r[4] = (u)0 + 97; CALL(R_GCL_GetOption);
    r[4] = (u)r[2] + (u)0;
    c = ((r[4] == 0)); r[2] = (u)r[16] + (u)0; if (c) goto L800c6fa0;
    L800c6f74:;
    r[2] = (int)r[16] < 8;
    c = ((r[2] == 0)); r[2] = (u)0 + -1; if (c) goto L800c6fa0;
    r[16] = (u)r[16] + 1; CALL(R_GCL_StrToInt);
    *(int *)((u)r[17] + 3680) = r[2]; CALL(R_GCL_NextStr);
    r[4] = (u)r[2] + (u)0;
    c = ((r[4] != 0)); r[17] = (u)r[17] + 4; if (c) goto L800c6f74;
    r[2] = (u)r[16] + (u)0;
    L800c6fa0:;
    r[31] = *(int *)((u)r[29] + 24);
    r[17] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 32; goto out;
out:
    return r[2];
}
