extern char R_GV_NearExp2[] __asm__("GV_NearExp2");
int G_s15a_800CA420(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s15a_800CA420");
int G_s15a_800CA420(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(32)
    r[29] = (u)r[29] + -32;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 20) = r[17];
    r[17] = (u)r[16] + 36;
    *(int *)((u)r[29] + 24) = r[31];
    r[2] = *(unsigned short *)((u)r[16] + 184);
    r[4] = *(short *)((u)r[17] + 54);
    r[5] = (u)0 + 450;
    *(short *)((u)r[17] + 50) = r[2]; CALL(R_GV_NearExp2);
    *(short *)((u)r[17] + 54) = r[2];
    r[2] = *(int *)((u)r[16] + 1644);
    c = (((int)r[2] >= 0)); r[2] = (u)r[2] + -16; if (c) goto L800ca480;
    r[2] = *(signed char *)((u)r[17] + 87);
    c = ((r[2] == 0));  if (c) goto L800ca474;
    *(int *)((u)r[16] + 1644) = 0;
    L800ca474:;
    r[2] = *(int *)((u)r[16] + 1644);
    r[2] = (u)r[2] + -16;
    L800ca480:;
    *(int *)((u)r[16] + 1644) = r[2];
    r[2] = *(unsigned short *)((u)r[16] + 1644);
    *(short *)((u)r[17] + 70) = r[2];
    r[31] = *(int *)((u)r[29] + 24);
    r[17] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 32; goto out;
out:
    RECOMP_RETURN;
}
