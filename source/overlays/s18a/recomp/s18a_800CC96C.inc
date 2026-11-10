int G_s18a_800CC96C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s18a_800CC96C");
int G_s18a_800CC96C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[2] = *(unsigned short *)((u)r[4] + 0);
    r[2] = (u)r[2] + -376;
    r[2] = (u)r[2] < (u)3999;
    c = ((r[2] == 0));  if (c) goto L800cc9a0;
    r[3] = *(short *)((u)r[4] + 4);
    r[2] = (int)r[3] < 1001;
    c = ((r[2] != 0)); r[2] = (int)r[3] < -1000; if (c) goto L800cc9a0;
    c = ((r[2] != 0)); r[2] = (u)0 + -1; if (c) goto L800cc9dc;
    L800cc9a0:;
    r[2] = *(short *)((u)r[4] + 0);
    r[2] = (int)r[2] < 2251;
    c = ((r[2] != 0));  if (c) goto L800cc9c0;
    r[2] = *(short *)((u)r[4] + 4);
    r[3] = (int)r[2] < 1; goto L800cc9d4;
    L800cc9c0:;
    r[2] = *(short *)((u)r[4] + 4);
    c = (((int)r[2] <= 0)); r[3] = (u)0 + 3; if (c) goto L800cc9d4;
    r[3] = (u)0 + 2;
    L800cc9d4:;
    r[2] = (u)r[3] + (u)0; goto out;
    L800cc9dc:;
     goto out;
out:
    RECOMP_RETURN;
}
