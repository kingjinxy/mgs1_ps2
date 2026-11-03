extern char R_s10a_800D3B08[] __asm__("s10a_800D3B08");
extern char R_s10a_dat_800E3F88[] __asm__("s10a_dat_800E3F88");
extern char R_s10a_rc_800D3B44[] __asm__("s10a_rc_800D3B44");
extern char R_GV_DestroyActor[] __asm__("GV_DestroyActor");
extern char R_GV_NewActor[] __asm__("GV_NewActor");
extern char R_GV_SetNamedActor[] __asm__("GV_SetNamedActor");
extern char R_s10a_800D3B4C[] __asm__("s10a_800D3B4C");
int G_s10a_800D3EB4(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s10a_800D3EB4");
int G_s10a_800D3EB4(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(32)
    r[29] = (u)r[29] + -32;
    *(int *)((u)r[29] + 20) = r[17];
    r[17] = (u)r[5] + (u)0;
    r[4] = (u)0 + 4;
    r[5] = (u)0 + 552;
    *(int *)((u)r[29] + 24) = r[31];
    *(int *)((u)r[29] + 16) = r[16]; CALL(R_GV_NewActor);
    r[16] = (u)r[2] + (u)0;
    c = ((r[16] == 0)); r[4] = (u)r[16] + (u)0; if (c) goto L800d3f20;
    r[5] = 0;
    r[5] = (u)r[5] + (int)R_s10a_rc_800D3B44;
    r[6] = 0;
    r[7] = 0;
    r[6] = (u)r[6] + (int)R_s10a_800D3B08;
    r[7] = (u)r[7] + ((int)R_s10a_dat_800E3F88 + 120); CALL(R_GV_SetNamedActor);
    r[4] = (u)r[16] + (u)0;
    r[5] = (u)r[17] + (u)0; CALL(R_s10a_800D3B4C);
    c = (((int)r[2] >= 0)); r[2] = (u)r[16] + (u)0; if (c) goto L800d3f24;
    r[4] = (u)r[16] + (u)0; CALL(R_GV_DestroyActor);
    r[2] = (u)0 + (u)0; goto L800d3f24;
    L800d3f20:;
    r[2] = (u)r[16] + (u)0;
    L800d3f24:;
    r[31] = *(int *)((u)r[29] + 24);
    r[17] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 32; goto out;
out:
    return r[2];
}
