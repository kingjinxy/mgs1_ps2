int G_s10a_800C52D8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s10a_800C52D8");
int G_s10a_800C52D8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(0)
    r[2] = *(int *)((u)r[4] + 336);
    c = ((r[2] == 0));  if (c) goto L800c5304;
    r[2] = *(int *)((u)r[4] + 32);
    r[3] = *(int *)((u)r[2] + 40);
    r[4] = (u)0 + -129;
    r[3] = r[3] & r[4];
    *(int *)((u)r[2] + 40) = r[3]; goto out;
    L800c5304:;
    r[3] = *(int *)((u)r[4] + 32);
    r[2] = *(int *)((u)r[3] + 40);
    r[2] = r[2] | 128;
    *(int *)((u)r[3] + 40) = r[2]; goto out;
out:
    return r[2];
}
