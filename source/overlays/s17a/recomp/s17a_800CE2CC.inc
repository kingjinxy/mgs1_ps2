extern char R_GM_FreeTarget[] __asm__("GM_FreeTarget");
extern char R_s17a_800CEE14[] __asm__("s17a_800CEE14");
int G_s17a_800CE2CC(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s17a_800CE2CC");
int G_s17a_800CE2CC(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 20) = r[31];
    r[2] = *(int *)((u)r[16] + 368);
    c = ((r[2] == 0));  if (c) goto L800ce2f8;
    r[4] = *(int *)((u)r[16] + 332);
     CALL(R_GM_FreeTarget);
    L800ce2f8:;
    r[4] = *(int *)((u)r[16] + 40);
     CALL(R_s17a_800CEE14);
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
