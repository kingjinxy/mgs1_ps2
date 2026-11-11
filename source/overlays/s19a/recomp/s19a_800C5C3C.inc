extern char R_GM_AlertMode[] __asm__("GM_AlertMode");
extern char R_s19a_800C53A4[] __asm__("s19a_800C53A4");
extern char R_s19a_800C54B0[] __asm__("s19a_800C54B0");
extern char R_s19a_800C5708[] __asm__("s19a_800C5708");
int G_s19a_800C5C3C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s19a_800C5C3C");
int G_s19a_800C5C3C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(32)
    r[29] = (u)r[29] + -32;
    *(int *)((u)r[29] + 24) = r[16];
    r[16] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 28) = r[31];
    r[3] = *(int *)((u)r[16] + 688);
    c = ((r[3] == 0)); r[2] = (u)0 + 4; if (c) goto L800c5c84;
    c = ((r[3] != r[2])); r[2] = 0; if (c) goto L800c5c9c;
     CALL(R_s19a_800C5708);
    r[4] = (u)r[16] + (u)0; CALL(R_s19a_800C54B0);
    c = ((r[2] != 0)); r[2] = 0; if (c) goto L800c5c9c;
    *(int *)((u)r[16] + 688) = 0; goto L800c5c9c;
    L800c5c84:;
    r[4] = (u)r[16] + (u)0; CALL(R_s19a_800C54B0);
    c = ((r[2] == 0)); r[2] = (u)0 + 4; if (c) goto L800c5c98;
    *(int *)((u)r[16] + 688) = r[2];
    L800c5c98:;
    r[2] = 0;
    L800c5c9c:;
    r[3] = *(int *)((u)r[2] + (int)R_GM_AlertMode);
    r[2] = (u)0 + 3;
    c = ((r[3] == r[2])); r[2] = (u)0 + 2; if (c) goto L800c5cd4;
    *(int *)((u)r[16] + 680) = r[2];
    r[2] = (u)0 + 5;
    r[6] = (u)0 + 255;
    *(int *)((u)r[16] + 688) = r[2];
    *(int *)((u)r[16] + 692) = 0;
    *(int *)((u)r[29] + 16) = 0;
    r[4] = *(int *)((u)r[16] + 436);
    r[5] = *(int *)((u)r[16] + 440);
    r[7] = (u)r[6] + (u)0; CALL(R_s19a_800C53A4);
    L800c5cd4:;
    r[31] = *(int *)((u)r[29] + 28);
    r[16] = *(int *)((u)r[29] + 24);
    r[29] = (u)r[29] + 32; goto out;
out:
    RECOMP_RETURN;
}
