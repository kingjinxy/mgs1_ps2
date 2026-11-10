int G_s18a_800DB1EC(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s18a_800DB1EC");
int G_s18a_800DB1EC(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[2] = *(int *)((u)r[4] + 2212);
    r[5] = *(unsigned short *)((u)r[2] + 0);
    r[2] = r[5] & 40960;
    c = ((r[2] == 0)); r[2] = r[5] & 32768; if (c) goto L800db224;
    r[3] = *(short *)((u)r[4] + 110);
    c = ((r[2] == 0));  if (c) goto L800db21c;
    r[3] = (u)r[3] + 32; goto L800db220;
    L800db21c:;
    r[3] = (u)r[3] + -32;
    L800db220:;
    *(short *)((u)r[4] + 110) = r[3];
    L800db224:;
     goto out;
out:
    RECOMP_RETURN;
}
