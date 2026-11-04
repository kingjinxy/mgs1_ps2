extern char R_s08b_dword_800C3448[] __asm__("s08b_dword_800C3448");
extern char R_s08b_bunsin2_800CE2E8[] __asm__("s08b_bunsin2_800CE2E8");
int G_s08b_bunsin2_800CF660(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s08b_bunsin2_800CF660");
int G_s08b_bunsin2_800CF660(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 20) = r[31];
    r[3] = *(int *)((u)r[16] + 6708);
    r[2] = (u)0 + 2;
    c = ((r[3] == r[2])); r[2] = (int)r[3] < 3; if (c) goto L800cf6ac;
    c = ((r[2] == 0)); r[2] = (u)0 + 1; if (c) goto L800cf698;
    c = ((r[3] == r[2])); r[2] = 0; if (c) goto L800cf6c4;
     goto L800cf6f4;
    L800cf698:;
    r[2] = (int)r[3] < 5;
    c = ((r[2] == 0)); r[2] = (u)0 + 7; if (c) goto L800cf6f4;
    r[4] = 0; goto L800cf6dc;
    L800cf6ac:;
    r[2] = 0;
    r[4] = (u)r[16] + (u)0;
    *(int *)((u)r[2] + (int)R_s08b_dword_800C3448) = 0; CALL(R_s08b_bunsin2_800CE2E8);
    r[2] = (u)0 + 7; goto L800cf6cc;
    L800cf6c4:;
    *(int *)((u)r[2] + (int)R_s08b_dword_800C3448) = 0;
    r[2] = (u)0 + 7;
    L800cf6cc:;
    *(int *)((u)r[16] + 6600) = r[2];
    r[2] = (u)0 + 23;
    *(int *)((u)r[16] + 6604) = r[2]; goto L800cf6f4;
    L800cf6dc:;
    *(int *)((u)r[16] + 6600) = r[2];
    r[2] = *(int *)((u)r[4] + (int)R_s08b_dword_800C3448);
    r[3] = (u)0 + 23;
    *(int *)((u)r[16] + 6604) = r[3];
    r[2] = (u)r[2] + 1;
    *(int *)((u)r[4] + (int)R_s08b_dword_800C3448) = r[2];
    L800cf6f4:;
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
