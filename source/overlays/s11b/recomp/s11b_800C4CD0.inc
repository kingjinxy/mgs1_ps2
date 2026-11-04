extern char R_DG_DequeuePrim[] __asm__("DG_DequeuePrim");
extern char R_DG_FreePrim[] __asm__("DG_FreePrim");
int G_s11b_800C4CD0(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s11b_800C4CD0");
int G_s11b_800C4CD0(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(32)
    r[29] = (u)r[29] + -32;
    *(int *)((u)r[29] + 28) = r[31];
    *(int *)((u)r[29] + 24) = r[18];
    *(int *)((u)r[29] + 20) = r[17];
    *(int *)((u)r[29] + 16) = r[16];
    r[17] = *(int *)((u)r[4] + 64);
    c = (((int)r[17] <= 0)); r[18] = (u)r[4] + 72; if (c) goto L800c4d20;
    L800c4cf4:;
    r[16] = *(int *)((u)r[18] + 32);
    c = ((r[16] == 0));  if (c) goto L800c4d14;
    r[4] = (u)r[16] + (u)0; CALL(R_DG_DequeuePrim);
    r[4] = (u)r[16] + (u)0; CALL(R_DG_FreePrim);
    L800c4d14:;
    r[17] = (u)r[17] + -1;
    c = (((int)r[17] > 0)); r[18] = (u)r[18] + 292; if (c) goto L800c4cf4;
    L800c4d20:;
    r[31] = *(int *)((u)r[29] + 28);
    r[18] = *(int *)((u)r[29] + 24);
    r[17] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 32; goto out;
out:
    RECOMP_RETURN;
}
