extern char R_GM_N_WhereList[] __asm__("GM_N_WhereList");
extern char R_GM_WhereList[] __asm__("GM_WhereList");
int G_s19a_800D9FA8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s19a_800D9FA8");
int G_s19a_800D9FA8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[5] = (u)0 + (u)0;
    r[2] = 0;
    r[3] = *(int *)((u)r[2] + (int)R_GM_N_WhereList);
    r[2] = 0;
    c = (((int)r[3] <= 0)); r[4] = (u)r[2] + (int)R_GM_WhereList; if (c) goto L800d9ffc;
    r[7] = 0 | 38386;
    r[6] = (u)0 + 15660;
    L800d9fc8:;
    r[2] = *(int *)((u)r[4] + 0);
    r[2] = *(unsigned short *)((u)r[2] + 48);
    c = ((r[2] != r[7]));  if (c) goto L800d9fe4;
    r[5] = (u)0 + 1;
    L800d9fe4:;
    c = ((r[2] != r[6]));  if (c) goto L800d9ff0;
    r[5] = (u)0 + 1;
    L800d9ff0:;
    r[3] = (u)r[3] + -1;
    c = (((int)r[3] > 0)); r[4] = (u)r[4] + 4; if (c) goto L800d9fc8;
    L800d9ffc:;
    r[2] = (u)r[5] + (u)0; goto out;
out:
    RECOMP_RETURN;
}
