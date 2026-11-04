extern char R_s14e_dword_800C3350[] __asm__("s14e_dword_800C3350");
extern char R_s14e_dword_800C336C[] __asm__("s14e_dword_800C336C");
extern char R_GM_ConfigObjectOverride[] __asm__("GM_ConfigObjectOverride");
int G_s14e_800C9A68(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s14e_800C9A68");
int G_s14e_800C9A68(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(32)
    r[29] = (u)r[29] + -32;
    *(int *)((u)r[29] + 24) = r[16];
    r[16] = (u)r[4] + (u)0;
    r[2] = (u)0 + 3000;
    *(int *)((u)r[29] + 28) = r[31];
    c = ((r[5] != 0)); *(short *)((u)r[16] + 2960) = r[2]; if (c) goto L800c9aac;
    r[4] = (u)r[16] + 156;
    r[6] = (u)0 + (u)0;
    r[7] = (u)0 + 4;
    r[2] = (u)0 + 14;
    *(short *)((u)r[16] + 2274) = r[2];
    r[2] = 0;
    r[5] = *(short *)((u)r[2] + (int)R_s14e_dword_800C336C);
    r[2] = (u)0 + 1022;
    *(int *)((u)r[29] + 16) = r[2]; CALL(R_GM_ConfigObjectOverride);
    L800c9aac:;
    r[2] = *(int *)((u)r[16] + 2872);
    r[2] = r[2] & 8192;
    c = ((r[2] != 0)); r[4] = (u)r[16] + 156; if (c) goto L800c9af0;
    r[6] = (u)0 + (u)0;
    r[2] = 0;
    *(short *)((u)r[16] + 2274) = 0;
    r[5] = *(short *)((u)r[2] + (int)R_s14e_dword_800C3350);
    r[7] = (u)0 + 4;
    *(int *)((u)r[29] + 16) = 0; CALL(R_GM_ConfigObjectOverride);
    *(int *)((u)r[16] + 2288) = 0;
    *(int *)((u)r[16] + 2296) = 0;
    *(short *)((u)r[16] + 2274) = 0;
    *(short *)((u)r[16] + 112) = 0;
    *(short *)((u)r[16] + 108) = 0;
    L800c9af0:;
    r[31] = *(int *)((u)r[29] + 28);
    r[16] = *(int *)((u)r[29] + 24);
    r[29] = (u)r[29] + 32; goto out;
out:
    RECOMP_RETURN;
}
