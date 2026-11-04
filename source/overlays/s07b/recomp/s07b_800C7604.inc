extern char R_linkvarbuf[] __asm__("linkvarbuf");
extern char R_MENU_DrawBar2[] __asm__("MENU_DrawBar2");
int G_s07b_800C7604(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s07b_800C7604");
int G_s07b_800C7604(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(40)
    r[29] = (u)r[29] + -40;
    *(int *)((u)r[29] + 32) = r[18];
    r[18] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 36) = r[31];
    *(int *)((u)r[29] + 28) = r[17];
    *(int *)((u)r[29] + 24) = r[16];
    r[2] = *(int *)((u)r[18] + 2128);
    r[2] = r[2] & 1024;
    c = ((r[2] == 0));  if (c) goto L800c76b0;
    r[2] = *(int *)((u)r[18] + 2012);
    r[16] = *(short *)((u)r[2] + 38);
    c = (((int)r[16] >= 0));  if (c) goto L800c764c;
    r[16] = (u)0 + (u)0;
    L800c764c:;
    r[17] = *(int *)((u)r[18] + 2216);
    r[2] = (int)r[17] < (int)r[16];
    c = ((r[2] == 0)); r[2] = (u)r[18] + 2204; if (c) goto L800c7664;
    r[17] = (u)r[16] + (u)0;
    L800c7664:;
    *(int *)((u)r[29] + 16) = r[2];
    r[2] = 0;
    r[5] = (u)r[17] + (u)0;
    r[7] = *(short *)((u)r[2] + ((int)R_linkvarbuf + 24));
    r[4] = *(int *)((u)r[18] + 2224);
    r[6] = (u)r[16] + (u)0; CALL(R_MENU_DrawBar2);
    r[5] = (u)r[17] - (u)r[16];
    c = (((int)r[5] <= 0)); r[2] = (int)r[5] < 64; if (c) goto L800c76b0;
    c = ((r[2] != 0));  if (c) goto L800c76a0;
    r[2] = *(int *)((u)r[18] + 2216);
    r[2] = (u)r[2] + -64; goto L800c76ac;
    L800c76a0:;
    r[2] = *(int *)((u)r[18] + 2216);
    r[2] = (u)r[2] - (u)r[5];
    L800c76ac:;
    *(int *)((u)r[18] + 2216) = r[2];
    L800c76b0:;
    r[31] = *(int *)((u)r[29] + 36);
    r[18] = *(int *)((u)r[29] + 32);
    r[17] = *(int *)((u)r[29] + 28);
    r[16] = *(int *)((u)r[29] + 24);
    r[29] = (u)r[29] + 40; goto out;
out:
    RECOMP_RETURN;
}
