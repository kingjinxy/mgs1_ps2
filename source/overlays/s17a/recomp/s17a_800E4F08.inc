int G_s17a_800E4F08(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s17a_800E4F08");
int G_s17a_800E4F08(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    Gte_DataWrite(0, *(int *)((u)r[4] + 0));
    Gte_DataWrite(1, *(int *)((u)r[4] + 4));
    Gte_Command(0x480012);
    *(int *)((u)r[5] + 0) = Gte_DataRead(25);
    *(int *)((u)r[5] + 4) = Gte_DataRead(26);
    *(int *)((u)r[5] + 8) = Gte_DataRead(27);
    r[2] = Gte_CtrlRead(31);
    *(int *)((u)r[6] + 0) = r[2]; goto out;
out:
    RECOMP_RETURN;
}
