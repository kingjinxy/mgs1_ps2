extern char R_s19a_dat_800E0CC8[] __asm__("s19a_dat_800E0CC8");
extern char R_GV_ReceiveMessage[] __asm__("GV_ReceiveMessage");
int G_s19a_800D739C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s19a_800D739C");
int G_s19a_800D739C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(32)
    r[29] = (u)r[29] + -32;
    r[2] = 0;
    r[4] = *(int *)((u)r[2] + (int)R_s19a_dat_800E0CC8);
    *(int *)((u)r[29] + 24) = r[31];
    r[5] = (u)r[29] + 16; CALL(R_GV_ReceiveMessage);
    c = (((int)r[2] <= 0)); r[2] = (u)0 + -1; if (c) goto L800d73c8;
    r[2] = *(int *)((u)r[29] + 16);
    r[2] = *(unsigned short *)((u)r[2] + 4);
    L800d73c8:;
    r[31] = *(int *)((u)r[29] + 24);
    r[29] = (u)r[29] + 32; goto out;
out:
    RECOMP_RETURN;
}
