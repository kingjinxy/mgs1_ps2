extern char R_DG_PutVector[] __asm__("DG_PutVector");
extern char R_DG_SetPos2[] __asm__("DG_SetPos2");
extern char R_HZD_SetDynamicSegment[] __asm__("HZD_SetDynamicSegment");
int G_s15a_800C9740(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s15a_800C9740");
int G_s15a_800C9740(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(48)
    r[29] = (u)r[29] + -48;
    *(int *)((u)r[29] + 32) = r[16];
    r[16] = (u)r[4] + (u)0;
    r[4] = (u)r[16] + 36;
    r[5] = (u)r[16] + 44;
    r[2] = (u)0 + -500;
    *(short *)((u)r[29] + 16) = r[2];
    r[2] = (u)0 + -1000;
    *(int *)((u)r[29] + 36) = r[17];
    r[17] = (u)0 + 500;
    *(int *)((u)r[29] + 40) = r[31];
    *(short *)((u)r[29] + 18) = 0;
    *(short *)((u)r[29] + 20) = r[2];
    *(short *)((u)r[29] + 24) = r[17];
    *(short *)((u)r[29] + 26) = 0;
    *(short *)((u)r[29] + 28) = r[2]; CALL(R_DG_SetPos2);
    r[4] = (u)r[29] + 16;
    r[5] = (u)r[4] + (u)0;
    r[6] = (u)0 + 2; CALL(R_DG_PutVector);
    r[2] = (u)0 + 1500;
    *(short *)((u)r[16] + 2348) = r[17];
    *(short *)((u)r[16] + 2350) = r[2];
    *(short *)((u)r[16] + 2356) = r[17];
    *(short *)((u)r[16] + 2358) = r[2];
    r[2] = *(unsigned short *)((u)r[29] + 16);
    *(short *)((u)r[16] + 2344) = r[2];
    r[2] = *(unsigned short *)((u)r[29] + 24);
    *(short *)((u)r[16] + 2352) = r[2];
    r[2] = *(unsigned short *)((u)r[29] + 20);
    r[4] = (u)r[16] + 2344;
    *(short *)((u)r[16] + 2346) = r[2];
    r[2] = *(unsigned short *)((u)r[29] + 28);
    r[5] = (u)r[4] + (u)0;
    *(short *)((u)r[16] + 2354) = r[2]; CALL(R_HZD_SetDynamicSegment);
    r[31] = *(int *)((u)r[29] + 40);
    r[17] = *(int *)((u)r[29] + 36);
    r[16] = *(int *)((u)r[29] + 32);
    r[29] = (u)r[29] + 48; goto out;
out:
    RECOMP_RETURN;
}
