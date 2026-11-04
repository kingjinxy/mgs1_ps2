int G_s10a_800CC95C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s10a_800CC95C");
int G_s10a_800CC95C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[2] = *(int *)((u)r[4] + 2856);
    c = ((r[2] == 0)); r[2] = (int)r[2] < 33; if (c) goto L800cc97c;
    c = ((r[2] != 0)); r[2] = (u)0 + 1; if (c) goto L800cc984;
     goto out;
    L800cc97c:;
    r[2] = (u)0 + 245;
    *(short *)((u)r[4] + 2890) = r[2];
    L800cc984:;
    r[3] = *(int *)((u)r[4] + 2856);
    r[2] = (u)0 + (u)0;
    r[3] = (u)r[3] + 1;
    *(int *)((u)r[4] + 2856) = r[3]; goto out;
out:
    RECOMP_RETURN;
}
