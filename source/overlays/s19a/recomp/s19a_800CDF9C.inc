extern char R_s19a_800CDC70[] __asm__("s19a_800CDC70");
extern char R_s19a_800CDD54[] __asm__("s19a_800CDD54");
extern char R_s19a_800CDF44[] __asm__("s19a_800CDF44");
int G_s19a_800CDF9C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s19a_800CDF9C");
int G_s19a_800CDF9C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(32)
    r[29] = (u)r[29] + -32;
    *(int *)((u)r[29] + 24) = r[18];
    r[18] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 28) = r[31];
    *(int *)((u)r[29] + 20) = r[17];
    *(int *)((u)r[29] + 16) = r[16]; CALL(R_s19a_800CDC70);
    r[4] = (u)r[18] + (u)0;
    r[16] = (u)r[2] + (u)0; CALL(R_s19a_800CDD54);
    r[4] = (u)r[18] + (u)0;
    r[17] = (u)r[2] + (u)0; CALL(R_s19a_800CDF44);
    r[16] = r[16] | r[17];
    r[16] = r[16] | r[2];
    c = ((r[16] == 0)); r[2] = (u)0 + (u)0; if (c) goto L800cdff0;
    r[2] = (u)0 + 1;
    r[4] = *(int *)((u)r[18] + 2304);
    r[3] = (u)r[2] + (u)0;
    *(short *)((u)r[4] + 0) = r[3];
    L800cdff0:;
    r[31] = *(int *)((u)r[29] + 28);
    r[18] = *(int *)((u)r[29] + 24);
    r[17] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 32; goto out;
out:
    RECOMP_RETURN;
}
