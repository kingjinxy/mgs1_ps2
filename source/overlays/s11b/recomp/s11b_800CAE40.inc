extern char R_DG_Chanls[] __asm__("DG_Chanls");
extern char R_GM_Camera[] __asm__("GM_Camera");
extern char R_gUnkCameraStruct2_800B7868[] __asm__("gUnkCameraStruct2_800B7868");
extern char R_DG_MakeCameraMatrix[] __asm__("DG_MakeCameraMatrix");
int G_s11b_800CAE40(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s11b_800CAE40");
int G_s11b_800CAE40(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    r[4] = 0;
    r[4] = (u)r[4] + ((int)R_DG_Chanls + 492);
    r[5] = (u)r[16] + 27340;
    r[6] = (u)r[16] + 27348;
    *(int *)((u)r[29] + 20) = r[31];
    r[7] = (u)0 + 320; CALL(R_DG_MakeCameraMatrix);
    r[2] = 0;
    r[2] = (u)r[2] + (int)R_GM_Camera;
    r[3] = (u)0 + 320;
    *(short *)((u)r[2] + 42) = 0;
    *(short *)((u)r[2] + 32) = r[3];
    r[2] = 0;
    r[11] = (u)r[2] + (int)R_gUnkCameraStruct2_800B7868;
    r[8] = LWL(((u)r[16] + 27343), r[8]);
    r[8] = LWR(((u)r[16] + 27340), r[8]);
    r[9] = LWL(((u)r[16] + 27347), r[9]);
    r[9] = LWR(((u)r[16] + 27344), r[9]);
    SWL(((u)r[11] + 3), r[8]);
    SWR(((u)r[11] + 0), r[8]);
    SWL(((u)r[11] + 7), r[9]);
    SWR(((u)r[11] + 4), r[9]);
    r[2] = (u)r[2] + (int)R_gUnkCameraStruct2_800B7868;
    r[8] = LWL(((u)r[16] + 27351), r[8]);
    r[8] = LWR(((u)r[16] + 27348), r[8]);
    r[9] = LWL(((u)r[16] + 27355), r[9]);
    r[9] = LWR(((u)r[16] + 27352), r[9]);
    SWL(((u)r[2] + 11), r[8]);
    SWR(((u)r[2] + 8), r[8]);
    SWL(((u)r[2] + 15), r[9]);
    SWR(((u)r[2] + 12), r[9]);
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
