extern char R_s19a_800D2C60[] __asm__("s19a_800D2C60");
extern char R_s19a_800D2F70[] __asm__("s19a_800D2F70");
int G_s19a_800D203C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s19a_800D203C");
int G_s19a_800D203C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(48)
    r[29] = (u)r[29] + -48;
    *(int *)((u)r[29] + 24) = r[16];
    r[16] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 40) = r[31];
    *(int *)((u)r[29] + 36) = r[19];
    *(int *)((u)r[29] + 32) = r[18];
    *(int *)((u)r[29] + 28) = r[17];
    r[2] = *(unsigned char *)((u)r[16] + 2975);
    r[2] = r[2] & 16;
    c = ((r[2] == 0)); r[2] = (u)0 + 5; if (c) goto L800d20cc;
    r[3] = *(short *)((u)r[16] + 2850);
    c = ((r[3] == r[2])); r[19] = (u)r[16] + 32; if (c) goto L800d20cc;
    r[2] = *(int *)((u)r[16] + 76);
    r[5] = (u)r[19] + (u)0;
    r[17] = *(int *)((u)r[2] + 8);
    r[18] = (u)r[16] + 2952;
    r[4] = (u)r[17] + (u)0; CALL(R_s19a_800D2F70);
    c = ((r[2] == 0)); r[4] = (u)r[17] + (u)0; if (c) goto L800d20cc;
    r[6] = *(short *)((u)r[16] + 2952);
    r[7] = *(short *)((u)r[18] + 2);
    r[2] = *(short *)((u)r[18] + 4);
    r[5] = (u)r[19] + (u)0;
    *(int *)((u)r[29] + 16) = r[2]; CALL(R_s19a_800D2C60);
    c = (((int)r[2] < 0));  if (c) goto L800d20cc;
    r[2] = *(unsigned char *)((u)r[16] + 2974);
    r[2] = r[2] | 16;
    *(char *)((u)r[16] + 2974) = r[2];
    L800d20cc:;
    r[31] = *(int *)((u)r[29] + 40);
    r[19] = *(int *)((u)r[29] + 36);
    r[18] = *(int *)((u)r[29] + 32);
    r[17] = *(int *)((u)r[29] + 28);
    r[16] = *(int *)((u)r[29] + 24);
    r[29] = (u)r[29] + 48; goto out;
out:
    RECOMP_RETURN;
}
