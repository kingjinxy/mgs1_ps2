extern char R_GV_RandU[] __asm__("GV_RandU");
int G_s11h_800C4324(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s11h_800C4324");
int G_s11h_800C4324(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(48)
    r[29] = (u)r[29] + -48;
    *(int *)((u)r[29] + 36) = r[17];
    r[17] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 32) = r[16];
    r[16] = (u)r[5] + -1;
    r[2] = (u)0 + 3;
    *(char *)((u)r[29] + 19) = r[2];
    r[2] = (u)0 + 96;
    *(char *)((u)r[29] + 23) = r[2];
    r[3] = *(int *)((u)r[29] + 20);
    r[2] = 0xff000000;
    *(int *)((u)r[29] + 44) = r[31];
    *(int *)((u)r[29] + 40) = r[18];
    c = (((int)r[16] < 0)); r[18] = r[3] & r[2]; if (c) goto L800c439c;
    L800c4360:;
    r[4] = (u)0 + 128; CALL(R_GV_RandU);
    r[2] = (u)r[2] + 128;
    r[3] = (u)r[2] >> 31;
    r[3] = (u)r[2] + (u)r[3];
    r[3] = (int)r[3] >> 1;
    r[4] = r[18] | r[3];
    r[3] = (u)r[3] << 8;
    r[4] = r[4] | r[3];
    r[2] = (u)r[2] << 16;
    r[4] = r[4] | r[2];
    *(int *)((u)r[17] + 0) = r[4];
    r[16] = (u)r[16] + -1;
    c = (((int)r[16] >= 0)); r[17] = (u)r[17] + 4; if (c) goto L800c4360;
    L800c439c:;
    r[31] = *(int *)((u)r[29] + 44);
    r[18] = *(int *)((u)r[29] + 40);
    r[17] = *(int *)((u)r[29] + 36);
    r[16] = *(int *)((u)r[29] + 32);
    r[29] = (u)r[29] + 48; goto out;
out:
    RECOMP_RETURN;
}
