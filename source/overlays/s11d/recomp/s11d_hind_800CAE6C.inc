extern char R_s11d_hind_800C97F0[] __asm__("s11d_hind_800C97F0");
extern char R_s11d_hind_800C9B94[] __asm__("s11d_hind_800C9B94");
extern char R_s11d_hind_800C9C7C[] __asm__("s11d_hind_800C9C7C");
extern char R_s11d_hind_800C9D60[] __asm__("s11d_hind_800C9D60");
extern char R_s11d_hind_800CA424[] __asm__("s11d_hind_800CA424");
extern char R_s11d_hind_800CA49C[] __asm__("s11d_hind_800CA49C");
extern char R_s11d_hind_800CA504[] __asm__("s11d_hind_800CA504");
extern char R_s11d_hind_800CABA8[] __asm__("s11d_hind_800CABA8");
extern char R_s11d_hind_800CAD9C[] __asm__("s11d_hind_800CAD9C");
int G_s11d_hind_800CAE6C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s11d_hind_800CAE6C");
int G_s11d_hind_800CAE6C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[16];
    *(int *)((u)r[29] + 20) = r[31];
    r[16] = (u)r[4] + (u)0; CALL(R_s11d_hind_800CA49C);
    r[4] = (u)r[16] + (u)0; CALL(R_s11d_hind_800CA504);
    r[2] = *(int *)((u)r[16] + 456);
    r[2] = r[2] & 32;
    c = ((r[2] == 0));  if (c) goto L800caeac;
    r[4] = (u)r[16] + (u)0; CALL(R_s11d_hind_800C9D60);
     goto L800caec4;
    L800caeac:;
    r[4] = (u)r[16] + (u)0; CALL(R_s11d_hind_800CAD9C);
    r[4] = (u)r[16] + (u)0; CALL(R_s11d_hind_800C9C7C);
    r[4] = (u)r[16] + (u)0; CALL(R_s11d_hind_800C9B94);
    L800caec4:;
    r[4] = (u)r[16] + (u)0; CALL(R_s11d_hind_800CA424);
    r[3] = *(int *)((u)r[16] + 2340);
    r[2] = *(int *)((u)r[3] + 36);
    r[2] = r[2] | 256;
    *(int *)((u)r[3] + 36) = r[2];
    r[3] = *(unsigned short *)((u)r[16] + 460);
    r[2] = (u)0 + 1;
    c = ((r[3] != r[2])); r[4] = (u)r[16] + (u)0; if (c) goto L800caf08;
    r[5] = *(int *)((u)r[16] + 452);
    r[2] = (u)r[5] + (u)r[2];
    *(int *)((u)r[16] + 452) = r[2]; CALL(R_s11d_hind_800CABA8);
    L800caf08:;
    r[4] = (u)r[16] + (u)0; CALL(R_s11d_hind_800C97F0);
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
