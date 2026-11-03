extern char R_DG_PutVector[] __asm__("DG_PutVector");
extern char R_DG_SetPos2[] __asm__("DG_SetPos2");
int G_s10a_800D0DAC(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s10a_800D0DAC");
int G_s10a_800D0DAC(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(32)
    r[29] = (u)r[29] + -32;
    *(int *)((u)r[29] + 24) = r[16];
    r[16] = (u)r[4] + (u)0;
    r[4] = (u)r[16] + 32;
    r[5] = (u)r[16] + 40;
    r[2] = (u)0 + 200;
    *(short *)((u)r[29] + 18) = r[2];
    r[2] = (u)0 + 900;
    *(int *)((u)r[29] + 28) = r[31];
    *(short *)((u)r[29] + 16) = 0;
    *(short *)((u)r[29] + 20) = r[2]; CALL(R_DG_SetPos2);
    r[4] = (u)r[29] + 16;
    r[5] = (u)r[4] + (u)0;
    r[6] = (u)0 + 1; CALL(R_DG_PutVector);
    r[3] = LWL(((u)r[29] + 19), r[3]);
    r[3] = LWR(((u)r[29] + 16), r[3]);
    r[7] = LWL(((u)r[29] + 23), r[7]);
    r[7] = LWR(((u)r[29] + 20), r[7]);
    SWL(((u)r[16] + 827), r[3]);
    SWR(((u)r[16] + 824), r[3]);
    SWL(((u)r[16] + 831), r[7]);
    SWR(((u)r[16] + 828), r[7]);
    r[31] = *(int *)((u)r[29] + 28);
    r[16] = *(int *)((u)r[29] + 24);
    r[29] = (u)r[29] + 32; goto out;
out:
    RECOMP_RETURN;
}
