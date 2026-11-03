extern char R_dword_8009F480[] __asm__("dword_8009F480");
extern char R_s10a_dat_800C3684[] __asm__("s10a_dat_800C3684");
extern char R_DG_DequeuePrim[] __asm__("DG_DequeuePrim");
extern char R_DG_FreePrim[] __asm__("DG_FreePrim");
extern char R_GM_FreeControl[] __asm__("GM_FreeControl");
extern char R_GM_FreeObject[] __asm__("GM_FreeObject");
extern char R_GM_FreeTarget[] __asm__("GM_FreeTarget");
int G_s10a_800D2ED0(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s10a_800D2ED0");
int G_s10a_800D2ED0(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    r[4] = (u)r[16] + 156;
    r[2] = 0;
    *(int *)((u)r[2] + (int)R_s10a_dat_800C3684) = 0;
    r[2] = 0;
    *(int *)((u)r[29] + 20) = r[31];
    *(int *)((u)r[2] + (int)R_dword_8009F480) = 0; CALL(R_GM_FreeObject);
    r[4] = (u)r[16] + 500; CALL(R_GM_FreeObject);
    r[4] = *(int *)((u)r[16] + 480);
     CALL(R_GM_FreeTarget);
    r[4] = (u)r[16] + 32; CALL(R_GM_FreeControl);
    r[16] = *(int *)((u)r[16] + 808);
    c = ((r[16] == 0));  if (c) goto L800d2f34;
    r[4] = (u)r[16] + (u)0; CALL(R_DG_DequeuePrim);
    r[4] = (u)r[16] + (u)0; CALL(R_DG_FreePrim);
    L800d2f34:;
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
