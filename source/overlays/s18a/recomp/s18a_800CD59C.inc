extern char R_GCL_ExecProc[] __asm__("GCL_ExecProc");
extern char R_GM_AlertModeSet[] __asm__("GM_AlertModeSet");
extern char R_s18a_800C5200[] __asm__("s18a_800C5200");
extern char R_s18a_800C7124[] __asm__("s18a_800C7124");
extern char R_s18a_800CCDA8[] __asm__("s18a_800CCDA8");
int G_s18a_800CD59C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s18a_800CD59C");
int G_s18a_800CD59C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[16];
    *(int *)((u)r[29] + 20) = r[31];
    r[16] = (u)r[4] + (u)0; CALL(R_s18a_800CCDA8);
    r[2] = *(short *)((u)r[16] + 2494);
    c = ((r[2] == 0)); r[4] = (u)0 + 5400; if (c) goto L800cd60c;
    r[5] = (u)0 + -1; CALL(R_s18a_800C7124);
    r[4] = (u)0 + 4; CALL(R_GM_AlertModeSet);
    r[4] = (u)0 + 4; CALL(R_s18a_800C5200);
    r[4] = *(int *)((u)r[16] + 2536);
    r[2] = (u)0 + 18;
    c = (((int)r[4] < 0)); *(int *)((u)r[16] + 2404) = r[2]; if (c) goto L800cd5f0;
    r[5] = (u)0 + (u)0; CALL(R_GCL_ExecProc);
    L800cd5f0:;
    r[3] = *(int *)((u)r[16] + 384);
    r[2] = *(int *)((u)r[3] + 40);
    r[2] = r[2] | 128;
    *(int *)((u)r[3] + 40) = r[2]; goto L800cd614;
    L800cd60c:;
    r[2] = (u)0 + 1;
    *(int *)((u)r[16] + 2404) = r[2];
    L800cd614:;
    *(int *)((u)r[16] + 2428) = 0;
    *(int *)((u)r[16] + 2408) = 0;
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
