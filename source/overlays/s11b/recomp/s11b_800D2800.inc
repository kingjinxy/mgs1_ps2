extern char R_GM_PlayerPosition[] __asm__("GM_PlayerPosition");
extern char R_GV_RandS[] __asm__("GV_RandS");
int G_s11b_800D2800(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s11b_800D2800");
int G_s11b_800D2800(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(32)
    r[29] = (u)r[29] + -32;
    *(int *)((u)r[29] + 20) = r[17];
    r[17] = (u)r[4] + (u)0;
    r[4] = (u)0 + 2;
    *(int *)((u)r[29] + 24) = r[31];
    *(int *)((u)r[29] + 16) = r[16]; CALL(R_GV_RandS);
    r[4] = (u)0 + 2;
    r[16] = 0;
    r[3] = (u)r[2] << 5;
    r[3] = (u)r[3] - (u)r[2];
    r[3] = (u)r[3] << (r[4] & 31);
    r[3] = (u)r[3] + (u)r[2];
    r[3] = (u)r[3] << (r[4] & 31);
    r[2] = *(short *)((u)r[16] + (int)R_GM_PlayerPosition);
    r[16] = (u)r[16] + (int)R_GM_PlayerPosition;
    r[2] = (u)r[2] + (u)r[3];
    *(int *)((u)r[17] + 1580) = r[2]; CALL(R_GV_RandS);
    r[4] = (u)0 + 2;
    r[3] = (u)r[2] << 5;
    r[3] = (u)r[3] - (u)r[2];
    r[3] = (u)r[3] << (r[4] & 31);
    r[3] = (u)r[3] + (u)r[2];
    r[2] = *(short *)((u)r[16] + 2);
    r[3] = (u)r[3] << (r[4] & 31);
    r[2] = (u)r[2] + (u)r[3];
    *(int *)((u)r[17] + 1584) = r[2]; CALL(R_GV_RandS);
    r[3] = (u)r[2] << 5;
    r[3] = (u)r[3] - (u)r[2];
    r[3] = (u)r[3] << 2;
    r[3] = (u)r[3] + (u)r[2];
    r[2] = *(short *)((u)r[16] + 4);
    r[3] = (u)r[3] << 2;
    r[2] = (u)r[2] + (u)r[3];
    *(int *)((u)r[17] + 1588) = r[2];
    r[31] = *(int *)((u)r[29] + 24);
    r[17] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 32; goto out;
out:
    RECOMP_RETURN;
}
