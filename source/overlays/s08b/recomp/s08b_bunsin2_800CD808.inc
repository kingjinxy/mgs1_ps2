extern char R_s08b_bunsin2_800CD808[] __asm__("s08b_bunsin2_800CD808");
extern char R_s08b_dword_800C3438[] __asm__("s08b_dword_800C3438");
extern char R_s08b_bunsin2_800CD95C[] __asm__("s08b_bunsin2_800CD95C");
extern char R_s08c_800C4194[] __asm__("s08c_800C4194");
int G_s08b_bunsin2_800CD808(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s08b_bunsin2_800CD808");
int G_s08b_bunsin2_800CD808(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(32)
    r[29] = (u)r[29] + -32;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = 0;
    r[2] = *(int *)((u)r[16] + (int)R_s08b_dword_800C3438);
    *(int *)((u)r[29] + 20) = r[17];
    r[17] = (u)r[4] + (u)0;
    r[2] = r[2] & 1;
    c = ((r[2] != 0)); *(int *)((u)r[29] + 24) = r[31]; if (c) goto L800cd838;
    r[4] = *(int *)((u)r[17] + 156);
    r[4] = (u)r[4] + 624; CALL(R_s08c_800C4194);
    L800cd838:;
    r[2] = *(int *)((u)r[16] + (int)R_s08b_dword_800C3438);
    r[2] = (int)r[2] < 8;
    c = ((r[2] != 0)); r[4] = (u)r[17] + (u)0; if (c) goto L800cd85c;
    *(int *)((u)r[16] + (int)R_s08b_dword_800C3438) = 0;
    r[5] = 0;
    r[5] = (u)r[5] + (int)R_s08b_bunsin2_800CD808; CALL(R_s08b_bunsin2_800CD95C);
    L800cd85c:;
    r[2] = *(int *)((u)r[16] + (int)R_s08b_dword_800C3438);
    r[31] = *(int *)((u)r[29] + 24);
    r[17] = *(int *)((u)r[29] + 20);
    r[2] = (u)r[2] + 1;
    *(int *)((u)r[16] + (int)R_s08b_dword_800C3438) = r[2];
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 32; goto out;
out:
    RECOMP_RETURN;
}
