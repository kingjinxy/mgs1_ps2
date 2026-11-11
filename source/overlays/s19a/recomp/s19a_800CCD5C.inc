extern char R_GV_ReceiveMessage[] __asm__("GV_ReceiveMessage");
extern char R_HZD_GetAddress[] __asm__("HZD_GetAddress");
int G_s19a_800CCD5C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s19a_800CCD5C");
int G_s19a_800CCD5C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(40)
    r[29] = (u)r[29] + -40;
    *(int *)((u)r[29] + 28) = r[17];
    r[17] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 24) = r[16];
    r[16] = (u)r[17] + 32;
    *(int *)((u)r[29] + 32) = r[31];
    r[4] = *(unsigned short *)((u)r[16] + 48);
    r[5] = (u)r[17] + 124; CALL(R_GV_ReceiveMessage);
    r[3] = (u)r[2] << 24;
    r[5] = (int)r[3] >> 24;
    r[3] = *(int *)((u)r[16] + 92);
    c = (((int)r[5] <= 0)); *(char *)((u)r[16] + 86) = r[2]; if (c) goto L800cce1c;
    r[4] = (u)r[3] + 12;
    L800ccd98:;
    r[3] = *(unsigned short *)((u)r[4] + -8);
    r[2] = (u)0 + 17167;
    c = ((r[3] != r[2]));  if (c) goto L800cce10;
    r[2] = *(unsigned char *)((u)r[4] + -6);
    *(char *)((u)r[17] + 2938) = r[2];
    r[2] = *(unsigned short *)((u)r[4] + -4);
    *(short *)((u)r[29] + 16) = r[2];
    r[2] = *(unsigned short *)((u)r[4] + -2);
    *(short *)((u)r[29] + 18) = r[2];
    r[2] = (u)r[2] << 16;
    r[2] = (int)r[2] >> 16;
    r[3] = *(unsigned short *)((u)r[4] + 0);
    r[2] = (int)r[2] < 30000;
    c = ((r[2] == 0)); *(short *)((u)r[29] + 20) = r[3]; if (c) goto L800cce00;
    r[2] = *(int *)((u)r[17] + 76);
    r[5] = (u)r[29] + 16;
    r[4] = *(int *)((u)r[2] + 8);
    r[6] = (u)0 + -1; CALL(R_HZD_GetAddress);
    *(char *)((u)r[17] + 2936) = r[2]; goto L800cce08;
    L800cce00:;
    r[2] = (u)0 + 255;
    *(char *)((u)r[17] + 2936) = r[2];
    L800cce08:;
    r[2] = (u)0 + 1; goto L800cce20;
    L800cce10:;
    r[5] = (u)r[5] + -1;
    c = (((int)r[5] > 0)); r[4] = (u)r[4] + 20; if (c) goto L800ccd98;
    L800cce1c:;
    r[2] = (u)0 + (u)0;
    L800cce20:;
    r[31] = *(int *)((u)r[29] + 32);
    r[17] = *(int *)((u)r[29] + 28);
    r[16] = *(int *)((u)r[29] + 24);
    r[29] = (u)r[29] + 40; goto out;
out:
    RECOMP_RETURN;
}
