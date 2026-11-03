extern char R_GM_NoisePower[] __asm__("GM_NoisePower");
extern char R_s10a_800CC4C8[] __asm__("s10a_800CC4C8");
extern char R_s10a_800CE21C[] __asm__("s10a_800CE21C");
int G_s10a_800CC850(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s10a_800CC850");
int G_s10a_800CC850(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    r[2] = 0;
    r[3] = *(int *)((u)r[2] + (int)R_GM_NoisePower);
    r[2] = (u)0 + 100;
    c = ((r[3] == r[2])); *(int *)((u)r[29] + 20) = r[31]; if (c) goto L800cc8dc;
    r[2] = (int)r[3] < 101;
    c = ((r[2] == 0)); r[2] = (u)0 + 5; if (c) goto L800cc88c;
    c = ((r[3] == r[2])); r[2] = (u)0 + 1; if (c) goto L800cc8a8;
     goto L800cc8dc;
    L800cc88c:;
    r[2] = (u)0 + 200;
    c = ((r[3] == r[2])); r[2] = (u)0 + 255; if (c) goto L800cc8b8;
    c = ((r[3] == r[2]));  if (c) goto L800cc8b8;
     goto L800cc8dc;
    L800cc8a8:;
    *(short *)((u)r[16] + 2850) = r[2];
    r[2] = (u)0 + 7;
    *(short *)((u)r[16] + 2852) = r[2]; goto L800cc8f8;
    L800cc8b8:;
    r[4] = (u)r[16] + (u)0; CALL(R_s10a_800CC4C8);
     CALL(R_s10a_800CE21C);
    r[2] = (u)0 + 7;
    *(short *)((u)r[16] + 2850) = r[2];
    r[2] = (u)0 + 12;
    *(short *)((u)r[16] + 2852) = r[2]; goto L800cc8f8;
    L800cc8dc:;
    r[4] = (u)r[16] + (u)0; CALL(R_s10a_800CC4C8);
    r[2] = (u)0 + 1;
    *(short *)((u)r[16] + 2850) = r[2];
    r[2] = (u)0 + 5;
    *(short *)((u)r[16] + 2852) = r[2];
    *(char *)((u)r[16] + 2968) = 0;
    L800cc8f8:;
    *(int *)((u)r[16] + 2856) = 0;
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
