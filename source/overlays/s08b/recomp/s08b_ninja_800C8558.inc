int G_s08b_ninja_800C8558(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s08b_ninja_800C8558");
int G_s08b_ninja_800C8558(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(0)
    r[2] = *(int *)((u)r[4] + 76);
    r[2] = *(int *)((u)r[2] + 8);
    r[2] = *(int *)((u)r[2] + 0);
    r[10] = *(short *)((u)r[2] + 14);
    r[9] = *(int *)((u)r[2] + 24);
    r[2] = (int)r[10] < 17;
    c = ((r[2] != 0)); r[7] = (u)r[4] + 2336; if (c) goto L800c858c;
    L800c8584:;
    r[2] = (u)0 + -1; goto out;
    L800c858c:;
    *(short *)((u)r[4] + 6496) = r[10];
    c = (((int)r[10] <= 0)); r[8] = (u)0 + (u)0; if (c) goto L800c861c;
    L800c8598:;
    r[3] = *(short *)((u)r[9] + 0);
    r[2] = (u)r[3] + -1;
    r[2] = (u)r[2] < (u)32;
    c = ((r[2] == 0)); *(int *)((u)r[7] + 0) = r[3]; if (c) goto L800c8584;
    r[6] = *(int *)((u)r[9] + 4);
    c = (((int)r[3] <= 0)); r[5] = (u)0 + (u)0; if (c) goto L800c8608;
    r[3] = (u)r[7] + (u)0;
    r[4] = (u)r[6] + 6;
    L800c85c4:;
    r[2] = *(unsigned short *)((u)r[6] + 0);
    *(short *)((u)r[3] + 4) = r[2];
    r[2] = *(unsigned short *)((u)r[4] + -2);
    r[6] = (u)r[6] + 8;
    *(short *)((u)r[3] + 6) = r[2];
    r[2] = *(unsigned short *)((u)r[4] + -4);
    r[5] = (u)r[5] + 1;
    *(short *)((u)r[3] + 8) = r[2];
    r[2] = *(unsigned short *)((u)r[4] + 0);
    r[4] = (u)r[4] + 8;
    *(short *)((u)r[3] + 10) = r[2];
    r[2] = *(int *)((u)r[7] + 0);
    r[2] = (int)r[5] < (int)r[2];
    c = ((r[2] != 0)); r[3] = (u)r[3] + 8; if (c) goto L800c85c4;
    L800c8608:;
    r[7] = (u)r[7] + 260;
    r[8] = (u)r[8] + 1;
    r[2] = (int)r[8] < (int)r[10];
    c = ((r[2] != 0)); r[9] = (u)r[9] + 8; if (c) goto L800c8598;
    L800c861c:;
    r[2] = (u)0 + (u)0; goto out;
out:
    RECOMP_RETURN;
}
