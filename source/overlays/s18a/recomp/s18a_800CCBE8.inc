extern char R_GV_Time[] __asm__("GV_Time");
int G_s18a_800CCBE8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s18a_800CCBE8");
int G_s18a_800CCBE8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[2] = 0;
    r[2] = *(int *)((u)r[2] + (int)R_GV_Time);
    r[2] = r[2] & 1;
    c = ((r[2] == 0)); r[3] = (u)0 + 3; if (c) goto L800ccc04;
    r[3] = (u)0 + 1;
    L800ccc04:;
    r[2] = (u)r[3] + (u)0; goto out;
out:
    RECOMP_RETURN;
}
