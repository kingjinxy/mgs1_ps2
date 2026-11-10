int G_s14e_800DA460(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s14e_800DA460");
int G_s14e_800DA460(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[10] = (u)r[4] + (u)0;
    r[6] = (u)r[6] + -1;
    c = (((int)r[6] < 0)); r[9] = (u)r[5] + (u)0; if (c) goto L800da504;
    r[8] = (int)PSX_ADDR(0x1f800000);
    r[8] = r[8] | 32;
    r[7] = (u)r[5] + 40;
    L800da47c:;
    r[2] = *(unsigned short *)((u)r[9] + 0);
    c = ((r[2] == 0));  if (c) goto L800da4f0;
    r[2] = *(int *)((u)r[10] + 0);
    r[3] = (u)r[2] + (u)0;
    r[4] = (u)r[2] + (u)0;
    r[5] = (u)r[2] + (u)0;
    r[2] = (u)r[2] << 2;
    r[3] = (u)r[3] >> 6;
    r[4] = (u)r[4] >> 22;
    r[5] = (u)r[5] >> 14;
    r[2] = r[2] & 508;
    r[3] = r[3] & 508;
    r[4] = r[4] & 508;
    r[5] = r[5] & 508;
    r[2] = (u)r[2] + (u)r[8];
    r[3] = (u)r[3] + (u)r[8];
    r[4] = (u)r[4] + (u)r[8];
    r[2] = *(int *)((u)r[2] + 0);
    r[3] = *(int *)((u)r[3] + 0);
    r[5] = (u)r[5] + (u)r[8];
    *(int *)((u)r[7] + -36) = r[2];
    *(int *)((u)r[7] + -24) = r[3];
    r[2] = *(int *)((u)r[4] + 0);
    r[3] = *(int *)((u)r[5] + 0);
    *(int *)((u)r[7] + -12) = r[2];
    *(int *)((u)r[7] + 0) = r[3];
    L800da4f0:;
    r[7] = (u)r[7] + 52;
    r[9] = (u)r[9] + 52;
    r[6] = (u)r[6] + -1;
    c = (((int)r[6] >= 0)); r[10] = (u)r[10] + 4; if (c) goto L800da47c;
    L800da504:;
    r[2] = (u)r[9] + (u)0; goto out;
out:
    RECOMP_RETURN;
}
