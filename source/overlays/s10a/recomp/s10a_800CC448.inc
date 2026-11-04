int G_s10a_800CC448(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s10a_800CC448");
int G_s10a_800CC448(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[2] = *(int *)((u)r[4] + 3044);
    *(int *)((u)r[4] + 3056) = r[2];
    r[3] = LWL(((u)r[4] + 3031), r[3]);
    r[3] = LWR(((u)r[4] + 3028), r[3]);
    r[5] = LWL(((u)r[4] + 3035), r[5]);
    r[5] = LWR(((u)r[4] + 3032), r[5]);
    SWL(((u)r[4] + 3039), r[3]);
    SWR(((u)r[4] + 3036), r[3]);
    SWL(((u)r[4] + 3043), r[5]);
    SWR(((u)r[4] + 3040), r[5]);
    r[2] = *(int *)((u)r[4] + 3048);
    *(int *)((u)r[4] + 3060) = r[2]; goto out;
out:
    RECOMP_RETURN;
}
