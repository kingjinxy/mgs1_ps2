extern char R_GV_DiffDirAbs[] __asm__("GV_DiffDirAbs");
int G_s19a_800C5828(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s19a_800C5828");
int G_s19a_800C5828(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 20) = r[31];
    r[2] = *(int *)((u)r[16] + 692);
    r[2] = (int)r[2] < 61;
    c = ((r[2] != 0)); r[2] = (u)r[16] + 108; if (c) goto L800c5880;
    r[5] = *(unsigned short *)((u)r[2] + 2);
    r[5] = (u)r[5] + 8;
    r[5] = r[5] & 4095;
    *(short *)((u)r[2] + 2) = r[5];
    r[4] = *(short *)((u)r[16] + 634);
     CALL(R_GV_DiffDirAbs);
    r[3] = *(unsigned short *)((u)r[16] + 846);
    r[3] = (int)r[3] < (int)r[2];
    c = ((r[3] != 0)); r[2] = (u)0 + 1; if (c) goto L800c5890;
    L800c5880:;
    r[3] = *(int *)((u)r[16] + 692);
    r[2] = (u)0 + (u)0;
    r[3] = (u)r[3] + 1;
    *(int *)((u)r[16] + 692) = r[3];
    L800c5890:;
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
