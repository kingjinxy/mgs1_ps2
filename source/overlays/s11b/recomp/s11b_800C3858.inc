extern char R_GV_ReceiveMessage[] __asm__("GV_ReceiveMessage");
extern char R_s11b_800C3574[] __asm__("s11b_800C3574");
extern char R_s11b_800C3820[] __asm__("s11b_800C3820");
int G_s11b_800C3858(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s11b_800C3858");
int G_s11b_800C3858(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(40)
    r[29] = (u)r[29] + -40;
    *(int *)((u)r[29] + 28) = r[17];
    r[17] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 36) = r[31];
    *(int *)((u)r[29] + 32) = r[18];
    *(int *)((u)r[29] + 24) = r[16];
    r[4] = *(unsigned short *)((u)r[17] + 40);
    r[5] = (u)r[29] + 16; CALL(R_GV_ReceiveMessage);
    r[16] = (u)r[2] + (u)0;
    c = (((int)r[16] <= 0)); r[18] = 0 | 48338; if (c) goto L800c390c;
    L800c3888:;
    r[4] = *(int *)((u)r[29] + 16);
    r[3] = *(unsigned short *)((u)r[4] + 4);
    c = ((r[3] == r[18])); r[2] = (int)r[18] < (int)r[3]; if (c) goto L800c38ec;
    c = ((r[2] != 0)); r[2] = 0 | 51495; if (c) goto L800c38bc;
    r[2] = (u)0 + 3662;
    c = ((r[3] == r[2]));  if (c) goto L800c38cc;
     goto L800c38f8;
    L800c38bc:;
    c = ((r[3] == r[2])); r[4] = (u)r[17] + (u)0; if (c) goto L800c38d8;
     goto L800c38f8;
    L800c38cc:;
    r[5] = *(unsigned short *)((u)r[4] + 6);
    r[4] = (u)r[17] + (u)0; goto L800c38dc;
    L800c38d8:;
    r[5] = (u)0 + (u)0;
    L800c38dc:;
     CALL(R_s11b_800C3574);
    *(int *)((u)r[17] + 60) = 0; goto L800c38f8;
    L800c38ec:;
    r[5] = *(unsigned short *)((u)r[4] + 6);
    r[4] = (u)r[17] + (u)0; CALL(R_s11b_800C3820);
    L800c38f8:;
    r[2] = *(int *)((u)r[29] + 16);
    r[16] = (u)r[16] + -1;
    r[2] = (u)r[2] + 20;
    c = (((int)r[16] > 0)); *(int *)((u)r[29] + 16) = r[2]; if (c) goto L800c3888;
    L800c390c:;
    r[31] = *(int *)((u)r[29] + 36);
    r[18] = *(int *)((u)r[29] + 32);
    r[17] = *(int *)((u)r[29] + 28);
    r[16] = *(int *)((u)r[29] + 24);
    r[29] = (u)r[29] + 40; goto out;
out:
    RECOMP_RETURN;
}
