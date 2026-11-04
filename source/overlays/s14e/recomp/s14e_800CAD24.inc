extern char R_AsiatoCheck[] __asm__("AsiatoCheck");
extern char R_SearchNearAsiato[] __asm__("SearchNearAsiato");
int G_s14e_800CAD24(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s14e_800CAD24");
int G_s14e_800CAD24(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(48)
    r[29] = (u)r[29] + -48;
    *(int *)((u)r[29] + 24) = r[16];
    r[16] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 40) = r[31];
    *(int *)((u)r[29] + 36) = r[19];
    *(int *)((u)r[29] + 32) = r[18];
    *(int *)((u)r[29] + 28) = r[17];
    r[2] = *(unsigned char *)((u)r[16] + 2979);
    r[2] = r[2] & 16;
    c = ((r[2] == 0)); r[2] = (u)0 + 5; if (c) goto L800cadb4;
    r[3] = *(short *)((u)r[16] + 2850);
    c = ((r[3] == r[2])); r[19] = (u)r[16] + 32; if (c) goto L800cadb4;
    r[2] = *(int *)((u)r[16] + 76);
    r[5] = (u)r[19] + (u)0;
    r[17] = *(int *)((u)r[2] + 8);
    r[18] = (u)r[16] + 2956;
    r[4] = (u)r[17] + (u)0; CALL(R_AsiatoCheck);
    c = ((r[2] == 0)); r[4] = (u)r[17] + (u)0; if (c) goto L800cadb4;
    r[6] = *(short *)((u)r[16] + 2956);
    r[7] = *(short *)((u)r[18] + 2);
    r[2] = *(short *)((u)r[18] + 4);
    r[5] = (u)r[19] + (u)0;
    *(int *)((u)r[29] + 16) = r[2]; CALL(R_SearchNearAsiato);
    c = (((int)r[2] < 0));  if (c) goto L800cadb4;
    r[2] = *(unsigned char *)((u)r[16] + 2978);
    r[2] = r[2] | 16;
    *(char *)((u)r[16] + 2978) = r[2];
    L800cadb4:;
    r[31] = *(int *)((u)r[29] + 40);
    r[19] = *(int *)((u)r[29] + 36);
    r[18] = *(int *)((u)r[29] + 32);
    r[17] = *(int *)((u)r[29] + 28);
    r[16] = *(int *)((u)r[29] + 24);
    r[29] = (u)r[29] + 48; goto out;
out:
    RECOMP_RETURN;
}
