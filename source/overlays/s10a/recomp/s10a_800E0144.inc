extern char R_s10a_800E0104[] __asm__("s10a_800E0104");
int G_s10a_800E0144(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s10a_800E0144");
int G_s10a_800E0144(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    r[4] = r[4] & 255;
    *(int *)((u)r[29] + 16) = r[31];
    r[5] = (u)0 + (u)0; CALL(R_s10a_800E0104);
    r[31] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    return r[2];
}
