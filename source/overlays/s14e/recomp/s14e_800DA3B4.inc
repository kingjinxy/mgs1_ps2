extern char R_DG_PacketCode[] __asm__("DG_PacketCode");
int G_s14e_800DA3B4(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s14e_800DA3B4");
int G_s14e_800DA3B4(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[3] = 0;
    r[2] = *(int *)((u)r[4] + 0);
    r[2] = r[2] & 2;
    c = ((r[2] == 0)); r[3] = (u)r[3] + (int)R_DG_PacketCode; if (c) goto L800da3d0;
    r[3] = (u)r[3] + 4;
    L800da3d0:;
    Gte_DataWrite(6, *(int *)((u)r[3] + 0));
    r[11] = (int)PSX_ADDR(0x1f800000);
    r[5] = *(int *)((u)r[4] + 68);
    r[2] = *(int *)((u)r[4] + 64);
    r[10] = *(int *)((u)r[5] + 0);
    r[9] = *(int *)((u)r[5] + 4);
    r[8] = *(int *)((u)r[5] + 8);
    r[7] = *(int *)((u)r[5] + 12);
    r[4] = *(int *)((u)r[5] + 16);
    r[6] = *(int *)((u)r[5] + 20);
    c = (((int)r[2] <= 0)); r[11] = r[11] | 32; if (c) goto L800da458;
    r[3] = (u)r[5] + 20;
    L800da404:;
    Gte_DataWrite(0, r[10]);
    Gte_DataWrite(1, r[9]);
    Gte_DataWrite(2, r[8]);
    Gte_DataWrite(3, r[7]);
    Gte_DataWrite(4, r[4]);
    Gte_DataWrite(5, r[6]);
    r[3] = (u)r[3] + 24;
    r[5] = (u)r[5] + 24;
    r[2] = (u)r[2] + -3;
    Gte_Command(0xd80420);
    r[10] = *(int *)((u)r[5] + 0);
    r[9] = *(int *)((u)r[3] + -16);
    r[8] = *(int *)((u)r[3] + -12);
    r[7] = *(int *)((u)r[3] + -8);
    r[4] = *(int *)((u)r[3] + -4);
    r[6] = *(int *)((u)r[3] + 0);
    *(int *)((u)r[11] + 0) = Gte_DataRead(20);
    *(int *)((u)r[11] + 4) = Gte_DataRead(21);
    *(int *)((u)r[11] + 8) = Gte_DataRead(22);
    c = (((int)r[2] > 0)); r[11] = (u)r[11] + 12; if (c) goto L800da404;
    L800da458:;
     goto out;
out:
    RECOMP_RETURN;
}
