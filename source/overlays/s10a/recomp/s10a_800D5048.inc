extern char R_GV_Malloc[] __asm__("GV_Malloc");
extern char R_s10a_800D4CC4[] __asm__("s10a_800D4CC4");
int G_s10a_800D5048(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s10a_800D5048");
int G_s10a_800D5048(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 20) = r[31];
    r[4] = (u)0 + 224; CALL(R_GV_Malloc);
    c = ((r[2] == 0)); *(int *)((u)r[16] + 32) = r[2]; if (c) goto L800d507c;
    r[4] = (u)r[16] + (u)0; CALL(R_s10a_800D4CC4);
    *(int *)((u)r[16] + 36) = 0;
    r[2] = (u)0 + (u)0; goto L800d5080;
    L800d507c:;
    r[2] = (u)0 + -1;
    L800d5080:;
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
