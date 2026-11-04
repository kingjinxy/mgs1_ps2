extern char R_GM_SeSet[] __asm__("GM_SeSet");
extern char R_s14e_800CA49C[] __asm__("s14e_800CA49C");
int G_s14e_800CD024(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s14e_800CD024");
int G_s14e_800CD024(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 20) = r[31];
    r[2] = *(int *)((u)r[16] + 2856);
    c = ((r[2] != 0)); r[4] = (u)r[16] + 32; if (c) goto L800cd058;
    r[5] = (u)0 + 83; CALL(R_GM_SeSet);
    r[4] = (u)r[16] + (u)0;
    r[5] = (u)0 + (u)0; CALL(R_s14e_800CA49C);
    L800cd058:;
    r[3] = *(int *)((u)r[16] + 2856);
    r[2] = (u)r[3] < (u)21;
    c = ((r[2] == 0)); r[2] = (u)r[3] + 1; if (c) goto L800cd078;
    *(int *)((u)r[16] + 2856) = r[2];
    r[2] = (u)0 + (u)0; goto L800cd07c;
    L800cd078:;
    r[2] = (u)0 + 1;
    L800cd07c:;
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
