int G_s19a_800CB468(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s19a_800CB468");
int G_s19a_800CB468(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[2] = *(int *)((u)r[4] + 32);
    r[2] = (u)r[2] + 16;
    r[4] = *(short *)((u)r[2] + 6);
    c = (((int)r[4] <= 0)); r[3] = (u)0 + (u)0; if (c) goto L800cb4b0;
    r[6] = (u)r[4] + (u)0;
    r[4] = (u)r[2] + (u)0;
    L800cb48c:;
    r[2] = *(unsigned short *)((u)r[4] + 8);
    c = ((r[2] != r[5])); r[3] = (u)r[3] + 1; if (c) goto L800cb4a4;
    r[2] = (u)0 + 1; goto out;
    L800cb4a4:;
    r[2] = (int)r[3] < (int)r[6];
    c = ((r[2] != 0)); r[4] = (u)r[4] + 2; if (c) goto L800cb48c;
    L800cb4b0:;
    r[2] = (u)0 + (u)0; goto out;
out:
    RECOMP_RETURN;
}
