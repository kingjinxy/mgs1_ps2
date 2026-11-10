extern char R_s18a_800C8990[] __asm__("s18a_800C8990");
extern char R_s18a_dat_800C3324[] __asm__("s18a_dat_800C3324");
extern char R_GM_ConfigObjectAction[] __asm__("GM_ConfigObjectAction");
extern char R_GM_SeSet[] __asm__("GM_SeSet");
int G_s18a_800C84B8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s18a_800C84B8");
int G_s18a_800C84B8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(32)
    r[29] = (u)r[29] + -32;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 20) = r[17];
    r[17] = (u)r[5] + (u)0;
    c = ((r[17] != 0)); *(int *)((u)r[29] + 24) = r[31]; if (c) goto L800c84f4;
    r[4] = (u)r[16] + 156;
    r[2] = (u)0 + 6;
    *(int *)((u)r[16] + 2364) = r[2];
    r[2] = 0;
    r[6] = (u)0 + (u)0;
    r[5] = *(short *)((u)r[2] + (int)R_s18a_dat_800C3324);
    r[7] = (u)0 + 4; CALL(R_GM_ConfigObjectAction);
    L800c84f4:;
    r[2] = (u)0 + 53;
    c = ((r[17] != r[2])); r[4] = (u)r[16] + 32; if (c) goto L800c8508;
    r[5] = (u)0 + 50; CALL(R_GM_SeSet);
    L800c8508:;
    r[2] = *(short *)((u)r[16] + 182);
    c = ((r[2] == 0)); r[2] = (u)0 + 1; if (c) goto L800c8538;
    *(int *)((u)r[16] + 2368) = r[2];
    r[2] = 0;
    r[2] = (u)r[2] + (int)R_s18a_800C8990;
    *(int *)((u)r[16] + 2348) = r[2];
    *(int *)((u)r[16] + 2356) = 0;
    *(short *)((u)r[16] + 112) = 0;
    *(short *)((u)r[16] + 108) = 0; goto L800c8544;
    L800c8538:;
    r[3] = *(int *)((u)r[16] + 2240);
    r[2] = (u)0 + 1;
    *(short *)((u)r[3] + 0) = r[2];
    L800c8544:;
    r[31] = *(int *)((u)r[29] + 24);
    r[17] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 32; goto out;
out:
    RECOMP_RETURN;
}
