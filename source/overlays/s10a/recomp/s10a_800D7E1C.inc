extern char R_ratan2[] __asm__("ratan2");
int G_s10a_800D7E1C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s10a_800D7E1C");
int G_s10a_800D7E1C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(32)
    r[29] = (u)r[29] + -32;
    *(int *)((u)r[29] + 24) = r[18];
    r[18] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 20) = r[17];
    r[17] = (u)r[7] + (u)0;
    *(int *)((u)r[29] + 28) = r[31];
    *(int *)((u)r[29] + 16) = r[16];
    r[2] = *(short *)((u)r[5] + 0);
    r[4] = *(short *)((u)r[6] + 0);
    r[16] = *(short *)((u)r[5] + 2);
    r[3] = *(short *)((u)r[5] + 4);
    r[5] = *(short *)((u)r[6] + 4);
    r[4] = (u)r[2] - (u)r[4];
    r[2] = *(short *)((u)r[6] + 2);
    r[5] = (u)r[3] - (u)r[5];
    r[16] = (u)r[16] - (u)r[2]; CALL(R_ratan2);
    r[4] = (u)r[18] + (u)0;
    r[5] = (u)r[16] + (u)0;
    r[2] = r[2] & 4095;
    *(short *)((u)r[17] + 2) = r[2]; CALL(R_ratan2);
    r[2] = r[2] & 4095;
    *(short *)((u)r[17] + 0) = r[2];
    *(short *)((u)r[17] + 4) = 0;
    r[31] = *(int *)((u)r[29] + 28);
    r[18] = *(int *)((u)r[29] + 24);
    r[17] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 32; goto out;
out:
    RECOMP_RETURN;
}
