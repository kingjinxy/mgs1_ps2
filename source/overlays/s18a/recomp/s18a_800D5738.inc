extern char R_s18a_dat_800E434C[] __asm__("s18a_dat_800E434C");
extern char R_s18a_dat_800E4354[] __asm__("s18a_dat_800E4354");
int G_s18a_800D5738(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s18a_800D5738");
int G_s18a_800D5738(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[2] = 0;
    r[2] = *(int *)((u)r[2] + (int)R_s18a_dat_800E4354);
    r[2] = r[2] ? *(unsigned char *)((u)r[2] + 0) : 3; /* mips2c.py NULLS */
    r[2] = r[2] & 64;
    c = ((r[2] == 0)); r[2] = 0; if (c) goto L800d5760;
    r[2] = (u)r[5] + (u)0; goto out;
    L800d5760:;
    r[3] = *(int *)((u)r[2] + (int)R_s18a_dat_800E434C);
    c = (((int)r[3] < 0)); r[2] = (u)r[5] - (u)r[3]; if (c) goto L800d5790;
    r[4] = r[2] & 4095;
    r[2] = (int)r[4] < 1024;
    c = ((r[2] == 0)); r[2] = (int)r[4] < 3073; if (c) goto L800d5784;
    r[5] = (u)r[3] + 1024;
    L800d5784:;
    c = ((r[2] != 0));  if (c) goto L800d5790;
    r[5] = (u)r[3] + -1024;
    L800d5790:;
    r[2] = (u)r[5] + (u)0; goto out;
out:
    RECOMP_RETURN;
}
