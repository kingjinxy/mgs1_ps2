int G_s11h_800C42F8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s11h_800C42F8");
int G_s11h_800C42F8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[5] = (u)r[5] + -1;
    c = (((int)r[5] < 0));  if (c) goto L800c431c;
    L800c4304:;
    r[2] = *(int *)((u)r[6] + 0);
    r[6] = (u)r[6] + 4;
    r[5] = (u)r[5] + -1;
    *(int *)((u)r[4] + 4) = r[2];
    c = (((int)r[5] >= 0)); r[4] = (u)r[4] + 16; if (c) goto L800c4304;
    L800c431c:;
     goto out;
out:
    RECOMP_RETURN;
}
