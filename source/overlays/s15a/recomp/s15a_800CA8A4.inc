extern char R_DG_ZeroVector[] __asm__("DG_ZeroVector");
int G_s15a_800CA8A4(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s15a_800CA8A4");
int G_s15a_800CA8A4(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[6] = (u)r[4] + 1444;
    *(int *)((u)r[4] + 1680) = 0;
    c = (((int)r[5] <= 0)); r[3] = (u)0 + (u)0; if (c) goto L800ca8ec;
    r[4] = 0;
    L800ca8b8:;
    r[10] = (u)r[4] + (int)R_DG_ZeroVector;
    r[7] = LWL(((u)r[10] + 3), r[7]);
    r[7] = LWR(((u)r[10] + 0), r[7]);
    r[8] = LWL(((u)r[10] + 7), r[8]);
    r[8] = LWR(((u)r[10] + 4), r[8]);
    SWL(((u)r[6] + 3), r[7]);
    SWR(((u)r[6] + 0), r[7]);
    SWL(((u)r[6] + 7), r[8]);
    SWR(((u)r[6] + 4), r[8]);
    r[3] = (u)r[3] + 1;
    r[2] = (int)r[3] < (int)r[5];
    c = ((r[2] != 0)); r[6] = (u)r[6] + 8; if (c) goto L800ca8b8;
    L800ca8ec:;
     goto out;
out:
    RECOMP_RETURN;
}
