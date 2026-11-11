extern char R_GCL_NextStr[] __asm__("GCL_NextStr");
extern char R_GCL_StrToSV[] __asm__("GCL_StrToSV");
extern char R_GM_GetMap[] __asm__("GM_GetMap");
extern char R_HZD_GetAddress[] __asm__("HZD_GetAddress");
int G_s19a_800C7B14(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s19a_800C7B14");
int G_s19a_800C7B14(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(48)
    r[29] = (u)r[29] + -48;
    *(int *)((u)r[29] + 24) = r[16];
    r[16] = (u)r[5] + (u)0;
    r[4] = (u)r[6] + (u)0;
    *(int *)((u)r[29] + 40) = r[31];
    *(int *)((u)r[29] + 36) = r[19];
    *(int *)((u)r[29] + 32) = r[18];
    *(int *)((u)r[29] + 28) = r[17]; CALL(R_GM_GetMap);
    r[18] = (u)r[2] + (u)0;
    r[17] = (u)0 + (u)0;
    r[19] = (u)0 + 255;
    L800c7b44:;
     CALL(R_GCL_NextStr);
    r[4] = (u)r[2] + (u)0;
    c = ((r[4] == 0)); r[2] = (int)r[17] < 4; if (c) goto L800c7ba4;
    c = ((r[2] == 0)); r[2] = (u)r[17] + (u)0; if (c) goto L800c7ba8;
    r[5] = (u)r[29] + 16; CALL(R_GCL_StrToSV);
    r[2] = *(short *)((u)r[29] + 18);
    r[2] = (int)r[2] < 30000;
    c = ((r[2] == 0)); r[5] = (u)r[29] + 16; if (c) goto L800c7b94;
    r[4] = *(int *)((u)r[18] + 8);
    r[6] = (u)0 + -1; CALL(R_HZD_GetAddress);
    r[2] = r[2] & 255;
    *(short *)((u)r[16] + 0) = r[2]; goto L800c7b98;
    L800c7b94:;
    *(short *)((u)r[16] + 0) = r[19];
    L800c7b98:;
    r[16] = (u)r[16] + 2;
    r[17] = (u)r[17] + 1; goto L800c7b44;
    L800c7ba4:;
    r[2] = (u)r[17] + (u)0;
    L800c7ba8:;
    r[31] = *(int *)((u)r[29] + 40);
    r[19] = *(int *)((u)r[29] + 36);
    r[18] = *(int *)((u)r[29] + 32);
    r[17] = *(int *)((u)r[29] + 28);
    r[16] = *(int *)((u)r[29] + 24);
    r[29] = (u)r[29] + 48; goto out;
out:
    RECOMP_RETURN;
}
