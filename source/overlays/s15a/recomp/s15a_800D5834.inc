int G_s15a_800D5834(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s15a_800D5834");
int G_s15a_800D5834(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    c = (((int)r[5] <= 0));  if (c) goto L800d5854;
    L800d583c:;
    c = ((r[6] != r[4])); r[5] = (u)r[5] + -1; if (c) goto L800d584c;
    r[2] = (u)0 + 1; goto out;
    L800d584c:;
    c = (((int)r[5] > 0)); r[6] = (u)r[6] + 16; if (c) goto L800d583c;
    L800d5854:;
    r[2] = (u)0 + (u)0; goto out;
out:
    RECOMP_RETURN;
}
