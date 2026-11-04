extern char R__overlay_bss_objend[] __asm__("_overlay_bss_objend");
extern char R_s14e_dword_800DD828[] __asm__("s14e_dword_800DD828");
extern char R_s14e_dword_800DD82C[] __asm__("s14e_dword_800DD82C");
extern char R_s14e_dword_800DD830[] __asm__("s14e_dword_800DD830");
extern char R_s14e_dword_800DD834[] __asm__("s14e_dword_800DD834");
extern char R_s14e_dword_800DDE3C[] __asm__("s14e_dword_800DDE3C");
int G_s14e_800D87D0(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s14e_800D87D0");
int G_s14e_800D87D0(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[5] = (u)r[4] + (u)0;
    r[2] = (int)r[5] < 256;
    c = ((r[2] != 0)); r[2] = 0; if (c) goto L800d87e4;
    r[5] = (u)0 + 255;
    L800d87e4:;
    r[3] = *(int *)((u)r[2] + (int)R_s14e_dword_800DD82C);
    r[2] = 0;
    *(int *)((u)r[2] + (int)R_s14e_dword_800DD828) = r[5];
    r[2] = (u)r[5] + (u)r[3];
    r[2] = (int)r[2] < 256;
    c = ((r[2] != 0)); r[2] = 0; if (c) goto L800d8814;
    r[3] = 0;
    r[2] = (u)0 + 255;
    r[2] = (u)r[2] - (u)r[5];
    *(int *)((u)r[3] + (int)R_s14e_dword_800DD834) = r[2]; goto L800d8818;
    L800d8814:;
    *(int *)((u)r[2] + (int)R_s14e_dword_800DD834) = r[3];
    L800d8818:;
    r[2] = 0;
    r[3] = 0;
    r[2] = *(int *)((u)r[2] + (int)R_s14e_dword_800DD834);
    r[4] = 0;
    r[2] = (u)r[5] + (u)r[2];
    *(int *)((u)r[3] + (int)R_s14e_dword_800DD830) = r[2];
    r[2] = 0;
    r[2] = *(int *)((u)r[2] + (int)R_s14e_dword_800DDE3C);
    r[3] = (u)r[5] << 1;
    r[2] = (u)r[2] - (u)r[3];
    *(int *)((u)r[4] + ((int)R__overlay_bss_objend + 4)) = r[2]; goto out;
out:
    RECOMP_RETURN;
}
