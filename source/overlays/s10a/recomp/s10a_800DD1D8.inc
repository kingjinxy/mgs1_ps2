extern char R_GM_StreamStatus[] __asm__("GM_StreamStatus");
extern char R_GM_VoxStream[] __asm__("GM_VoxStream");
int G_s10a_800DD1D8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s10a_800DD1D8");
int G_s10a_800DD1D8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(32)
    r[29] = (u)r[29] + -32;
    *(int *)((u)r[29] + 20) = r[17];
    r[17] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 24) = r[18];
    *(int *)((u)r[29] + 28) = r[31];
    *(int *)((u)r[29] + 16) = r[16];
    r[2] = *(int *)((u)r[17] + 1772);
    r[16] = (u)0 + -1;
    c = ((r[2] == r[16])); r[18] = (u)r[5] + (u)0; if (c) goto L800dd220;
     CALL(R_GM_StreamStatus);
    c = ((r[2] != r[16])); r[2] = (u)r[18] << 2; if (c) goto L800dd220;
    r[2] = (u)r[17] + (u)r[2];
    r[4] = *(int *)((u)r[2] + 1772);
    r[5] = (u)0 + (u)0; CALL(R_GM_VoxStream);
    L800dd220:;
    r[31] = *(int *)((u)r[29] + 28);
    r[18] = *(int *)((u)r[29] + 24);
    r[17] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 32; goto out;
out:
    RECOMP_RETURN;
}
