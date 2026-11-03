extern char R_HZD_OnlineHazardCheck[] __asm__("HZD_OnlineHazardCheck");
int G_s10a_800D91E0(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s10a_800D91E0");
int G_s10a_800D91E0(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(48)
    r[29] = (u)r[29] + -48;
    *(int *)((u)r[29] + 40) = r[31];
    r[2] = *(int *)((u)r[4] + 160);
    r[3] = *(unsigned short *)((u)r[2] + 460);
    r[7] = (u)0 + 5;
    *(short *)((u)r[29] + 24) = r[3];
    r[2] = *(int *)((u)r[4] + 160);
    r[3] = (u)r[3] << 16;
    r[5] = *(unsigned short *)((u)r[2] + 464);
    r[3] = (int)r[3] >> 16;
    *(short *)((u)r[29] + 26) = r[5];
    r[2] = *(int *)((u)r[4] + 160);
    r[5] = (u)r[5] << 16;
    r[6] = *(unsigned short *)((u)r[2] + 468);
    r[5] = (int)r[5] >> 16;
    *(short *)((u)r[29] + 28) = r[6];
    r[2] = *(short *)((u)r[4] + 2556);
    r[6] = (u)r[6] << 16;
    r[2] = (u)r[2] + (u)r[3];
    r[3] = (u)r[2] >> 31;
    r[2] = (u)r[2] + (u)r[3];
    r[2] = (int)r[2] >> 1;
    *(short *)((u)r[29] + 32) = r[2];
    r[2] = *(short *)((u)r[4] + 2558);
    r[6] = (int)r[6] >> 16;
    r[2] = (u)r[2] + (u)r[5];
    r[3] = (u)r[2] >> 31;
    r[2] = (u)r[2] + (u)r[3];
    r[2] = (int)r[2] >> 1;
    *(short *)((u)r[29] + 34) = r[2];
    r[2] = *(short *)((u)r[4] + 2560);
    r[5] = (u)r[4] + 2556;
    r[2] = (u)r[2] + (u)r[6];
    r[3] = (u)r[2] >> 31;
    r[2] = (u)r[2] + (u)r[3];
    r[2] = (int)r[2] >> 1;
    *(short *)((u)r[29] + 36) = r[2];
    r[3] = *(int *)((u)r[4] + 80);
    r[2] = (u)0 + 4;
    *(int *)((u)r[29] + 16) = r[2];
    r[4] = *(int *)((u)r[3] + 8);
    r[6] = (u)r[29] + 32; CALL(R_HZD_OnlineHazardCheck);
    r[31] = *(int *)((u)r[29] + 40);
    r[2] = (u)0 < (u)r[2];
    r[29] = (u)r[29] + 48; goto out;
out:
    return r[2];
}
