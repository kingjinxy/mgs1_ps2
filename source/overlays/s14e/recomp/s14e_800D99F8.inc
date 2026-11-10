int G_s14e_800D99F8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s14e_800D99F8");
int G_s14e_800D99F8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[12] = (int)PSX_ADDR(0x1f800000);
    r[11] = *(int *)((u)r[12] + 1016);
    c = ((r[11] == 0)); r[9] = (u)0 + (u)0; if (c) goto L800d9ac0;
    r[13] = *(int *)((u)r[12] + 1020);
    r[8] = (u)r[9] + (u)0;
    r[5] = (u)r[5] + 8;
    r[7] = (u)0 + 8;
    r[10] = (u)0 + 4;
    r[14] = (u)0 + 32;
    L800d9a24:;
    r[2] = r[4] & 128;
    c = ((r[2] != 0)); r[6] = r[4] & 127; if (c) goto L800d9a4c;
    r[2] = (u)r[6] << 2;
    r[6] = (u)r[12] + (u)r[2];
    r[8] = (u)r[8] + 1;
    r[2] = *(int *)((u)r[6] + 512);
    r[6] = *(int *)((u)r[6] + 0);
    r[9] = (u)r[9] + (u)r[2]; goto L800d9a78;
    L800d9a4c:;
    r[2] = (u)r[6] << 3;
    r[6] = (u)r[13] + (u)r[2];
    r[2] = *(unsigned short *)((u)r[12] + 510);
    r[6] = *(short *)((u)r[6] + 6);
    r[2] = r[2] & 4;
    c = ((r[2] == 0)); r[2] = (u)r[11] + (u)r[6]; if (c) goto L800d9a70;
    r[2] = (u)r[2] + -4;
    *(int *)((u)r[5] + -4) = r[2];
    L800d9a70:;
    r[2] = (u)r[11] + (u)r[6];
    r[6] = *(int *)((u)r[2] + 0);
    L800d9a78:;
    *(int *)((u)r[5] + 0) = r[6];
    r[5] = (u)r[5] + 12;
    r[2] = (u)r[14] - (u)r[7];
    r[2] = (u)r[4] << (r[2] & 31);
    r[3] = (u)r[4] >> (r[7] & 31);
    r[4] = r[2] | r[3];
    r[10] = (u)r[10] + -1;
    c = (((int)r[10] > 0)); r[7] = (u)r[7] + 8; if (c) goto L800d9a24;
    r[2] = (u)0 + 2;
    c = ((r[8] != r[2])); r[2] = (u)r[9] >> 31; if (c) goto L800d9ab8;
    r[2] = (u)r[9] + (u)r[2];
    r[2] = (int)r[2] >> 1; goto out;
    L800d9ab8:;
    c = ((r[8] != 0));  if (c) goto L800d9ac8;
    L800d9ac0:;
    r[2] = (u)0 + (u)0; goto out;
    L800d9ac8:;
    if (r[8]) { lo_ = (int)r[9] / (int)r[8]; hi_ = (int)r[9] % (int)r[8]; }
    c = ((r[8] != 0));  if (c) goto L800d9ad8;
    L800d9ad8:;
    r[1] = (u)0 + -1;
    c = ((r[8] != r[1])); r[1] = 0; if (c) goto L800d9af0;
    c = ((r[9] != r[1]));  if (c) goto L800d9af0;
    L800d9af0:;
    r[2] = lo_;
     goto out;
out:
    RECOMP_RETURN;
}
