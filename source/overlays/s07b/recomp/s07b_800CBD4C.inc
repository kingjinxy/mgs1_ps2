extern char R_NewKogaku2[] __asm__("NewKogaku2");
int G_s07b_800CBD4C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s07b_800CBD4C");
int G_s07b_800CBD4C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(32)
    r[29] = (u)r[29] + -32;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 24) = r[31];
    *(int *)((u)r[29] + 20) = r[17];
    r[2] = *(int *)((u)r[16] + 2108);
    r[17] = (u)0 + 10;
    c = ((r[2] == r[17])); r[4] = (u)r[16] + 32; if (c) goto L800cbd8c;
    r[5] = (u)r[16] + 156;
    r[6] = (u)0 + 6; CALL(R_NewKogaku2);
    r[3] = *(int *)((u)r[16] + 2012);
    *(int *)((u)r[16] + 2104) = r[2];
    *(int *)((u)r[16] + 2108) = r[17];
    *(int *)((u)r[3] + 0) = 0;
    L800cbd8c:;
    r[31] = *(int *)((u)r[29] + 24);
    r[17] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 32; goto out;
out:
    RECOMP_RETURN;
}
