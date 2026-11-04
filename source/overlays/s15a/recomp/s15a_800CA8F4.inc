extern char R_GM_PlayerPosition[] __asm__("GM_PlayerPosition");
extern char R_amissile_alive_8009F490[] __asm__("amissile_alive_8009F490");
extern char R_dword_8009F46C[] __asm__("dword_8009F46C");
extern char R_svector_8009F478[] __asm__("svector_8009F478");
extern char R_svector_8009F494[] __asm__("svector_8009F494");
int G_s15a_800CA8F4(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s15a_800CA8F4");
int G_s15a_800CA8F4(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[2] = 0;
    r[2] = *(int *)((u)r[2] + (int)R_dword_8009F46C);
    r[3] = (u)0 + 1;
    c = ((r[2] != r[3])); r[2] = 0; if (c) goto L800ca938;
    r[2] = 0;
    r[8] = (u)r[2] + (int)R_svector_8009F478;
    r[5] = LWL(((u)r[8] + 3), r[5]);
    r[5] = LWR(((u)r[8] + 0), r[5]);
    r[6] = LWL(((u)r[8] + 7), r[6]);
    r[6] = LWR(((u)r[8] + 4), r[6]);
    SWL(((u)r[4] + 1311), r[5]);
    SWR(((u)r[4] + 1308), r[5]);
    SWL(((u)r[4] + 1315), r[6]);
    SWR(((u)r[4] + 1312), r[6]);
     goto out;
    L800ca938:;
    r[2] = *(int *)((u)r[2] + (int)R_amissile_alive_8009F490);
    c = ((r[2] != r[3])); *(int *)((u)r[4] + 2092) = 0; if (c) goto L800ca978;
    r[2] = 0;
    r[8] = (u)r[2] + (int)R_svector_8009F494;
    r[5] = LWL(((u)r[8] + 3), r[5]);
    r[5] = LWR(((u)r[8] + 0), r[5]);
    r[6] = LWL(((u)r[8] + 7), r[6]);
    r[6] = LWR(((u)r[8] + 4), r[6]);
    SWL(((u)r[4] + 1311), r[5]);
    SWR(((u)r[4] + 1308), r[5]);
    SWL(((u)r[4] + 1315), r[6]);
    SWR(((u)r[4] + 1312), r[6]);
     goto out;
    L800ca978:;
    r[2] = 0;
    *(int *)((u)r[4] + 2104) = 0;
    r[8] = (u)r[2] + (int)R_GM_PlayerPosition;
    r[5] = LWL(((u)r[8] + 3), r[5]);
    r[5] = LWR(((u)r[8] + 0), r[5]);
    r[6] = LWL(((u)r[8] + 7), r[6]);
    r[6] = LWR(((u)r[8] + 4), r[6]);
    SWL(((u)r[4] + 1311), r[5]);
    SWR(((u)r[4] + 1308), r[5]);
    SWL(((u)r[4] + 1315), r[6]);
    SWR(((u)r[4] + 1312), r[6]);
     goto out;
out:
    RECOMP_RETURN;
}
