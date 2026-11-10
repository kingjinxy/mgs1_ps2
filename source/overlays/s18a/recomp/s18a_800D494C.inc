extern char R_GV_DestroyActor[] __asm__("GV_DestroyActor");
extern char R_HZD_GetAddress[] __asm__("HZD_GetAddress");
int G_s18a_800D494C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s18a_800D494C");
int G_s18a_800D494C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 20) = r[31];
    r[3] = *(int *)((u)r[16] + 2964);
    r[2] = *(int *)((u)r[16] + 2704);
    r[3] = (u)r[3] + 1;
    r[2] = (int)r[3] < (int)r[2];
    c = ((r[2] != 0)); r[2] = (u)r[3] << 3; if (c) goto L800d497c;
    r[3] = (u)0 + (u)0;
    r[2] = (u)r[3] << 3;
    L800d497c:;
    r[2] = (u)r[16] + (u)r[2];
    *(int *)((u)r[16] + 2964) = r[3];
    r[7] = LWL(((u)r[2] + 2711), r[7]);
    r[7] = LWR(((u)r[2] + 2708), r[7]);
    r[8] = LWL(((u)r[2] + 2715), r[8]);
    r[8] = LWR(((u)r[2] + 2712), r[8]);
    SWL(((u)r[16] + 2979), r[7]);
    SWR(((u)r[16] + 2976), r[7]);
    SWL(((u)r[16] + 2983), r[8]);
    SWR(((u)r[16] + 2980), r[8]);
    r[2] = *(int *)((u)r[16] + 76);
    r[5] = (u)r[16] + 2976;
    r[4] = *(int *)((u)r[2] + 8);
    r[6] = (u)0 + -1; CALL(R_HZD_GetAddress);
    *(int *)((u)r[16] + 2996) = r[2];
    r[2] = (u)0 + 31;
    r[3] = *(short *)((u)r[16] + 2982);
    r[4] = *(int *)((u)r[16] + 2988);
    r[3] = r[3] & 31;
    c = ((r[3] != r[2])); *(int *)((u)r[16] + 3000) = r[4]; if (c) goto L800d49dc;
    r[4] = (u)r[16] + (u)0; CALL(R_GV_DestroyActor);
    L800d49dc:;
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
