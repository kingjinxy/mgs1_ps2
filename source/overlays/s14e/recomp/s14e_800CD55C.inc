int G_s14e_800CD55C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s14e_800CD55C");
int G_s14e_800CD55C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[5] = (u)r[4] + (u)0;
    r[2] = *(int *)((u)r[5] + 3116);
    r[2] = (int)r[2] < 800;
    c = ((r[2] != 0)); r[2] = (u)0 + 1; if (c) goto L800cd590;
    r[2] = (u)0 + (u)0;
    r[3] = *(int *)((u)r[5] + 2856);
    r[4] = *(unsigned short *)((u)r[5] + 3120);
    r[3] = (u)r[3] + 1;
    *(short *)((u)r[5] + 2888) = r[4];
    *(int *)((u)r[5] + 2856) = r[3]; goto out;
    L800cd590:;
    r[3] = *(int *)((u)r[5] + 2872);
    r[4] = 0x10000;
    r[3] = r[3] | r[4];
    *(int *)((u)r[5] + 2872) = r[3]; goto out;
out:
    RECOMP_RETURN;
}
