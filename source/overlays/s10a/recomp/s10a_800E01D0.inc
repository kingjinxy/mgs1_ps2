extern char R_GCL_GetOption[] __asm__("GCL_GetOption");
extern char R_GCL_NextStr[] __asm__("GCL_NextStr");
extern char R_GCL_StrToSV[] __asm__("GCL_StrToSV");
int G_s10a_800E01D0(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s10a_800E01D0");
int G_s10a_800E01D0(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(40)
    r[29] = (u)r[29] + -40;
    *(int *)((u)r[29] + 20) = r[17];
    r[17] = (u)r[5] + (u)0;
    *(int *)((u)r[29] + 24) = r[18];
    r[18] = (u)r[6] + (u)0;
    *(int *)((u)r[29] + 28) = r[19];
    r[19] = (u)r[7] + (u)0;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = *(int *)((u)r[29] + 56);
    *(int *)((u)r[29] + 32) = r[31];
    r[4] = r[4] & 255; CALL(R_GCL_GetOption);
    c = ((r[2] == 0));  if (c) goto L800e0224;
     CALL(R_GCL_NextStr);
    r[4] = (u)r[2] + (u)0;
    r[5] = (u)r[16] + (u)0; CALL(R_GCL_StrToSV);
     goto L800e0230;
    L800e0224:;
    *(short *)((u)r[16] + 0) = r[17];
    *(short *)((u)r[16] + 2) = r[18];
    *(short *)((u)r[16] + 4) = r[19];
    L800e0230:;
    r[31] = *(int *)((u)r[29] + 32);
    r[19] = *(int *)((u)r[29] + 28);
    r[18] = *(int *)((u)r[29] + 24);
    r[17] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 40; goto out;
out:
    RECOMP_RETURN;
}
