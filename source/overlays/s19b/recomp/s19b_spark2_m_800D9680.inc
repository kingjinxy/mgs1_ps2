extern char R_Takabe_JeepSystem[] __asm__("Takabe_JeepSystem");
int G_s19b_spark2_m_800D9680(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s19b_spark2_m_800D9680");
int G_s19b_spark2_m_800D9680(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[2] = 0;
    r[3] = *(int *)((u)r[2] + ((int)R_Takabe_JeepSystem + 84));
    r[2] = r[3] & 4096;
    c = ((r[2] == 0)); r[5] = (u)r[4] + (u)0; if (c) goto L800d96b8;
    r[2] = (u)0 + 1;
    L800d969c:;
    r[4] = *(int *)((u)r[5] + 2304);
    r[3] = (u)0 + 4;
    *(int *)((u)r[5] + 2324) = r[3];
    *(int *)((u)r[5] + 2328) = 0;
    r[4] = r[4] | 16;
    *(int *)((u)r[5] + 2304) = r[4]; goto out;
    L800d96b8:;
    r[2] = r[3] & 2;
    c = ((r[2] == 0)); r[2] = r[3] & 32768; if (c) goto L800d96d8;
    r[2] = *(int *)((u)r[5] + 2304);
    r[3] = 0x2000000;
    r[2] = r[2] | r[3];
    *(int *)((u)r[5] + 2304) = r[2]; goto L800d96fc;
    L800d96d8:;
    c = ((r[2] == 0)); r[2] = 0x4000000; if (c) goto L800d96ec;
    *(int *)((u)r[5] + 2304) = r[2];
    r[2] = (u)0 + 1; goto out;
    L800d96ec:;
    r[3] = *(int *)((u)r[5] + 2300);
    r[2] = (u)0 + 20;
    c = ((r[3] == r[2])); r[2] = (u)0 + 1; if (c) goto L800d969c;
    L800d96fc:;
    r[2] = (u)0 + (u)0; goto out;
out:
    RECOMP_RETURN;
}
