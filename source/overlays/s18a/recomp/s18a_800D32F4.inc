extern char R_s18a_800D2418[] __asm__("s18a_800D2418");
extern char R_s18a_800D2E6C[] __asm__("s18a_800D2E6C");
extern char R_s18a_dat_800E39DC[] __asm__("s18a_dat_800E39DC");
extern char R_GV_DestroyActor[] __asm__("GV_DestroyActor");
extern char R_GV_NewActor[] __asm__("GV_NewActor");
extern char R_GV_SetNamedActor[] __asm__("GV_SetNamedActor");
extern char R_s18a_800D3020[] __asm__("s18a_800D3020");
int G_s18a_800D32F4(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s18a_800D32F4");
int G_s18a_800D32F4(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(32)
    r[29] = (u)r[29] + -32;
    *(int *)((u)r[29] + 20) = r[17];
    r[17] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 24) = r[18];
    r[18] = (u)r[5] + (u)0;
    r[4] = (u)0 + 4;
    r[5] = (u)0 + 3716;
    *(int *)((u)r[29] + 28) = r[31];
    *(int *)((u)r[29] + 16) = r[16]; CALL(R_GV_NewActor);
    r[16] = (u)r[2] + (u)0;
    c = ((r[16] == 0)); r[4] = (u)r[16] + (u)0; if (c) goto L800d336c;
    r[5] = 0;
    r[5] = (u)r[5] + (int)R_s18a_800D2418;
    r[6] = 0;
    r[6] = (u)r[6] + (int)R_s18a_800D2E6C;
    r[7] = 0;
    r[7] = (u)r[7] + ((int)R_s18a_dat_800E39DC + 48); CALL(R_GV_SetNamedActor);
    r[4] = (u)r[16] + (u)0;
    r[5] = (u)r[17] + (u)0;
    r[6] = (u)r[18] + (u)0; CALL(R_s18a_800D3020);
    c = (((int)r[2] >= 0)); r[2] = (u)r[16] + (u)0; if (c) goto L800d3370;
    r[4] = (u)r[16] + (u)0; CALL(R_GV_DestroyActor);
    r[2] = (u)0 + (u)0; goto L800d3370;
    L800d336c:;
    r[2] = (u)r[16] + (u)0;
    L800d3370:;
    r[31] = *(int *)((u)r[29] + 28);
    r[18] = *(int *)((u)r[29] + 24);
    r[17] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 32; goto out;
out:
    RECOMP_RETURN;
}
int G_s18a_rc_800D3388(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s18a_rc_800D3388");
int G_s18a_rc_800D3388(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[3] = *(int *)((u)r[4] + 32);
    r[2] = *(int *)((u)r[4] + 36);
    r[5] = *(int *)((u)r[2] + 0);
    r[6] = *(int *)((u)r[2] + 4);
    r[7] = *(int *)((u)r[2] + 8);
    r[8] = *(int *)((u)r[2] + 12);
    *(int *)((u)r[3] + 0) = r[5];
    *(int *)((u)r[3] + 4) = r[6];
    *(int *)((u)r[3] + 8) = r[7];
    *(int *)((u)r[3] + 12) = r[8];
    r[5] = *(int *)((u)r[2] + 16);
    r[6] = *(int *)((u)r[2] + 20);
    r[7] = *(int *)((u)r[2] + 24);
    r[8] = *(int *)((u)r[2] + 28);
    *(int *)((u)r[3] + 16) = r[5];
    *(int *)((u)r[3] + 20) = r[6];
    *(int *)((u)r[3] + 24) = r[7];
    *(int *)((u)r[3] + 28) = r[8];
    r[2] = *(int *)((u)r[4] + 40);
    c = ((r[2] == 0));  if (c) goto L800d3400;
    r[2] = *(int *)((u)r[4] + 32);
    r[3] = *(int *)((u)r[2] + 36);
    r[4] = (u)0 + -257;
    r[3] = r[3] & r[4];
    *(int *)((u)r[2] + 36) = r[3]; goto out;
    L800d3400:;
    r[3] = *(int *)((u)r[4] + 32);
    r[2] = *(int *)((u)r[3] + 36);
    r[2] = r[2] | 256;
    *(int *)((u)r[3] + 36) = r[2]; goto out;
out:
    RECOMP_RETURN;
}
