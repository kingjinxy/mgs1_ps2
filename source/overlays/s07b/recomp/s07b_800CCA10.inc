int G_s07b_800CCA10(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s07b_800CCA10");
int G_s07b_800CCA10(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(0)
    r[5] = (u)r[4] + (u)0;
    r[2] = *(int *)((u)r[5] + 2124);
    r[4] = *(int *)((u)r[5] + 2016);
    r[3] = (u)0 + -3;
    *(char *)((u)r[5] + 2658) = 0;
    r[2] = r[2] & r[3];
    *(int *)((u)r[5] + 2124) = r[2];
    r[2] = *(int *)((u)r[5] + 2128);
    r[3] = (u)0 + -513;
    r[2] = r[2] & r[3];
    *(int *)((u)r[5] + 2128) = r[2];
    r[2] = *(unsigned short *)((u)r[4] + 0);
    r[2] = r[2] | 156;
    *(short *)((u)r[4] + 0) = r[2];
    r[2] = *(int *)((u)r[5] + 2128);
    r[2] = r[2] & 1;
    c = ((r[2] != 0)); r[4] = (u)0 + -129; if (c) goto L800cca78;
    r[2] = *(int *)((u)r[5] + 156);
    r[3] = *(int *)((u)r[2] + 40);
    r[3] = r[3] & r[4];
    *(int *)((u)r[2] + 40) = r[3];
    L800cca78:;
     goto out;
out:
    RECOMP_RETURN;
}
