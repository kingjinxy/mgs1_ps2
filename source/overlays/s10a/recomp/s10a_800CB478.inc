extern char R_GM_PlayerStatus[] __asm__("GM_PlayerStatus");
int G_s10a_800CB478(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s10a_800CB478");
int G_s10a_800CB478(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(0)
    r[2] = *(unsigned char *)((u)r[4] + 2975);
    r[2] = r[2] & 4;
    c = ((r[2] == 0));  if (c) goto L800cb4f4;
    r[2] = *(int *)((u)r[4] + 2304);
    r[2] = *(unsigned short *)((u)r[2] + 6);
    r[2] = r[2] & 6;
    c = ((r[2] == 0));  if (c) goto L800cb4bc;
    r[2] = *(unsigned char *)((u)r[4] + 2974);
    r[2] = r[2] | 4;
    *(char *)((u)r[4] + 2974) = r[2]; goto out;
    L800cb4bc:;
    r[2] = *(unsigned short *)((u)r[4] + 2386);
    r[2] = r[2] & 128;
    c = ((r[2] == 0)); r[2] = 0; if (c) goto L800cb4f4;
    r[2] = *(int *)((u)r[2] + (int)R_GM_PlayerStatus);
    r[3] = (u)0 + 4096;
    r[2] = r[2] & 4112;
    c = ((r[2] == r[3]));  if (c) goto L800cb4f4;
    r[2] = *(unsigned char *)((u)r[4] + 2974);
    r[2] = r[2] | 12;
    *(char *)((u)r[4] + 2974) = r[2];
    L800cb4f4:;
     goto out;
out:
    return r[2];
}
