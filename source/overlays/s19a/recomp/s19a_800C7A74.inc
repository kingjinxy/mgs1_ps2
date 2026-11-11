extern char R_s19a_dat_800E0530[] __asm__("s19a_dat_800E0530");
int G_s19a_800C7A74(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s19a_800C7A74");
int G_s19a_800C7A74(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[2] = 0;
    r[4] = (u)r[2] + (int)R_s19a_dat_800E0530;
    r[2] = *(int *)((u)r[4] + 8);
    c = (((int)r[2] <= 0)); r[3] = (u)0 + (u)0; if (c) goto L800c7aac;
    r[6] = (u)0 + 255;
    r[5] = (u)r[4] + (u)0;
    L800c7a94:;
    *(int *)((u)r[4] + 328) = r[6];
    r[2] = *(int *)((u)r[5] + 8);
    r[3] = (u)r[3] + 1;
    r[2] = (int)r[3] < (int)r[2];
    c = ((r[2] != 0)); r[4] = (u)r[4] + 4; if (c) goto L800c7a94;
    L800c7aac:;
     goto out;
out:
    RECOMP_RETURN;
}
