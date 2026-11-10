extern char R_s18a_800C82A4[] __asm__("s18a_800C82A4");
extern char R_s18a_dat_800C3358[] __asm__("s18a_dat_800C3358");
extern char R_GM_ConfigObjectAction[] __asm__("GM_ConfigObjectAction");
extern char R_s18a_800C7684[] __asm__("s18a_800C7684");
extern char R_s18a_800C80B8[] __asm__("s18a_800C80B8");
int G_s18a_800CA3B4(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s18a_800CA3B4");
int G_s18a_800CA3B4(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    c = ((r[5] != 0)); *(int *)((u)r[29] + 20) = r[31]; if (c) goto L800ca3f4;
    r[4] = (u)r[16] + 156;
    r[2] = (u)0 + 32;
    *(int *)((u)r[16] + 2364) = r[2];
    r[2] = 0;
    r[6] = (u)0 + (u)0;
    r[5] = *(short *)((u)r[2] + (int)R_s18a_dat_800C3358);
    r[7] = (u)0 + 4; CALL(R_GM_ConfigObjectAction);
    r[4] = (u)r[16] + (u)0;
    r[5] = (u)0 + (u)0; CALL(R_s18a_800C80B8);
    L800ca3f4:;
    r[4] = (u)r[16] + (u)0; CALL(R_s18a_800C7684);
    c = ((r[2] != 0));  if (c) goto L800ca430;
    r[2] = *(short *)((u)r[16] + 182);
    c = ((r[2] == 0)); r[2] = (u)0 + 1; if (c) goto L800ca430;
    *(int *)((u)r[16] + 2368) = r[2];
    r[2] = 0;
    r[2] = (u)r[2] + (int)R_s18a_800C82A4;
    *(int *)((u)r[16] + 2348) = r[2];
    *(int *)((u)r[16] + 2356) = 0;
    *(short *)((u)r[16] + 112) = 0;
    *(short *)((u)r[16] + 108) = 0;
    L800ca430:;
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
