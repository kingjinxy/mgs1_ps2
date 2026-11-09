extern char R_DG_SetPos2[] __asm__("DG_SetPos2");
extern char R_GM_ActObject2[] __asm__("GM_ActObject2");
extern char R_s15c_dyncon_800D3EBC[] __asm__("s15c_dyncon_800D3EBC");
int G_s15c_dyncon_800D7E30(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s15c_dyncon_800D7E30");
int G_s15c_dyncon_800D7E30(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(40)
    r[29] = (u)r[29] + -40;
    *(int *)((u)r[29] + 24) = r[16];
    r[16] = (u)r[4] + (u)0;
    r[3] = (u)r[5] + (u)0;
    *(int *)((u)r[29] + 28) = r[17];
    r[17] = (u)r[7] + (u)0;
    r[4] = (u)r[29] + 16;
    r[5] = (u)r[6] << 2;
    r[5] = (u)r[5] + (u)r[6];
    r[5] = (u)r[5] << 3;
    r[5] = (u)r[5] - (u)r[6];
    r[5] = (u)r[5] << 2;
    r[2] = (u)r[16] + (u)r[5];
    r[5] = (u)r[5] + (u)r[16];
    *(int *)((u)r[29] + 32) = r[31];
    r[8] = LWL(((u)r[2] + 115), r[8]);
    r[8] = LWR(((u)r[2] + 112), r[8]);
    r[9] = LWL(((u)r[2] + 119), r[9]);
    r[9] = LWR(((u)r[2] + 116), r[9]);
    SWL(((u)r[29] + 19), r[8]);
    SWR(((u)r[29] + 16), r[8]);
    SWL(((u)r[29] + 23), r[9]);
    SWR(((u)r[29] + 20), r[9]);
    r[2] = *(unsigned short *)((u)r[29] + 18);
    r[5] = (u)r[5] + 120;
    r[2] = (u)r[2] + 1749;
    *(short *)((u)r[29] + 18) = r[2];
    r[2] = (u)r[3] << 1;
    r[2] = (u)r[2] + (u)r[3];
    r[2] = (u)r[2] << 3;
    r[2] = (u)r[2] + (u)r[3];
    r[2] = (u)r[2] << 2;
    r[2] = (u)r[2] + 12804;
    r[16] = (u)r[16] + (u)r[2]; CALL(R_DG_SetPos2);
    r[4] = (u)r[16] + (u)0;
    r[5] = (u)r[17] + (u)0;
    r[6] = (u)0 + 71; CALL(R_s15c_dyncon_800D3EBC);
    r[4] = (u)r[16] + (u)0;
    r[3] = *(int *)((u)r[4] + 0);
    r[2] = (u)0 + -250;
    *(short *)((u)r[3] + 152) = r[2]; CALL(R_GM_ActObject2);
    r[31] = *(int *)((u)r[29] + 32);
    r[17] = *(int *)((u)r[29] + 28);
    r[16] = *(int *)((u)r[29] + 24);
    r[29] = (u)r[29] + 40; goto out;
out:
    RECOMP_RETURN;
}
