extern char R_GM_CheckMessage[] __asm__("GM_CheckMessage");
extern char R_GV_DestroyActor[] __asm__("GV_DestroyActor");
extern char R_s18a_800C4504[] __asm__("s18a_800C4504");
extern char R_s18a_800C4564[] __asm__("s18a_800C4564");
extern char R_s18a_800C462C[] __asm__("s18a_800C462C");
int G_s18a_800C46E8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s18a_800C46E8");
int G_s18a_800C46E8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[16];
    *(int *)((u)r[29] + 20) = r[31];
    r[16] = (u)r[4] + (u)0; CALL(R_s18a_800C4504);
    r[4] = (u)r[16] + (u)0; CALL(R_s18a_800C4564);
    r[4] = (u)r[16] + (u)0; CALL(R_s18a_800C462C);
    r[4] = (u)r[16] + (u)0;
    r[5] = *(int *)((u)r[16] + 332);
    r[6] = (u)0 + 12835; CALL(R_GM_CheckMessage);
    c = ((r[2] == 0));  if (c) goto L800c472c;
    r[4] = (u)r[16] + (u)0; CALL(R_GV_DestroyActor);
    L800c472c:;
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
