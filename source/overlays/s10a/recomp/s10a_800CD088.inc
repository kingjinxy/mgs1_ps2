int G_s10a_800CD088(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s10a_800CD088");
int G_s10a_800CD088(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[5] = (u)r[4] + (u)0;
    r[3] = 0x10000;
    r[2] = *(int *)((u)r[5] + 2872);
    r[4] = *(int *)((u)r[5] + 2856);
    r[3] = r[2] | r[3];
    c = ((r[4] == 0)); *(int *)((u)r[5] + 2872) = r[3]; if (c) goto L800cd0b8;
    r[2] = (u)0 + 4;
    c = ((r[4] != r[2])); r[2] = (u)0 + (u)0; if (c) goto L800cd0c8;
    r[2] = (u)0 + 1; goto out;
    L800cd0b8:;
    r[2] = 0x40000;
    r[2] = r[3] | r[2];
    *(int *)((u)r[5] + 2872) = r[2];
    r[2] = (u)0 + (u)0;
    L800cd0c8:;
    r[3] = *(int *)((u)r[5] + 2856);
    r[4] = *(unsigned short *)((u)r[5] + 3116);
    r[3] = (u)r[3] + 1;
    *(short *)((u)r[5] + 2888) = r[4];
    *(int *)((u)r[5] + 2856) = r[3]; goto out;
out:
    RECOMP_RETURN;
}
