extern char R_s10a_800E01D0[] __asm__("s10a_800E01D0");
int G_s10a_800E024C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s10a_800E024C");
int G_s10a_800E024C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(32)
    r[29] = (u)r[29] + -32;
    r[4] = r[4] & 255;
    *(int *)((u)r[29] + 16) = r[5];
    r[5] = (u)0 + (u)0;
    r[6] = (u)r[5] + (u)0;
    *(int *)((u)r[29] + 24) = r[31];
    r[7] = (u)r[5] + (u)0; CALL(R_s10a_800E01D0);
    r[31] = *(int *)((u)r[29] + 24);
    r[29] = (u)r[29] + 32; goto out;
out:
    return r[2];
}
