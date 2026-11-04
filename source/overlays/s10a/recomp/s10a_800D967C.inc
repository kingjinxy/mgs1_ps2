extern char R_GV_Time[] __asm__("GV_Time");
extern char R_GV_RandU[] __asm__("GV_RandU");
int G_s10a_800D967C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s10a_800D967C");
int G_s10a_800D967C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[31];
    r[3] = *(int *)((u)r[4] + 2660);
    r[2] = (u)0 + 1;
    c = ((r[3] != r[2])); r[2] = (u)0 + (u)0; if (c) goto L800d96c4;
    r[2] = 0;
    r[2] = *(int *)((u)r[2] + (int)R_GV_Time);
    r[2] = r[2] & 31;
    c = ((r[2] != 0));  if (c) goto L800d96c0;
    r[4] = (u)0 + 8; CALL(R_GV_RandU);
    r[3] = (u)r[2] + (u)0;
    c = ((r[3] == 0)); r[2] = (u)0 + 1; if (c) goto L800d96c4;
    L800d96c0:;
    r[2] = (u)0 + (u)0;
    L800d96c4:;
    r[31] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
