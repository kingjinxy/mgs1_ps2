extern char R_s11h_dat_800C3330[] __asm__("s11h_dat_800C3330");
int G_s11h_800C7A24(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s11h_800C7A24");
int G_s11h_800C7A24(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[2] = 0;
    r[2] = *(int *)((u)r[2] + (int)R_s11h_dat_800C3330);
    c = ((r[2] == 0));  if (c) goto L800c7a3c;
    *(int *)((u)r[2] + 92) = 0;
    L800c7a3c:;
     goto out;
out:
    RECOMP_RETURN;
}
