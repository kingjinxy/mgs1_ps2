extern char R_s14e_dword_800DD828[] __asm__("s14e_dword_800DD828");
extern char R_s14e_dword_800DD830[] __asm__("s14e_dword_800DD830");
extern char R_s14e_dword_800DD834[] __asm__("s14e_dword_800DD834");
int G_s14e_800D8A10(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s14e_800D8A10");
int G_s14e_800D8A10(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[10] = (u)r[4] + (u)0;
    r[7] = (u)0 + 256;
    r[9] = 0xc000000;
    r[8] = 0xff0000;
    r[2] = 0x1f800000;
    r[3] = 0;
    r[4] = 0;
    r[5] = 0;
    r[6] = *(int *)((u)r[2] + 0);
    r[3] = *(int *)((u)r[3] + (int)R_s14e_dword_800DD828);
    r[4] = *(int *)((u)r[4] + (int)R_s14e_dword_800DD830);
    r[5] = *(int *)((u)r[5] + (int)R_s14e_dword_800DD834);
    r[8] = r[8] | 65535;
    *(int *)((u)r[2] + 12) = r[3];
    *(int *)((u)r[2] + 16) = r[4];
    *(int *)((u)r[2] + 20) = r[5];
    L800d8a50:;
    r[5] = *(int *)((u)r[6] + 0);
    c = ((r[5] == 0)); r[6] = (u)r[6] + 4; if (c) goto L800d8a94;
    L800d8a60:;
    r[4] = *(int *)((u)r[5] + 0);
    r[3] = (u)r[4] >> 24;
    r[3] = (u)r[3] << 2;
    r[3] = (u)r[10] + (u)r[3];
    r[2] = *(int *)((u)r[3] + 0);
    r[2] = r[2] | r[9];
    *(int *)((u)r[5] + 0) = r[2];
    *(int *)((u)r[3] + 0) = r[5];
    r[5] = r[4] & r[8];
    c = ((r[5] != 0));  if (c) goto L800d8a60;
    L800d8a94:;
    r[7] = (u)r[7] + -1;
    c = (((int)r[7] > 0));  if (c) goto L800d8a50;
     goto out;
out:
    RECOMP_RETURN;
}
