extern char R_s19a_800D17B4[] __asm__("s19a_800D17B4");
int G_s19a_800D4A88(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s19a_800D4A88");
int G_s19a_800D4A88(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 20) = r[31];
    r[2] = *(int *)((u)r[16] + 2872);
    r[3] = *(int *)((u)r[16] + 2856);
    r[2] = r[2] | 4;
    *(int *)((u)r[16] + 2872) = r[2];
    r[2] = (u)0 + 20;
    c = ((r[3] != r[2]));  if (c) goto L800d4ac4;
    r[5] = (u)0 + 5; CALL(R_s19a_800D17B4);
    r[2] = (u)0 + 242;
    *(short *)((u)r[16] + 2890) = r[2];
    L800d4ac4:;
    r[3] = *(int *)((u)r[16] + 2856);
    r[2] = (u)r[3] < (u)121;
    c = ((r[2] == 0)); r[2] = (u)r[3] + 1; if (c) goto L800d4ae4;
    *(int *)((u)r[16] + 2856) = r[2];
    r[2] = (u)0 + (u)0; goto L800d4ae8;
    L800d4ae4:;
    r[2] = (u)0 + 1;
    L800d4ae8:;
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
