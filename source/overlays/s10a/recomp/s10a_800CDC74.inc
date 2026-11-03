extern char R_s10a_dat_800E4A9C[] __asm__("s10a_dat_800E4A9C");
extern char R_s10a_800CDB14[] __asm__("s10a_800CDB14");
extern char R_s10a_800CDBBC[] __asm__("s10a_800CDBBC");
int G_s10a_800CDC74(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s10a_800CDC74");
int G_s10a_800CDC74(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 20) = r[31];
    r[3] = *(short *)((u)r[16] + 2848);
    r[2] = (u)0 + -1;
    *(short *)((u)r[16] + 2888) = r[2];
    c = ((r[3] == 0)); *(int *)((u)r[16] + 2872) = 0; if (c) goto L800cdcac;
    r[2] = (u)0 + 1;
    c = ((r[3] == r[2])); r[2] = 0; if (c) goto L800cdcc4;
     goto L800cdcd4;
    L800cdcac:;
    r[2] = (u)0 + 1;
    *(short *)((u)r[16] + 2278) = r[2];
    r[4] = (u)r[16] + (u)0; CALL(R_s10a_800CDB14);
    r[2] = 0; goto L800cdcd4;
    L800cdcc4:;
    *(short *)((u)r[16] + 2278) = r[3];
    r[4] = (u)r[16] + (u)0; CALL(R_s10a_800CDBBC);
    r[2] = 0;
    L800cdcd4:;
    r[2] = *(int *)((u)r[2] + (int)R_s10a_dat_800E4A9C);
    c = (((int)r[2] <= 0)); r[2] = (u)0 + 255; if (c) goto L800cdcec;
    *(int *)((u)r[16] + 2964) = r[2]; goto L800cdcf4;
    L800cdcec:;
    *(int *)((u)r[16] + 2964) = 0;
    *(short *)((u)r[16] + 90) = 0;
    L800cdcf4:;
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
