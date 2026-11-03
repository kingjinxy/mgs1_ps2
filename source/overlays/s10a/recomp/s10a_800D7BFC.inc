int G_s10a_800D7BFC(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s10a_800D7BFC");
int G_s10a_800D7BFC(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(0)
    r[2] = *(int *)((u)r[4] + 1628);
    r[3] = (u)0 + 21;
    *(short *)((u)r[2] + 0) = r[3];
    r[2] = *(int *)((u)r[4] + 1632);
    *(short *)((u)r[2] + 0) = r[3];
    r[2] = *(unsigned short *)((u)r[4] + 184);
    r[3] = (u)r[4] + 36;
    *(short *)((u)r[3] + 50) = r[2];
    r[2] = *(int *)((u)r[4] + 1724);
    c = (((int)r[2] >= 0)); r[2] = (u)r[2] + -16; if (c) goto L800d7c50;
    r[2] = *(signed char *)((u)r[3] + 87);
    c = ((r[2] == 0));  if (c) goto L800d7c44;
    *(int *)((u)r[4] + 1724) = 0;
    L800d7c44:;
    r[2] = *(int *)((u)r[4] + 1724);
    r[2] = (u)r[2] + -16;
    L800d7c50:;
    *(int *)((u)r[4] + 1724) = r[2];
    r[2] = *(unsigned short *)((u)r[4] + 1724);
    *(short *)((u)r[3] + 70) = r[2]; goto out;
out:
    RECOMP_RETURN;
}
