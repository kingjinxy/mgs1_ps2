int G_s18a_800CC1F0(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s18a_800CC1F0");
int G_s18a_800CC1F0(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[5] = (u)r[4] + (u)0;
    r[2] = *(int *)((u)r[5] + 2376);
    c = (((int)r[2] <= 0)); r[2] = r[2] & 2; if (c) goto L800cc270;
    c = ((r[2] == 0)); r[4] = (u)0 + -129; if (c) goto L800cc228;
    r[3] = *(int *)((u)r[5] + 156);
    r[2] = *(int *)((u)r[3] + 40);
    r[2] = r[2] | 128;
    *(int *)((u)r[3] + 40) = r[2]; goto L800cc240;
    L800cc228:;
    r[2] = *(int *)((u)r[5] + 156);
    r[3] = *(int *)((u)r[2] + 40);
    r[3] = r[3] & r[4];
    *(int *)((u)r[2] + 40) = r[3];
    L800cc240:;
    r[2] = *(int *)((u)r[5] + 2236);
    r[4] = (u)0 + 1;
    *(short *)((u)r[2] + 0) = r[4];
    r[2] = *(int *)((u)r[5] + 2236);
    *(short *)((u)r[2] + 66) = 0;
    r[2] = *(int *)((u)r[5] + 2376);
    r[3] = *(int *)((u)r[5] + 2240);
    r[2] = (u)r[2] + -1;
    *(int *)((u)r[5] + 2376) = r[2];
    *(short *)((u)r[3] + 0) = r[4]; goto out;
    L800cc270:;
    *(int *)((u)r[5] + 2376) = 0; goto out;
out:
    RECOMP_RETURN;
}
