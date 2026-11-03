extern char R_GCL_ExecProc[] __asm__("GCL_ExecProc");
extern char R_GV_DestroyActor[] __asm__("GV_DestroyActor");
int G_s07b_800CAFC8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s07b_800CAFC8");
int G_s07b_800CAFC8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(40)
    r[29] = (u)r[29] + -40;
    *(int *)((u)r[29] + 32) = r[16];
    r[16] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 36) = r[31];
    r[3] = *(int *)((u)r[16] + 2128);
    r[2] = r[3] & 16;
    c = ((r[2] == 0)); r[2] = (u)0 + -17; if (c) goto L800cb058;
    r[2] = r[3] & r[2];
    *(int *)((u)r[16] + 2128) = r[2];
    r[2] = *(short *)((u)r[16] + 2118);
    r[3] = *(unsigned short *)((u)r[16] + 2118);
    c = (((int)r[2] >= 0));  if (c) goto L800cb050;
    r[2] = *(int *)((u)r[16] + 2704);
    c = (((int)r[2] < 0)); r[2] = (u)0 + 1; if (c) goto L800cb040;
    *(short *)((u)r[29] + 16) = r[2];
    r[2] = (u)r[29] + 24;
    *(int *)((u)r[29] + 20) = r[2];
    r[2] = *(int *)((u)r[16] + 2016);
    r[2] = *(short *)((u)r[2] + 38);
    *(int *)((u)r[29] + 24) = r[2];
    r[4] = *(int *)((u)r[16] + 2704);
    r[5] = (u)r[29] + 16; CALL(R_GCL_ExecProc);
    L800cb040:;
    r[4] = (u)r[16] + (u)0; CALL(R_GV_DestroyActor);
     goto L800cb058;
    L800cb050:;
    *(short *)((u)r[16] + 2116) = r[3];
    *(int *)((u)r[16] + 2120) = 0;
    L800cb058:;
    r[31] = *(int *)((u)r[29] + 36);
    r[16] = *(int *)((u)r[29] + 32);
    r[29] = (u)r[29] + 40; goto out;
out:
    RECOMP_RETURN;
}
