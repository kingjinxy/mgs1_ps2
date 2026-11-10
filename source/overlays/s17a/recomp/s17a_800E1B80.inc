extern char R_ApplyMatrixLV[] __asm__("ApplyMatrixLV");
int G_s17a_800E1B80(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s17a_800E1B80");
int G_s17a_800E1B80(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(72)
    r[29] = (u)r[29] + -72;
    *(int *)((u)r[29] + 64) = r[31];
    r[2] = *(unsigned short *)((u)r[4] + 0);
    *(short *)((u)r[29] + 16) = r[2];
    r[2] = *(unsigned short *)((u)r[4] + 6);
    *(short *)((u)r[29] + 18) = r[2];
    r[2] = *(unsigned short *)((u)r[4] + 12);
    *(short *)((u)r[29] + 20) = r[2];
    r[2] = *(unsigned short *)((u)r[4] + 2);
    *(short *)((u)r[29] + 22) = r[2];
    r[2] = *(unsigned short *)((u)r[4] + 8);
    *(short *)((u)r[29] + 24) = r[2];
    r[2] = *(unsigned short *)((u)r[4] + 14);
    *(short *)((u)r[29] + 26) = r[2];
    r[2] = *(unsigned short *)((u)r[4] + 4);
    *(short *)((u)r[29] + 28) = r[2];
    r[2] = *(unsigned short *)((u)r[4] + 10);
    *(short *)((u)r[29] + 30) = r[2];
    r[2] = *(unsigned short *)((u)r[4] + 16);
    *(short *)((u)r[29] + 32) = r[2];
    r[2] = *(short *)((u)r[5] + 0);
    r[3] = *(int *)((u)r[4] + 20);
    r[2] = (u)r[2] - (u)r[3];
    *(int *)((u)r[29] + 48) = r[2];
    r[2] = *(short *)((u)r[5] + 2);
    r[3] = *(int *)((u)r[4] + 24);
    r[2] = (u)r[2] - (u)r[3];
    *(int *)((u)r[29] + 52) = r[2];
    r[3] = *(int *)((u)r[4] + 28);
    r[4] = (u)r[29] + 16;
    r[2] = *(short *)((u)r[5] + 4);
    r[5] = (u)r[29] + 48;
    r[2] = (u)r[2] - (u)r[3];
    *(int *)((u)r[29] + 56) = r[2]; CALL(R_ApplyMatrixLV);
    r[31] = *(int *)((u)r[29] + 64);
    r[29] = (u)r[29] + 72; goto out;
out:
    RECOMP_RETURN;
}
