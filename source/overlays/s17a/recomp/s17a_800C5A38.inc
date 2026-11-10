extern char R_GV_ReceiveMessage[] __asm__("GV_ReceiveMessage");
extern char R_s17a_800C5754[] __asm__("s17a_800C5754");
extern char R_s17a_800C5A00[] __asm__("s17a_800C5A00");
int G_s17a_800C5A38(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s17a_800C5A38");
int G_s17a_800C5A38(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
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
    c = (((int)r[16] <= 0)); r[18] = 0 | 48338; if (c) goto L800c5aec;
    L800c5a68:;
    r[4] = *(int *)((u)r[29] + 16);
    r[3] = *(unsigned short *)((u)r[4] + 4);
    c = ((r[3] == r[18])); r[2] = (int)r[18] < (int)r[3]; if (c) goto L800c5acc;
    c = ((r[2] != 0)); r[2] = 0 | 51495; if (c) goto L800c5a9c;
    r[2] = (u)0 + 3662;
    c = ((r[3] == r[2]));  if (c) goto L800c5aac;
     goto L800c5ad8;
    L800c5a9c:;
    c = ((r[3] == r[2])); r[4] = (u)r[17] + (u)0; if (c) goto L800c5ab8;
     goto L800c5ad8;
    L800c5aac:;
    r[5] = *(unsigned short *)((u)r[4] + 6);
    r[4] = (u)r[17] + (u)0; goto L800c5abc;
    L800c5ab8:;
    r[5] = (u)0 + (u)0;
    L800c5abc:;
     CALL(R_s17a_800C5754);
    *(int *)((u)r[17] + 60) = 0; goto L800c5ad8;
    L800c5acc:;
    r[5] = *(unsigned short *)((u)r[4] + 6);
    r[4] = (u)r[17] + (u)0; CALL(R_s17a_800C5A00);
    L800c5ad8:;
    r[2] = *(int *)((u)r[29] + 16);
    r[16] = (u)r[16] + -1;
    r[2] = (u)r[2] + 20;
    c = (((int)r[16] > 0)); *(int *)((u)r[29] + 16) = r[2]; if (c) goto L800c5a68;
    L800c5aec:;
    r[31] = *(int *)((u)r[29] + 36);
    r[18] = *(int *)((u)r[29] + 32);
    r[17] = *(int *)((u)r[29] + 28);
    r[16] = *(int *)((u)r[29] + 24);
    r[29] = (u)r[29] + 40; goto out;
out:
    RECOMP_RETURN;
}
