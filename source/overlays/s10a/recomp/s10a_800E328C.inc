extern char R_s10a_dat_800C3844[] __asm__("s10a_dat_800C3844");
extern char R_GCL_ExecProc[] __asm__("GCL_ExecProc");
extern char R_GV_DestroyActor[] __asm__("GV_DestroyActor");
extern char R_s10a_800E027C[] __asm__("s10a_800E027C");
int G_s10a_800E328C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s10a_800E328C");
int G_s10a_800E328C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    r[5] = (u)0 + 1;
    r[6] = 0;
    *(int *)((u)r[29] + 20) = r[31];
    r[4] = *(unsigned short *)((u)r[16] + 32);
    r[6] = (u)r[6] + ((int)R_s10a_dat_800C3844 + 20); CALL(R_s10a_800E027C);
    c = ((r[2] != 0)); r[2] = (u)0 + -1; if (c) goto L800e32bc;
    *(int *)((u)r[16] + 44) = r[2];
    L800e32bc:;
    r[2] = *(int *)((u)r[16] + 44);
    r[2] = (u)r[2] + -1;
    c = (((int)r[2] >= 0)); *(int *)((u)r[16] + 44) = r[2]; if (c) goto L800e32f0;
    r[4] = *(int *)((u)r[16] + 48);
    c = ((r[4] == 0));  if (c) goto L800e32e8;
    r[5] = (u)0 + (u)0; CALL(R_GCL_ExecProc);
    L800e32e8:;
    r[4] = (u)r[16] + (u)0; CALL(R_GV_DestroyActor);
    L800e32f0:;
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    return r[2];
}
