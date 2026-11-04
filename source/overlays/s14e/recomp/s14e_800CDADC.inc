extern char R_linkvarbuf[] __asm__("linkvarbuf");
extern char R_s14e_800CD08C[] __asm__("s14e_800CD08C");
int G_s14e_800CDADC(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s14e_800CDADC");
int G_s14e_800CDADC(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 20) = r[31];
    r[3] = *(short *)((u)r[16] + 2852);
    r[2] = (u)0 + 16;
    c = ((r[3] != r[2]));  if (c) goto L800cdb1c;
     CALL(R_s14e_800CD08C);
    c = ((r[2] == 0)); r[2] = (u)0 + 2; if (c) goto L800cdb1c;
    *(short *)((u)r[16] + 2850) = r[2];
    r[2] = (u)0 + 14;
    *(short *)((u)r[16] + 2852) = r[2];
    *(int *)((u)r[16] + 2856) = 0;
    L800cdb1c:;
    r[2] = *(int *)((u)r[16] + 3116);
    r[2] = (int)r[2] < 800;
    c = ((r[2] == 0)); r[2] = 0; if (c) goto L800cdb68;
    r[2] = *(short *)((u)r[2] + ((int)R_linkvarbuf + 32));
    c = ((r[2] != 0)); r[2] = (u)0 + 2; if (c) goto L800cdb68;
    *(short *)((u)r[16] + 2850) = r[2];
    r[2] = (u)0 + 10;
    *(short *)((u)r[16] + 2852) = r[2];
    r[2] = *(int *)((u)r[16] + 2872);
    r[4] = *(unsigned short *)((u)r[16] + 3120);
    r[3] = 0x10000;
    *(int *)((u)r[16] + 2856) = 0;
    r[2] = r[2] | r[3];
    *(int *)((u)r[16] + 2872) = r[2];
    *(short *)((u)r[16] + 2888) = r[4];
    L800cdb68:;
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
