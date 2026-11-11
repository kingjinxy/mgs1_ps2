extern char R_GM_PlayerControl[] __asm__("GM_PlayerControl");
int G_s19a_800C96B0(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s19a_800C96B0");
int G_s19a_800C96B0(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[2] = 0;
    r[2] = *(int *)((u)r[2] + (int)R_GM_PlayerControl);
    r[2] = (u)r[2] + 16;
    r[3] = *(short *)((u)r[2] + 6);
    c = (((int)r[3] <= 0)); r[8] = (u)0 + (u)0; if (c) goto L800c9720;
    r[11] = *(int *)((u)r[4] + 48);
    r[10] = (u)r[3] + (u)0;
    r[9] = (u)r[2] + (u)0;
    L800c96dc:;
    c = (((int)r[11] <= 0)); r[3] = (u)0 + (u)0; if (c) goto L800c9710;
    r[5] = (u)r[4] + (u)0;
    r[7] = *(unsigned short *)((u)r[9] + 8);
    r[6] = *(int *)((u)r[4] + 48);
    L800c96f0:;
    r[2] = *(int *)((u)r[5] + 32);
    c = ((r[7] == r[2])); r[2] = (u)r[3] + (u)0; if (c) goto L800c9728;
    r[3] = (u)r[3] + 1;
    r[2] = (int)r[3] < (int)r[6];
    c = ((r[2] != 0)); r[5] = (u)r[5] + 4; if (c) goto L800c96f0;
    L800c9710:;
    r[8] = (u)r[8] + 1;
    r[2] = (int)r[8] < (int)r[10];
    c = ((r[2] != 0)); r[9] = (u)r[9] + 2; if (c) goto L800c96dc;
    L800c9720:;
    r[2] = (u)0 + -1; goto out;
    L800c9728:;
     goto out;
out:
    RECOMP_RETURN;
}
