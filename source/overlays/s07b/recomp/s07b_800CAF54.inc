extern char R_NewShadow2[] __asm__("NewShadow2");
int G_s07b_800CAF54(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s07b_800CAF54");
int G_s07b_800CAF54(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(40)
    r[29] = (u)r[29] + -40;
    *(int *)((u)r[29] + 32) = r[16];
    r[16] = (u)r[4] + (u)0;
    r[2] = (u)0 + 6;
    *(short *)((u)r[29] + 26) = r[2];
    r[2] = (u)0 + 12;
    *(short *)((u)r[29] + 28) = r[2];
    r[2] = (u)0 + 15;
    *(short *)((u)r[29] + 30) = r[2];
    r[2] = (u)r[16] + 2012;
    r[4] = (u)r[16] + 32;
    *(short *)((u)r[29] + 24) = 0;
    *(int *)((u)r[29] + 16) = r[2];
    r[6] = *(unsigned short *)((u)r[29] + 26);
    r[7] = *(unsigned short *)((u)r[29] + 30);
    r[2] = *(unsigned short *)((u)r[29] + 24);
    r[3] = *(unsigned short *)((u)r[29] + 28);
    r[5] = (u)r[16] + 156;
    *(int *)((u)r[29] + 36) = r[31];
    r[6] = (u)r[6] << 16;
    r[7] = (u)r[7] << 16;
    r[6] = r[2] | r[6];
    r[7] = r[3] | r[7]; CALL(R_NewShadow2);
    *(int *)((u)r[16] + 2008) = r[2];
    r[31] = *(int *)((u)r[29] + 36);
    r[16] = *(int *)((u)r[29] + 32);
    r[29] = (u)r[29] + 40; goto out;
out:
    return r[2];
}
