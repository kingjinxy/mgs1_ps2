extern char R_GV_RandU[] __asm__("GV_RandU");
extern char R_Port_GameTick[] __asm__("Port_GameTick");
extern char R_s10a_800D712C[] __asm__("s10a_800D712C");
int G_s10a_800D7A98(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s10a_800D7A98");
int G_s10a_800D7A98(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(40)
    r[29] = (u)r[29] + -40;
    *(int *)((u)r[29] + 24) = r[18];
    r[18] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 28) = r[19];
    r[19] = (u)r[5] + (u)0;
    *(int *)((u)r[29] + 32) = r[20];
    r[20] = (u)r[6] + (u)0;
    *(int *)((u)r[29] + 36) = r[31];
    *(int *)((u)r[29] + 20) = r[17];
    *(int *)((u)r[29] + 16) = r[16]; CALL(R_Port_GameTick);
    r[3] = (u)r[2] + (u)0;
    c = (((int)r[3] >= 0)); r[17] = (int)r[2] >> 8; if (c) goto L800d7ad8;
    r[2] = (u)r[3] + 255;
    r[17] = (int)r[2] >> 8;
    L800d7ad8:;
    r[2] = (u)r[17] << 8;
    r[17] = (u)r[3] - (u)r[2];
    c = (((int)r[17] <= 0)); r[16] = (u)0 + (u)0; if (c) goto L800d7b00;
    L800d7ae8:;
    r[4] = (u)0 + 4096; CALL(R_GV_RandU);
    r[16] = (u)r[16] + 1;
    r[2] = (int)r[16] < (int)r[17];
    c = ((r[2] != 0));  if (c) goto L800d7ae8;
    L800d7b00:;
    r[4] = (u)r[18] + (u)0;
    r[5] = (u)r[19] + (u)0;
    r[6] = (u)r[20] + (u)0;
    *(short *)((u)r[4] + 2476) = 0;
    *(short *)((u)r[4] + 2478) = 0;
    *(short *)((u)r[4] + 2480) = 0;
    *(int *)((u)r[4] + 2544) = 0;
    *(int *)((u)r[4] + 2648) = 0; CALL(R_s10a_800D712C);
    r[3] = (u)r[2] + (u)0;
    c = (((int)r[3] < 0)); r[2] = (u)0 + -1; if (c) goto L800d7b34;
    r[2] = (u)0 + (u)0;
    L800d7b34:;
    r[31] = *(int *)((u)r[29] + 36);
    r[20] = *(int *)((u)r[29] + 32);
    r[19] = *(int *)((u)r[29] + 28);
    r[18] = *(int *)((u)r[29] + 24);
    r[17] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 40; goto out;
out:
    RECOMP_RETURN;
}
