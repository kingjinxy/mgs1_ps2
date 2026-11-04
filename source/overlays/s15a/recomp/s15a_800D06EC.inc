int G_s15a_800D06EC(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s15a_800D06EC");
int G_s15a_800D06EC(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[5] = (u)r[5] << 2;
    r[4] = (u)r[4] + (u)r[5];
    r[2] = *(int *)((u)r[4] + 16144);
    r[2] = (u)r[2] + -1;
    c = ((r[2] != 0)); *(int *)((u)r[4] + 16144) = r[2]; if (c) goto L800d0718;
    r[2] = *(int *)((u)r[4] + 16160);
    r[2] = (u)r[2] + 1;
    *(int *)((u)r[4] + 16160) = r[2];
    L800d0718:;
     goto out;
out:
    RECOMP_RETURN;
}
