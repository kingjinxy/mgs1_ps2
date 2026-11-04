extern char R_s10a_dat_800C3728[] __asm__("s10a_dat_800C3728");
int G_s10a_800D4B04(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s10a_800D4B04");
int G_s10a_800D4B04(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[2] = 0;
    r[2] = *(int *)((u)r[2] + (int)R_s10a_dat_800C3728);
    c = ((r[2] == 0));  if (c) goto L800d4b1c;
    *(int *)((u)r[2] + 92) = 0;
    L800d4b1c:;
     goto out;
out:
    RECOMP_RETURN;
}
