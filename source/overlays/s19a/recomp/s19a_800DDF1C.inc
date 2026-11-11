extern char R_s19a_dat_800C393C[] __asm__("s19a_dat_800C393C");
extern char R_GCL_ExecProc[] __asm__("GCL_ExecProc");
extern char R_GV_DestroyActor[] __asm__("GV_DestroyActor");
extern char R_s19a_800D88EC[] __asm__("s19a_800D88EC");
int G_s19a_800DDF1C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s19a_800DDF1C");
int G_s19a_800DDF1C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    r[5] = (u)0 + 1;
    r[6] = 0;
    *(int *)((u)r[29] + 20) = r[31];
    r[4] = *(unsigned short *)((u)r[16] + 32);
    r[6] = (u)r[6] + ((int)R_s19a_dat_800C393C + 24); CALL(R_s19a_800D88EC);
    c = ((r[2] != 0)); r[2] = (u)0 + -1; if (c) goto L800ddf4c;
    *(int *)((u)r[16] + 44) = r[2];
    L800ddf4c:;
    r[2] = *(int *)((u)r[16] + 44);
    r[2] = (u)r[2] + -1;
    c = (((int)r[2] >= 0)); *(int *)((u)r[16] + 44) = r[2]; if (c) goto L800ddf80;
    r[4] = *(int *)((u)r[16] + 48);
    c = ((r[4] == 0));  if (c) goto L800ddf78;
    r[5] = (u)0 + (u)0; CALL(R_GCL_ExecProc);
    L800ddf78:;
    r[4] = (u)r[16] + (u)0; CALL(R_GV_DestroyActor);
    L800ddf80:;
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
