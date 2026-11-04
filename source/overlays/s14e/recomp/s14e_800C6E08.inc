extern char R_s14e_800C6A34[] __asm__("s14e_800C6A34");
extern char R_s14e_800C6B18[] __asm__("s14e_800C6B18");
extern char R_s14e_800C6DB0[] __asm__("s14e_800C6DB0");
int G_s14e_800C6E08(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s14e_800C6E08");
int G_s14e_800C6E08(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(32)
    r[29] = (u)r[29] + -32;
    *(int *)((u)r[29] + 20) = r[17];
    r[17] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 24) = r[31];
    *(int *)((u)r[29] + 16) = r[16]; CALL(R_s14e_800C6B18);
    c = ((r[2] != 0));  if (c) goto L800c6e48;
    r[4] = (u)r[17] + (u)0; CALL(R_s14e_800C6A34);
    r[4] = (u)r[17] + (u)0;
    r[16] = (u)r[2] + (u)0; CALL(R_s14e_800C6DB0);
    r[16] = r[16] | r[2];
    c = ((r[16] == 0)); r[2] = (u)0 + (u)0; if (c) goto L800c6e58;
    L800c6e48:;
    r[2] = (u)0 + 1;
    r[4] = *(int *)((u)r[17] + 2304);
    r[3] = (u)r[2] + (u)0;
    *(short *)((u)r[4] + 0) = r[3];
    L800c6e58:;
    r[31] = *(int *)((u)r[29] + 24);
    r[17] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 32; goto out;
out:
    RECOMP_RETURN;
}
