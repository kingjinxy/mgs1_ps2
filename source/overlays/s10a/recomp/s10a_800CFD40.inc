int G_s10a_800CFD40(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s10a_800CFD40");
int G_s10a_800CFD40(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(0)
    r[7] = (u)r[4] + (u)0;
    r[3] = *(int *)((u)r[7] + 440);
    r[2] = (u)r[3] << 1;
    r[2] = (u)r[2] + (u)r[3];
    r[2] = (u)r[2] << 4;
    r[2] = (u)r[2] + (u)r[3];
    r[2] = (u)r[2] << 3;
    r[2] = (u)r[2] + 480;
    r[6] = (u)r[7] + (u)r[2];
    r[3] = *(int *)((u)r[6] + 384);
    c = ((r[3] == 0)); r[2] = (u)0 + 3; if (c) goto L800cfd80;
    c = ((r[3] != r[2]));  if (c) goto L800cfe18;
    L800cfd80:;
    r[2] = *(int *)((u)r[6] + 304);
    *(int *)((u)r[6] + 388) = 0;
    *(int *)((u)r[6] + 380) = 0;
    *(int *)((u)r[6] + 384) = 0;
    r[3] = (u)r[2] + (u)0;
    r[3] = (u)r[3] + 1;
    *(int *)((u)r[6] + 300) = r[2];
    *(int *)((u)r[6] + 304) = r[3];
    r[2] = *(int *)((u)r[7] + 32);
    r[3] = (int)r[3] < (int)r[2];
    c = ((r[3] != 0));  if (c) goto L800cfdb8;
    *(int *)((u)r[6] + 304) = 0;
    L800cfdb8:;
    r[3] = *(unsigned short *)((u)r[6] + 356);
    r[4] = *(unsigned short *)((u)r[6] + 358);
    r[2] = *(int *)((u)r[6] + 304);
    r[5] = *(unsigned short *)((u)r[6] + 360);
    r[2] = (u)r[2] << 3;
    r[2] = (u)r[7] + (u)r[2];
    *(short *)((u)r[6] + 316) = r[3];
    *(short *)((u)r[6] + 318) = r[4];
    *(short *)((u)r[6] + 320) = r[5];
    r[3] = *(unsigned short *)((u)r[2] + 52);
    r[2] = *(int *)((u)r[6] + 304);
    r[2] = (u)r[2] << 3;
    r[2] = (u)r[7] + (u)r[2];
    *(short *)((u)r[6] + 324) = r[3];
    r[3] = *(unsigned short *)((u)r[2] + 54);
    r[2] = *(int *)((u)r[6] + 304);
    r[2] = (u)r[2] << 3;
    r[2] = (u)r[7] + (u)r[2];
    *(short *)((u)r[6] + 326) = r[3];
    r[2] = *(unsigned short *)((u)r[2] + 56);
    *(short *)((u)r[6] + 328) = r[2];
    L800cfe18:;
     goto out;
out:
    return r[2];
}
