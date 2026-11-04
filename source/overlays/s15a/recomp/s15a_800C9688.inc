extern char R_GV_SubVec3[] __asm__("GV_SubVec3");
extern char R_ratan2[] __asm__("ratan2");
int G_s15a_800C9688(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s15a_800C9688");
int G_s15a_800C9688(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(32)
    r[29] = (u)r[29] + -32;
    r[2] = (u)r[4] + (u)0;
    r[4] = (u)r[5] + (u)0;
    r[5] = (u)r[2] + (u)0;
    *(int *)((u)r[29] + 24) = r[31];
    r[6] = (u)r[29] + 16; CALL(R_GV_SubVec3);
    r[4] = *(short *)((u)r[29] + 16);
    r[5] = *(short *)((u)r[29] + 20);
     CALL(R_ratan2);
    r[31] = *(int *)((u)r[29] + 24);
    r[2] = r[2] & 4095;
    r[29] = (u)r[29] + 32; goto out;
out:
    RECOMP_RETURN;
}
