extern char R_GM_CurrentMap[] __asm__("GM_CurrentMap");
extern char R_GCL_GetOption[] __asm__("GCL_GetOption");
extern char R_GCL_StrToInt[] __asm__("GCL_StrToInt");
extern char R_s17a_800C8CB4[] __asm__("s17a_800C8CB4");
extern char R_s17a_800C9D68[] __asm__("s17a_800C9D68");
int G_s17a_800C9E34(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s17a_800C9E34");
int G_s17a_800C9E34(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    r[4] = (u)0 + 98;
    r[2] = (u)0 + 255;
    *(int *)((u)r[29] + 20) = r[31];
    *(int *)((u)r[16] + 940) = r[2];
    r[2] = 0;
    *(int *)((u)r[16] + 944) = 0;
    *(int *)((u)r[16] + 72) = 0;
    *(int *)((u)r[16] + 36) = r[5];
    *(int *)((u)r[16] + 32) = r[6];
    *(int *)((u)r[2] + (int)R_GM_CurrentMap) = r[6]; CALL(R_GCL_GetOption);
    c = ((r[2] != 0)); r[4] = (u)r[2] + (u)0; if (c) goto L800c9e7c;
    r[2] = (u)0 + -1; goto L800c9ec0;
    L800c9e7c:;
    r[5] = (u)r[16] + 52; CALL(R_s17a_800C8CB4);
    r[4] = (u)0 + 104; CALL(R_GCL_GetOption);
    c = ((r[2] == 0));  if (c) goto L800c9ea4;
    r[4] = (u)r[2] + (u)0; CALL(R_GCL_StrToInt);
    *(int *)((u)r[16] + 68) = r[2]; goto L800c9ea8;
    L800c9ea4:;
    *(int *)((u)r[16] + 68) = 0;
    L800c9ea8:;
    r[4] = (u)r[16] + (u)0; CALL(R_s17a_800C9D68);
    r[3] = (u)r[2] + (u)0;
    c = (((int)r[3] < 0)); r[2] = (u)0 + -1; if (c) goto L800c9ec0;
    r[2] = (u)0 + (u)0;
    L800c9ec0:;
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
