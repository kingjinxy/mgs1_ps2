int G_s08b_bunsin2_800D12A0(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s08b_bunsin2_800D12A0");
int G_s08b_bunsin2_800D12A0(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[2] = *(int *)((u)r[4] + 6608);
    r[5] = (u)0 + 18;
    c = ((r[2] != 0)); *(int *)((u)r[4] + 6576) = r[5]; if (c) goto L800d12c4;
    r[3] = (u)r[2] + (u)0;
    r[2] = (u)0 + (u)0;
    r[3] = (u)r[3] + 1;
    *(int *)((u)r[4] + 6608) = r[3]; goto out;
    L800d12c4:;
    r[2] = (u)r[2] + 1;
    *(int *)((u)r[4] + 6608) = r[2];
    r[2] = (int)r[2] < 301;
    c = ((r[2] == 0));  if (c) goto L800d12e4;
    r[2] = *(int *)((u)r[4] + 6568);
     goto out;
    L800d12e4:;
    r[2] = (u)0 + 1; goto out;
out:
    RECOMP_RETURN;
}
