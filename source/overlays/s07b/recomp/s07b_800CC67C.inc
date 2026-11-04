extern char R_s07b_dword_800E4FB4[] __asm__("s07b_dword_800E4FB4");
extern char R_printf[] __asm__("printf");
int G_s07b_800CC67C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s07b_800CC67C");
int G_s07b_800CC67C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 20) = r[31];
    r[2] = *(int *)((u)r[16] + 2288);
    c = ((r[2] == 0));  if (c) goto L800cc6bc;
    r[2] = *(int *)((u)r[2] + 0);
    c = (((int)r[2] > 0));  if (c) goto L800cc6bc;
    r[4] = 0;
    r[4] = (u)r[4] + (int)R_s07b_dword_800E4FB4; CALL(R_printf);
    *(int *)((u)r[16] + 2288) = 0;
    L800cc6bc:;
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
