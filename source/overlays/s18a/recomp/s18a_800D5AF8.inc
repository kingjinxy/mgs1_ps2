int G_s18a_800D5AF8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s18a_800D5AF8");
int G_s18a_800D5AF8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    c = ((r[5] != 0)); r[2] = (u)0 + 1; if (c) goto L800d5b1c;
    r[2] = *(int *)((u)r[4] + 2216);
    r[2] = *(int *)((u)r[2] + 0);
    r[2] = *(unsigned char *)((u)r[2] + 0);
    L800d5b14:;
     goto out;
    L800d5b1c:;
    c = ((r[5] != r[2])); r[2] = (u)0 + 2; if (c) goto L800d5b40;
    r[2] = *(int *)((u)r[4] + 2216);
    r[2] = *(int *)((u)r[2] + 0);
    r[2] = *(unsigned char *)((u)r[2] + 2);
     goto out;
    L800d5b40:;
    c = ((r[5] != r[2])); r[2] = (u)0 + -1; if (c) goto L800d5b14;
    r[2] = *(int *)((u)r[4] + 2216);
    r[2] = *(int *)((u)r[2] + 0);
    r[2] = *(unsigned char *)((u)r[2] + 3);
     goto out;
out:
    RECOMP_RETURN;
}
