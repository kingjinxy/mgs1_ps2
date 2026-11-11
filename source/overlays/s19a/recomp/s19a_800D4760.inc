int G_s19a_800D4760(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s19a_800D4760");
int G_s19a_800D4760(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    *(short *)((u)r[16] + 2888) = r[2];
    *(short *)((u)r[16] + 2888) = r[2];
    r[3] = *(int *)((u)r[16] + 2856);
    r[2] = (u)r[3] < (u)16;
    c = ((r[2] == 0)); r[2] = (u)r[3] + 1; if (c) goto L800d4788;
    *(int *)((u)r[16] + 2856) = r[2];
    r[2] = (u)0 + (u)0; goto L800d478c;
    L800d4788:;
    r[2] = (u)0 + 1;
    L800d478c:;
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
