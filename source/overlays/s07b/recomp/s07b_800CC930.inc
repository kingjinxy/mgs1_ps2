extern char R_amissile_alive_8009F490[] __asm__("amissile_alive_8009F490");
extern char R_dword_8009F470[] __asm__("dword_8009F470");
extern char R_dword_8009F480[] __asm__("dword_8009F480");
extern char R_dword_8009F49C[] __asm__("dword_8009F49C");
int G_s07b_800CC930(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s07b_800CC930");
int G_s07b_800CC930(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(0)
    r[2] = 0;
    r[2] = *(int *)((u)r[2] + (int)R_dword_8009F470);
    c = ((r[2] == 0)); r[3] = 0; if (c) goto L800cc94c;
    r[2] = (u)0 + 1;
    *(int *)((u)r[3] + (int)R_dword_8009F480) = r[2];
    L800cc94c:;
    r[2] = 0;
    r[2] = *(int *)((u)r[2] + (int)R_amissile_alive_8009F490);
    c = ((r[2] == 0)); r[3] = 0; if (c) goto L800cc968;
    r[2] = (u)0 + 1;
    *(int *)((u)r[3] + (int)R_dword_8009F49C) = r[2];
    L800cc968:;
     goto out;
out:
    return r[2];
}
