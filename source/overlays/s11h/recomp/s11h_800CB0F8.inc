int G_s11h_800CB0F8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s11h_800CB0F8");
int G_s11h_800CB0F8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[2] = 0;
    c = (((int)r[5] <= 0)); r[4] = r[4] | r[2]; if (c) goto L800cb11c;
    L800cb104:;
    c = ((r[6] != r[4])); r[5] = (u)r[5] + -1; if (c) goto L800cb114;
    r[2] = (u)0 + 1; goto out;
    L800cb114:;
    c = (((int)r[5] > 0)); r[6] = (u)r[6] + 48; if (c) goto L800cb104;
    L800cb11c:;
    r[2] = (u)0 + (u)0; goto out;
out:
    RECOMP_RETURN;
}
