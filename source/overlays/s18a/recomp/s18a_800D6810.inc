extern char R_GM_PlayerStatus[] __asm__("GM_PlayerStatus");
extern char R_linkvarbuf[] __asm__("linkvarbuf");
extern char R_s18a_800DA590[] __asm__("s18a_800DA590");
int G_s18a_800D6810(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s18a_800D6810");
int G_s18a_800D6810(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[2] = 0;
    r[2] = *(unsigned short *)((u)r[2] + ((int)R_linkvarbuf + 26));
    r[2] = r[2] & 2;
    c = ((r[2] == 0)); r[2] = 0; if (c) goto L800d6878;
    r[2] = *(int *)((u)r[2] + (int)R_GM_PlayerStatus);
    r[2] = r[2] & 4;
    c = ((r[2] != 0));  if (c) goto L800d6878;
    r[2] = *(unsigned short *)((u)r[4] + 2350);
    r[2] = (u)r[2] + 1;
    *(short *)((u)r[4] + 2350) = r[2];
    r[2] = r[2] & 65535;
    r[2] = (u)r[2] < (u)300;
    c = ((r[2] != 0)); r[2] = 0; if (c) goto L800d6878;
    r[3] = *(int *)((u)r[4] + 2020);
    r[2] = (u)r[2] + (int)R_s18a_800DA590;
    *(short *)((u)r[4] + 2350) = 0;
    *(int *)((u)r[4] + 2228) = r[2];
    *(int *)((u)r[4] + 2232) = 0;
    r[3] = r[3] | 256;
    *(int *)((u)r[4] + 2020) = r[3];
    L800d6878:;
     goto out;
out:
    RECOMP_RETURN;
}
