extern char R_GCL_GetOption[] __asm__("GCL_GetOption");
extern char R_GCL_NextStr[] __asm__("GCL_NextStr");
extern char R_GCL_StrToInt[] __asm__("GCL_StrToInt");
int G_s18a_800C3E4C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s18a_800C3E4C");
int G_s18a_800C3E4C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 20) = r[31];
    r[4] = (u)0 + 112; CALL(R_GCL_GetOption);
    c = ((r[2] == 0)); r[2] = (u)0 + -1; if (c) goto L800c3e84;
     CALL(R_GCL_NextStr);
    r[4] = (u)r[2] + (u)0; CALL(R_GCL_StrToInt);
    *(int *)((u)r[16] + 32) = r[2]; goto L800c3e88;
    L800c3e84:;
    *(int *)((u)r[16] + 32) = r[2];
    L800c3e88:;
    r[4] = (u)0 + 109; CALL(R_GCL_GetOption);
    c = ((r[2] == 0)); r[2] = 0 | 65535; if (c) goto L800c3eb0;
     CALL(R_GCL_NextStr);
    r[4] = (u)r[2] + (u)0; CALL(R_GCL_StrToInt);
    *(int *)((u)r[16] + 36) = r[2]; goto L800c3eb4;
    L800c3eb0:;
    *(int *)((u)r[16] + 36) = r[2];
    L800c3eb4:;
    r[4] = (u)0 + 115; CALL(R_GCL_GetOption);
    c = ((r[2] == 0)); r[2] = (u)0 + 8; if (c) goto L800c3edc;
     CALL(R_GCL_NextStr);
    r[4] = (u)r[2] + (u)0; CALL(R_GCL_StrToInt);
    *(int *)((u)r[16] + 44) = r[2]; goto L800c3ee0;
    L800c3edc:;
    *(int *)((u)r[16] + 44) = r[2];
    L800c3ee0:;
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[2] = (u)0 + (u)0;
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
