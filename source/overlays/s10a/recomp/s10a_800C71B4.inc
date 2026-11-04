extern char R_s10a_dat_800E37EC[] __asm__("s10a_dat_800E37EC");
extern char R_GM_ConfigObjectAction[] __asm__("GM_ConfigObjectAction");
extern char R_printf[] __asm__("printf");
extern char R_s10a_800C8950[] __asm__("s10a_800C8950");
int G_s10a_800C71B4(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s10a_800C71B4");
int G_s10a_800C71B4(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(32)
    r[29] = (u)r[29] + -32;
    *(int *)((u)r[29] + 24) = r[18];
    r[18] = (u)r[4] + (u)0;
    r[4] = 0;
    *(int *)((u)r[29] + 28) = r[31];
    *(int *)((u)r[29] + 20) = r[17];
    *(int *)((u)r[29] + 16) = r[16];
    r[2] = *(unsigned short *)((u)r[18] + 2714);
    r[4] = (u)r[4] + (int)R_s10a_dat_800E37EC;
    r[17] = r[2] & 31;
    r[5] = (u)r[17] + (u)0; CALL(R_printf);
    r[2] = (u)r[17] + -1;
    r[2] = (u)r[2] < (u)15;
    c = ((r[2] == 0)); r[4] = (u)r[18] + 156; if (c) goto L800c7228;
    r[16] = (u)r[17] + 1;
    r[5] = (u)r[16] + (u)0;
    r[6] = (u)0 + (u)0;
    r[7] = (u)r[6] + (u)0; CALL(R_GM_ConfigObjectAction);
    r[4] = (u)r[18] + (u)0;
    r[2] = (u)0 + 1;
    *(int *)((u)r[18] + 3040) = r[16];
    *(int *)((u)r[18] + 3076) = r[17];
    *(short *)((u)r[18] + 3080) = r[2]; CALL(R_s10a_800C8950);
     goto L800c7238;
    L800c7228:;
    r[5] = (u)0 + (u)0;
    r[6] = (u)r[5] + (u)0;
    r[7] = (u)r[5] + (u)0; CALL(R_GM_ConfigObjectAction);
    L800c7238:;
    r[2] = *(unsigned short *)((u)r[18] + 180);
    *(short *)((u)r[18] + 82) = r[2];
    r[31] = *(int *)((u)r[29] + 28);
    r[18] = *(int *)((u)r[29] + 24);
    r[17] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 32; goto out;
out:
    RECOMP_RETURN;
}
