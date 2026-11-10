int G_s14e_800D9964(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s14e_800D9964");
int G_s14e_800D9964(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[2] = (u)r[4] + (u)0;
    r[11] = (int)PSX_ADDR(0x1f800000);
    r[9] = (u)r[11] + (u)0;
    r[10] = *(int *)((u)r[2] + 0);
    r[8] = *(int *)((u)r[2] + 4);
    r[7] = *(int *)((u)r[2] + 8);
    r[6] = *(int *)((u)r[2] + 12);
    r[3] = *(int *)((u)r[2] + 16);
    c = (((int)r[5] <= 0)); r[9] = r[9] | 512; if (c) goto L800d99f0;
    r[4] = (u)r[4] + 16;
    L800d9990:;
    Gte_DataWrite(0, r[10]);
    Gte_DataWrite(1, r[8]);
    Gte_DataWrite(2, r[7]);
    Gte_DataWrite(3, r[6]);
    Gte_DataWrite(4, r[3]);
    Gte_DataWrite(5, *(int *)((u)r[2] + 20));
    r[4] = (u)r[4] + 24;
    r[2] = (u)r[2] + 24;
    r[5] = (u)r[5] + -3;
    Gte_Command(0x280030);
    r[10] = *(int *)((u)r[2] + 0);
    r[8] = *(int *)((u)r[4] + -12);
    r[7] = *(int *)((u)r[4] + -8);
    r[6] = *(int *)((u)r[4] + -4);
    r[3] = *(int *)((u)r[4] + 0);
    *(int *)((u)r[11] + 0) = Gte_DataRead(12);
    *(int *)((u)r[11] + 4) = Gte_DataRead(13);
    *(int *)((u)r[11] + 8) = Gte_DataRead(14);
    *(int *)((u)r[9] + 0) = Gte_DataRead(17);
    *(int *)((u)r[9] + 4) = Gte_DataRead(18);
    *(int *)((u)r[9] + 8) = Gte_DataRead(19);
    r[11] = (u)r[11] + 12;
    c = (((int)r[5] > 0)); r[9] = (u)r[9] + 12; if (c) goto L800d9990;
    L800d99f0:;
     goto out;
out:
    RECOMP_RETURN;
}
