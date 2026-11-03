extern char R_GV_Time[] __asm__("GV_Time");
extern char R_rsin[] __asm__("rsin");
int G_s07b_800CC704(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s07b_800CC704");
int G_s07b_800CC704(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(32)
    r[2] = 0;
    r[3] = *(int *)((u)r[2] + (int)R_GV_Time);
    r[29] = (u)r[29] + -32;
    *(int *)((u)r[29] + 20) = r[17];
    r[17] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 24) = r[31];
    *(int *)((u)r[29] + 16) = r[16];
    c = (((int)r[3] >= 0)); r[2] = (u)r[3] + (u)0; if (c) goto L800cc72c;
    r[2] = (u)r[3] + 127;
    L800cc72c:;
    r[16] = (int)r[2] >> 7;
    r[2] = (u)r[16] << 7;
    r[16] = (u)r[3] - (u)r[2];
    r[4] = (u)r[16] << 5; CALL(R_rsin);
    r[4] = (u)r[16] + -1;
    r[4] = (u)r[4] << 5;
    r[16] = (u)r[2] + (u)0; CALL(R_rsin);
    r[16] = (u)r[16] - (u)r[2];
    r[2] = (u)r[16] << 2;
    r[2] = (u)r[2] + (u)r[16];
    r[3] = (u)r[2] << 5;
    c = (((int)r[3] >= 0));  if (c) goto L800cc76c;
    r[3] = (u)r[3] + 4095;
    L800cc76c:;
    r[2] = *(unsigned short *)((u)r[17] + 102);
    r[3] = (int)r[3] >> 12;
    r[2] = (u)r[2] + (u)r[3];
    *(short *)((u)r[17] + 102) = r[2];
    r[31] = *(int *)((u)r[29] + 24);
    r[17] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 32; goto out;
out:
    RECOMP_RETURN;
}
