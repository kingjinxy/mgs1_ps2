extern char R_s10a_800C5924[] __asm__("s10a_800C5924");
extern char R_s10a_800C5B48[] __asm__("s10a_800C5B48");
int G_s10a_800C5BFC(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s10a_800C5BFC");
int G_s10a_800C5BFC(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 20) = r[31];
    r[2] = *(int *)((u)r[16] + 32);
    r[2] = *(int *)((u)r[2] + 0);
    r[2] = *(int *)((u)r[2] + 40);
    r[2] = r[2] & 128;
    c = ((r[2] == 0)); r[4] = (u)r[16] + (u)0; if (c) goto L800c5c4c;
    r[3] = *(int *)((u)r[16] + 36);
    r[2] = *(int *)((u)r[3] + 36);
    r[2] = r[2] | 256;
    *(int *)((u)r[3] + 36) = r[2]; goto L800c5c70;
    L800c5c4c:;
    r[2] = *(int *)((u)r[16] + 36);
    r[3] = *(int *)((u)r[2] + 36);
    r[5] = (u)0 + -257;
    r[3] = r[3] & r[5];
    *(int *)((u)r[2] + 36) = r[3]; CALL(R_s10a_800C5924);
    r[4] = (u)r[16] + (u)0; CALL(R_s10a_800C5B48);
    L800c5c70:;
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
