extern char R_GM_CheckMessage[] __asm__("GM_CheckMessage");
extern char R_GV_DestroyActor[] __asm__("GV_DestroyActor");
extern char R_s17a_800CC368[] __asm__("s17a_800CC368");
extern char R_s17a_800CC5A8[] __asm__("s17a_800CC5A8");
int G_s17a_800CC7E4(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s17a_800CC7E4");
int G_s17a_800CC7E4(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 20) = r[31];
    r[5] = *(int *)((u)r[16] + 40);
    r[2] = (u)0 + -1;
    c = ((r[5] == r[2]));  if (c) goto L800cc824;
    r[6] = (u)0 + 12835; CALL(R_GM_CheckMessage);
    c = ((r[2] == 0));  if (c) goto L800cc824;
    r[4] = (u)r[16] + (u)0; CALL(R_GV_DestroyActor);
     goto L800cc84c;
    L800cc824:;
    r[2] = *(int *)((u)r[16] + 36);
    c = ((r[2] == 0)); r[2] = (u)0 + 1; if (c) goto L800cc840;
    r[4] = (u)r[16] + (u)0; CALL(R_s17a_800CC5A8);
    r[2] = (u)0 + 1;
    L800cc840:;
    *(int *)((u)r[16] + 36) = r[2];
    r[4] = (u)r[16] + (u)0; CALL(R_s17a_800CC368);
    L800cc84c:;
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
