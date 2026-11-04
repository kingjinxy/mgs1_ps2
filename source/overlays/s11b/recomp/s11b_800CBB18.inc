extern char R_GM_GameStatus[] __asm__("GM_GameStatus");
extern char R_DG_DequeuePrim[] __asm__("DG_DequeuePrim");
extern char R_DG_FreePrim[] __asm__("DG_FreePrim");
extern char R_GCL_ForceExecProc[] __asm__("GCL_ForceExecProc");
extern char R_GM_FreeObject[] __asm__("GM_FreeObject");
int G_s11b_800CBB18(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s11b_800CBB18");
int G_s11b_800CBB18(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(32)
    r[29] = (u)r[29] + -32;
    *(int *)((u)r[29] + 24) = r[18];
    r[18] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 28) = r[31];
    *(int *)((u)r[29] + 20) = r[17];
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = *(int *)((u)r[18] + 40);
    c = ((r[16] == 0)); r[17] = (u)0 + (u)0; if (c) goto L800cbb54;
    r[4] = (u)r[16] + (u)0; CALL(R_DG_DequeuePrim);
    r[4] = (u)r[16] + (u)0; CALL(R_DG_FreePrim);
    r[17] = (u)0 + (u)0;
    L800cbb54:;
    r[16] = (u)0 + 20588;
    L800cbb58:;
    r[4] = (u)r[18] + (u)r[16]; CALL(R_GM_FreeObject);
    r[17] = (u)r[17] + 1;
    r[2] = (int)r[17] < 16;
    c = ((r[2] != 0)); r[16] = (u)r[16] + 228; if (c) goto L800cbb58;
    r[5] = 0xefff0000;
    r[5] = r[5] | 65535;
    r[3] = 0;
    r[2] = *(int *)((u)r[3] + (int)R_GM_GameStatus);
    r[4] = *(int *)((u)r[18] + 27392);
    r[2] = r[2] & r[5];
    r[5] = (u)0 + (u)0;
    *(int *)((u)r[3] + (int)R_GM_GameStatus) = r[2]; CALL(R_GCL_ForceExecProc);
    r[31] = *(int *)((u)r[29] + 28);
    r[18] = *(int *)((u)r[29] + 24);
    r[17] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 32; goto out;
out:
    RECOMP_RETURN;
}
