int G_s19a_800D4C7C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s19a_800D4C7C");
int G_s19a_800D4C7C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[5] = (u)r[4] + (u)0;
    r[2] = 0x20000;
    r[3] = *(int *)((u)r[5] + 2872);
    r[4] = *(unsigned short *)((u)r[5] + 3116);
    r[6] = *(int *)((u)r[5] + 2856);
    r[3] = r[3] | r[2];
    *(int *)((u)r[5] + 2872) = r[3];
    c = ((r[6] == 0)); *(short *)((u)r[5] + 2888) = r[4]; if (c) goto L800d4cb4;
    r[2] = (u)0 + 8;
    c = ((r[6] != r[2])); r[2] = (u)0 + 1; if (c) goto L800d4cc4;
     goto out;
    L800d4cb4:;
    r[2] = *(int *)((u)r[5] + 2872);
    r[3] = 0x80000;
    r[2] = r[2] | r[3];
    *(int *)((u)r[5] + 2872) = r[2];
    L800d4cc4:;
    r[3] = *(int *)((u)r[5] + 2856);
    r[2] = (u)0 + (u)0;
    r[3] = (u)r[3] + 1;
    *(int *)((u)r[5] + 2856) = r[3]; goto out;
out:
    RECOMP_RETURN;
}
