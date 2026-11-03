extern char R_s10a_dat_800E4560[] __asm__("s10a_dat_800E4560");
extern char R_s10a_800C78DC[] __asm__("s10a_800C78DC");
int G_s10a_800C8038(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s10a_800C8038");
int G_s10a_800C8038(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(32)
    r[29] = (u)r[29] + -32;
    *(int *)((u)r[29] + 24) = r[18];
    r[18] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 20) = r[17];
    r[17] = (u)0 + (u)0;
    r[2] = 0;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[2] + (int)R_s10a_dat_800E4560;
    *(int *)((u)r[29] + 28) = r[31];
    L800c805c:;
    r[4] = (u)r[16] + (u)0;
    r[5] = (u)0 + (u)0;
    r[6] = (u)r[5] + (u)0;
    r[7] = (u)r[5] + (u)0; CALL(R_s10a_800C78DC);
    *(short *)((u)r[16] + 6) = 0;
    r[17] = (u)r[17] + 1;
    r[2] = (int)r[17] < 128;
    c = ((r[2] != 0)); r[16] = (u)r[16] + 8; if (c) goto L800c805c;
    r[2] = 0;
    r[2] = (u)r[2] + (int)R_s10a_dat_800E4560;
    *(short *)((u)r[2] + 1024) = 0;
    *(short *)((u)r[2] + 1026) = 0;
    *(int *)((u)r[18] + 44) = 0;
    r[31] = *(int *)((u)r[29] + 28);
    r[18] = *(int *)((u)r[29] + 24);
    r[17] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 32; goto out;
out:
    RECOMP_RETURN;
}
