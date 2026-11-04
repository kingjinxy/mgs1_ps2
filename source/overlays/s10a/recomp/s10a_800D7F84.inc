extern char R_DG_ZeroVector[] __asm__("DG_ZeroVector");
int G_s10a_800D7F84(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s10a_800D7F84");
int G_s10a_800D7F84(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    c = (((int)r[5] <= 0)); r[3] = (u)0 + (u)0; if (c) goto L800d7fc4;
    r[6] = 0;
    L800d7f90:;
    r[10] = (u)r[6] + (int)R_DG_ZeroVector;
    r[7] = LWL(((u)r[10] + 3), r[7]);
    r[7] = LWR(((u)r[10] + 0), r[7]);
    r[8] = LWL(((u)r[10] + 7), r[8]);
    r[8] = LWR(((u)r[10] + 4), r[8]);
    SWL(((u)r[4] + 3), r[7]);
    SWR(((u)r[4] + 0), r[7]);
    SWL(((u)r[4] + 7), r[8]);
    SWR(((u)r[4] + 4), r[8]);
    r[3] = (u)r[3] + 1;
    r[2] = (int)r[3] < (int)r[5];
    c = ((r[2] != 0)); r[4] = (u)r[4] + 8; if (c) goto L800d7f90;
    L800d7fc4:;
     goto out;
out:
    RECOMP_RETURN;
}
