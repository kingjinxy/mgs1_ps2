int G_s18a_800D96D8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s18a_800D96D8");
int G_s18a_800D96D8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[31];
    r[2] = *(unsigned char *)((u)r[4] + 2021);
    r[2] = r[2] & 1;
    c = ((r[2] == 0));  if (c) goto L800d9714;
    r[5] = *(int *)((u)r[4] + 2232);
    r[2] = (u)r[5] + 1;
    *(int *)((u)r[4] + 2232) = r[2];
    r[2] = *(int *)((u)r[4] + 2228);
    t = r[2];  CALL((int (*)())t);
    L800d9714:;
    r[31] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
