extern char R_GV_NearRange[] __asm__("GV_NearRange");
int G_s18a_800C5108(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s18a_800C5108");
int G_s18a_800C5108(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(32)
    r[29] = (u)r[29] + -32;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 20) = r[17];
    r[17] = (u)r[5] + (u)0;
    *(int *)((u)r[29] + 24) = r[31];
    r[4] = *(short *)((u)r[16] + 0);
    r[5] = *(short *)((u)r[17] + 0);
    r[6] = (u)0 + 250; CALL(R_GV_NearRange);
    r[4] = *(short *)((u)r[16] + 2);
    *(short *)((u)r[16] + 0) = r[2];
    r[5] = *(short *)((u)r[17] + 2);
    r[6] = (u)0 + 100; CALL(R_GV_NearRange);
    r[4] = *(short *)((u)r[16] + 4);
    *(short *)((u)r[16] + 2) = r[2];
    r[5] = *(short *)((u)r[17] + 4);
    r[6] = (u)0 + 250; CALL(R_GV_NearRange);
    *(short *)((u)r[16] + 4) = r[2];
    r[31] = *(int *)((u)r[29] + 24);
    r[17] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 32; goto out;
out:
    RECOMP_RETURN;
}
