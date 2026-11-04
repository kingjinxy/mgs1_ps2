int G_s10a_800E358C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s10a_800E358C");
int G_s10a_800E358C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[8] = *(int *)((u)r[4] + 0);
    r[9] = *(int *)((u)r[4] + 4);
    r[10] = *(int *)((u)r[4] + 8);
    r[11] = *(int *)((u)r[4] + 12);
    r[12] = *(int *)((u)r[4] + 16);
    Gte_CtrlWrite(8, r[8]);
    Gte_CtrlWrite(9, r[9]);
    Gte_CtrlWrite(10, r[10]);
    Gte_CtrlWrite(11, r[11]);
    Gte_CtrlWrite(12, r[12]);
     goto out;
out:
    RECOMP_RETURN;
}
