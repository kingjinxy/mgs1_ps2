extern char R_s19a_800D2B80[] __asm__("s19a_800D2B80");
int G_s19a_800D4AF8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s19a_800D4AF8");
int G_s19a_800D4AF8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 20) = r[31];
    r[2] = *(int *)((u)r[16] + 76);
    r[5] = *(signed char *)((u)r[16] + 2972);
    r[4] = *(int *)((u)r[2] + 8);
     CALL(R_s19a_800D2B80);
    c = (((int)r[2] >= 0));  if (c) goto L800d4b34;
    r[2] = (u)0 + -1;
    *(char *)((u)r[16] + 2972) = r[2];
    r[2] = (u)0 + (u)0; goto L800d4b3c;
    L800d4b34:;
    *(char *)((u)r[16] + 2972) = r[2];
    r[2] = (u)0 + 1;
    L800d4b3c:;
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
