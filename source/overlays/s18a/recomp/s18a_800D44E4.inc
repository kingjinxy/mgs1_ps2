extern char R_s18a_800D4000[] __asm__("s18a_800D4000");
extern char R_s18a_800D457C[] __asm__("s18a_800D457C");
extern char R_s18a_dat_800C3670[] __asm__("s18a_dat_800C3670");
extern char R_GM_ConfigObjectAction[] __asm__("GM_ConfigObjectAction");
extern char R_s18a_800D3F48[] __asm__("s18a_800D3F48");
int G_s18a_800D44E4(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s18a_800D44E4");
int G_s18a_800D44E4(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(32)
    r[29] = (u)r[29] + -32;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 24) = r[31];
    *(int *)((u)r[29] + 20) = r[17];
    r[17] = *(int *)((u)r[16] + 3068);
    c = ((r[5] != 0)); r[4] = (u)r[16] + 156; if (c) goto L800d451c;
    r[2] = 0;
    r[6] = (u)0 + (u)0;
    *(int *)((u)r[16] + 3040) = 0;
    r[5] = *(short *)((u)r[2] + (int)R_s18a_dat_800C3670);
    r[7] = (u)0 + 4; CALL(R_GM_ConfigObjectAction);
    L800d451c:;
    r[4] = (u)r[16] + (u)0; CALL(R_s18a_800D3F48);
    r[2] = r[17] & 1;
    c = ((r[2] != 0)); r[2] = 0; if (c) goto L800d4538;
    r[2] = (u)r[2] + (int)R_s18a_800D4000; goto L800d4548;
    L800d4538:;
    r[2] = r[17] & 2;
    c = ((r[2] == 0)); r[2] = 0; if (c) goto L800d455c;
    r[2] = (u)r[2] + (int)R_s18a_800D457C;
    L800d4548:;
    *(int *)((u)r[16] + 3024) = r[2];
    *(int *)((u)r[16] + 3032) = 0;
    *(short *)((u)r[16] + 112) = 0;
    *(short *)((u)r[16] + 108) = 0; goto L800d4568;
    L800d455c:;
    r[2] = *(unsigned short *)((u)r[16] + 3592);
    *(short *)((u)r[16] + 110) = r[2];
    L800d4568:;
    r[31] = *(int *)((u)r[29] + 24);
    r[17] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 32; goto out;
out:
    RECOMP_RETURN;
}
