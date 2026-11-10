extern char R_s18a_dat_800C341C[] __asm__("s18a_dat_800C341C");
int G_s18a_800CC8B0(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s18a_800CC8B0");
int G_s18a_800CC8B0(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[2] = 0;
    r[2] = (u)r[2] + (int)R_s18a_dat_800C341C;
    r[6] = (u)r[6] << 3;
    r[5] = (u)r[5] << 4;
    r[6] = (u)r[6] + (u)r[5];
    r[6] = (u)r[6] + (u)r[2];
    r[3] = LWL(((u)r[6] + 3), r[3]);
    r[3] = LWR(((u)r[6] + 0), r[3]);
    r[7] = LWL(((u)r[6] + 7), r[7]);
    r[7] = LWR(((u)r[6] + 4), r[7]);
    SWL(((u)r[4] + 2419), r[3]);
    SWR(((u)r[4] + 2416), r[3]);
    SWL(((u)r[4] + 2423), r[7]);
    SWR(((u)r[4] + 2420), r[7]);
     goto out;
out:
    RECOMP_RETURN;
}
