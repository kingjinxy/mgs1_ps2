extern char R_GV_ReceiveMessage[] __asm__("GV_ReceiveMessage");
int G_s18a_800C3F68(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s18a_800C3F68");
int G_s18a_800C3F68(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(32)
    r[29] = (u)r[29] + -32;
    *(int *)((u)r[29] + 24) = r[16];
    r[16] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 28) = r[31];
    r[4] = *(int *)((u)r[16] + 76);
    r[5] = (u)r[29] + 16; CALL(R_GV_ReceiveMessage);
    r[4] = (u)r[2] + (u)0;
    c = (((int)r[4] <= 0));  if (c) goto L800c4004;
    r[4] = (u)r[4] + -1;
    c = (((int)r[4] < 0));  if (c) goto L800c4004;
    r[5] = (u)0 + 32273;
    L800c3fa0:;
    r[3] = *(int *)((u)r[29] + 16);
    r[2] = *(unsigned short *)((u)r[3] + 4);
    c = ((r[2] != r[5]));  if (c) goto L800c3ff0;
    r[2] = *(unsigned short *)((u)r[3] + 18);
    r[2] = (u)r[2] < (u)4;
    c = ((r[2] != 0));  if (c) goto L800c3ff0;
    r[2] = *(unsigned short *)((u)r[3] + 6);
    *(short *)((u)r[16] + 56) = r[2];
    r[2] = *(unsigned short *)((u)r[3] + 8);
    *(short *)((u)r[16] + 58) = r[2];
    r[2] = *(unsigned short *)((u)r[3] + 10);
    *(short *)((u)r[16] + 60) = r[2];
    L800c3ff0:;
    r[2] = *(int *)((u)r[29] + 16);
    r[4] = (u)r[4] + -1;
    r[2] = (u)r[2] + 20;
    c = (((int)r[4] >= 0)); *(int *)((u)r[29] + 16) = r[2]; if (c) goto L800c3fa0;
    L800c4004:;
    r[31] = *(int *)((u)r[29] + 28);
    r[16] = *(int *)((u)r[29] + 24);
    r[29] = (u)r[29] + 32; goto out;
out:
    RECOMP_RETURN;
}
