extern char R_s19a_800DBA10[] __asm__("s19a_800DBA10");
extern char R_s19a_800DBA54[] __asm__("s19a_800DBA54");
extern char R_s19a_800DBC28[] __asm__("s19a_800DBC28");
extern char R_s19a_800DBCF8[] __asm__("s19a_800DBCF8");
extern char R_s19a_800DBE58[] __asm__("s19a_800DBE58");
extern char R_s19a_800DBFB8[] __asm__("s19a_800DBFB8");
int G_s19a_800DB950(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s19a_800DB950");
int G_s19a_800DB950(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[3] = *(int *)((u)r[4] + 2048);
    r[2] = r[3] & 2;
    c = ((r[2] == 0)); r[2] = (u)0 + 1; if (c) goto L800db980;
    r[3] = 0;
    r[3] = (u)r[3] + (int)R_s19a_800DBFB8;
    L800db96c:;
    *(int *)((u)r[4] + 2028) = r[3];
    *(int *)((u)r[4] + 2036) = 0;
    *(short *)((u)r[4] + 120) = 0;
    *(short *)((u)r[4] + 116) = 0; goto out;
    L800db980:;
    r[2] = r[3] & 1;
    c = ((r[2] == 0)); r[2] = (u)0 + 1; if (c) goto L800db998;
    r[3] = 0;
    r[3] = (u)r[3] + (int)R_s19a_800DBA10; goto L800db96c;
    L800db998:;
    r[2] = r[3] & 32;
    c = ((r[2] == 0)); r[2] = (u)0 + 1; if (c) goto L800db9b0;
    r[3] = 0;
    r[3] = (u)r[3] + (int)R_s19a_800DBCF8; goto L800db96c;
    L800db9b0:;
    r[2] = r[3] & 512;
    c = ((r[2] == 0)); r[2] = (u)0 + 1; if (c) goto L800db9c8;
    r[3] = 0;
    r[3] = (u)r[3] + (int)R_s19a_800DBE58; goto L800db96c;
    L800db9c8:;
    r[2] = r[3] & 4096;
    c = ((r[2] == 0)); r[2] = (u)0 + 1; if (c) goto L800db9e0;
    r[3] = 0;
    r[3] = (u)r[3] + (int)R_s19a_800DBA54; goto L800db96c;
    L800db9e0:;
    r[2] = r[3] & 8192;
    c = ((r[2] != 0)); r[2] = (u)0 + 1; if (c) goto L800db9f4;
    r[2] = (u)0 + (u)0; goto out;
    L800db9f4:;
    r[3] = 0;
    r[3] = (u)r[3] + (int)R_s19a_800DBC28;
    *(int *)((u)r[4] + 2028) = r[3];
    *(int *)((u)r[4] + 2036) = 0;
    *(short *)((u)r[4] + 120) = 0;
    *(short *)((u)r[4] + 116) = 0; goto out;
out:
    RECOMP_RETURN;
}
