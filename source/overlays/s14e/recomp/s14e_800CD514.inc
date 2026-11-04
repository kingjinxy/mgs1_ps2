int G_s14e_800CD514(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s14e_800CD514");
int G_s14e_800CD514(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[7] = (u)r[4] + (u)0;
    r[2] = *(int *)((u)r[7] + 2856);
    r[2] = (int)r[2] < 201;
    c = ((r[2] == 0)); r[2] = (u)0 + (u)0; if (c) goto L800cd554;
    r[5] = 0x10000;
    r[3] = *(int *)((u)r[7] + 2872);
    r[6] = *(unsigned short *)((u)r[7] + 3120);
    r[4] = *(int *)((u)r[7] + 2856);
    r[3] = r[3] | r[5];
    r[4] = (u)r[4] + 1;
    *(int *)((u)r[7] + 2872) = r[3];
    *(short *)((u)r[7] + 2888) = r[6];
    *(int *)((u)r[7] + 2856) = r[4]; goto out;
    L800cd554:;
    r[2] = (u)0 + 1; goto out;
out:
    RECOMP_RETURN;
}
