int G_s19a_800CC9D4(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s19a_800CC9D4");
int G_s19a_800CC9D4(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[5] = (u)r[4] + (u)0;
    r[3] = *(int *)((u)r[5] + 3100);
    r[2] = (int)r[3] < 16;
    c = ((r[2] != 0)); r[2] = (u)0 + 3; if (c) goto L800cc9f8;
    *(int *)((u)r[5] + 3096) = r[2];
    *(int *)((u)r[5] + 3100) = 0; goto out;
    L800cc9f8:;
    c = ((r[3] == 0));  if (c) goto L800cca10;
    c = ((r[3] == r[2])); r[2] = (u)0 + 6; if (c) goto L800cca10;
    c = ((r[3] != r[2]));  if (c) goto L800cca20;
    L800cca10:;
    r[2] = *(int *)((u)r[5] + 3068);
    r[2] = r[2] | 2;
    *(int *)((u)r[5] + 3068) = r[2];
    L800cca20:;
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
