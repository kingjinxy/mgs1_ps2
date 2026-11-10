extern char R_s17a_dat_800C34C4[] __asm__("s17a_dat_800C34C4");
int G_s17a_800CB054(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s17a_800CB054");
int G_s17a_800CB054(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[2] = 0;
    r[2] = *(int *)((u)r[2] + (int)R_s17a_dat_800C34C4);
    c = ((r[2] == 0));  if (c) goto L800cb06c;
    *(int *)((u)r[2] + 92) = 0;
    L800cb06c:;
     goto out;
out:
    RECOMP_RETURN;
}
