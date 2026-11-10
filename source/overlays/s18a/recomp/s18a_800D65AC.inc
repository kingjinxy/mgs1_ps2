extern char R_s18a_800DA208[] __asm__("s18a_800DA208");
int G_s18a_800D65AC(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s18a_800D65AC");
int G_s18a_800D65AC(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[3] = *(int *)((u)r[4] + 2148);
    r[2] = (u)0 + 6;
    c = ((r[3] == r[2]));  if (c) goto L800d65f0;
    r[2] = *(int *)((u)r[4] + 2212);
    r[2] = *(unsigned short *)((u)r[2] + 2);
    r[2] = r[2] & 32;
    c = ((r[2] == 0)); r[2] = 0; if (c) goto L800d65f0;
    r[3] = *(int *)((u)r[4] + 2020);
    r[2] = (u)r[2] + (int)R_s18a_800DA208;
    *(int *)((u)r[4] + 2228) = r[2];
    *(int *)((u)r[4] + 2232) = 0;
    r[3] = r[3] | 256;
    *(int *)((u)r[4] + 2020) = r[3];
    L800d65f0:;
     goto out;
out:
    RECOMP_RETURN;
}
