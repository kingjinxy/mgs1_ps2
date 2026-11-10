extern char R_DG_DequeuePrim[] __asm__("DG_DequeuePrim");
extern char R_DG_FreePrim[] __asm__("DG_FreePrim");
int G_s18a_800D1F30(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s18a_800D1F30");
int G_s18a_800D1F30(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(40)
    r[29] = (u)r[29] + -40;
    *(int *)((u)r[29] + 28) = r[19];
    r[19] = (u)r[5] + (u)0;
    *(int *)((u)r[29] + 20) = r[17];
    r[17] = (u)0 + (u)0;
    *(int *)((u)r[29] + 32) = r[31];
    *(int *)((u)r[29] + 24) = r[18];
    c = (((int)r[19] <= 0)); *(int *)((u)r[29] + 16) = r[16]; if (c) goto L800d1f88;
    r[18] = (u)r[4] + (u)0;
    L800d1f58:;
    r[16] = *(int *)((u)r[18] + 96);
    c = ((r[16] == 0));  if (c) goto L800d1f78;
    r[4] = (u)r[16] + (u)0; CALL(R_DG_DequeuePrim);
    r[4] = (u)r[16] + (u)0; CALL(R_DG_FreePrim);
    L800d1f78:;
    r[17] = (u)r[17] + 1;
    r[2] = (int)r[17] < (int)r[19];
    c = ((r[2] != 0)); r[18] = (u)r[18] + 4; if (c) goto L800d1f58;
    L800d1f88:;
    r[31] = *(int *)((u)r[29] + 32);
    r[19] = *(int *)((u)r[29] + 28);
    r[18] = *(int *)((u)r[29] + 24);
    r[17] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 40; goto out;
out:
    RECOMP_RETURN;
}
