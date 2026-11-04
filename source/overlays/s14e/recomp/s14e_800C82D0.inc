extern char R_GM_PlayerControl[] __asm__("GM_PlayerControl");
extern char R_GM_PlayerPosition[] __asm__("GM_PlayerPosition");
extern char R_s14e_dword_800C33C4[] __asm__("s14e_dword_800C33C4");
extern char R_DG_PutVector[] __asm__("DG_PutVector");
extern char R_DG_SetPos2[] __asm__("DG_SetPos2");
extern char R_GV_SubVec3[] __asm__("GV_SubVec3");
int G_s14e_800C82D0(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s14e_800C82D0");
int G_s14e_800C82D0(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(32)
    r[29] = (u)r[29] + -32;
    *(int *)((u)r[29] + 24) = r[16];
    r[16] = (u)r[4] + (u)0;
    r[4] = 0;
    r[2] = 0;
    r[5] = *(int *)((u)r[2] + (int)R_GM_PlayerControl);
    r[4] = (u)r[4] + (int)R_GM_PlayerPosition;
    *(int *)((u)r[29] + 28) = r[31];
    r[2] = (u)r[5] + (u)0;
    r[3] = LWL(((u)r[2] + 11), r[3]);
    r[3] = LWR(((u)r[2] + 8), r[3]);
    r[7] = LWL(((u)r[2] + 15), r[7]);
    r[7] = LWR(((u)r[2] + 12), r[7]);
    SWL(((u)r[16] + 111), r[3]);
    SWR(((u)r[16] + 108), r[3]);
    SWL(((u)r[16] + 115), r[7]);
    SWR(((u)r[16] + 112), r[7]);
    r[5] = (u)r[5] + 8; CALL(R_DG_SetPos2);
    r[4] = 0;
    r[4] = (u)r[4] + (int)R_s14e_dword_800C33C4;
    r[5] = (u)r[29] + 16;
    r[6] = (u)0 + 1; CALL(R_DG_PutVector);
    r[4] = (u)r[29] + 16;
    r[5] = (u)r[16] + 32;
    r[6] = (u)r[16] + 100; CALL(R_GV_SubVec3);
    r[31] = *(int *)((u)r[29] + 28);
    r[16] = *(int *)((u)r[29] + 24);
    r[29] = (u)r[29] + 32; goto out;
out:
    RECOMP_RETURN;
}
