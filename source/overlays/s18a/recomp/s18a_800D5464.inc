int G_s18a_800D5464(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s18a_800D5464");
int G_s18a_800D5464(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[2] = (u)0 + -16385;
    r[3] = *(int *)((u)r[4] + 2020);
    r[5] = *(int *)((u)r[4] + 2212);
    r[3] = r[3] & r[2];
    *(int *)((u)r[4] + 2020) = r[3];
    r[2] = *(short *)((u)r[5] + 10);
    c = ((r[2] == 0));  if (c) goto L800d54d8;
    r[2] = *(unsigned short *)((u)r[5] + 0);
    r[2] = r[2] & 61440;
    c = ((r[2] == 0)); r[5] = (u)r[5] + 12; if (c) goto L800d54d8;
    r[3] = (u)0 + (u)0;
    L800d54a0:;
    r[2] = *(unsigned char *)((u)r[5] + 0);
    r[2] = (u)r[2] + -80;
    r[2] = (u)r[2] < (u)97;
    c = ((r[2] != 0)); r[3] = (u)r[3] + 1; if (c) goto L800d54cc;
    r[2] = *(int *)((u)r[4] + 2020);
    r[2] = r[2] | 16384;
    *(int *)((u)r[4] + 2020) = r[2]; goto out;
    L800d54cc:;
    r[2] = (int)r[3] < 4;
    c = ((r[2] != 0)); r[5] = (u)r[5] + 1; if (c) goto L800d54a0;
    L800d54d8:;
     goto out;
out:
    RECOMP_RETURN;
}
