extern char R_s14e_800CDB78[] __asm__("s14e_800CDB78");
int G_s14e_800CDC08(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s14e_800CDC08");
int G_s14e_800CDC08(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[31];
    r[3] = *(short *)((u)r[4] + 2848);
    r[2] = (u)0 + -1;
    *(short *)((u)r[4] + 2888) = r[2];
    r[2] = (u)0 + 5;
    *(short *)((u)r[4] + 90) = r[2];
    r[2] = (u)0 + 255;
    *(int *)((u)r[4] + 2872) = 0;
    c = ((r[3] != 0)); *(int *)((u)r[4] + 2968) = r[2]; if (c) goto L800cdc40;
    r[2] = (u)0 + 1;
    *(short *)((u)r[4] + 2278) = r[2]; CALL(R_s14e_800CDB78);
    L800cdc40:;
    r[31] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
