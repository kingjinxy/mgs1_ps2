extern char R_s07b_800CDBA4[] __asm__("s07b_800CDBA4");
extern char R_s07b_dword_800E5BB0[] __asm__("s07b_dword_800E5BB0");
extern char R_GM_ConfigObjectOverride[] __asm__("GM_ConfigObjectOverride");
extern char R_s07b_800CBC20[] __asm__("s07b_800CBC20");
extern char R_s07b_800CDA90[] __asm__("s07b_800CDA90");
int G_s07b_800CDAFC(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s07b_800CDAFC");
int G_s07b_800CDAFC(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(32)
    r[29] = (u)r[29] + -32;
    *(int *)((u)r[29] + 24) = r[16];
    r[16] = (u)r[4] + (u)0;
    c = ((r[5] != 0)); *(int *)((u)r[29] + 28) = r[31]; if (c) goto L800cdb28;
     CALL(R_s07b_800CDA90);
    r[2] = *(int *)((u)r[16] + 2128);
    r[3] = (u)0 + -2;
    r[2] = r[2] & r[3];
    *(int *)((u)r[16] + 2128) = r[2];
    L800cdb28:;
    r[4] = (u)r[16] + (u)0; CALL(R_s07b_800CBC20);
    r[2] = 0;
    r[2] = *(int *)((u)r[2] + (int)R_s07b_dword_800E5BB0);
    r[2] = *(int *)((u)r[2] + 0);
    r[2] = r[2] & 4;
    c = ((r[2] != 0));  if (c) goto L800cdb94;
    r[2] = *(short *)((u)r[16] + 172);
    c = ((r[2] == 0)); r[4] = (u)r[16] + 156; if (c) goto L800cdb74;
    *(int *)((u)r[29] + 16) = 0;
    r[5] = (u)0 + (u)0;
    r[6] = (u)r[5] + (u)0;
    r[7] = (u)0 + 4; CALL(R_GM_ConfigObjectOverride);
    L800cdb74:;
    r[2] = 0;
    r[2] = (u)r[2] + (int)R_s07b_800CDBA4;
    *(int *)((u)r[16] + 2132) = r[2];
    *(int *)((u)r[16] + 2136) = 0;
    *(short *)((u)r[16] + 2662) = 0;
    *(short *)((u)r[16] + 2660) = 0;
    *(short *)((u)r[16] + 112) = 0;
    *(short *)((u)r[16] + 108) = 0;
    L800cdb94:;
    r[31] = *(int *)((u)r[29] + 28);
    r[16] = *(int *)((u)r[29] + 24);
    r[29] = (u)r[29] + 32; goto out;
out:
    RECOMP_RETURN;
}
