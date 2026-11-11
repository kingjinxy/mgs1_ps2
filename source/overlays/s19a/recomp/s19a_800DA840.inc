extern char R_GV_RandS[] __asm__("GV_RandS");
extern char R_s19a_800DA798[] __asm__("s19a_800DA798");
int G_s19a_800DA840(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s19a_800DA840");
int G_s19a_800DA840(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[16];
    *(int *)((u)r[29] + 20) = r[31];
    r[16] = (u)r[4] + (u)0; CALL(R_s19a_800DA798);
    c = ((r[2] != 0)); r[4] = (u)0 + 512; if (c) goto L800da864;
    r[2] = (u)0 + (u)0; goto L800da890;
    L800da864:;
    r[3] = *(int *)((u)r[16] + 2320);
    r[2] = (u)0 + 1;
    *(short *)((u)r[3] + 0) = r[2];
    r[2] = (u)0 + 4;
    *(int *)((u)r[16] + 2372) = r[2]; CALL(R_GV_RandS);
    r[3] = *(int *)((u)r[16] + 2312);
    r[3] = (u)r[3] + (u)r[2];
    r[2] = (u)0 + 1;
    *(int *)((u)r[16] + 2312) = r[3];
    L800da890:;
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
