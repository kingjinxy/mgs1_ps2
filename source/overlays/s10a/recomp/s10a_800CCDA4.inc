int G_s10a_800CCDA4(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s10a_800CCDA4");
int G_s10a_800CCDA4(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(0)
    r[5] = (u)r[4] + (u)0;
    r[2] = *(int *)((u)r[5] + 2884);
    c = ((r[2] == 0));  if (c) goto L800ccdd8;
    r[2] = *(int *)((u)r[5] + 2872);
    r[4] = *(int *)((u)r[5] + 2880);
    r[3] = *(int *)((u)r[5] + 2884);
    r[2] = r[2] | r[4];
    r[3] = (u)r[3] + -1;
    *(int *)((u)r[5] + 2872) = r[2];
    *(int *)((u)r[5] + 2884) = r[3]; goto L800ccde8;
    L800ccdd8:;
    r[3] = *(int *)((u)r[5] + 2288);
    c = ((r[3] == 0)); r[2] = (u)0 + 1; if (c) goto L800ccdec;
    L800ccde8:;
    r[2] = (u)0 + (u)0;
    L800ccdec:;
     goto out;
out:
    RECOMP_RETURN;
}
