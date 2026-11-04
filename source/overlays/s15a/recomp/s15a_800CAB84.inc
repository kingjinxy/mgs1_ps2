extern char R_GM_PlayerPosition[] __asm__("GM_PlayerPosition");
extern char R_DG_SetPos2[] __asm__("DG_SetPos2");
extern char R_NewBulletEx[] __asm__("NewBulletEx");
extern char R_ReadRotMatrix[] __asm__("ReadRotMatrix");
extern char R_s15a_800CA824[] __asm__("s15a_800CA824");
int G_s15a_800CAB84(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s15a_800CAB84");
int G_s15a_800CAB84(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(96)
    r[29] = (u)r[29] + -96;
    r[4] = (u)r[4] + 36;
    *(int *)((u)r[29] + 80) = r[16];
    r[16] = 0;
    r[16] = (u)r[16] + (int)R_GM_PlayerPosition;
    r[5] = (u)r[16] + (u)0;
    *(int *)((u)r[29] + 84) = r[17];
    r[17] = (u)r[29] + 72;
    *(int *)((u)r[29] + 88) = r[31];
    r[6] = (u)r[17] + (u)0; CALL(R_s15a_800CA824);
    r[4] = (u)r[16] + (u)0;
    r[5] = (u)r[17] + (u)0; CALL(R_DG_SetPos2);
    r[4] = (u)r[29] + 40; CALL(R_ReadRotMatrix);
    r[4] = (u)0 + 2048;
    r[5] = (u)r[29] + 40;
    r[6] = (u)0 + 2;
    r[2] = (u)0 + 30;
    *(int *)((u)r[29] + 20) = r[2];
    r[2] = (u)0 + 90;
    *(int *)((u)r[29] + 24) = r[2];
    r[2] = (u)0 + 30000;
    *(int *)((u)r[29] + 28) = r[2];
    r[2] = (u)0 + 100;
    r[7] = (u)0 + (u)0;
    *(int *)((u)r[29] + 16) = 0;
    *(int *)((u)r[29] + 32) = r[2]; CALL(R_NewBulletEx);
    r[31] = *(int *)((u)r[29] + 88);
    r[17] = *(int *)((u)r[29] + 84);
    r[16] = *(int *)((u)r[29] + 80);
    r[29] = (u)r[29] + 96; goto out;
out:
    RECOMP_RETURN;
}
