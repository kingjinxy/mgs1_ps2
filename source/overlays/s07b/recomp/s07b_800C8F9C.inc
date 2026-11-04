extern char R_GM_ConfigObjectAction[] __asm__("GM_ConfigObjectAction");
extern char R_s07b_800C4E90[] __asm__("s07b_800C4E90");
int G_s07b_800C8F9C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s07b_800C8F9C");
int G_s07b_800C8F9C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    c = ((r[5] != 0)); *(int *)((u)r[29] + 20) = r[31]; if (c) goto L800c8fd0;
    r[3] = *(short *)((u)r[16] + 170);
    r[2] = (u)0 + 19;
    c = ((r[3] == r[2])); r[4] = (u)r[16] + 156; if (c) goto L800c8fd0;
    r[5] = (u)r[2] + (u)0;
    r[6] = (u)0 + (u)0;
    r[7] = (u)0 + 4; CALL(R_GM_ConfigObjectAction);
    L800c8fd0:;
    r[2] = *(short *)((u)r[16] + 2244);
    c = ((r[2] != 0));  if (c) goto L800c902c;
    r[2] = *(short *)((u)r[16] + 182);
    c = ((r[2] == 0)); r[2] = (u)0 + -5; if (c) goto L800c9034;
    r[3] = *(int *)((u)r[16] + 2124);
    r[4] = *(short *)((u)r[16] + 170);
    r[3] = r[3] & r[2];
    c = ((r[4] == 0)); *(int *)((u)r[16] + 2124) = r[3]; if (c) goto L800c9018;
    r[4] = (u)r[16] + 156;
    r[5] = (u)0 + (u)0;
    r[6] = (u)r[5] + (u)0;
    r[7] = (u)0 + 4; CALL(R_GM_ConfigObjectAction);
    L800c9018:;
    r[2] = *(unsigned short *)((u)r[16] + 2244);
    r[2] = (u)r[2] + 1;
    *(short *)((u)r[16] + 2244) = r[2]; goto L800c9034;
    L800c902c:;
    r[4] = (u)r[16] + (u)0; CALL(R_s07b_800C4E90);
    L800c9034:;
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
