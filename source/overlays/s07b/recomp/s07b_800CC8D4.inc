extern char R_linkvarbuf[] __asm__("linkvarbuf");
int G_s07b_800CC8D4(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s07b_800CC8D4");
int G_s07b_800CC8D4(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[2] = *(int *)((u)r[4] + 2104);
    c = ((r[2] == 0)); r[2] = 0; if (c) goto L800cc928;
    r[3] = *(short *)((u)r[2] + ((int)R_linkvarbuf + 30));
    r[2] = (u)0 + 6;
    c = ((r[3] != r[2]));  if (c) goto L800cc910;
    r[2] = *(int *)((u)r[4] + 156);
    r[3] = *(int *)((u)r[2] + 40);
    r[4] = (u)0 + -129;
    r[3] = r[3] & r[4];
    *(int *)((u)r[2] + 40) = r[3]; goto out;
    L800cc910:;
    r[3] = *(int *)((u)r[4] + 156);
    r[2] = *(int *)((u)r[3] + 40);
    r[2] = r[2] | 128;
    *(int *)((u)r[3] + 40) = r[2];
    L800cc928:;
     goto out;
out:
    RECOMP_RETURN;
}
