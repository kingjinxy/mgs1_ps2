extern char R_GV_RandU[] __asm__("GV_RandU");
extern char R_s19a_800C55A8[] __asm__("s19a_800C55A8");
int G_s19a_800C5918(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s19a_800C5918");
int G_s19a_800C5918(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(32)
    r[29] = (u)r[29] + -32;
    *(int *)((u)r[29] + 20) = r[17];
    r[17] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 24) = r[31];
    *(int *)((u)r[29] + 16) = r[16];
    r[2] = *(int *)((u)r[17] + 692);
    r[2] = r[2] & 63;
    c = ((r[2] != 0));  if (c) goto L800c5994;
    r[4] = (u)0 + 16; CALL(R_GV_RandU);
    r[4] = (u)0 + 2048;
    r[5] = (u)0 + 48;
    r[3] = *(int *)((u)r[17] + 692);
    r[16] = (u)r[17] + 108;
    *(char *)((u)r[17] + 116) = r[5];
    r[3] = (u)r[3] + (u)r[2];
    *(int *)((u)r[17] + 692) = r[3]; CALL(R_GV_RandU);
    r[3] = *(short *)((u)r[17] + 634);
    r[4] = (u)0 + 768;
    r[3] = (u)r[3] + -1024;
    r[3] = (u)r[3] + (u)r[2];
    r[3] = r[3] & 4095;
    *(short *)((u)r[16] + 2) = r[3]; CALL(R_GV_RandU);
    r[4] = (u)r[17] + 632;
    r[5] = (u)r[16] + (u)0;
    *(short *)((u)r[17] + 108) = r[2]; CALL(R_s19a_800C55A8);
    L800c5994:;
    r[2] = *(int *)((u)r[17] + 692);
    r[2] = (u)r[2] + 1;
    *(int *)((u)r[17] + 692) = r[2];
    r[31] = *(int *)((u)r[29] + 24);
    r[17] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 32; goto out;
out:
    RECOMP_RETURN;
}
