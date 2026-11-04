int G_s15a_800CAAA8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s15a_800CAAA8");
int G_s15a_800CAAA8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[3] = *(int *)((u)r[4] + 1680);
    r[2] = (int)r[3] < 48;
    c = ((r[2] != 0)); r[2] = (int)r[3] < 144; if (c) goto L800caadc;
    c = ((r[2] == 0));  if (c) goto L800caad0;
    r[2] = *(unsigned short *)((u)r[4] + 1494);
    r[2] = (u)r[2] + -8; goto L800caae8;
    L800caad0:;
    r[2] = (int)r[3] < 192;
    c = ((r[2] == 0));  if (c) goto L800caaec;
    L800caadc:;
    r[2] = *(unsigned short *)((u)r[4] + 1494);
    r[2] = (u)r[2] + 8;
    L800caae8:;
    *(short *)((u)r[4] + 1494) = r[2];
    L800caaec:;
    r[2] = *(int *)((u)r[4] + 1680);
    r[2] = (u)r[2] + 1;
    *(int *)((u)r[4] + 1680) = r[2];
    r[2] = (int)r[2] < 192;
    c = ((r[2] != 0));  if (c) goto L800cab0c;
    *(int *)((u)r[4] + 1680) = 0;
    L800cab0c:;
     goto out;
out:
    RECOMP_RETURN;
}
