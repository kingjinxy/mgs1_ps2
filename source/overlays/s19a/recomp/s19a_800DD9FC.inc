extern char R_GCL_GetOption[] __asm__("GCL_GetOption");
extern char R_GCL_NextStr[] __asm__("GCL_NextStr");
extern char R_GCL_StrToInt[] __asm__("GCL_StrToInt");
extern char R_s19a_800DD3D8[] __asm__("s19a_800DD3D8");
extern char R_s19a_800DD6EC[] __asm__("s19a_800DD6EC");
int G_s19a_800DD9FC(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s19a_800DD9FC");
int G_s19a_800DD9FC(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(40)
    r[29] = (u)r[29] + -40;
    *(int *)((u)r[29] + 28) = r[19];
    r[19] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 32) = r[20];
    r[20] = (u)r[5] + (u)0;
    r[4] = (u)0 + 118;
    *(int *)((u)r[29] + 36) = r[31];
    *(int *)((u)r[29] + 24) = r[18];
    *(int *)((u)r[29] + 20) = r[17];
    *(int *)((u)r[29] + 16) = r[16]; CALL(R_GCL_GetOption);
    c = ((r[2] == 0));  if (c) goto L800dda74;
    r[4] = (u)0 + (u)0; CALL(R_s19a_800DD3D8);
    r[16] = (u)r[2] + (u)0;
    r[17] = (u)0 + 32;
    r[18] = (u)0 + -1;
    L800dda44:;
     CALL(R_GCL_NextStr);
    c = ((r[2] != 0));  if (c) goto L800dda5c;
    *(int *)((u)r[16] + 0) = r[18]; goto L800dda74;
    L800dda5c:;
    r[4] = (u)r[2] + (u)0; CALL(R_GCL_StrToInt);
    *(int *)((u)r[16] + 0) = r[2];
    r[17] = (u)r[17] + -1;
    c = (((int)r[17] > 0)); r[16] = (u)r[16] + 4; if (c) goto L800dda44;
    L800dda74:;
    r[4] = (u)0 + (u)0; CALL(R_s19a_800DD6EC);
    *(int *)((u)r[19] + 32) = r[20];
    r[31] = *(int *)((u)r[29] + 36);
    r[20] = *(int *)((u)r[29] + 32);
    r[19] = *(int *)((u)r[29] + 28);
    r[18] = *(int *)((u)r[29] + 24);
    r[17] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[2] = (u)0 + (u)0;
    r[29] = (u)r[29] + 40; goto out;
out:
    RECOMP_RETURN;
}
