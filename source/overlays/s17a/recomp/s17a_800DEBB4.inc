int G_s17a_800DEBB4(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s17a_800DEBB4");
int G_s17a_800DEBB4(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[3] = *(int *)((u)r[4] + 6496);
    r[2] = (u)0 + 1;
    c = ((r[3] != r[2]));  if (c) goto L800debe4;
    r[2] = *(int *)((u)r[4] + 6484);
    c = ((r[2] == r[5])); r[2] = (u)0 + 1; if (c) goto L800debe4;
    *(int *)((u)r[4] + 6484) = r[5];
    *(int *)((u)r[4] + 6488) = r[6];
    *(int *)((u)r[4] + 6496) = 0; goto out;
    L800debe4:;
    r[2] = (u)0 + (u)0; goto out;
out:
    RECOMP_RETURN;
}
