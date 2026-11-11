extern char R_s19a_dat_800E0B38[] __asm__("s19a_dat_800E0B38");
extern char R_s19a_800D26B0[] __asm__("s19a_800D26B0");
int G_s19a_800D324C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s19a_800D324C");
int G_s19a_800D324C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(32)
    r[29] = (u)r[29] + -32;
    *(int *)((u)r[29] + 24) = r[18];
    r[18] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 20) = r[17];
    r[17] = (u)0 + (u)0;
    r[2] = 0;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[2] + (int)R_s19a_dat_800E0B38;
    *(int *)((u)r[29] + 28) = r[31];
    L800d3270:;
    r[4] = (u)r[16] + (u)0;
    r[5] = (u)0 + (u)0;
    r[6] = (u)r[5] + (u)0;
    r[7] = (u)r[5] + (u)0; CALL(R_s19a_800D26B0);
    *(short *)((u)r[16] + 6) = 0;
    r[17] = (u)r[17] + 1;
    r[2] = (int)r[17] < 48;
    c = ((r[2] != 0)); r[16] = (u)r[16] + 8; if (c) goto L800d3270;
    r[2] = 0;
    r[2] = (u)r[2] + (int)R_s19a_dat_800E0B38;
    *(short *)((u)r[2] + 384) = 0;
    *(short *)((u)r[2] + 386) = 0;
    *(int *)((u)r[18] + 36) = 0;
    r[31] = *(int *)((u)r[29] + 28);
    r[18] = *(int *)((u)r[29] + 24);
    r[17] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 32; goto out;
out:
    RECOMP_RETURN;
}
