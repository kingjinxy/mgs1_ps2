extern char R_s10a_dat_800E43D8[] __asm__("s10a_dat_800E43D8");
extern char R_DG_DequeuePrim[] __asm__("DG_DequeuePrim");
extern char R_DG_FreePrim[] __asm__("DG_FreePrim");
int G_s10a_800C4918(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s10a_800C4918");
int G_s10a_800C4918(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(32)
    r[29] = (u)r[29] + -32;
    *(int *)((u)r[29] + 20) = r[17];
    r[17] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 24) = r[31];
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = *(int *)((u)r[17] + 32);
    c = ((r[16] == 0)); r[3] = 0; if (c) goto L800c4950;
    r[4] = (u)r[16] + (u)0; CALL(R_DG_DequeuePrim);
    r[4] = (u)r[16] + (u)0; CALL(R_DG_FreePrim);
    r[3] = 0;
    L800c4950:;
    r[2] = *(int *)((u)r[17] + 76);
    r[3] = (u)r[3] + (int)R_s10a_dat_800E43D8;
    r[2] = (u)r[2] << 3;
    r[2] = (u)r[2] + (u)r[3];
    *(short *)((u)r[2] + 6) = 0;
    r[2] = *(unsigned short *)((u)r[3] + 386);
    r[2] = (u)r[2] + -1;
    *(short *)((u)r[3] + 386) = r[2];
    r[31] = *(int *)((u)r[29] + 24);
    r[17] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 32; goto out;
out:
    return r[2];
}
