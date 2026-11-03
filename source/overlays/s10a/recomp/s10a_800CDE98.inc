extern char R_GV_DestroyActor[] __asm__("GV_DestroyActor");
extern char R_s10a_800CDDA8[] __asm__("s10a_800CDDA8");
int G_s10a_800CDE98(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s10a_800CDE98");
int G_s10a_800CDE98(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 20) = r[31];
    r[2] = *(int *)((u)r[16] + 56);
    r[2] = (u)r[2] + -1;
    c = ((r[2] != 0)); *(int *)((u)r[16] + 56) = r[2]; if (c) goto L800cdec4;
     CALL(R_GV_DestroyActor);
    L800cdec4:;
    r[3] = *(int *)((u)r[16] + 40);
    r[2] = *(int *)((u)r[16] + 44);
    r[4] = (u)r[16] + (u)0;
    r[5] = *(int *)((u)r[2] + 0);
    r[6] = *(int *)((u)r[2] + 4);
    r[7] = *(int *)((u)r[2] + 8);
    r[8] = *(int *)((u)r[2] + 12);
    *(int *)((u)r[3] + 0) = r[5];
    *(int *)((u)r[3] + 4) = r[6];
    *(int *)((u)r[3] + 8) = r[7];
    *(int *)((u)r[3] + 12) = r[8];
    r[5] = *(int *)((u)r[2] + 16);
    r[6] = *(int *)((u)r[2] + 20);
    r[7] = *(int *)((u)r[2] + 24);
    r[8] = *(int *)((u)r[2] + 28);
    *(int *)((u)r[3] + 16) = r[5];
    *(int *)((u)r[3] + 20) = r[6];
    *(int *)((u)r[3] + 24) = r[7];
    *(int *)((u)r[3] + 28) = r[8]; CALL(R_s10a_800CDDA8);
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
