extern char R_GCL_GetOption[] __asm__("GCL_GetOption");
extern char R_GCL_NextStr[] __asm__("GCL_NextStr");
extern char R_GCL_StrToSV[] __asm__("GCL_StrToSV");
extern char R_s11h_800CAC14[] __asm__("s11h_800CAC14");
extern char R_s11h_800CAC54[] __asm__("s11h_800CAC54");
int G_s11h_800CC704(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s11h_800CC704");
int G_s11h_800CC704(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 20) = r[31];
    r[4] = (u)0 + 99; CALL(R_GCL_GetOption);
    c = ((r[2] == 0));  if (c) goto L800cc770;
     CALL(R_GCL_NextStr);
    r[4] = (u)r[2] + (u)0;
    r[5] = (u)r[16] + 32; CALL(R_GCL_StrToSV);
     CALL(R_GCL_NextStr);
    r[4] = (u)r[2] + (u)0;
    r[5] = (u)r[16] + 40; CALL(R_GCL_StrToSV);
    r[4] = (u)0 + 97;
    r[5] = (u)0 + 320; CALL(R_s11h_800CAC14);
    r[4] = (u)0 + 109;
    *(int *)((u)r[16] + 48) = r[2]; CALL(R_s11h_800CAC54);
    *(int *)((u)r[16] + 52) = r[2];
    r[2] = (u)0 + (u)0; goto L800cc774;
    L800cc770:;
    r[2] = (u)0 + -1;
    L800cc774:;
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
