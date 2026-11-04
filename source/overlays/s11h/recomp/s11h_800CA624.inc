extern char R_DG_DequeueObjs[] __asm__("DG_DequeueObjs");
extern char R_DG_FreeObjs[] __asm__("DG_FreeObjs");
extern char R_DG_FreePreshade[] __asm__("DG_FreePreshade");
int G_s11h_800CA624(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s11h_800CA624");
int G_s11h_800CA624(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[16];
    *(int *)((u)r[29] + 20) = r[31];
    r[16] = (u)r[4] + (u)0; CALL(R_DG_DequeueObjs);
    r[4] = (u)r[16] + (u)0; CALL(R_DG_FreePreshade);
    r[4] = (u)r[16] + (u)0; CALL(R_DG_FreeObjs);
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
