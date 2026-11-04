extern char R_ZAKO14_GameFlag[] __asm__("ZAKO14_GameFlag");
extern char R_s14e_dword_800C35F0[] __asm__("s14e_dword_800C35F0");
int G_s14e_800CD6C4(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s14e_800CD6C4");
int G_s14e_800CD6C4(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[3] = 0x10000;
    r[2] = *(int *)((u)r[4] + 2872);
    r[5] = *(unsigned short *)((u)r[4] + 3120);
    r[2] = r[2] | r[3];
    *(short *)((u)r[4] + 2888) = r[5];
    r[5] = 0;
    r[5] = (u)r[5] + (int)R_s14e_dword_800C35F0;
    *(int *)((u)r[4] + 2872) = r[2];
    r[2] = 0;
    r[2] = *(int *)((u)r[2] + (int)R_ZAKO14_GameFlag);
    r[3] = *(signed char *)((u)r[4] + 2932);
    r[2] = (u)r[2] << 2;
    r[3] = (u)r[3] << 6;
    r[2] = (u)r[2] + (u)r[3];
    r[2] = (u)r[2] + (u)r[5];
    r[2] = *(unsigned char *)((u)r[2] + 0);
    *(char *)((u)r[4] + 2936) = r[2];
    r[2] = (u)0 + 15; goto out;
out:
    RECOMP_RETURN;
}
