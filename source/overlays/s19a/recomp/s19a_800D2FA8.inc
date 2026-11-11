extern char R_s19a_800D2DB0[] __asm__("s19a_800D2DB0");
int G_s19a_800D2FA8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s19a_800D2FA8");
int G_s19a_800D2FA8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(32)
    r[29] = (u)r[29] + -32;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 20) = r[17];
    r[17] = (u)r[5] + (u)0;
    *(int *)((u)r[29] + 24) = r[18];
    r[18] = (u)r[6] + (u)0;
    r[4] = (u)r[17] + (u)0;
    r[5] = (u)r[18] + (u)0;
    r[6] = 0 | 51845;
    *(int *)((u)r[29] + 28) = r[31];
    *(int *)((u)r[16] + 32) = 0; CALL(R_s19a_800D2DB0);
    c = ((r[2] == 0)); r[2] = (u)0 + 60; if (c) goto L800d2ff0;
    *(int *)((u)r[16] + 36) = r[2];
    r[2] = (u)0 + (u)0; goto L800d3034;
    L800d2ff0:;
    r[3] = *(int *)((u)r[16] + 36);
    c = (((int)r[3] > 0)); r[2] = (u)0 + 1; if (c) goto L800d3018;
    r[4] = (u)r[17] + (u)0;
    r[5] = (u)r[18] + (u)0;
    r[6] = 0 | 56405; CALL(R_s19a_800D2DB0);
     goto L800d3034;
    L800d3018:;
    r[3] = (u)r[3] << (r[2] & 31);
    r[4] = (u)0 + 360;
    r[5] = *(int *)((u)r[16] + 36);
    r[4] = (u)r[4] - (u)r[3];
    *(int *)((u)r[16] + 32) = r[4];
    r[5] = (u)r[5] + -1;
    *(int *)((u)r[16] + 36) = r[5];
    L800d3034:;
    r[31] = *(int *)((u)r[29] + 28);
    r[18] = *(int *)((u)r[29] + 24);
    r[17] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 32; goto out;
out:
    RECOMP_RETURN;
}
