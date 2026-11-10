extern char R_s18a_800C4C74[] __asm__("s18a_800C4C74");
extern char R_s18a_dat_800E2C0C[] __asm__("s18a_dat_800E2C0C");
extern char R_s18a_rc_800C4E18[] __asm__("s18a_rc_800C4E18");
extern char R_GV_DestroyActor[] __asm__("GV_DestroyActor");
extern char R_GV_NewActor[] __asm__("GV_NewActor");
extern char R_GV_SetNamedActor[] __asm__("GV_SetNamedActor");
extern char R_s18a_800C4E20[] __asm__("s18a_800C4E20");
int G_s18a_800C5094(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s18a_800C5094");
int G_s18a_800C5094(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    r[4] = (u)0 + 4;
    r[5] = (u)0 + 164;
    *(int *)((u)r[29] + 20) = r[31];
    *(int *)((u)r[29] + 16) = r[16]; CALL(R_GV_NewActor);
    r[16] = (u)r[2] + (u)0;
    c = ((r[16] == 0)); r[4] = (u)r[16] + (u)0; if (c) goto L800c50f4;
    r[5] = 0;
    r[5] = (u)r[5] + (int)R_s18a_800C4C74;
    r[6] = 0;
    r[7] = 0;
    r[6] = (u)r[6] + (int)R_s18a_rc_800C4E18;
    r[7] = (u)r[7] + ((int)R_s18a_dat_800E2C0C + 48); CALL(R_GV_SetNamedActor);
    r[4] = (u)r[16] + (u)0; CALL(R_s18a_800C4E20);
    c = (((int)r[2] >= 0)); r[2] = (u)r[16] + (u)0; if (c) goto L800c50f8;
    r[4] = (u)r[16] + (u)0; CALL(R_GV_DestroyActor);
    r[2] = (u)0 + (u)0; goto L800c50f8;
    L800c50f4:;
    r[2] = (u)r[16] + (u)0;
    L800c50f8:;
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
