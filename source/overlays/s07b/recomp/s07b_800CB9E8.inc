extern char R_GV_RandU[] __asm__("GV_RandU");
extern char R_s07b_800CB6B0[] __asm__("s07b_800CB6B0");
int G_s07b_800CB9E8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s07b_800CB9E8");
int G_s07b_800CB9E8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(32)
    r[29] = (u)r[29] + -32;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 24) = r[18];
    r[18] = (u)r[5] + (u)0;
    *(int *)((u)r[29] + 28) = r[31];
    *(int *)((u)r[29] + 20) = r[17];
    r[17] = *(int *)((u)r[16] + 2212);
    r[4] = (u)0 + 32; goto L800cba24;
    L800cba10:;
    r[3] = *(short *)((u)r[6] + 4);
    r[2] = *(short *)((u)r[16] + 2164);
    c = ((r[3] != r[2])); r[4] = (u)0 + 32; if (c) goto L800cba78;
    L800cba24:;
     CALL(R_GV_RandU);
    if (r[17]) { lo_ = (int)r[2] / (int)r[17]; hi_ = (int)r[2] % (int)r[17]; }
    c = ((r[17] != 0));  if (c) goto L800cba3c;
    L800cba3c:;
    r[1] = (u)0 + -1;
    c = ((r[17] != r[1])); r[1] = 0; if (c) goto L800cba54;
    c = ((r[2] != r[1]));  if (c) goto L800cba54;
    L800cba54:;
    r[3] = hi_;
    r[2] = *(short *)((u)r[16] + 2160);
    r[3] = (u)r[3] << 3;
    r[3] = (u)r[3] + 2216;
    r[6] = (u)r[16] + (u)r[3];
    r[3] = *(short *)((u)r[6] + 0);
    c = ((r[3] == r[2]));  if (c) goto L800cba10;
    L800cba78:;
    r[4] = (u)r[16] + (u)0;
    r[5] = *(short *)((u)r[6] + 0);
    r[6] = *(short *)((u)r[6] + 4);
    r[7] = (u)r[18] + (u)0; CALL(R_s07b_800CB6B0);
    r[31] = *(int *)((u)r[29] + 28);
    r[18] = *(int *)((u)r[29] + 24);
    r[17] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 32; goto out;
out:
    RECOMP_RETURN;
}
