extern char R_s18a_800D1638[] __asm__("s18a_800D1638");
int G_s18a_800D0F24(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s18a_800D0F24");
int G_s18a_800D0F24(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(32)
    r[29] = (u)r[29] + -32;
    *(int *)((u)r[29] + 24) = r[18];
    r[18] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 28) = r[31];
    *(int *)((u)r[29] + 20) = r[17];
    *(int *)((u)r[29] + 16) = r[16];
    r[2] = *(int *)((u)r[18] + 68);
    c = (((int)r[2] <= 0)); r[16] = (u)0 + (u)0; if (c) goto L800d0f9c;
    r[17] = (u)0 + 32;
    L800d0f50:;
    r[4] = *(int *)((u)r[18] + 72);
    c = (((int)r[4] >= 0)); r[2] = (u)r[4] + (u)0; if (c) goto L800d0f64;
    r[2] = (u)r[4] + 7;
    L800d0f64:;
    r[2] = (int)r[2] >> 3;
    r[2] = (u)r[2] << 3;
    r[3] = (u)r[18] + (u)r[16];
    r[3] = *(unsigned char *)((u)r[3] + 64);
    r[2] = (u)r[4] - (u)r[2];
    c = ((r[2] != r[3]));  if (c) goto L800d0f88;
    r[4] = (u)r[18] + (u)r[17]; CALL(R_s18a_800D1638);
    L800d0f88:;
    r[2] = *(int *)((u)r[18] + 68);
    r[16] = (u)r[16] + 1;
    r[2] = (int)r[16] < (int)r[2];
    c = ((r[2] != 0)); r[17] = (u)r[17] + 8; if (c) goto L800d0f50;
    L800d0f9c:;
    r[2] = *(int *)((u)r[18] + 72);
    r[2] = (u)r[2] + 1;
    *(int *)((u)r[18] + 72) = r[2];
    r[31] = *(int *)((u)r[29] + 28);
    r[18] = *(int *)((u)r[29] + 24);
    r[17] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 32; goto out;
out:
    RECOMP_RETURN;
}
int G_s18a_rc_800D0FC4(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s18a_rc_800D0FC4");
int G_s18a_rc_800D0FC4(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
     goto out;
out:
    RECOMP_RETURN;
}
