extern char R_ZAKO14_EYE_LENGTH[] __asm__("ZAKO14_EYE_LENGTH");
int G_s14e_800C6E6C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s14e_800C6E6C");
int G_s14e_800C6E6C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[2] = (u)0 + 30000;
    r[3] = (u)r[4] + 32;
    *(short *)((u)r[4] + 32) = r[2];
    *(short *)((u)r[3] + 2) = r[2];
    *(short *)((u)r[3] + 4) = r[2];
    r[2] = (u)0 + 1;
    *(char *)((u)r[4] + 2940) = r[2];
    r[2] = (u)0 + 1;
    *(short *)((u)r[4] + 2852) = r[2];
    r[2] = *(int *)((u)r[4] + 2536);
    r[3] = *(int *)((u)r[4] + 3048);
    *(int *)((u)r[4] + 2532) = 0;
    *(short *)((u)r[4] + 2848) = 0;
    *(short *)((u)r[4] + 2850) = 0;
    *(short *)((u)r[4] + 2854) = 0;
    *(int *)((u)r[4] + 2856) = 0;
    r[2] = (u)r[2] + -1;
    *(int *)((u)r[4] + 2868) = r[2];
    r[2] = 0;
    *(int *)((u)r[4] + 3060) = r[3];
    r[3] = *(unsigned short *)((u)r[2] + (int)R_ZAKO14_EYE_LENGTH);
    r[2] = (u)0 + 512;
    r[5] = LWL(((u)r[4] + 3035), r[5]);
    r[5] = LWR(((u)r[4] + 3032), r[5]);
    r[6] = LWL(((u)r[4] + 3039), r[6]);
    r[6] = LWR(((u)r[4] + 3036), r[6]);
    SWL(((u)r[4] + 3043), r[5]);
    SWR(((u)r[4] + 3040), r[5]);
    SWL(((u)r[4] + 3047), r[6]);
    SWR(((u)r[4] + 3044), r[6]);
    *(short *)((u)r[4] + 2958) = r[2];
    *(short *)((u)r[4] + 2960) = r[3];
    r[3] = *(int *)((u)r[4] + 3052);
    r[2] = (u)0 + 1;
    *(int *)((u)r[4] + 2968) = 0;
    *(short *)((u)r[4] + 2956) = 0;
    *(short *)((u)r[4] + 2890) = 0;
    *(int *)((u)r[4] + 2876) = r[2];
    *(short *)((u)r[4] + 3136) = 0;
    *(int *)((u)r[4] + 3064) = r[3];
    r[5] = LWL(((u)r[4] + 3035), r[5]);
    r[5] = LWR(((u)r[4] + 3032), r[5]);
    r[6] = LWL(((u)r[4] + 3039), r[6]);
    r[6] = LWR(((u)r[4] + 3036), r[6]);
    SWL(((u)r[4] + 3103), r[5]);
    SWR(((u)r[4] + 3100), r[5]);
    SWL(((u)r[4] + 3107), r[6]);
    SWR(((u)r[4] + 3104), r[6]);
    r[2] = *(int *)((u)r[4] + 3048);
    *(int *)((u)r[4] + 3088) = r[2];
    *(int *)((u)r[4] + 3056) = r[2]; goto out;
out:
    RECOMP_RETURN;
}
