extern char R_GM_PlayerPosition[] __asm__("GM_PlayerPosition");
extern char R_dword_8009F46C[] __asm__("dword_8009F46C");
extern char R_dword_8009F480[] __asm__("dword_8009F480");
extern char R_svector_8009F478[] __asm__("svector_8009F478");
int G_s10a_800D0E1C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s10a_800D0E1C");
int G_s10a_800D0E1C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[3] = (u)0 + 1;
    r[5] = 0;
    r[2] = 0;
    *(int *)((u)r[4] + 928) = r[3];
    r[9] = (u)r[5] + (int)R_GM_PlayerPosition;
    r[6] = LWL(((u)r[9] + 3), r[6]);
    r[6] = LWR(((u)r[9] + 0), r[6]);
    r[7] = LWL(((u)r[9] + 7), r[7]);
    r[7] = LWR(((u)r[9] + 4), r[7]);
    SWL(((u)r[4] + 943), r[6]);
    SWR(((u)r[4] + 940), r[6]);
    SWL(((u)r[4] + 947), r[7]);
    SWR(((u)r[4] + 944), r[7]);
    r[2] = *(int *)((u)r[2] + (int)R_dword_8009F46C);
    c = ((r[2] != r[3]));  if (c) goto L800d0e94;
    *(int *)((u)r[4] + 932) = r[2];
    r[2] = 0;
    r[9] = (u)r[2] + (int)R_svector_8009F478;
    r[6] = LWL(((u)r[9] + 3), r[6]);
    r[6] = LWR(((u)r[9] + 0), r[6]);
    r[7] = LWL(((u)r[9] + 7), r[7]);
    r[7] = LWR(((u)r[9] + 4), r[7]);
    SWL(((u)r[4] + 951), r[6]);
    SWR(((u)r[4] + 948), r[6]);
    SWL(((u)r[4] + 955), r[7]);
    SWR(((u)r[4] + 952), r[7]);
     goto out;
    L800d0e94:;
    r[2] = 0;
    r[9] = (u)r[5] + (int)R_GM_PlayerPosition;
    r[6] = LWL(((u)r[9] + 3), r[6]);
    r[6] = LWR(((u)r[9] + 0), r[6]);
    r[7] = LWL(((u)r[9] + 7), r[7]);
    r[7] = LWR(((u)r[9] + 4), r[7]);
    SWL(((u)r[4] + 951), r[6]);
    SWR(((u)r[4] + 948), r[6]);
    SWL(((u)r[4] + 955), r[7]);
    SWR(((u)r[4] + 952), r[7]);
    *(int *)((u)r[4] + 932) = 0;
    *(int *)((u)r[2] + (int)R_dword_8009F480) = 0;
    *(int *)((u)r[4] + 964) = 0; goto out;
out:
    RECOMP_RETURN;
}
