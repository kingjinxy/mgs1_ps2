extern char R_GV_SendMessage[] __asm__("GV_SendMessage");
int G_s07b_800CC138(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s07b_800CC138");
int G_s07b_800CC138(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(48)
    r[29] = (u)r[29] + -48;
    *(int *)((u)r[29] + 40) = r[31];
    r[2] = *(unsigned short *)((u)r[4] + 2112);
    r[3] = (u)0 + 2;
    *(short *)((u)r[29] + 34) = r[3];
    r[3] = (u)0 + 18717;
    r[4] = (u)r[29] + 16;
    *(short *)((u)r[29] + 20) = r[3];
    *(short *)((u)r[29] + 22) = r[5];
    *(short *)((u)r[29] + 16) = r[2]; CALL(R_GV_SendMessage);
    r[31] = *(int *)((u)r[29] + 40);
    r[29] = (u)r[29] + 48; goto out;
out:
    return r[2];
}
