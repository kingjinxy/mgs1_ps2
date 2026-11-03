extern char R_HZD_GetAddress[] __asm__("HZD_GetAddress");
int G_s10a_800CC5E0(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s10a_800CC5E0");
int G_s10a_800CC5E0(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 20) = r[31];
    r[3] = *(int *)((u)r[16] + 2868);
    r[2] = *(int *)((u)r[16] + 2536);
    r[3] = (u)r[3] + 1;
    r[2] = (int)r[3] < (int)r[2];
    c = ((r[2] != 0)); r[2] = (u)r[3] << 3; if (c) goto L800cc610;
    r[3] = (u)0 + (u)0;
    r[2] = (u)r[3] << 3;
    L800cc610:;
    r[2] = (u)r[16] + (u)r[2];
    *(int *)((u)r[16] + 2868) = r[3];
    r[7] = LWL(((u)r[2] + 2543), r[7]);
    r[7] = LWR(((u)r[2] + 2540), r[7]);
    r[8] = LWL(((u)r[2] + 2547), r[8]);
    r[8] = LWR(((u)r[2] + 2544), r[8]);
    SWL(((u)r[16] + 3039), r[7]);
    SWR(((u)r[16] + 3036), r[7]);
    SWL(((u)r[16] + 3043), r[8]);
    SWR(((u)r[16] + 3040), r[8]);
    r[2] = *(int *)((u)r[16] + 76);
    r[5] = (u)r[16] + 3036;
    r[4] = *(int *)((u)r[2] + 8);
    r[6] = (u)0 + -1; CALL(R_HZD_GetAddress);
    r[3] = *(int *)((u)r[16] + 3048);
    *(int *)((u)r[16] + 3056) = r[2];
    *(int *)((u)r[16] + 3060) = r[3];
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
