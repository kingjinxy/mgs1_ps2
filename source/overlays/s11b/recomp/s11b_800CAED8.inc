extern char R_s11b_800C7900[] __asm__("s11b_800C7900");
int G_s11b_800CAED8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s11b_800CAED8");
int G_s11b_800CAED8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(48)
    r[29] = (u)r[29] + -48;
    r[2] = (u)0 + 32;
    *(short *)((u)r[29] + 24) = r[2];
    *(short *)((u)r[29] + 26) = r[2];
    *(short *)((u)r[29] + 28) = r[2];
    r[2] = (u)0 + 8;
    *(short *)((u)r[29] + 32) = r[2];
    *(short *)((u)r[29] + 34) = r[2];
    *(short *)((u)r[29] + 36) = r[2];
    r[2] = (u)0 + 1;
    *(int *)((u)r[29] + 16) = r[2];
    r[2] = (u)0 + 15;
    r[4] = (u)0 + (u)0;
    r[5] = (u)0 + 1;
    r[6] = (u)r[29] + 24;
    r[7] = (u)r[29] + 32;
    *(int *)((u)r[29] + 40) = r[31];
    *(int *)((u)r[29] + 20) = r[2]; CALL(R_s11b_800C7900);
    r[31] = *(int *)((u)r[29] + 40);
    r[29] = (u)r[29] + 48; goto out;
out:
    RECOMP_RETURN;
}
