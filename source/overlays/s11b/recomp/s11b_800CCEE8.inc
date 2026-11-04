extern char R_s11b_dat_800DB304[] __asm__("s11b_dat_800DB304");
extern char R_GV_ReceiveMessage[] __asm__("GV_ReceiveMessage");
int G_s11b_800CCEE8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s11b_800CCEE8");
int G_s11b_800CCEE8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(40)
    r[29] = (u)r[29] + -40;
    *(int *)((u)r[29] + 24) = r[16];
    r[16] = (u)r[5] + (u)0;
    *(int *)((u)r[29] + 28) = r[17];
    r[17] = (u)r[6] + (u)0;
    r[4] = r[4] & 65535;
    *(int *)((u)r[29] + 32) = r[31];
    r[5] = (u)r[29] + 16; CALL(R_GV_ReceiveMessage);
    r[5] = (u)r[2] + (u)0;
    c = (((int)r[5] <= 0)); r[8] = (u)0 + -1; if (c) goto L800ccf78;
    r[9] = 0;
    L800ccf1c:;
    r[2] = *(int *)((u)r[29] + 16);
    r[7] = *(unsigned short *)((u)r[2] + 4);
    c = (((int)r[16] <= 0)); r[3] = (u)0 + (u)0; if (c) goto L800ccf68;
    r[6] = (u)r[2] + (u)0;
    r[4] = (u)r[17] + (u)0;
    L800ccf38:;
    r[2] = *(unsigned short *)((u)r[4] + 0);
    c = ((r[7] != r[2]));  if (c) goto L800ccf54;
    r[2] = *(unsigned short *)((u)r[6] + 6);
    r[8] = (u)r[3] + (u)0;
    *(int *)((u)r[9] + (int)R_s11b_dat_800DB304) = r[2];
    L800ccf54:;
    r[3] = (u)r[3] + 1;
    r[2] = (int)r[3] < (int)r[16];
    c = ((r[2] != 0)); r[4] = (u)r[4] + 2; if (c) goto L800ccf38;
    r[2] = *(int *)((u)r[29] + 16);
    L800ccf68:;
    r[5] = (u)r[5] + -1;
    r[2] = (u)r[2] + 20;
    c = (((int)r[5] > 0)); *(int *)((u)r[29] + 16) = r[2]; if (c) goto L800ccf1c;
    L800ccf78:;
    r[31] = *(int *)((u)r[29] + 32);
    r[17] = *(int *)((u)r[29] + 28);
    r[16] = *(int *)((u)r[29] + 24);
    r[2] = (u)r[8] + (u)0;
    r[29] = (u)r[29] + 40; goto out;
    r[2] = 0;
    r[2] = *(int *)((u)r[2] + (int)R_s11b_dat_800DB304);
     goto out;
out:
    RECOMP_RETURN;
}
