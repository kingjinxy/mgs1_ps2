extern char R_GM_PlayerStatus[] __asm__("GM_PlayerStatus");
extern char R_d18a_snake18_800CE7BC[] __asm__("d18a_snake18_800CE7BC");
extern char R_dword_8009F46C[] __asm__("dword_8009F46C");
extern char R_d18a_snake18_800CB34C[] __asm__("d18a_snake18_800CB34C");
int G_d18a_snake18_800CBB34(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("d18a_snake18_800CBB34");
int G_d18a_snake18_800CBB34(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[31];
    r[2] = *(int *)((u)r[4] + 2212);
    r[2] = *(unsigned short *)((u)r[2] + 2);
    r[2] = r[2] & 16;
    c = ((r[2] == 0)); r[2] = 0; if (c) goto L800cbbb8;
    r[3] = *(int *)((u)r[4] + 2240);
    r[2] = (u)r[2] + (int)R_d18a_snake18_800CE7BC;
    c = ((r[3] == r[2])); r[2] = 0; if (c) goto L800cbba4;
    r[2] = *(int *)((u)r[2] + (int)R_GM_PlayerStatus);
    r[2] = r[2] & 2053;
    c = ((r[2] != 0)); r[2] = (u)0 + (u)0; if (c) goto L800cbba8;
    r[2] = *(int *)((u)r[4] + 2020);
    r[2] = r[2] & 4;
    c = ((r[2] != 0)); r[2] = (u)0 + (u)0; if (c) goto L800cbba8;
    r[2] = 0;
    r[2] = *(int *)((u)r[2] + (int)R_dword_8009F46C);
    c = ((r[2] == 0)); r[2] = (u)0 + 1; if (c) goto L800cbba8;
    L800cbba4:;
    r[2] = (u)0 + (u)0;
    L800cbba8:;
    c = ((r[2] == 0));  if (c) goto L800cbbb8;
     CALL(R_d18a_snake18_800CB34C);
    L800cbbb8:;
    r[31] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
