extern char R_s08b_dword_800E3BD8[] __asm__("s08b_dword_800E3BD8");
extern char R_s08b_bunsin2_800CDBAC[] __asm__("s08b_bunsin2_800CDBAC");
extern char R_s08b_bunsin2_800D1EC8[] __asm__("s08b_bunsin2_800D1EC8");
extern char R_s08b_bunsin2_800D2510[] __asm__("s08b_bunsin2_800D2510");
extern char R_s08b_bunsin2_800D2860[] __asm__("s08b_bunsin2_800D2860");
extern char R_s08b_bunsin2_800D2F80[] __asm__("s08b_bunsin2_800D2F80");
extern char R_s08b_bunsin2_800D367C[] __asm__("s08b_bunsin2_800D367C");
extern char R_s08b_bunsin2_800D3DBC[] __asm__("s08b_bunsin2_800D3DBC");
extern char R_s08b_bunsin2_800D3EA4[] __asm__("s08b_bunsin2_800D3EA4");
extern char R_s08b_bunsin2_800D41DC[] __asm__("s08b_bunsin2_800D41DC");
extern char R_s08b_bunsin2_800D4460[] __asm__("s08b_bunsin2_800D4460");
int G_s08b_bunsin2_800D4AF4(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s08b_bunsin2_800D4AF4");
int G_s08b_bunsin2_800D4AF4(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 20) = r[31];
    r[3] = *(int *)((u)r[16] + 6600);
    r[2] = (u)r[3] < (u)10;
    c = ((r[2] == 0)); r[2] = 0; if (c) goto L800d4bbc;
    r[2] = (u)r[2] + (int)R_s08b_dword_800E3BD8;
    r[3] = (u)r[3] << 2;
    r[3] = (u)r[3] + (u)r[2];
    r[2] = *(int *)((u)r[3] + 0);
    t = r[2];  switch ((u)t) { case 0x800d4b34: goto L800d4b34; case 0x800d4b44: goto L800d4b44; case 0x800d4b54: goto L800d4b54; case 0x800d4b64: goto L800d4b64; case 0x800d4b74: goto L800d4b74; case 0x800d4b84: goto L800d4b84; case 0x800d4b94: goto L800d4b94; case 0x800d4ba4: goto L800d4ba4; case 0x800d4bb4: goto L800d4bb4; case 0x800d4bbc: goto L800d4bbc; default: goto out; }
    L800d4b34:;
    r[4] = (u)r[16] + (u)0; CALL(R_s08b_bunsin2_800D1EC8);
     goto L800d4bbc;
    L800d4b44:;
    r[4] = (u)r[16] + (u)0; CALL(R_s08b_bunsin2_800D367C);
     goto L800d4bbc;
    L800d4b54:;
    r[4] = (u)r[16] + (u)0; CALL(R_s08b_bunsin2_800D3DBC);
     goto L800d4bbc;
    L800d4b64:;
    r[4] = (u)r[16] + (u)0; CALL(R_s08b_bunsin2_800D3EA4);
     goto L800d4bbc;
    L800d4b74:;
    r[4] = (u)r[16] + (u)0; CALL(R_s08b_bunsin2_800D41DC);
     goto L800d4bbc;
    L800d4b84:;
    r[4] = (u)r[16] + (u)0; CALL(R_s08b_bunsin2_800D4460);
     goto L800d4bbc;
    L800d4b94:;
    r[4] = (u)r[16] + (u)0; CALL(R_s08b_bunsin2_800D2860);
     goto L800d4bbc;
    L800d4ba4:;
    r[4] = (u)r[16] + (u)0; CALL(R_s08b_bunsin2_800D2510);
     goto L800d4bbc;
    L800d4bb4:;
    r[4] = (u)r[16] + (u)0; CALL(R_s08b_bunsin2_800D2F80);
    L800d4bbc:;
    r[4] = (u)r[16] + (u)0; CALL(R_s08b_bunsin2_800CDBAC);
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
