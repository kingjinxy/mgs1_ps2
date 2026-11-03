int G_s10a_800C91B8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s10a_800C91B8");
int G_s10a_800C91B8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(0)
    r[5] = (u)r[4] + (u)0;
    r[3] = *(int *)((u)r[5] + 3100);
    r[2] = (int)r[3] < 16;
    c = ((r[2] != 0)); r[2] = (u)0 + 3; if (c) goto L800c91dc;
    *(int *)((u)r[5] + 3096) = r[2];
    *(int *)((u)r[5] + 3100) = 0; goto out;
    L800c91dc:;
    c = ((r[3] == 0));  if (c) goto L800c91f4;
    c = ((r[3] == r[2])); r[2] = (u)0 + 6; if (c) goto L800c91f4;
    c = ((r[3] != r[2]));  if (c) goto L800c9204;
    L800c91f4:;
    r[2] = *(int *)((u)r[5] + 3068);
    r[2] = r[2] | 2;
    *(int *)((u)r[5] + 3068) = r[2];
    L800c9204:;
    r[2] = *(int *)((u)r[5] + 3068);
    r[4] = *(unsigned short *)((u)r[5] + 3592);
    r[3] = *(int *)((u)r[5] + 3100);
    r[2] = r[2] | 1;
    r[3] = (u)r[3] + 1;
    *(int *)((u)r[5] + 3068) = r[2];
    *(short *)((u)r[5] + 3082) = r[4];
    *(int *)((u)r[5] + 3100) = r[3]; goto out;
out:
    RECOMP_RETURN;
}
