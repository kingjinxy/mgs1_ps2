extern char R_s18a_dat_800E3044[] __asm__("s18a_dat_800E3044");
extern char R_printf[] __asm__("printf");
int G_s18a_800CC830(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s18a_800CC830");
int G_s18a_800CC830(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    r[6] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 16) = r[31];
    r[2] = *(int *)((u)r[6] + 2452);
    r[3] = *(int *)((u)r[6] + 2448);
    r[2] = (u)r[2] << 3;
    r[3] = (u)r[3] + (u)r[2];
    r[2] = *(unsigned short *)((u)r[3] + 0);
    r[3] = *(int *)((u)r[6] + 2448);
    *(short *)((u)r[6] + 2416) = r[2];
    r[2] = *(int *)((u)r[6] + 2452);
    r[5] = *(short *)((u)r[6] + 2416);
    r[2] = (u)r[2] << 3;
    r[3] = (u)r[3] + (u)r[2];
    r[2] = *(unsigned short *)((u)r[3] + 2);
    r[4] = 0;
    *(short *)((u)r[6] + 2418) = r[2];
    r[2] = *(int *)((u)r[6] + 2452);
    r[3] = *(int *)((u)r[6] + 2448);
    r[2] = (u)r[2] << 3;
    r[3] = (u)r[3] + (u)r[2];
    r[7] = *(unsigned short *)((u)r[3] + 4);
    r[4] = (u)r[4] + (int)R_s18a_dat_800E3044;
    *(short *)((u)r[6] + 2420) = r[7];
    r[7] = (u)r[7] << 16;
    r[6] = *(short *)((u)r[6] + 2418);
    r[7] = (int)r[7] >> 16; CALL(R_printf);
    r[31] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
