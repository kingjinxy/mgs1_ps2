extern char R_s18a_dat_800E4354[] __asm__("s18a_dat_800E4354");
extern char R_s18a_dat_800E4368[] __asm__("s18a_dat_800E4368");
int G_s18a_800D5A40(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s18a_800D5A40");
int G_s18a_800D5A40(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[2] = 0;
    r[2] = *(int *)((u)r[2] + (int)R_s18a_dat_800E4354);
    r[2] = *(unsigned char *)((u)r[2] + 0);
    r[2] = r[2] & 144;
    c = ((r[2] == 0)); r[2] = 0; if (c) goto L800d5a68;
    r[2] = (u)0 + (u)0; goto out;
    L800d5a68:;
    r[3] = *(int *)((u)r[2] + (int)R_s18a_dat_800E4368);
    r[2] = *(short *)((u)r[3] + 4);
    r[3] = *(short *)((u)r[3] + 6);
    r[4] = *(short *)((u)r[4] + 34);
    r[3] = (u)r[2] + (u)r[3];
    r[2] = (int)r[2] < (int)r[4];
    c = ((r[2] == 0)); r[3] = (int)r[4] < (int)r[3]; if (c) goto L800d5a94;
    c = ((r[3] != 0)); r[2] = (u)0 + 1; if (c) goto L800d5a98;
    L800d5a94:;
    r[2] = (u)0 + (u)0;
    L800d5a98:;
     goto out;
out:
    RECOMP_RETURN;
}
