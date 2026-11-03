extern char R_DG_DequeuePrim[] __asm__("DG_DequeuePrim");
extern char R_DG_FreePrim[] __asm__("DG_FreePrim");
extern char R_GM_FreeControl[] __asm__("GM_FreeControl");
extern char R_GM_FreeObject[] __asm__("GM_FreeObject");
extern char R_GM_FreeTarget[] __asm__("GM_FreeTarget");
extern char R_GM_ResetHomingTarget[] __asm__("GM_ResetHomingTarget");
int G_s10a_800DCE18(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s10a_800DCE18");
int G_s10a_800DCE18(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(32)
    r[29] = (u)r[29] + -32;
    *(int *)((u)r[29] + 20) = r[17];
    r[17] = (u)r[4] + (u)0;
    r[4] = (u)r[17] + 36;
    *(int *)((u)r[29] + 24) = r[31];
    *(int *)((u)r[29] + 16) = r[16]; CALL(R_GM_FreeControl);
    r[4] = (u)r[17] + 160; CALL(R_GM_FreeObject);
    r[16] = *(int *)((u)r[17] + 1748);
    c = ((r[16] == 0));  if (c) goto L800dce5c;
    r[4] = (u)r[16] + (u)0; CALL(R_DG_DequeuePrim);
    r[4] = (u)r[16] + (u)0; CALL(R_DG_FreePrim);
    L800dce5c:;
    r[4] = *(int *)((u)r[17] + 1628);
     CALL(R_GM_FreeTarget);
    r[4] = *(int *)((u)r[17] + 1632);
     CALL(R_GM_FreeTarget);
    r[4] = *(int *)((u)r[17] + 1636);
     CALL(R_GM_ResetHomingTarget);
    r[31] = *(int *)((u)r[29] + 24);
    r[17] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 32; goto out;
out:
    RECOMP_RETURN;
}
