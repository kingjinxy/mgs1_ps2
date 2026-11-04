int G_s14e_800D8968(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s14e_800D8968");
int G_s14e_800D8968(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[3] = *(int *)((u)r[4] + 24);
    *(int *)((u)r[3] + 4) = Gte_DataRead(22);
    Gte_DataWrite(8, r[6]);
    Gte_DataWrite(20, *(int *)((u)r[5] + 16));
    Gte_DataWrite(21, *(int *)((u)r[5] + 28));
    *(int *)((u)r[4] + 24) = r[5];
    Gte_Command(0xf8002a);
    r[2] = *(int *)((u)r[5] + 4);
    *(int *)((u)r[5] + 16) = Gte_DataRead(20);
    *(int *)((u)r[5] + 28) = Gte_DataRead(21);
    Gte_DataWrite(6, *(int *)((u)r[2] + 0));
    Gte_Command(0x780010);
     goto out;
out:
    RECOMP_RETURN;
}
