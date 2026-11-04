extern char R_GM_CheckMessage[] __asm__("GM_CheckMessage");
extern char R_GV_DestroyActor[] __asm__("GV_DestroyActor");
extern char R_s10a_800D4B24[] __asm__("s10a_800D4B24");
extern char R_s10a_800D4D64[] __asm__("s10a_800D4D64");
int G_s10a_800D4FA0(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s10a_800D4FA0");
int G_s10a_800D4FA0(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 20) = r[31];
    r[5] = *(int *)((u)r[16] + 40);
    r[2] = (u)0 + -1;
    c = ((r[5] == r[2]));  if (c) goto L800d4fe0;
    r[6] = (u)0 + 12835; CALL(R_GM_CheckMessage);
    c = ((r[2] == 0));  if (c) goto L800d4fe0;
    r[4] = (u)r[16] + (u)0; CALL(R_GV_DestroyActor);
     goto L800d5008;
    L800d4fe0:;
    r[2] = *(int *)((u)r[16] + 36);
    c = ((r[2] == 0)); r[2] = (u)0 + 1; if (c) goto L800d4ffc;
    r[4] = (u)r[16] + (u)0; CALL(R_s10a_800D4D64);
    r[2] = (u)0 + 1;
    L800d4ffc:;
    *(int *)((u)r[16] + 36) = r[2];
    r[4] = (u)r[16] + (u)0; CALL(R_s10a_800D4B24);
    L800d5008:;
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
