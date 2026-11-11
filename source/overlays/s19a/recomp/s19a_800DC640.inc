extern char R_DG_MakePreshade[] __asm__("DG_MakePreshade");
extern char R_s19a_800DC674[] __asm__("s19a_800DC674");
int G_s19a_800DC640(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s19a_800DC640");
int G_s19a_800DC640(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 20) = r[31];
    r[6] = *(int *)((u)r[5] + 0);
    r[5] = (u)r[5] + 4; CALL(R_DG_MakePreshade);
    r[4] = (u)r[16] + (u)0; CALL(R_s19a_800DC674);
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
