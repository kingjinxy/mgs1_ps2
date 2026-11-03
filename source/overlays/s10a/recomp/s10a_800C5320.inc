extern char R_DG_WriteObjPacketRGB[] __asm__("DG_WriteObjPacketRGB");
int G_s10a_800C5320(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s10a_800C5320");
int G_s10a_800C5320(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(32)
    r[29] = (u)r[29] + -32;
    *(int *)((u)r[29] + 28) = r[31];
    *(int *)((u)r[29] + 24) = r[18];
    *(int *)((u)r[29] + 20) = r[17];
    *(int *)((u)r[29] + 16) = r[16];
    r[18] = *(short *)((u)r[4] + 46);
    c = (((int)r[18] <= 0)); r[17] = (u)r[4] + 72; if (c) goto L800c5388;
    r[16] = (u)r[4] + 160;
    L800c5348:;
    r[2] = *(int *)((u)r[16] + -4);
    c = ((r[2] == 0)); r[4] = (u)r[17] + (u)0; if (c) goto L800c5360;
    r[5] = (u)0 + (u)0; CALL(R_DG_WriteObjPacketRGB);
    L800c5360:;
    r[2] = *(int *)((u)r[16] + 0);
    c = ((r[2] == 0)); r[4] = (u)r[17] + (u)0; if (c) goto L800c5378;
    r[5] = (u)0 + 1; CALL(R_DG_WriteObjPacketRGB);
    L800c5378:;
    r[16] = (u)r[16] + 92;
    r[18] = (u)r[18] + -1;
    c = (((int)r[18] > 0)); r[17] = (u)r[17] + 92; if (c) goto L800c5348;
    L800c5388:;
    r[31] = *(int *)((u)r[29] + 28);
    r[18] = *(int *)((u)r[29] + 24);
    r[17] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 32; goto out;
out:
    RECOMP_RETURN;
}
