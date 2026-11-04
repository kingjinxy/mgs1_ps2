int G_s14e_800CD4A8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s14e_800CD4A8");
int G_s14e_800CD4A8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[6] = (u)r[4] + (u)0;
    r[4] = 0x10000;
    r[5] = *(int *)((u)r[6] + 2856);
    r[2] = *(int *)((u)r[6] + 2872);
    r[3] = *(unsigned short *)((u)r[6] + 3120);
    r[2] = r[2] | r[4];
    *(int *)((u)r[6] + 2872) = r[2];
    r[2] = (int)r[5] < 10;
    c = ((r[2] != 0)); *(short *)((u)r[6] + 2888) = r[3]; if (c) goto L800cd4e4;
    r[2] = (int)r[5] < 20;
    c = ((r[2] != 0)); r[2] = (u)0 + 1; if (c) goto L800cd500;
     goto out;
    L800cd4e4:;
    r[2] = r[5] & 1;
    c = ((r[2] != 0)); r[3] = 0x40000; if (c) goto L800cd500;
    r[2] = *(int *)((u)r[6] + 2872);
    r[2] = r[2] | r[3];
    *(int *)((u)r[6] + 2872) = r[2];
    L800cd500:;
    r[3] = *(int *)((u)r[6] + 2856);
    r[2] = (u)0 + (u)0;
    r[3] = (u)r[3] + 1;
    *(int *)((u)r[6] + 2856) = r[3]; goto out;
out:
    RECOMP_RETURN;
}
