extern char R_s11h_dat_800DA988[] __asm__("s11h_dat_800DA988");
extern char R_GV_ReceiveMessage[] __asm__("GV_ReceiveMessage");
extern char R_GV_StrCode[] __asm__("GV_StrCode");
int G_s11h_800C49F0(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s11h_800C49F0");
int G_s11h_800C49F0(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    r[4] = 0;
    *(int *)((u)r[29] + 20) = r[31];
    r[4] = (u)r[4] + ((int)R_s11h_dat_800DA988 + 24); CALL(R_GV_StrCode);
    r[4] = (u)r[2] + (u)0;
    r[5] = (u)r[16] + 9560; CALL(R_GV_ReceiveMessage);
    r[4] = (u)r[2] + (u)0;
    c = (((int)r[4] <= 0));  if (c) goto L800c4a7c;
    r[4] = (u)r[4] + -1;
    r[2] = *(int *)((u)r[16] + 9560);
    c = (((int)r[4] < 0));  if (c) goto L800c4a7c;
    r[7] = (u)0 + 3662;
    r[6] = 0 | 51495;
    r[5] = (u)0 + 1;
    r[3] = (u)r[2] + 4;
    L800c4a44:;
    r[2] = *(unsigned short *)((u)r[3] + 0);
    c = ((r[2] == r[7]));  if (c) goto L800c4a64;
    c = ((r[2] == r[6]));  if (c) goto L800c4a6c;
    *(int *)((u)r[16] + 9552) = r[2]; goto L800c4a70;
    L800c4a64:;
    *(int *)((u)r[16] + 9556) = r[5]; goto L800c4a70;
    L800c4a6c:;
    *(int *)((u)r[16] + 9556) = 0;
    L800c4a70:;
    r[4] = (u)r[4] + -1;
    c = (((int)r[4] >= 0)); r[3] = (u)r[3] + 20; if (c) goto L800c4a44;
    L800c4a7c:;
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
