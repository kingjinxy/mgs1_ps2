extern char R_GM_PlayerPosition[] __asm__("GM_PlayerPosition");
extern char R_s19a_800DBA10[] __asm__("s19a_800DBA10");
extern char R_GM_ConfigObjectAction[] __asm__("GM_ConfigObjectAction");
extern char R_GV_SubVec3[] __asm__("GV_SubVec3");
extern char R_ratan2[] __asm__("ratan2");
int G_s19a_800DBC28(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s19a_800DBC28");
int G_s19a_800DBC28(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(32)
    r[29] = (u)r[29] + -32;
    *(int *)((u)r[29] + 24) = r[16];
    r[16] = (u)r[4] + (u)0;
    c = ((r[5] != 0)); *(int *)((u)r[29] + 28) = r[31]; if (c) goto L800dbc54;
    *(int *)((u)r[16] + 2044) = 0;
    r[4] = (u)r[16] + 164;
    r[5] = (u)0 + (u)0;
    r[6] = (u)r[5] + (u)0;
    r[7] = (u)0 + 4; CALL(R_GM_ConfigObjectAction);
    L800dbc54:;
    r[4] = 0;
    r[4] = (u)r[4] + (int)R_GM_PlayerPosition;
    r[5] = (u)r[16] + 40;
    r[6] = (u)r[29] + 16; CALL(R_GV_SubVec3);
    r[4] = *(short *)((u)r[29] + 20);
    r[5] = *(short *)((u)r[29] + 16);
     CALL(R_ratan2);
    r[3] = *(short *)((u)r[16] + 50);
    r[2] = (u)0 - (u)r[2];
    r[3] = (u)r[2] - (u)r[3];
    r[3] = r[3] & 4095;
    r[2] = r[3] & 2048;
    c = ((r[2] == 0)); r[2] = (int)r[3] < -1024; if (c) goto L800dbc9c;
    r[3] = (u)r[3] + -4096;
    r[2] = (int)r[3] < -1024;
    L800dbc9c:;
    c = ((r[2] == 0)); r[2] = (int)r[3] < 1025; if (c) goto L800dbcac;
    r[3] = (u)0 + -1024;
    r[2] = (int)r[3] < 1025;
    L800dbcac:;
    c = ((r[2] != 0));  if (c) goto L800dbcb8;
    r[3] = (u)0 + 1024;
    L800dbcb8:;
    r[2] = *(int *)((u)r[16] + 2048);
    r[2] = r[2] & 8192;
    c = ((r[2] != 0)); *(int *)((u)r[16] + 2020) = r[3]; if (c) goto L800dbce8;
    r[2] = 0;
    r[2] = (u)r[2] + (int)R_s19a_800DBA10;
    *(int *)((u)r[16] + 2028) = r[2];
    *(int *)((u)r[16] + 2036) = 0;
    *(short *)((u)r[16] + 120) = 0;
    *(short *)((u)r[16] + 116) = 0;
    *(int *)((u)r[16] + 2020) = 0;
    L800dbce8:;
    r[31] = *(int *)((u)r[29] + 28);
    r[16] = *(int *)((u)r[29] + 24);
    r[29] = (u)r[29] + 32; goto out;
out:
    RECOMP_RETURN;
}
