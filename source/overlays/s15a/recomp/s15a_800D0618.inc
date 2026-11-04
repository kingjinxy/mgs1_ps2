extern char R_s15a_800D058C[] __asm__("s15a_800D058C");
int G_s15a_800D0618(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s15a_800D0618");
int G_s15a_800D0618(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    r[2] = (u)r[5] << 2;
    r[2] = (u)r[2] + (u)r[5];
    r[2] = (u)r[2] << 3;
    r[2] = (u)r[2] - (u)r[5];
    r[2] = (u)r[2] << 2;
    r[8] = *(int *)((u)r[29] + 40);
    r[2] = (u)r[4] + (u)r[2];
    *(int *)((u)r[29] + 16) = r[31];
    r[3] = *(unsigned short *)((u)r[2] + 120);
    r[5] = *(unsigned short *)((u)r[2] + 122);
    r[3] = (u)r[3] + (u)r[7];
    r[5] = (u)r[5] + (u)r[8];
    *(short *)((u)r[2] + 120) = r[3];
    *(short *)((u)r[2] + 122) = r[5];
    r[7] = *(int *)((u)r[29] + 44);
    r[8] = *(int *)((u)r[29] + 48);
    r[3] = *(unsigned short *)((u)r[2] + 124);
    r[5] = *(unsigned short *)((u)r[2] + 112);
    r[3] = (u)r[3] + (u)r[7];
    r[5] = (u)r[5] + (u)r[8];
    *(short *)((u)r[2] + 124) = r[3];
    *(short *)((u)r[2] + 112) = r[5];
    r[7] = *(int *)((u)r[29] + 52);
    r[8] = *(int *)((u)r[29] + 56);
    r[3] = *(unsigned short *)((u)r[2] + 114);
    r[5] = *(unsigned short *)((u)r[2] + 116);
    r[3] = (u)r[3] + (u)r[7];
    r[5] = (u)r[5] + (u)r[8];
    *(short *)((u)r[2] + 116) = r[5];
    r[5] = (u)r[6] + (u)0;
    *(short *)((u)r[2] + 114) = r[3];
    r[6] = *(int *)((u)r[29] + 60);
     CALL(R_s15a_800D058C);
    r[31] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
