extern char R_GV_ReceiveMessage[] __asm__("GV_ReceiveMessage");
int G_s19a_800C9C80(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s19a_800C9C80");
int G_s19a_800C9C80(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(32)
    r[29] = (u)r[29] + -32;
    *(int *)((u)r[29] + 20) = r[17];
    r[17] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[17] + 32;
    *(int *)((u)r[29] + 24) = r[31];
    r[4] = *(unsigned short *)((u)r[16] + 48);
    r[5] = (u)r[17] + 124; CALL(R_GV_ReceiveMessage);
    r[3] = (u)r[2] << 24;
    r[4] = *(int *)((u)r[16] + 92);
    r[3] = (int)r[3] >> 24;
    c = (((int)r[3] <= 0)); *(char *)((u)r[16] + 86) = r[2]; if (c) goto L800c9cfc;
    r[7] = (u)0 + 10081;
    r[6] = 0 | 60799;
    r[5] = (u)0 + 1;
    L800c9cc4:;
    r[2] = *(unsigned short *)((u)r[4] + 4);
    c = ((r[2] == r[7]));  if (c) goto L800c9ce4;
    c = ((r[2] == r[6]));  if (c) goto L800c9cec;
    r[3] = (u)r[3] + -1; goto L800c9cf4;
    L800c9ce4:;
    *(short *)((u)r[17] + 3586) = r[5]; goto L800c9cf0;
    L800c9cec:;
    *(short *)((u)r[17] + 3586) = 0;
    L800c9cf0:;
    r[3] = (u)r[3] + -1;
    L800c9cf4:;
    c = (((int)r[3] > 0)); r[4] = (u)r[4] + 20; if (c) goto L800c9cc4;
    L800c9cfc:;
    r[31] = *(int *)((u)r[29] + 24);
    r[17] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 32; goto out;
out:
    RECOMP_RETURN;
}
