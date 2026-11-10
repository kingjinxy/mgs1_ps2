int G_s17a_800C6E20(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s17a_800C6E20");
int G_s17a_800C6E20(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[2] = (int)r[4] < (int)r[5];
    c = ((r[2] == 0)); r[2] = (int)r[5] < (int)r[6]; if (c) goto L800c6e34;
    r[5] = (u)r[4] + (u)0;
    r[2] = (int)r[5] < (int)r[6];
    L800c6e34:;
    c = ((r[2] == 0));  if (c) goto L800c6e40;
    r[6] = (u)r[5] + (u)0;
    L800c6e40:;
    r[2] = (u)r[6] + (u)0; goto out;
out:
    RECOMP_RETURN;
}
