extern char R_s19a_dat_800E0530[] __asm__("s19a_dat_800E0530");
extern char R_GV_ReceiveMessage[] __asm__("GV_ReceiveMessage");
int G_s19a_800C8EB8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s19a_800C8EB8");
int G_s19a_800C8EB8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(32)
    r[29] = (u)r[29] + -32;
    *(int *)((u)r[29] + 24) = r[31];
    r[4] = *(int *)((u)r[4] + 36);
    r[5] = (u)r[29] + 16; CALL(R_GV_ReceiveMessage);
    r[3] = (u)r[2] + (u)0;
    c = (((int)r[3] <= 0));  if (c) goto L800c8f34;
    r[7] = (u)0 + 10081;
    r[6] = 0 | 60799;
    r[2] = 0;
    r[4] = (u)r[2] + (int)R_s19a_dat_800E0530;
    r[5] = (u)0 + 1;
    L800c8eec:;
    r[2] = *(int *)((u)r[29] + 16);
    r[2] = *(unsigned short *)((u)r[2] + 4);
    c = ((r[2] == r[7]));  if (c) goto L800c8f14;
    c = ((r[2] == r[6]));  if (c) goto L800c8f1c;
     goto L800c8f20;
    L800c8f14:;
    *(short *)((u)r[4] + 378) = r[5]; goto L800c8f20;
    L800c8f1c:;
    *(short *)((u)r[4] + 378) = 0;
    L800c8f20:;
    r[2] = *(int *)((u)r[29] + 16);
    r[3] = (u)r[3] + -1;
    r[2] = (u)r[2] + 20;
    c = (((int)r[3] > 0)); *(int *)((u)r[29] + 16) = r[2]; if (c) goto L800c8eec;
    L800c8f34:;
    r[31] = *(int *)((u)r[29] + 24);
    r[29] = (u)r[29] + 32; goto out;
out:
    RECOMP_RETURN;
}
