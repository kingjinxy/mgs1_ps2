extern char R_s19a_dat_800E0E28[] __asm__("s19a_dat_800E0E28");
int G_s19a_800DD430(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s19a_800DD430");
int G_s19a_800DD430(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[2] = 0;
    r[3] = (u)r[2] + (int)R_s19a_dat_800E0E28;
    r[2] = *(int *)((u)r[3] + 40);
    c = ((r[2] != 0));  if (c) goto L800dd458;
    r[2] = *(int *)((u)r[3] + 12);
    r[2] = (u)r[2] + 1;
    *(int *)((u)r[3] + 12) = r[2];
    L800dd458:;
     goto out;
out:
    RECOMP_RETURN;
}
