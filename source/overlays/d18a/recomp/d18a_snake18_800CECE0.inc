extern char R_d18a_dword_800DAEF0[] __asm__("d18a_dword_800DAEF0");
extern char R_d18a_rc_800D3508[] __asm__("d18a_rc_800D3508");
extern char R_d18a_rc_800D37FC[] __asm__("d18a_rc_800D37FC");
extern char R_d18a_snake18_800CE7BC[] __asm__("d18a_snake18_800CE7BC");
int G_d18a_snake18_800CECE0(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("d18a_snake18_800CECE0");
int G_d18a_snake18_800CECE0(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[2] = 0;
    r[3] = 0;
    r[3] = *(int *)((u)r[3] + (int)R_d18a_dword_800DAEF0);
    r[2] = (u)r[2] + (int)R_d18a_snake18_800CE7BC;
    *(int *)((u)r[4] + 2236) = r[2];
    c = (((int)r[3] < 0)); *(int *)((u)r[4] + 2240) = r[2]; if (c) goto L800ced08;
    r[2] = 0;
    r[2] = (u)r[2] + (int)R_d18a_rc_800D3508; goto L800ced10;
    L800ced08:;
    r[2] = 0;
    r[2] = (u)r[2] + (int)R_d18a_rc_800D37FC;
    L800ced10:;
    *(int *)((u)r[4] + 2220) = r[2];
    *(int *)((u)r[4] + 2224) = 0;
    *(short *)((u)r[4] + 2322) = 0;
    *(short *)((u)r[4] + 2320) = 0;
    *(short *)((u)r[4] + 112) = 0;
    *(short *)((u)r[4] + 108) = 0; goto out;
out:
    RECOMP_RETURN;
}
