extern char R_s07b_800C49CC[] __asm__("s07b_800C49CC");
extern char R_s07b_800C4A18[] __asm__("s07b_800C4A18");
int G_s07b_800C4A94(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s07b_800C4A94");
int G_s07b_800C4A94(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[31];
    r[2] = *(short *)((u)r[4] + 2156);
    r[3] = *(unsigned short *)((u)r[4] + 2156);
    c = ((r[2] == 0));  if (c) goto L800c4b48;
    c = (((int)r[2] <= 0));  if (c) goto L800c4afc;
    r[2] = *(int *)((u)r[4] + 2124);
    r[2] = r[2] & 1;
    c = ((r[2] != 0)); r[2] = (u)r[3] + -1; if (c) goto L800c4b48;
    *(short *)((u)r[4] + 2156) = r[2];
    r[2] = (u)r[2] << 16;
    c = ((r[2] != 0)); r[5] = (u)0 + (u)0; if (c) goto L800c4b48;
    r[2] = *(int *)((u)r[4] + 156);
    r[3] = *(int *)((u)r[2] + 40);
    r[6] = (u)0 + -129;
    r[3] = r[3] & r[6];
    *(int *)((u)r[2] + 40) = r[3]; CALL(R_s07b_800C4A18);
    r[4] = (u)0 + (u)0; goto L800c4b40;
    L800c4afc:;
    r[2] = *(int *)((u)r[4] + 2124);
    r[2] = r[2] & 1;
    c = ((r[2] == 0)); r[2] = (u)r[3] + 1; if (c) goto L800c4b48;
    *(short *)((u)r[4] + 2156) = r[2];
    r[2] = (u)r[2] << 16;
    c = ((r[2] != 0)); r[5] = (u)0 + 1; if (c) goto L800c4b48;
    r[3] = *(int *)((u)r[4] + 156);
    r[2] = *(int *)((u)r[3] + 40);
    r[2] = r[2] | 128;
    *(int *)((u)r[3] + 40) = r[2]; CALL(R_s07b_800C4A18);
    r[4] = (u)0 + 1;
    L800c4b40:;
     CALL(R_s07b_800C49CC);
    L800c4b48:;
    r[31] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
