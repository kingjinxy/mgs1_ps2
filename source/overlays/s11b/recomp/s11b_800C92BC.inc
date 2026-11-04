extern char R_s11b_800C9154[] __asm__("s11b_800C9154");
extern char R_s11b_800C91CC[] __asm__("s11b_800C91CC");
extern char R_s11b_dat_800DAA58[] __asm__("s11b_dat_800DAA58");
extern char R_GV_DestroyActor[] __asm__("GV_DestroyActor");
extern char R_GV_NewActor[] __asm__("GV_NewActor");
extern char R_GV_SetNamedActor[] __asm__("GV_SetNamedActor");
extern char R_s11b_800C91FC[] __asm__("s11b_800C91FC");
int G_s11b_800C92BC(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s11b_800C92BC");
int G_s11b_800C92BC(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(32)
    r[29] = (u)r[29] + -32;
    *(int *)((u)r[29] + 20) = r[17];
    r[17] = (u)r[4] + (u)0;
    r[4] = (u)0 + 7;
    r[5] = (u)0 + 44;
    *(int *)((u)r[29] + 24) = r[31];
    *(int *)((u)r[29] + 16) = r[16]; CALL(R_GV_NewActor);
    r[16] = (u)r[2] + (u)0;
    c = ((r[16] == 0)); r[4] = (u)r[16] + (u)0; if (c) goto L800c9328;
    r[5] = 0;
    r[5] = (u)r[5] + (int)R_s11b_800C9154;
    r[6] = 0;
    r[7] = 0;
    r[6] = (u)r[6] + (int)R_s11b_800C91CC;
    r[7] = (u)r[7] + ((int)R_s11b_dat_800DAA58 + 104); CALL(R_GV_SetNamedActor);
    r[4] = (u)r[16] + (u)0; CALL(R_s11b_800C91FC);
    c = (((int)r[2] >= 0));  if (c) goto L800c9324;
    r[4] = (u)r[16] + (u)0; CALL(R_GV_DestroyActor);
    r[2] = (u)0 + (u)0; goto L800c932c;
    L800c9324:;
    *(int *)((u)r[16] + 40) = r[17];
    L800c9328:;
    r[2] = (u)r[16] + (u)0;
    L800c932c:;
    r[31] = *(int *)((u)r[29] + 24);
    r[17] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 32; goto out;
out:
    RECOMP_RETURN;
}
