extern char R_DG_DequeuePrim[] __asm__("DG_DequeuePrim");
extern char R_DG_FreePrim[] __asm__("DG_FreePrim");
extern char R_sub_8007913C[] __asm__("sub_8007913C");
int G_s17a_800D433C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s17a_800D433C");
int G_s17a_800D433C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(32)
    r[29] = (u)r[29] + -32;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 28) = r[31];
    *(int *)((u)r[29] + 24) = r[18];
    *(int *)((u)r[29] + 20) = r[17];
    r[3] = *(int *)((u)r[16] + 232);
    r[2] = (u)0 + 1;
    c = ((r[3] != r[2])); r[18] = (u)0 + (u)0; if (c) goto L800d436c;
     CALL(R_sub_8007913C);
    L800d436c:;
    r[17] = (u)r[16] + (u)0;
    L800d4370:;
    r[16] = *(int *)((u)r[17] + 36);
    c = ((r[16] == 0));  if (c) goto L800d4390;
    r[4] = (u)r[16] + (u)0; CALL(R_DG_DequeuePrim);
    r[4] = (u)r[16] + (u)0; CALL(R_DG_FreePrim);
    L800d4390:;
    r[18] = (u)r[18] + 1;
    r[2] = (int)r[18] < 8;
    c = ((r[2] != 0)); r[17] = (u)r[17] + 4; if (c) goto L800d4370;
    r[31] = *(int *)((u)r[29] + 28);
    r[18] = *(int *)((u)r[29] + 24);
    r[17] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 32; goto out;
out:
    RECOMP_RETURN;
}
