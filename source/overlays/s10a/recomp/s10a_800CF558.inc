extern char R_ScaleMatrix[] __asm__("ScaleMatrix");
int G_s10a_800CF558(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s10a_800CF558");
int G_s10a_800CF558(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(40)
    r[29] = (u)r[29] + -40;
    *(int *)((u)r[29] + 32) = r[31];
    r[2] = *(int *)((u)r[4] + 468);
    *(int *)((u)r[29] + 16) = r[2];
    r[2] = *(int *)((u)r[4] + 468);
    *(int *)((u)r[29] + 20) = r[2];
    r[2] = *(int *)((u)r[4] + 468);
    *(int *)((u)r[29] + 24) = r[2];
    r[4] = *(int *)((u)r[5] + 0);
    r[5] = (u)r[29] + 16; CALL(R_ScaleMatrix);
    r[31] = *(int *)((u)r[29] + 32);
    r[29] = (u)r[29] + 40; goto out;
out:
    RECOMP_RETURN;
}
