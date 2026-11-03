extern char R_GM_CheckMessage[] __asm__("GM_CheckMessage");
extern char R_GV_DestroyActor[] __asm__("GV_DestroyActor");
extern char R_s10a_800C5278[] __asm__("s10a_800C5278");
extern char R_s10a_800C52D8[] __asm__("s10a_800C52D8");
extern char R_s10a_800C53A0[] __asm__("s10a_800C53A0");
int G_s10a_800C545C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s10a_800C545C");
int G_s10a_800C545C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[16];
    *(int *)((u)r[29] + 20) = r[31];
    r[16] = (u)r[4] + (u)0; CALL(R_s10a_800C5278);
    r[4] = (u)r[16] + (u)0; CALL(R_s10a_800C52D8);
    r[4] = (u)r[16] + (u)0; CALL(R_s10a_800C53A0);
    r[4] = (u)r[16] + (u)0;
    r[5] = *(int *)((u)r[16] + 332);
    r[6] = (u)0 + 12835; CALL(R_GM_CheckMessage);
    c = ((r[2] == 0));  if (c) goto L800c54a0;
    r[4] = (u)r[16] + (u)0; CALL(R_GV_DestroyActor);
    L800c54a0:;
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    return r[2];
}
