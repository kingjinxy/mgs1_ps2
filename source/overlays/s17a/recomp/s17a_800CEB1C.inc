int G_s17a_800CEB1C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s17a_800CEB1C");
int G_s17a_800CEB1C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[2] = 0;
    c = (((int)r[5] <= 0)); r[4] = r[4] | r[2]; if (c) goto L800ceb40;
    L800ceb28:;
    c = ((r[6] != r[4])); r[5] = (u)r[5] + -1; if (c) goto L800ceb38;
    r[2] = (u)0 + 1; goto out;
    L800ceb38:;
    c = (((int)r[5] > 0)); r[6] = (u)r[6] + 48; if (c) goto L800ceb28;
    L800ceb40:;
    r[2] = (u)0 + (u)0; goto out;
out:
    RECOMP_RETURN;
}
