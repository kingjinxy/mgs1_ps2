extern char R_GV_RandU[] __asm__("GV_RandU");
int G_s19a_800D4BE0(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s19a_800D4BE0");
int G_s19a_800D4BE0(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(32)
    r[29] = (u)r[29] + -32;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    r[2] = 0x10000;
    *(int *)((u)r[29] + 24) = r[31];
    *(int *)((u)r[29] + 20) = r[17];
    r[3] = *(int *)((u)r[16] + 2872);
    r[4] = *(unsigned short *)((u)r[16] + 3116);
    r[17] = *(int *)((u)r[16] + 2856);
    r[3] = r[3] | r[2];
    *(int *)((u)r[16] + 2872) = r[3];
    c = ((r[17] != 0)); *(short *)((u)r[16] + 2888) = r[4]; if (c) goto L800d4c20;
    r[4] = (u)0 + 8; CALL(R_GV_RandU);
    *(int *)((u)r[16] + 2856) = r[2];
    L800d4c20:;
    r[2] = (int)r[17] < 9;
    c = ((r[2] == 0)); r[2] = r[17] & 1; if (c) goto L800d4c44;
    c = ((r[2] != 0)); r[2] = (int)r[17] < 12; if (c) goto L800d4c48;
    r[2] = *(int *)((u)r[16] + 2872);
    r[3] = 0x40000;
    r[2] = r[2] | r[3];
    *(int *)((u)r[16] + 2872) = r[2];
    L800d4c44:;
    r[2] = (int)r[17] < 12;
    L800d4c48:;
    c = ((r[2] == 0)); r[2] = (u)0 + (u)0; if (c) goto L800d4c64;
    r[3] = *(int *)((u)r[16] + 2856);
    r[3] = (u)r[3] + 1;
    *(int *)((u)r[16] + 2856) = r[3]; goto L800d4c68;
    L800d4c64:;
    r[2] = (u)0 + 1;
    L800d4c68:;
    r[31] = *(int *)((u)r[29] + 24);
    r[17] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 32; goto out;
out:
    RECOMP_RETURN;
}
