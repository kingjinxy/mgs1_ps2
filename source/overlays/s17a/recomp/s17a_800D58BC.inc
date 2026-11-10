extern char R_s17a_800D6288[] __asm__("s17a_800D6288");
int G_s17a_800D58BC(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s17a_800D58BC");
int G_s17a_800D58BC(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(48)
    r[29] = (u)r[29] + -48;
    r[9] = (u)r[4] + (u)0;
    r[14] = (u)r[6] + (u)0;
    r[6] = (u)r[7] + (u)0;
    r[4] = (u)0 + (u)0;
    r[7] = *(unsigned char *)((u)r[29] + 64);
    r[10] = *(unsigned char *)((u)r[29] + 68);
    r[8] = *(unsigned char *)((u)r[29] + 72);
    r[11] = *(unsigned char *)((u)r[29] + 76);
    r[12] = *(unsigned char *)((u)r[29] + 80);
    r[13] = *(unsigned char *)((u)r[29] + 84);
    r[3] = (u)r[9] + (u)0;
    *(int *)((u)r[29] + 40) = r[31];
    L800d58f0:;
    r[2] = *(unsigned char *)((u)r[3] + 424);
    c = ((r[2] == 0)); r[2] = (int)r[4] < 100; if (c) goto L800d5914;
    r[4] = (u)r[4] + 1;
    r[2] = (int)r[4] < 100;
    c = ((r[2] != 0)); r[3] = (u)r[3] + 33; if (c) goto L800d58f0;
    r[2] = (int)r[4] < 100;
    L800d5914:;
    c = ((r[2] == 0)); r[3] = (u)r[4] << 5; if (c) goto L800d5974;
    r[3] = (u)r[3] + (u)r[4];
    r[4] = (u)r[9] + (u)r[3];
    r[2] = (u)r[8] + 1;
    *(char *)((u)r[4] + 424) = r[2];
    r[2] = r[10] & 255;
    *(int *)((u)r[29] + 16) = r[2];
    r[2] = r[8] & 255;
    *(int *)((u)r[29] + 20) = r[2];
    r[2] = r[11] & 255;
    *(int *)((u)r[29] + 24) = r[2];
    r[2] = r[12] & 255;
    *(int *)((u)r[29] + 28) = r[2];
    r[2] = r[13] & 255;
    r[3] = (u)r[3] + (u)r[9];
    r[3] = (u)r[3] + 425;
    r[4] = (u)r[5] + (u)0;
    r[5] = (u)r[14] + (u)0;
    r[6] = r[6] & 255;
    r[7] = r[7] & 255;
    *(int *)((u)r[29] + 32) = r[2];
    *(int *)((u)r[29] + 36) = r[3]; CALL(R_s17a_800D6288);
    L800d5974:;
    r[31] = *(int *)((u)r[29] + 40);
    r[29] = (u)r[29] + 48; goto out;
out:
    RECOMP_RETURN;
}
