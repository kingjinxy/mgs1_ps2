extern char R_GM_ConfigObjectAction[] __asm__("GM_ConfigObjectAction");
int G_s17a_800DEBEC(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s17a_800DEBEC");
int G_s17a_800DEBEC(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(32)
    r[29] = (u)r[29] + -32;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 20) = r[17];
    r[17] = (u)r[5] + (u)0;
    *(int *)((u)r[29] + 28) = r[31];
    *(int *)((u)r[29] + 24) = r[18];
    r[2] = *(short *)((u)r[16] + 170);
    c = ((r[2] == r[17])); r[18] = (u)r[6] + (u)0; if (c) goto L800dec54;
    *(int *)((u)r[16] + 1804) = r[17];
    r[4] = (u)r[16] + 156;
    r[6] = (u)0 + (u)0;
    r[7] = (u)r[18] + (u)0; CALL(R_GM_ConfigObjectAction);
    r[4] = (u)r[16] + 384;
    r[5] = (u)r[17] + (u)0;
    r[6] = (u)0 + (u)0;
    r[7] = (u)r[18] + (u)0; CALL(R_GM_ConfigObjectAction);
    r[4] = (u)r[16] + 612;
    r[5] = (u)r[17] + (u)0;
    r[6] = (u)0 + (u)0;
    r[7] = (u)r[18] + (u)0; CALL(R_GM_ConfigObjectAction);
    L800dec54:;
    r[31] = *(int *)((u)r[29] + 28);
    r[18] = *(int *)((u)r[29] + 24);
    r[17] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 32; goto out;
out:
    RECOMP_RETURN;
}
