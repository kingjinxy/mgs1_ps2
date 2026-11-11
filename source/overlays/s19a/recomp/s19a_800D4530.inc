int G_s19a_800D4530(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s19a_800D4530");
int G_s19a_800D4530(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[5] = (u)r[4] + (u)0;
    r[2] = *(int *)((u)r[5] + 2884);
    c = ((r[2] == 0));  if (c) goto L800d4564;
    r[2] = *(int *)((u)r[5] + 2872);
    r[4] = *(int *)((u)r[5] + 2880);
    r[3] = *(int *)((u)r[5] + 2884);
    r[2] = r[2] | r[4];
    r[3] = (u)r[3] + -1;
    *(int *)((u)r[5] + 2872) = r[2];
    *(int *)((u)r[5] + 2884) = r[3]; goto L800d4574;
    L800d4564:;
    r[3] = *(int *)((u)r[5] + 2288);
    c = ((r[3] == 0)); r[2] = (u)0 + 1; if (c) goto L800d4578;
    L800d4574:;
    r[2] = (u)0 + (u)0;
    L800d4578:;
     goto out;
out:
    RECOMP_RETURN;
}
