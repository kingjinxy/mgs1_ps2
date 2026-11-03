extern char R_linkvarbuf[] __asm__("linkvarbuf");
extern char R_s10a_dat_800E40F0[] __asm__("s10a_dat_800E40F0");
extern char R_GV_RandU[] __asm__("GV_RandU");
int G_s10a_800D7E98(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s10a_800D7E98");
int G_s10a_800D7E98(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 20) = r[31];
    r[4] = (u)0 + 16; CALL(R_GV_RandU);
    *(int *)((u)r[16] + 1768) = r[2];
    r[2] = 0;
    r[2] = *(unsigned short *)((u)r[2] + ((int)R_linkvarbuf + 2));
    r[2] = (u)r[2] + 1;
    r[2] = (u)r[2] << 16;
    r[3] = (int)r[2] >> 16;
    r[2] = (u)r[3] < (u)5;
    c = ((r[2] == 0)); r[3] = (u)r[3] << 2; if (c) goto L800d7ef4;
    r[2] = 0;
    r[2] = (u)r[2] + (int)R_s10a_dat_800E40F0;
    r[3] = (u)r[3] + (u)r[2];
    r[2] = *(int *)((u)r[3] + 0);
    t = r[2];  switch ((u)t) { case 0x800d7ef4: goto L800d7ef4; case 0x800d7f00: goto L800d7f00; case 0x800d7f0c: goto L800d7f0c; case 0x800d7f18: goto L800d7f18; default: goto out; }
    L800d7ef4:;
    r[2] = *(int *)((u)r[16] + 1768);
    r[2] = (u)r[2] + 150; goto L800d7f24;
    L800d7f00:;
    r[2] = *(int *)((u)r[16] + 1768);
    r[2] = (u)r[2] + 120; goto L800d7f24;
    L800d7f0c:;
    r[2] = *(int *)((u)r[16] + 1768);
    r[2] = (u)r[2] + 90; goto L800d7f24;
    L800d7f18:;
    r[2] = *(int *)((u)r[16] + 1768);
    r[2] = (u)r[2] + 20;
    L800d7f24:;
    *(int *)((u)r[16] + 1768) = r[2];
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    return r[2];
}
