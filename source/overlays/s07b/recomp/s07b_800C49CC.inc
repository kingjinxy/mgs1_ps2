extern char R_GV_SendMessage[] __asm__("GV_SendMessage");
int G_s07b_800C49CC(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s07b_800C49CC");
int G_s07b_800C49CC(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(48)
    r[29] = (u)r[29] + -48;
    r[2] = 0 | 50371;
    *(short *)((u)r[29] + 16) = r[2];
    r[2] = (u)0 + 2;
    *(int *)((u)r[29] + 40) = r[31];
    c = ((r[4] == 0)); *(short *)((u)r[29] + 34) = r[2]; if (c) goto L800c49f0;
    r[2] = 0 | 53634; goto L800c49f4;
    L800c49f0:;
    r[2] = (u)0 + 107;
    L800c49f4:;
    *(short *)((u)r[29] + 20) = r[2];
    r[2] = (u)0 + 1024;
    r[4] = (u)r[29] + 16;
    *(short *)((u)r[29] + 22) = r[2]; CALL(R_GV_SendMessage);
    r[31] = *(int *)((u)r[29] + 40);
    r[29] = (u)r[29] + 48; goto out;
out:
    RECOMP_RETURN;
}
