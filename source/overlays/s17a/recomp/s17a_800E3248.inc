extern char R_GM_PlayerPosition[] __asm__("GM_PlayerPosition");
extern char R_s17a_800E2F68[] __asm__("s17a_800E2F68");
int G_s17a_800E3248(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s17a_800E3248");
int G_s17a_800E3248(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(32)
    r[29] = (u)r[29] + -32;
    r[3] = 0;
    r[2] = *(unsigned short *)((u)r[3] + (int)R_GM_PlayerPosition);
    r[3] = (u)r[3] + (int)R_GM_PlayerPosition;
    r[2] = (u)r[2] + 16000;
    r[2] = r[2] & 65535;
    r[2] = (u)r[2] < (u)32001;
    c = ((r[2] == 0)); *(int *)((u)r[29] + 24) = r[31]; if (c) goto L800e3298;
    r[2] = *(short *)((u)r[3] + 2);
    c = (((int)r[2] < 0));  if (c) goto L800e3298;
    r[3] = *(short *)((u)r[3] + 4);
    r[2] = (int)r[3] < -28000;
    c = ((r[2] != 0)); r[2] = (int)r[3] < 27001; if (c) goto L800e3298;
    c = ((r[2] != 0)); r[2] = (u)0 + (u)0; if (c) goto L800e32a4;
    L800e3298:;
    r[2] = *(int *)((u)r[29] + 48);
    *(int *)((u)r[29] + 16) = r[2]; CALL(R_s17a_800E2F68);
    L800e32a4:;
    r[31] = *(int *)((u)r[29] + 24);
    r[29] = (u)r[29] + 32; goto out;
out:
    RECOMP_RETURN;
}
