extern char R_GV_RandU[] __asm__("GV_RandU");
int G_s11h_800C43B4(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s11h_800C43B4");
int G_s11h_800C43B4(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(48)
    r[29] = (u)r[29] + -48;
    *(int *)((u)r[29] + 28) = r[19];
    r[19] = (u)r[7] + (u)0;
    *(int *)((u)r[29] + 24) = r[18];
    r[18] = (u)r[6] + -1;
    *(int *)((u)r[29] + 40) = r[31];
    *(int *)((u)r[29] + 36) = r[21];
    *(int *)((u)r[29] + 32) = r[20];
    *(int *)((u)r[29] + 20) = r[17];
    c = (((int)r[18] < 0)); *(int *)((u)r[29] + 16) = r[16]; if (c) goto L800c4440;
    r[21] = (u)0 + 3;
    r[20] = (u)0 + 96;
    r[17] = (u)r[5] + 14;
    r[16] = (u)r[4] + 14;
    L800c43f0:;
    r[18] = (u)r[18] + -1;
    r[4] = (u)0 + 2; CALL(R_GV_RandU);
    *(char *)((u)r[16] + -11) = r[21];
    *(char *)((u)r[16] + -7) = r[20];
    r[3] = *(int *)((u)r[19] + 0);
    r[2] = (u)r[2] + 1;
    *(short *)((u)r[16] + -2) = r[2];
    *(short *)((u)r[16] + 0) = r[2];
    *(int *)((u)r[16] + -10) = r[3];
    r[16] = (u)r[16] + 16;
    *(char *)((u)r[17] + -11) = r[21];
    *(char *)((u)r[17] + -7) = r[20];
    r[3] = *(int *)((u)r[19] + 0);
    r[19] = (u)r[19] + 4;
    *(short *)((u)r[17] + -2) = r[2];
    *(short *)((u)r[17] + 0) = r[2];
    *(int *)((u)r[17] + -10) = r[3];
    c = (((int)r[18] >= 0)); r[17] = (u)r[17] + 16; if (c) goto L800c43f0;
    L800c4440:;
    r[31] = *(int *)((u)r[29] + 40);
    r[21] = *(int *)((u)r[29] + 36);
    r[20] = *(int *)((u)r[29] + 32);
    r[19] = *(int *)((u)r[29] + 28);
    r[18] = *(int *)((u)r[29] + 24);
    r[17] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 48; goto out;
out:
    RECOMP_RETURN;
}
