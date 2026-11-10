int G_s18a_800C4014(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s18a_800C4014");
int G_s18a_800C4014(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[2] = *(short *)((u)r[4] + 10);
    c = ((r[2] == 0));  if (c) goto L800c4038;
    r[2] = *(unsigned short *)((u)r[4] + 0);
    r[2] = r[2] & 61440;
    c = ((r[2] != 0)); r[4] = (u)r[4] + 14; if (c) goto L800c4048;
    L800c4038:;
    r[2] = (u)0 + (u)0; goto out;
    L800c4040:;
    r[2] = (u)0 + 1; goto out;
    L800c4048:;
    r[3] = (u)0 + (u)0;
    L800c404c:;
    r[2] = *(unsigned char *)((u)r[4] + 0);
    r[2] = (u)r[2] + -64;
    r[2] = r[2] & 255;
    r[2] = (u)r[2] < (u)129;
    c = ((r[2] == 0)); r[3] = (u)r[3] + 1; if (c) goto L800c4040;
    r[2] = (int)r[3] < 2;
    c = ((r[2] != 0)); r[4] = (u)r[4] + 1; if (c) goto L800c404c;
    r[2] = (u)0 + (u)0; goto out;
out:
    RECOMP_RETURN;
}
