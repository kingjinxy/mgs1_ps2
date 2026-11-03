extern char R_GM_GameStatus[] __asm__("GM_GameStatus");
extern char R_DG_GetLightMatrix2[] __asm__("DG_GetLightMatrix2");
extern char R_GM_ConfigObjectLight[] __asm__("GM_ConfigObjectLight");
extern char R_s10a_800C5320[] __asm__("s10a_800C5320");
int G_s10a_800C53A0(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s10a_800C53A0");
int G_s10a_800C53A0(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(32)
    r[29] = (u)r[29] + -32;
    *(int *)((u)r[29] + 20) = r[17];
    r[17] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 24) = r[31];
    *(int *)((u)r[29] + 16) = r[16];
    r[2] = *(short *)((u)r[17] + 340);
    c = ((r[2] == 0)); r[2] = 0; if (c) goto L800c5448;
    r[2] = *(int *)((u)r[2] + (int)R_GM_GameStatus);
    r[2] = r[2] & 8;
    c = ((r[2] == 0));  if (c) goto L800c541c;
    r[2] = *(short *)((u)r[17] + 342);
    c = ((r[2] != 0)); r[4] = (u)r[17] + 324; if (c) goto L800c5448;
    r[16] = (u)r[17] + 260;
    r[5] = (u)r[16] + (u)0;
    r[3] = *(int *)((u)r[17] + 32);
    r[2] = (u)0 + 861;
    *(int *)((u)r[17] + 36) = r[2];
    *(int *)((u)r[3] + 40) = r[2]; CALL(R_DG_GetLightMatrix2);
    r[4] = (u)r[17] + 32;
    r[5] = (u)r[16] + (u)0; CALL(R_GM_ConfigObjectLight);
    r[2] = (u)0 + 1;
    *(short *)((u)r[17] + 342) = r[2]; goto L800c5448;
    L800c541c:;
    r[2] = *(short *)((u)r[17] + 342);
    c = ((r[2] == 0)); r[2] = (u)0 + 599; if (c) goto L800c5448;
    r[3] = *(int *)((u)r[17] + 32);
    *(int *)((u)r[17] + 36) = r[2];
    *(int *)((u)r[3] + 40) = r[2];
    r[4] = *(int *)((u)r[17] + 32);
     CALL(R_s10a_800C5320);
    *(short *)((u)r[17] + 342) = 0;
    L800c5448:;
    r[31] = *(int *)((u)r[29] + 24);
    r[17] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 32; goto out;
out:
    return r[2];
}
