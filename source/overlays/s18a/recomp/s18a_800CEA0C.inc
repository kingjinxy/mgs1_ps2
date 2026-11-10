extern char R_s18a_dat_800E3120[] __asm__("s18a_dat_800E3120");
extern char R_printf[] __asm__("printf");
extern char R_s18a_800CC830[] __asm__("s18a_800CC830");
extern char R_s18a_800CC8F0[] __asm__("s18a_800CC8F0");
extern char R_s18a_800CC96C[] __asm__("s18a_800CC96C");
extern char R_s18a_800CCCE0[] __asm__("s18a_800CCCE0");
int G_s18a_800CEA0C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s18a_800CEA0C");
int G_s18a_800CEA0C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(32)
    r[29] = (u)r[29] + -32;
    *(int *)((u)r[29] + 20) = r[17];
    r[17] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 28) = r[31];
    *(int *)((u)r[29] + 24) = r[18];
    *(int *)((u)r[29] + 16) = r[16];
    r[2] = *(int *)((u)r[17] + 2408);
    c = ((r[2] != 0)); r[18] = (u)r[17] + 32; if (c) goto L800cea70;
    r[4] = (u)r[18] + (u)0; CALL(R_s18a_800CC96C);
    r[4] = 0;
    r[4] = (u)r[4] + (int)R_s18a_dat_800E3120;
    r[16] = (u)r[2] + (u)0;
    r[5] = (u)r[16] + (u)0; CALL(R_printf);
    c = (((int)r[16] < 0)); r[4] = (u)r[16] + (u)0; if (c) goto L800ceaac;
    r[5] = (u)r[18] + (u)0; CALL(R_s18a_800CCCE0);
    r[4] = (u)r[17] + (u)0;
    *(int *)((u)r[17] + 2448) = r[2];
    *(int *)((u)r[17] + 2452) = 0; CALL(R_s18a_800CC830);
    L800cea70:;
    r[4] = (u)r[17] + (u)0;
    r[5] = (u)0 + 300; CALL(R_s18a_800CC8F0);
    c = ((r[2] == 0));  if (c) goto L800ceac4;
    r[2] = *(int *)((u)r[17] + 2452);
    c = ((r[2] != 0)); r[2] = (u)0 + 2; if (c) goto L800ceab0;
    r[2] = (u)0 + 1;
    *(int *)((u)r[17] + 2452) = r[2];
    r[4] = (u)r[17] + (u)0; CALL(R_s18a_800CC830);
     goto L800ceac4;
    L800ceaac:;
    r[2] = (u)0 + 2;
    L800ceab0:;
    *(int *)((u)r[17] + 2400) = r[2];
    r[2] = (u)0 + 9;
    *(int *)((u)r[17] + 2404) = r[2];
    *(int *)((u)r[17] + 2408) = 0; goto L800cead4;
    L800ceac4:;
    r[2] = *(int *)((u)r[17] + 2408);
    r[2] = (u)r[2] + 1;
    *(int *)((u)r[17] + 2408) = r[2];
    L800cead4:;
    r[31] = *(int *)((u)r[29] + 28);
    r[18] = *(int *)((u)r[29] + 24);
    r[17] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 32; goto out;
out:
    RECOMP_RETURN;
}
