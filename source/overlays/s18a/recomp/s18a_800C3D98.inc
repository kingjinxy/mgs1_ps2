extern char R_DG_UnDrawFrameCount[] __asm__("DG_UnDrawFrameCount");
extern char R_GV_PauseLevel[] __asm__("GV_PauseLevel");
extern char R_s18a_800C3D1C[] __asm__("s18a_800C3D1C");
extern char R_GM_StreamCancelCallback[] __asm__("GM_StreamCancelCallback");
extern char R_GM_StreamPlayStop[] __asm__("GM_StreamPlayStop");
extern char R_mts_read_pad[] __asm__("mts_read_pad");
int G_s18a_800C3D98(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s18a_800C3D98");
int G_s18a_800C3D98(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 20) = r[31];
    r[4] = (u)0 + 1; CALL(R_mts_read_pad);
    r[3] = *(int *)((u)r[16] + 36);
    r[2] = r[2] & r[3];
    c = ((r[2] == 0));  if (c) goto L800c3e00;
     CALL(R_GM_StreamCancelCallback);
     CALL(R_GM_StreamPlayStop);
    r[2] = 0;
    r[2] = (u)r[2] + (int)R_s18a_800C3D1C;
    r[5] = 0;
    r[3] = *(int *)((u)r[5] + (int)R_GV_PauseLevel);
    r[4] = 0;
    *(int *)((u)r[16] + 8) = r[2];
    r[2] = 0x7fff0000;
    *(int *)((u)r[4] + (int)R_DG_UnDrawFrameCount) = r[2];
    *(int *)((u)r[16] + 40) = 0;
    r[3] = r[3] | 4;
    *(int *)((u)r[5] + (int)R_GV_PauseLevel) = r[3];
    L800c3e00:;
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
