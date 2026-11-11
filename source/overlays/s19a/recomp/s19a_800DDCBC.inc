extern char R_s19a_800D87B4[] __asm__("s19a_800D87B4");
extern char R_s19a_800D88BC[] __asm__("s19a_800D88BC");
int G_s19a_800DDCBC(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s19a_800DDCBC");
int G_s19a_800DDCBC(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    r[4] = (u)0 + 112;
    *(int *)((u)r[29] + 20) = r[31];
    *(int *)((u)r[16] + 36) = r[5];
    r[5] = (u)r[16] + 40;
    *(int *)((u)r[16] + 32) = r[6]; CALL(R_s19a_800D88BC);
    r[4] = (u)0 + 114; CALL(R_s19a_800D87B4);
    r[4] = (u)0 + 115;
    *(int *)((u)r[16] + 48) = r[2]; CALL(R_s19a_800D87B4);
    r[4] = (u)0 + 108;
    *(int *)((u)r[16] + 52) = r[2]; CALL(R_s19a_800D87B4);
    r[4] = (u)0 + 116;
    *(int *)((u)r[16] + 56) = r[2]; CALL(R_s19a_800D87B4);
    r[3] = *(int *)((u)r[16] + 56);
    *(int *)((u)r[16] + 60) = r[2];
    *(int *)((u)r[16] + 64) = r[3];
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[2] = (u)0 + (u)0;
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
