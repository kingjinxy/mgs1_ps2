int G_s08b_bunsin2_800CE800(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s08b_bunsin2_800CE800");
int G_s08b_bunsin2_800CE800(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[2] = *(short *)((u)r[4] + 42);
    c = (((int)r[2] >= 0));  if (c) goto L800ce814;
    r[2] = (u)r[2] + 1023;
    L800ce814:;
    r[2] = (int)r[2] >> 10;
    r[3] = (u)r[2] << 10;
    r[5] = (u)r[5] + 4;
    r[5] = (u)r[5] - (u)r[2];
    r[2] = (int)r[5] < 4;
    c = ((r[2] != 0)); *(short *)((u)r[4] + 110) = r[3]; if (c) goto L800ce834;
    r[5] = (u)r[5] + -4;
    L800ce834:;
    r[6] = (u)0 + 1;
    c = ((r[5] == r[6])); r[2] = (int)r[5] < 2; if (c) goto L800ce880;
    c = ((r[2] == 0));  if (c) goto L800ce858;
    c = ((r[5] == 0));  if (c) goto L800ce874;
     goto out;
    L800ce858:;
    r[2] = (u)0 + 2;
    c = ((r[5] == r[2])); r[2] = (u)0 + 3; if (c) goto L800ce88c;
    c = ((r[5] == r[2]));  if (c) goto L800ce898;
     goto out;
    L800ce874:;
    *(short *)((u)r[4] + 6952) = r[3];
    *(int *)((u)r[4] + 6576) = r[6]; goto out;
    L800ce880:;
    r[2] = (u)0 + 2;
    *(int *)((u)r[4] + 6576) = r[2]; goto out;
    L800ce88c:;
    r[2] = (u)0 + 4;
    *(int *)((u)r[4] + 6576) = r[2]; goto out;
    L800ce898:;
    *(int *)((u)r[4] + 6576) = r[5]; goto out;
out:
    RECOMP_RETURN;
}
