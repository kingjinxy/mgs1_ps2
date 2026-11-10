extern char R_HZD_SetDynamicSegment[] __asm__("HZD_SetDynamicSegment");
int G_s17a_800E377C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s17a_800E377C");
int G_s17a_800E377C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(32)
    r[29] = (u)r[29] + -32;
    *(int *)((u)r[29] + 20) = r[17];
    r[17] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 24) = r[18];
    r[18] = (u)r[5] + (u)0;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[6] + (u)0;
    c = (((int)r[16] <= 0)); *(int *)((u)r[29] + 28) = r[31]; if (c) goto L800e37bc;
    L800e37a0:;
    r[4] = (u)r[17] + (u)0;
    r[5] = (u)r[18] + (u)0; CALL(R_HZD_SetDynamicSegment);
    r[17] = (u)r[17] + 16;
    r[16] = (u)r[16] + -1;
    c = (((int)r[16] > 0)); r[18] = (u)r[18] + 16; if (c) goto L800e37a0;
    L800e37bc:;
    r[31] = *(int *)((u)r[29] + 28);
    r[18] = *(int *)((u)r[29] + 24);
    r[17] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 32; goto out;
out:
    RECOMP_RETURN;
}
