extern char R_GM_PlayerStatus[] __asm__("GM_PlayerStatus");
extern char R_d18a_rc_800D2F70[] __asm__("d18a_rc_800D2F70");
extern char R_GM_ConfigObjectAction[] __asm__("GM_ConfigObjectAction");
int G_d18a_snake18_800D1F90(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("d18a_snake18_800D1F90");
int G_d18a_snake18_800D1F90(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    c = ((r[5] != 0)); *(int *)((u)r[29] + 20) = r[31]; if (c) goto L800d1ffc;
    r[2] = 0;
    r[3] = *(int *)((u)r[16] + 2216);
    r[2] = (u)r[2] + (int)R_d18a_rc_800D2F70;
    *(int *)((u)r[16] + 2236) = r[2];
    *(int *)((u)r[16] + 2240) = r[2];
    r[2] = *(int *)((u)r[3] + 16);
    r[5] = *(unsigned char *)((u)r[2] + 0);
    r[2] = *(short *)((u)r[16] + 170);
    c = ((r[2] == r[5])); r[4] = (u)r[16] + 156; if (c) goto L800d1fe0;
    r[6] = (u)0 + (u)0;
    r[7] = (u)0 + 4; CALL(R_GM_ConfigObjectAction);
    L800d1fe0:;
    r[4] = 0xffff0000;
    r[3] = 0;
    r[2] = *(int *)((u)r[3] + (int)R_GM_PlayerStatus);
    r[4] = r[4] | 32671;
    *(short *)((u)r[16] + 2302) = 0;
    r[2] = r[2] & r[4];
    *(int *)((u)r[3] + (int)R_GM_PlayerStatus) = r[2];
    L800d1ffc:;
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
