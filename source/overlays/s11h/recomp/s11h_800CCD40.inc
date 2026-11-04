extern char R_HZD_DequeueDynamicFloor[] __asm__("HZD_DequeueDynamicFloor");
extern char R_HZD_DequeueDynamicSegment[] __asm__("HZD_DequeueDynamicSegment");
int G_s11h_800CCD40(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s11h_800CCD40");
int G_s11h_800CCD40(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(32)
    r[29] = (u)r[29] + -32;
    *(int *)((u)r[29] + 24) = r[18];
    r[18] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 28) = r[31];
    *(int *)((u)r[29] + 20) = r[17];
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = *(int *)((u)r[18] + 68);
    r[17] = *(int *)((u)r[18] + 72);
    c = (((int)r[16] <= 0));  if (c) goto L800ccd84;
    L800ccd68:;
    r[4] = *(int *)((u)r[18] + 60);
    r[5] = (u)r[17] + (u)0;
    r[17] = (u)r[17] + 16;
    r[16] = (u)r[16] + -1; CALL(R_HZD_DequeueDynamicSegment);
    c = (((int)r[16] > 0));  if (c) goto L800ccd68;
    L800ccd84:;
    r[16] = *(int *)((u)r[18] + 64);
    r[17] = *(int *)((u)r[18] + 76);
    c = (((int)r[16] <= 0));  if (c) goto L800ccdb0;
    L800ccd94:;
    r[4] = *(int *)((u)r[18] + 60);
    r[5] = (u)r[17] + (u)0;
    r[17] = (u)r[17] + 48;
    r[16] = (u)r[16] + -1; CALL(R_HZD_DequeueDynamicFloor);
    c = (((int)r[16] > 0));  if (c) goto L800ccd94;
    L800ccdb0:;
    r[31] = *(int *)((u)r[29] + 28);
    r[18] = *(int *)((u)r[29] + 24);
    r[17] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 32; goto out;
out:
    RECOMP_RETURN;
}
