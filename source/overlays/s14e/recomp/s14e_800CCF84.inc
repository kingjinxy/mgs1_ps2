extern char R_s14e_dword_800DCF30[] __asm__("s14e_dword_800DCF30");
extern char R_GM_SeSet[] __asm__("GM_SeSet");
extern char R_NewEyeflash[] __asm__("NewEyeflash");
extern char R_s14e_800CA49C[] __asm__("s14e_800CA49C");
int G_s14e_800CCF84(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s14e_800CCF84");
int G_s14e_800CCF84(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(32)
    r[29] = (u)r[29] + -32;
    *(int *)((u)r[29] + 20) = r[17];
    r[17] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 24) = r[31];
    *(int *)((u)r[29] + 16) = r[16];
    r[2] = *(int *)((u)r[17] + 2856);
    c = ((r[2] != 0)); r[2] = (u)r[2] < (u)20; if (c) goto L800ccfe8;
    r[5] = (u)0 + (u)0; CALL(R_s14e_800CA49C);
    r[16] = (u)r[17] + 32;
    r[4] = (u)r[16] + (u)0;
    r[5] = (u)0 + 83; CALL(R_GM_SeSet);
    r[4] = *(int *)((u)r[17] + 156);
    r[5] = (u)r[16] + (u)0;
    r[6] = 0;
    r[6] = (u)r[6] + (int)R_s14e_dword_800DCF30;
    r[7] = (u)0 + (u)0;
    r[4] = (u)r[4] + 624; CALL(R_NewEyeflash);
    r[2] = *(int *)((u)r[17] + 2856);
    r[2] = (u)r[2] < (u)20;
    L800ccfe8:;
    c = ((r[2] != 0)); r[2] = (u)0 + (u)0; if (c) goto L800ccff8;
    r[2] = (u)0 + 1; goto L800cd010;
    L800ccff8:;
    r[3] = *(int *)((u)r[17] + 2872);
    r[4] = *(int *)((u)r[17] + 2856);
    r[3] = r[3] | 32;
    r[4] = (u)r[4] + 1;
    *(int *)((u)r[17] + 2872) = r[3];
    *(int *)((u)r[17] + 2856) = r[4];
    L800cd010:;
    r[31] = *(int *)((u)r[29] + 24);
    r[17] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 32; goto out;
out:
    RECOMP_RETURN;
}
