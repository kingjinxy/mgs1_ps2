extern char R_s18a_800D5F88[] __asm__("s18a_800D5F88");
int G_s18a_800D5FD8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s18a_800D5FD8");
int G_s18a_800D5FD8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 20) = r[31];
    r[2] = *(int *)((u)r[16] + 396);
    c = ((r[5] == r[2])); r[2] = ~(0 | r[5]); if (c) goto L800d6024;
    *(int *)((u)r[16] + 420) = r[2];
    r[2] = 0 | 65535;
    c = ((r[5] != r[2])); *(int *)((u)r[16] + 396) = r[5]; if (c) goto L800d6024;
    r[5] = (u)0 + 2; CALL(R_s18a_800D5F88);
    c = (((int)r[2] < 0)); r[2] = (u)0 + 4; if (c) goto L800d6024;
    *(int *)((u)r[16] + 448) = r[2];
    r[2] = (u)0 + 2;
    *(short *)((u)r[16] + 432) = r[2];
    L800d6024:;
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
