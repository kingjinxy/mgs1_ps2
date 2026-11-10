extern char R_GM_PlayerStatus[] __asm__("GM_PlayerStatus");
extern char R_dword_8009F46C[] __asm__("dword_8009F46C");
extern char R_s18a_rc_800D9034[] __asm__("s18a_rc_800D9034");
extern char R_s18a_800D5BC4[] __asm__("s18a_800D5BC4");
int G_s18a_800D63AC(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s18a_800D63AC");
int G_s18a_800D63AC(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[31];
    r[2] = *(int *)((u)r[4] + 2212);
    r[2] = *(unsigned short *)((u)r[2] + 2);
    r[2] = r[2] & 16;
    c = ((r[2] == 0)); r[2] = 0; if (c) goto L800d6430;
    r[3] = *(int *)((u)r[4] + 2240);
    r[2] = (u)r[2] + (int)R_s18a_rc_800D9034;
    c = ((r[3] == r[2])); r[2] = 0; if (c) goto L800d641c;
    r[2] = *(int *)((u)r[2] + (int)R_GM_PlayerStatus);
    r[2] = r[2] & 2053;
    c = ((r[2] != 0)); r[2] = (u)0 + (u)0; if (c) goto L800d6420;
    r[2] = *(int *)((u)r[4] + 2020);
    r[2] = r[2] & 4;
    c = ((r[2] != 0)); r[2] = (u)0 + (u)0; if (c) goto L800d6420;
    r[2] = 0;
    r[2] = *(int *)((u)r[2] + (int)R_dword_8009F46C);
    c = ((r[2] == 0)); r[2] = (u)0 + 1; if (c) goto L800d6420;
    L800d641c:;
    r[2] = (u)0 + (u)0;
    L800d6420:;
    c = ((r[2] == 0));  if (c) goto L800d6430;
     CALL(R_s18a_800D5BC4);
    L800d6430:;
    r[31] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
