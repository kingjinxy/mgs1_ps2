extern char R_GM_GameStatus[] __asm__("GM_GameStatus");
int G_s15a_800D38C8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s15a_800D38C8");
int G_s15a_800D38C8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[2] = 0;
    r[2] = *(int *)((u)r[2] + (int)R_GM_GameStatus);
    r[2] = r[2] & 2;
    c = ((r[2] == 0)); r[3] = (u)0 + 1; if (c) goto L800d38f8;
    r[2] = *(int *)((u)r[4] + 968);
    c = ((r[2] == r[3])); r[2] = (u)0 + 10; if (c) goto L800d38f8;
    *(int *)((u)r[4] + 968) = r[3];
    *(int *)((u)r[4] + 964) = r[2];
    L800d38f8:;
     goto out;
out:
    RECOMP_RETURN;
}
