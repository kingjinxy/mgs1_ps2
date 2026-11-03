int G_s10a_800CD138(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s10a_800CD138");
int G_s10a_800CD138(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(0)
    r[5] = (u)r[4] + (u)0;
    r[3] = *(int *)((u)r[5] + 2872);
    r[2] = 0x10000;
    r[4] = r[3] | r[2];
    r[3] = *(int *)((u)r[5] + 2856);
    r[2] = (u)0 + 30;
    c = ((r[3] == r[2])); *(int *)((u)r[5] + 2872) = r[4]; if (c) goto L800cd170;
    r[2] = *(short *)((u)r[5] + 182);
    c = ((r[2] == 0)); r[2] = (u)0 + (u)0; if (c) goto L800cd180;
    r[2] = (u)0 + 1; goto out;
    L800cd170:;
    r[2] = 0x100000;
    r[2] = r[4] | r[2];
    *(int *)((u)r[5] + 2872) = r[2];
    r[2] = (u)0 + (u)0;
    L800cd180:;
    r[3] = *(int *)((u)r[5] + 2856);
    r[4] = *(unsigned short *)((u)r[5] + 3116);
    r[3] = (u)r[3] + 1;
    *(short *)((u)r[5] + 2888) = r[4];
    *(int *)((u)r[5] + 2856) = r[3]; goto out;
out:
    return r[2];
}
