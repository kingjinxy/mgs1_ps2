int G_s14e_800D96E8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s14e_800D96E8");
int G_s14e_800D96E8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[5] = (u)r[5] << 2;
    r[5] = (u)r[4] + (u)r[5];
    r[5] = *(int *)((u)r[5] + 84);
    c = ((r[5] == 0)); r[6] = (u)0 + 16383; if (c) goto L800d9748;
    r[3] = *(unsigned short *)((u)r[5] + 14);
    r[2] = (u)0 + 16383;
    c = ((r[3] == r[2]));  if (c) goto L800d9748;
    c = ((r[4] == 0));  if (c) goto L800d9748;
    L800d9718:;
    r[2] = *(short *)((u)r[4] + 82);
    c = (((int)r[2] <= 0));  if (c) goto L800d9738;
    L800d9728:;
    *(short *)((u)r[5] + 14) = r[6];
    r[2] = (u)r[2] + -1;
    c = (((int)r[2] > 0)); r[5] = (u)r[5] + 52; if (c) goto L800d9728;
    L800d9738:;
    r[4] = *(int *)((u)r[4] + 72);
    c = ((r[4] != 0));  if (c) goto L800d9718;
    L800d9748:;
     goto out;
out:
    RECOMP_RETURN;
}
