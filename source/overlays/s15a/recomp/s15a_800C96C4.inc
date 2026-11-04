extern char R_GM_GetMap[] __asm__("GM_GetMap");
extern char R_HZD_QueueDynamicSegment2[] __asm__("HZD_QueueDynamicSegment2");
int G_s15a_800C96C4(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s15a_800C96C4");
int G_s15a_800C96C4(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(32)
    r[29] = (u)r[29] + -32;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 24) = r[31];
    *(int *)((u)r[29] + 20) = r[17];
    r[4] = *(int *)((u)r[16] + 32);
    r[17] = (u)r[5] + (u)0; CALL(R_GM_GetMap);
    r[5] = (u)r[16] + 2344;
    r[4] = *(int *)((u)r[2] + 8);
    r[6] = (u)r[17] + (u)0; CALL(R_HZD_QueueDynamicSegment2);
    r[31] = *(int *)((u)r[29] + 24);
    r[17] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 32; goto out;
out:
    RECOMP_RETURN;
}
