extern char R_DG_DequeuePrim[] __asm__("DG_DequeuePrim");
extern char R_DG_FreePrim[] __asm__("DG_FreePrim");
extern char R_GCL_ExecProc[] __asm__("GCL_ExecProc");
extern char R_GM_FreeControl[] __asm__("GM_FreeControl");
extern char R_GM_FreeObject[] __asm__("GM_FreeObject");
extern char R_GM_FreeTarget[] __asm__("GM_FreeTarget");
extern char R_s15a_800C9708[] __asm__("s15a_800C9708");
int G_s15a_800CA050(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s15a_800CA050");
int G_s15a_800CA050(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(32)
    r[29] = (u)r[29] + -32;
    *(int *)((u)r[29] + 20) = r[17];
    r[17] = (u)r[4] + (u)0;
    r[4] = (u)r[17] + 36;
    *(int *)((u)r[29] + 24) = r[31];
    *(int *)((u)r[29] + 16) = r[16]; CALL(R_GM_FreeControl);
    r[4] = (u)r[17] + 160; CALL(R_GM_FreeObject);
    r[4] = (u)r[17] + 388; CALL(R_GM_FreeObject);
    r[16] = *(int *)((u)r[17] + 1780);
    c = ((r[16] == 0));  if (c) goto L800ca09c;
    r[4] = (u)r[16] + (u)0; CALL(R_DG_DequeuePrim);
    r[4] = (u)r[16] + (u)0; CALL(R_DG_FreePrim);
    L800ca09c:;
    r[4] = *(int *)((u)r[17] + 1636);
     CALL(R_GM_FreeTarget);
    r[4] = *(int *)((u)r[17] + 1640);
     CALL(R_GM_FreeTarget);
    r[4] = *(int *)((u)r[17] + 2256);
    r[5] = (u)0 + (u)0; CALL(R_GCL_ExecProc);
    r[4] = (u)r[17] + (u)0; CALL(R_s15a_800C9708);
    r[31] = *(int *)((u)r[29] + 24);
    r[17] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 32; goto out;
out:
    RECOMP_RETURN;
}
