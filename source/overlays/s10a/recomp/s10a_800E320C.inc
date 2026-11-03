extern char R_GCL_GetOption[] __asm__("GCL_GetOption");
extern char R_GCL_NextStr[] __asm__("GCL_NextStr");
extern char R_GCL_StrToSV[] __asm__("GCL_StrToSV");
extern char R_s10a_800E0104[] __asm__("s10a_800E0104");
extern char R_s10a_800E0144[] __asm__("s10a_800E0144");
int G_s10a_800E320C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s10a_800E320C");
int G_s10a_800E320C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 20) = r[31];
    r[4] = (u)0 + 99; CALL(R_GCL_GetOption);
    c = ((r[2] == 0));  if (c) goto L800e3278;
     CALL(R_GCL_NextStr);
    r[4] = (u)r[2] + (u)0;
    r[5] = (u)r[16] + 32; CALL(R_GCL_StrToSV);
     CALL(R_GCL_NextStr);
    r[4] = (u)r[2] + (u)0;
    r[5] = (u)r[16] + 40; CALL(R_GCL_StrToSV);
    r[4] = (u)0 + 97;
    r[5] = (u)0 + 320; CALL(R_s10a_800E0104);
    r[4] = (u)0 + 109;
    *(int *)((u)r[16] + 48) = r[2]; CALL(R_s10a_800E0144);
    *(int *)((u)r[16] + 52) = r[2];
    r[2] = (u)0 + (u)0; goto L800e327c;
    L800e3278:;
    r[2] = (u)0 + -1;
    L800e327c:;
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    return r[2];
}
