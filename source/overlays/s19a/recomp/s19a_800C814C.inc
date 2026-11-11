extern char R_s19a_dat_800E0530[] __asm__("s19a_dat_800E0530");
extern char R_s19a_dat_800E053C[] __asm__("s19a_dat_800E053C");
extern char R_GM_SeSet[] __asm__("GM_SeSet");
extern char R_s19a_800C7E68[] __asm__("s19a_800C7E68");
int G_s19a_800C814C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s19a_800C814C");
int G_s19a_800C814C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    r[2] = 0;
    r[3] = (u)r[2] + (int)R_s19a_dat_800E0530;
    *(int *)((u)r[29] + 16) = r[31];
    r[2] = *(int *)((u)r[3] + 28);
    r[10] = (u)r[4] + (u)0;
    r[2] = (u)r[2] + -1;
    c = (((int)r[2] >= 0)); *(int *)((u)r[3] + 28) = r[2]; if (c) goto L800c8174;
    *(int *)((u)r[3] + 28) = 0;
    L800c8174:;
    r[2] = *(int *)((u)r[3] + 28);
    c = (((int)r[2] > 0)); r[9] = 0x10000; if (c) goto L800c8220;
    r[9] = r[9] | 34464;
    r[8] = (u)0 + (u)0;
    r[2] = *(int *)((u)r[10] + 8);
    c = (((int)r[2] <= 0)); r[4] = (u)r[8] + (u)0; if (c) goto L800c8200;
    r[11] = (u)0 + 2;
    r[7] = (u)r[10] + (u)0;
    L800c81a4:;
    r[2] = *(int *)((u)r[7] + 204);
    c = ((r[2] != r[11]));  if (c) goto L800c81ec;
    r[3] = *(int *)((u)r[7] + 212);
    r[6] = *(short *)((u)r[3] + 2890);
    c = ((r[6] == 0));  if (c) goto L800c81e8;
    r[5] = *(int *)((u)r[3] + 3108);
    r[2] = (int)r[5] < (int)r[9];
    c = ((r[2] == 0));  if (c) goto L800c81e8;
    r[4] = (u)r[6] + (u)0;
    r[9] = (u)r[5] + (u)0;
    L800c81e8:;
    *(short *)((u)r[3] + 2890) = 0;
    L800c81ec:;
    r[2] = *(int *)((u)r[10] + 8);
    r[8] = (u)r[8] + 1;
    r[2] = (int)r[8] < (int)r[2];
    c = ((r[2] != 0)); r[7] = (u)r[7] + 16; if (c) goto L800c81a4;
    L800c8200:;
    c = ((r[4] == 0)); r[3] = 0; if (c) goto L800c8220;
    r[2] = (u)0 + 30;
    *(int *)((u)r[3] + ((int)R_s19a_dat_800E053C + 16)) = r[2]; CALL(R_s19a_800C7E68);
    r[4] = (u)0 + (u)0;
    r[5] = (u)r[2] + (u)0; CALL(R_GM_SeSet);
    L800c8220:;
    r[31] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
