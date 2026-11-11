extern char R_s19a_800CB468[] __asm__("s19a_800CB468");
int G_s19a_800CB4B8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s19a_800CB4B8");
int G_s19a_800CB4B8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    r[5] = 0 | 51845;
    *(int *)((u)r[29] + 20) = r[31];
    *(int *)((u)r[16] + 40) = 0; CALL(R_s19a_800CB468);
    c = ((r[2] == 0)); r[2] = (u)0 + 360; if (c) goto L800cb4e8;
    *(int *)((u)r[16] + 44) = r[2];
    r[2] = (u)0 + (u)0; goto L800cb524;
    L800cb4e8:;
    r[5] = *(int *)((u)r[16] + 44);
    c = (((int)r[5] > 0)); r[2] = (u)0 + 1; if (c) goto L800cb50c;
    r[4] = (u)r[16] + (u)0;
    r[5] = 0 | 56405; CALL(R_s19a_800CB468);
     goto L800cb524;
    L800cb50c:;
    r[3] = (u)0 + 360;
    r[4] = *(int *)((u)r[16] + 44);
    r[3] = (u)r[3] - (u)r[5];
    *(int *)((u)r[16] + 40) = r[3];
    r[4] = (u)r[4] + -1;
    *(int *)((u)r[16] + 44) = r[4];
    L800cb524:;
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
