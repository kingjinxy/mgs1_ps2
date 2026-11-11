extern char R_s19b_spark2_m_800D91DC[] __asm__("s19b_spark2_m_800D91DC");
extern char R_GM_ConfigObjectAction[] __asm__("GM_ConfigObjectAction");
extern char R_s19b_spark2_m_800D88D8[] __asm__("s19b_spark2_m_800D88D8");
int G_s19b_spark2_m_800D9148(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s19b_spark2_m_800D9148");
int G_s19b_spark2_m_800D9148(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(32)
    r[29] = (u)r[29] + -32;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 24) = r[31];
    *(int *)((u)r[29] + 20) = r[17];
    r[2] = *(int *)((u)r[16] + 2304);
    r[2] = r[2] & 16;
    c = ((r[2] == 0)); r[17] = (u)r[5] + (u)0; if (c) goto L800d91b0;
    r[4] = (u)r[16] + (u)0; CALL(R_s19b_spark2_m_800D88D8);
    c = ((r[2] != 0));  if (c) goto L800d91c8;
    c = ((r[17] != 0)); r[2] = (int)r[17] < 91; if (c) goto L800d91a8;
    r[2] = (u)0 + 17;
    *(int *)((u)r[16] + 2300) = r[2];
    r[4] = (u)r[16] + 164;
    r[5] = (u)r[2] + (u)0;
    r[6] = (u)0 + (u)0;
    r[7] = (u)0 + 4; CALL(R_GM_ConfigObjectAction);
    r[2] = (int)r[17] < 91;
    L800d91a8:;
    c = ((r[2] != 0));  if (c) goto L800d91c8;
    L800d91b0:;
    r[2] = 0;
    r[2] = (u)r[2] + (int)R_s19b_spark2_m_800D91DC;
    *(int *)((u)r[16] + 2284) = r[2];
    *(int *)((u)r[16] + 2292) = 0;
    *(short *)((u)r[16] + 120) = 0;
    *(short *)((u)r[16] + 116) = 0;
    L800d91c8:;
    r[31] = *(int *)((u)r[29] + 24);
    r[17] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 32; goto out;
out:
    RECOMP_RETURN;
}
