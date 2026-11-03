int G_s10a_800C89F0(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s10a_800C89F0");
int G_s10a_800C89F0(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(0)
    r[2] = *(int *)((u)r[4] + 2984);
    *(int *)((u)r[4] + 2996) = r[2];
    r[3] = LWL(((u)r[4] + 2971), r[3]);
    r[3] = LWR(((u)r[4] + 2968), r[3]);
    r[5] = LWL(((u)r[4] + 2975), r[5]);
    r[5] = LWR(((u)r[4] + 2972), r[5]);
    SWL(((u)r[4] + 2979), r[3]);
    SWR(((u)r[4] + 2976), r[3]);
    SWL(((u)r[4] + 2983), r[5]);
    SWR(((u)r[4] + 2980), r[5]);
    r[2] = *(int *)((u)r[4] + 2988);
    *(int *)((u)r[4] + 3000) = r[2]; goto out;
out:
    RECOMP_RETURN;
}
