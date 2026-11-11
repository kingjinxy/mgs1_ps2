extern char R_GM_AlertLevel[] __asm__("GM_AlertLevel");
extern char R_GM_AlertMode[] __asm__("GM_AlertMode");
extern char R_GM_SeSet[] __asm__("GM_SeSet");
extern char R_s19a_800C53A4[] __asm__("s19a_800C53A4");
extern char R_s19a_800C569C[] __asm__("s19a_800C569C");
extern char R_s19a_800C5708[] __asm__("s19a_800C5708");
extern char R_s19a_800C732C[] __asm__("s19a_800C732C");
extern char R_s19a_800C796C[] __asm__("s19a_800C796C");
int G_s19a_800C5754(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s19a_800C5754");
int G_s19a_800C5754(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(40)
    r[29] = (u)r[29] + -40;
    *(int *)((u)r[29] + 24) = r[16];
    r[16] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 32) = r[31];
    *(int *)((u)r[29] + 28) = r[17];
    r[17] = *(int *)((u)r[16] + 692);
    c = ((r[17] != 0)); r[4] = (u)r[16] + 32; if (c) goto L800c5798;
    r[5] = (u)0 + 95; CALL(R_GM_SeSet);
    r[6] = (u)0 + 255;
    *(int *)((u)r[29] + 16) = 0;
    r[4] = *(int *)((u)r[16] + 436);
    r[5] = *(int *)((u)r[16] + 440);
    r[7] = (u)0 + (u)0; CALL(R_s19a_800C53A4);
    L800c5798:;
    r[4] = (u)r[16] + (u)0; CALL(R_s19a_800C5708);
    r[2] = (u)0 + 15;
    c = ((r[17] != r[2])); r[2] = (u)0 + 35; if (c) goto L800c57dc;
    r[4] = (u)r[16] + 32;
    r[5] = (u)0 + 32; CALL(R_s19a_800C796C);
    r[4] = *(int *)((u)r[16] + 156);
    r[5] = (u)0 + (u)0;
    r[4] = (u)r[4] + 72; CALL(R_s19a_800C732C);
    r[4] = (u)r[16] + (u)0;
    r[2] = (u)0 + 10;
    *(int *)((u)r[16] + 704) = r[2]; CALL(R_s19a_800C569C);
    r[2] = (u)0 + 35;
    L800c57dc:;
    c = ((r[17] == r[2])); r[2] = (u)0 + (u)0; if (c) goto L800c57f8;
    r[3] = *(int *)((u)r[16] + 692);
    r[3] = (u)r[3] + 1;
    *(int *)((u)r[16] + 692) = r[3]; goto L800c5814;
    L800c57f8:;
    r[2] = (u)0 + 1;
    r[4] = 0;
    r[3] = (u)0 + 255;
    *(int *)((u)r[4] + (int)R_GM_AlertLevel) = r[3];
    r[4] = 0;
    r[3] = (u)0 + 3;
    *(int *)((u)r[4] + (int)R_GM_AlertMode) = r[3];
    L800c5814:;
    r[31] = *(int *)((u)r[29] + 32);
    r[17] = *(int *)((u)r[29] + 28);
    r[16] = *(int *)((u)r[29] + 24);
    r[29] = (u)r[29] + 40; goto out;
out:
    RECOMP_RETURN;
}
