int G_s14e_800D8850(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s14e_800D8850");
int G_s14e_800D8850(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[2] = *(int *)((u)r[4] + 24);
    *(int *)((u)r[2] + 4) = Gte_DataRead(22);
    Gte_DataWrite(8, r[6]);
    Gte_DataWrite(6, *(int *)((u)r[5] + 4));
    *(int *)((u)r[4] + 24) = r[5];
    Gte_Command(0x780010);
     goto out;
out:
    RECOMP_RETURN;
}
