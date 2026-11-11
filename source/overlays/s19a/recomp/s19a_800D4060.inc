extern char R_GV_RandU[] __asm__("GV_RandU");
int G_s19a_800D4060(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s19a_800D4060");
int G_s19a_800D4060(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 20) = r[31];
    r[3] = *(int *)((u)r[16] + 2856);
    r[2] = r[3] & 31;
    c = ((r[2] == 0)); r[2] = (int)r[3] < 65; if (c) goto L800d4094;
    c = ((r[2] != 0)); r[2] = (u)0 + (u)0; if (c) goto L800d40ac;
    r[2] = (u)0 + 1; goto L800d40bc;
    L800d4094:;
    r[4] = (u)0 + 8; CALL(R_GV_RandU);
    r[2] = (u)r[2] << 9;
    *(short *)((u)r[16] + 2904) = r[2];
    r[2] = (u)0 + (u)0;
    r[3] = *(int *)((u)r[16] + 2856);
    L800d40ac:;
    r[4] = *(unsigned short *)((u)r[16] + 2904);
    r[3] = (u)r[3] + 1;
    *(short *)((u)r[16] + 2888) = r[4];
    *(int *)((u)r[16] + 2856) = r[3];
    L800d40bc:;
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
