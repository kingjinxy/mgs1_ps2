extern char R_s07b_800C54E8[] __asm__("s07b_800C54E8");
int G_s07b_800C5514(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s07b_800C5514");
int G_s07b_800C5514(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[31];
    r[2] = *(short *)((u)r[4] + 2242);
    r[3] = *(unsigned short *)((u)r[4] + 2242);
    c = ((r[2] == 0)); r[2] = (u)r[3] + -1; if (c) goto L800c5544;
    *(short *)((u)r[4] + 2242) = r[2];
    r[2] = (u)r[2] << 16;
    c = ((r[2] != 0));  if (c) goto L800c5544;
     CALL(R_s07b_800C54E8);
    L800c5544:;
    r[31] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
