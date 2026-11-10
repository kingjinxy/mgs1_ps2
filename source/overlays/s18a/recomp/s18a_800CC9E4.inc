int G_s18a_800CC9E4(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s18a_800CC9E4");
int G_s18a_800CC9E4(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[5] = *(short *)((u)r[4] + 4);
    r[2] = (int)r[5] < 2251;
    c = ((r[2] == 0)); r[3] = (u)0 + 4; if (c) goto L800cca18;
    r[2] = *(short *)((u)r[4] + 0);
    r[2] = (int)r[2] < 2251;
    c = ((r[2] == 0)); r[3] = (int)r[5] < 1; if (c) goto L800cca18;
    c = (((int)r[5] <= 0)); r[3] = (u)0 + 3; if (c) goto L800cca18;
    r[3] = (u)0 + 2;
    L800cca18:;
    r[2] = (u)r[3] + (u)0; goto out;
out:
    RECOMP_RETURN;
}
