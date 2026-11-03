extern char R_GM_PlayerBody[] __asm__("GM_PlayerBody");
extern char R_GV_NearExp8[] __asm__("GV_NearExp8");
extern char R_ratan2[] __asm__("ratan2");
int G_s10a_800CA3B4(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s10a_800CA3B4");
int G_s10a_800CA3B4(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(24)
    r[2] = 0;
    r[2] = *(int *)((u)r[2] + (int)R_GM_PlayerBody);
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 20) = r[31];
    r[3] = *(int *)((u)r[16] + 156);
    r[2] = *(int *)((u)r[2] + 0);
    r[5] = *(int *)((u)r[3] + 648);
    r[2] = *(int *)((u)r[2] + 648);
    r[4] = *(int *)((u)r[16] + 3112);
    r[5] = (u)r[2] - (u)r[5]; CALL(R_ratan2);
    r[2] = r[2] & 4095;
    r[4] = *(short *)((u)r[16] + 1844);
    r[5] = (u)r[2] + -1024; CALL(R_GV_NearExp8);
    r[3] = (u)r[2] + (u)0;
    *(short *)((u)r[16] + 1844) = r[3];
    c = (((int)r[3] >= 0)); *(short *)((u)r[16] + 1876) = r[3]; if (c) goto L800ca414;
    r[2] = (u)r[3] << 1;
    r[2] = (u)r[2] + (u)r[3]; goto L800ca428;
    L800ca414:;
    r[2] = (u)r[3] << 1;
    r[2] = (u)r[2] + (u)r[3];
    r[3] = (u)r[2] >> 31;
    r[2] = (u)r[2] + (u)r[3];
    r[2] = (int)r[2] >> 1;
    L800ca428:;
    *(short *)((u)r[16] + 1884) = r[2];
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    return r[2];
}
