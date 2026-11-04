extern char R_GM_CheckMessage[] __asm__("GM_CheckMessage");
extern char R_GV_DestroyActor[] __asm__("GV_DestroyActor");
extern char R_s15a_800C4984[] __asm__("s15a_800C4984");
extern char R_s15a_800C49E4[] __asm__("s15a_800C49E4");
extern char R_s15a_800C4AAC[] __asm__("s15a_800C4AAC");
int G_s15a_800C4B68(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s15a_800C4B68");
int G_s15a_800C4B68(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[16];
    *(int *)((u)r[29] + 20) = r[31];
    r[16] = (u)r[4] + (u)0; CALL(R_s15a_800C4984);
    r[4] = (u)r[16] + (u)0; CALL(R_s15a_800C49E4);
    r[4] = (u)r[16] + (u)0; CALL(R_s15a_800C4AAC);
    r[4] = (u)r[16] + (u)0;
    r[5] = *(int *)((u)r[16] + 332);
    r[6] = (u)0 + 12835; CALL(R_GM_CheckMessage);
    c = ((r[2] == 0));  if (c) goto L800c4bac;
    r[4] = (u)r[16] + (u)0; CALL(R_GV_DestroyActor);
    L800c4bac:;
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
