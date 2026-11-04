extern char R_GV_ReceiveMessage[] __asm__("GV_ReceiveMessage");
int G_s10a_800C5278(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s10a_800C5278");
int G_s10a_800C5278(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(32)
    r[29] = (u)r[29] + -32;
    *(int *)((u)r[29] + 24) = r[16];
    r[16] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 28) = r[31];
    r[4] = *(int *)((u)r[16] + 332);
    r[5] = (u)r[29] + 16; CALL(R_GV_ReceiveMessage);
    c = ((r[2] == 0));  if (c) goto L800c52c8;
    r[2] = *(int *)((u)r[29] + 16);
    r[3] = *(unsigned short *)((u)r[2] + 4);
    r[2] = 0 | 54732;
    c = ((r[3] != r[2])); r[2] = (u)0 + 3538; if (c) goto L800c52bc;
    *(int *)((u)r[16] + 336) = 0; goto L800c52c8;
    L800c52bc:;
    c = ((r[3] != r[2])); r[2] = (u)0 + 1; if (c) goto L800c52c8;
    *(int *)((u)r[16] + 336) = r[2];
    L800c52c8:;
    r[31] = *(int *)((u)r[29] + 28);
    r[16] = *(int *)((u)r[29] + 24);
    r[29] = (u)r[29] + 32; goto out;
out:
    RECOMP_RETURN;
}
