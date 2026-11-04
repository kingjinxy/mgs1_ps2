extern char R_s11b_dat_800C3348[] __asm__("s11b_dat_800C3348");
int G_s11b_800C79C4(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s11b_800C79C4");
int G_s11b_800C79C4(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[2] = 0;
    r[2] = *(int *)((u)r[2] + (int)R_s11b_dat_800C3348);
    c = ((r[2] == 0));  if (c) goto L800c79dc;
    *(int *)((u)r[2] + 92) = 0;
    L800c79dc:;
     goto out;
out:
    RECOMP_RETURN;
}
