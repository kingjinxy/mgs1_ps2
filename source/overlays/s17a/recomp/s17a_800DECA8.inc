int G_s17a_800DECA8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s17a_800DECA8");
int G_s17a_800DECA8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[5] = *(int *)((u)r[4] + 176);
    r[2] = *(int *)((u)r[5] + 4);
    r[3] = (u)0 + 1;
    c = ((r[2] == r[3]));  if (c) goto L800decdc;
    *(short *)((u)r[5] + 24) = r[3];
    r[2] = *(int *)((u)r[4] + 404);
    *(short *)((u)r[2] + 24) = r[3];
    r[2] = *(int *)((u)r[4] + 632);
    *(short *)((u)r[2] + 24) = r[3];
    L800decdc:;
     goto out;
out:
    RECOMP_RETURN;
}
