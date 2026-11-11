extern char R_s19a_800CBDDC[] __asm__("s19a_800CBDDC");
extern char R_s19a_dat_800C34AC[] __asm__("s19a_dat_800C34AC");
extern char R_GM_ConfigObjectAction[] __asm__("GM_ConfigObjectAction");
extern char R_s19a_800CB840[] __asm__("s19a_800CB840");
extern char R_s19a_800CB8BC[] __asm__("s19a_800CB8BC");
int G_s19a_800CBE74(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s19a_800CBE74");
int G_s19a_800CBE74(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    c = ((r[5] != 0)); *(int *)((u)r[29] + 20) = r[31]; if (c) goto L800cbeac;
    r[4] = (u)r[16] + 156;
    r[2] = 0;
    r[6] = (u)0 + (u)0;
    *(int *)((u)r[16] + 3040) = 0;
    r[5] = *(short *)((u)r[2] + (int)R_s19a_dat_800C34AC);
    r[7] = (u)0 + 4; CALL(R_GM_ConfigObjectAction);
    r[4] = (u)r[16] + (u)0; CALL(R_s19a_800CB8BC);
    L800cbeac:;
    r[4] = (u)r[16] + (u)0; CALL(R_s19a_800CB840);
    r[2] = 0;
    r[3] = *(unsigned short *)((u)r[16] + 3592);
    r[2] = (u)r[2] + (int)R_s19a_800CBDDC;
    *(int *)((u)r[16] + 3024) = r[2];
    *(int *)((u)r[16] + 3032) = 0;
    *(short *)((u)r[16] + 112) = 0;
    *(short *)((u)r[16] + 108) = 0;
    *(short *)((u)r[16] + 110) = r[3];
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
