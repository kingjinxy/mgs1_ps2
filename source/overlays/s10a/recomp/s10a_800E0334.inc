extern char R_GV_SendMessage[] __asm__("GV_SendMessage");
int G_s10a_800E0334(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s10a_800E0334");
int G_s10a_800E0334(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(48)
    r[29] = (u)r[29] + -48;
    r[2] = (u)0 + 1;
    *(short *)((u)r[29] + 16) = r[4];
    r[4] = (u)r[29] + 16;
    *(int *)((u)r[29] + 40) = r[31];
    *(short *)((u)r[29] + 18) = r[2];
    *(short *)((u)r[29] + 20) = r[5]; CALL(R_GV_SendMessage);
    r[31] = *(int *)((u)r[29] + 40);
    r[29] = (u)r[29] + 48; goto out;
out:
    return r[2];
}
