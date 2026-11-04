extern char R_DG_Chanls[] __asm__("DG_Chanls");
extern char R_GM_Camera[] __asm__("GM_Camera");
extern char R_gUnkCameraStruct2_800B7868[] __asm__("gUnkCameraStruct2_800B7868");
extern char R_DG_MakeCameraMatrix[] __asm__("DG_MakeCameraMatrix");
int G_s11h_800CFFA8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s11h_800CFFA8");
int G_s11h_800CFFA8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(32)
    r[29] = (u)r[29] + -32;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 20) = r[17];
    r[17] = (u)r[5] + (u)0;
    r[4] = 0;
    r[4] = (u)r[4] + ((int)R_DG_Chanls + 492);
    r[5] = (u)r[16] + (u)0;
    r[6] = (u)r[17] + (u)0;
    *(int *)((u)r[29] + 24) = r[31];
    r[7] = (u)0 + 320; CALL(R_DG_MakeCameraMatrix);
    r[2] = 0;
    *(short *)((u)r[2] + ((int)R_GM_Camera + 42)) = 0;
    r[2] = 0;
    r[10] = (u)r[2] + (int)R_gUnkCameraStruct2_800B7868;
    r[3] = LWL(((u)r[16] + 3), r[3]);
    r[3] = LWR(((u)r[16] + 0), r[3]);
    r[8] = LWL(((u)r[16] + 7), r[8]);
    r[8] = LWR(((u)r[16] + 4), r[8]);
    SWL(((u)r[10] + 3), r[3]);
    SWR(((u)r[10] + 0), r[3]);
    SWL(((u)r[10] + 7), r[8]);
    SWR(((u)r[10] + 4), r[8]);
    r[2] = (u)r[2] + (int)R_gUnkCameraStruct2_800B7868;
    r[3] = LWL(((u)r[17] + 3), r[3]);
    r[3] = LWR(((u)r[17] + 0), r[3]);
    r[8] = LWL(((u)r[17] + 7), r[8]);
    r[8] = LWR(((u)r[17] + 4), r[8]);
    SWL(((u)r[2] + 11), r[3]);
    SWR(((u)r[2] + 8), r[3]);
    SWL(((u)r[2] + 15), r[8]);
    SWR(((u)r[2] + 12), r[8]);
    r[31] = *(int *)((u)r[29] + 24);
    r[17] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 32; goto out;
out:
    RECOMP_RETURN;
}
