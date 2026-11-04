extern char R_GV_Free[] __asm__("GV_Free");
extern char R_s11h_800CCD40[] __asm__("s11h_800CCD40");
int G_s11h_800CCA70(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s11h_800CCA70");
int G_s11h_800CCA70(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 20) = r[31];
    r[5] = *(int *)((u)r[16] + 56);
     CALL(R_s11h_800CCD40);
    r[2] = *(int *)((u)r[16] + 40);
    c = ((r[2] == 0));  if (c) goto L800ccaa8;
    r[4] = *(int *)((u)r[16] + 72);
     CALL(R_GV_Free);
    L800ccaa8:;
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
