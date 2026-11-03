extern char R_GM_SeSet[] __asm__("GM_SeSet");
extern char R_GV_DiffDirAbs[] __asm__("GV_DiffDirAbs");
int G_s10a_800D14F4(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s10a_800D14F4");
int G_s10a_800D14F4(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 20) = r[31];
    r[2] = *(int *)((u)r[16] + 844);
    r[2] = (int)r[2] < 61;
    c = ((r[2] != 0));  if (c) goto L800d1568;
    r[2] = *(int *)((u)r[16] + 1028);
    c = ((r[2] == 0)); r[4] = (u)r[16] + 32; if (c) goto L800d1530;
    r[5] = (u)0 + 94; CALL(R_GM_SeSet);
    L800d1530:;
    r[2] = (u)r[16] + 108;
    r[5] = *(unsigned short *)((u)r[2] + 2);
    r[5] = (u)r[5] + 8;
    r[5] = r[5] & 4095;
    *(short *)((u)r[2] + 2) = r[5];
    r[4] = *(short *)((u)r[16] + 818);
     CALL(R_GV_DiffDirAbs);
    r[3] = *(int *)((u)r[16] + 876);
    r[3] = (int)r[3] < (int)r[2];
    c = ((r[3] != 0)); r[2] = (u)0 + 1; if (c) goto L800d1578;
    L800d1568:;
    r[3] = *(int *)((u)r[16] + 844);
    r[2] = (u)0 + (u)0;
    r[3] = (u)r[3] + 1;
    *(int *)((u)r[16] + 844) = r[3];
    L800d1578:;
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
