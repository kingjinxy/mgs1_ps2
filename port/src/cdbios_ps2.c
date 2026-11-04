/** @brief PS1 disc reads for libfs/cdbios.c (its MGS_PORT branch): the PS1 disc is one file on the DVD
 * (DISC1.BIN, raw 2352-byte sectors from the CHD, build/link_ps2.py), so PS1 sector n (absolute, as the
 * game counts them: LBA + 150) is at byte (n - 150) * 2352 of that file. Reads are asynchronous, in
 * chunks of whole PS1 sectors: MgsCd_Start, then MgsCd_Poll until done, then MgsCd_Sector.
 * PS2 side: compiled against ps2sdk's headers (build/link_ps2.py). */

#include <stdio.h>
#include <kernel.h>
#include <libcdvd.h>

#define PS1_RAW_SECTOR 2352
#define PS1_PREGAP     150 /* the game's sector numbers count from MSF 00:00:00 */
#define DVD_SECTOR     2048
#define CHUNK_MAX      16  /* PS1 sectors per read */
#define BOUNCE_SECTORS ((CHUNK_MAX * PS1_RAW_SECTOR + DVD_SECTOR - 1) / DVD_SECTOR + 1)

static sceCdlFILE    s_Disc;
static int           s_Ready;
static int           s_DiscNo = 1; /* the PS1 disc in the drive (MgsCd_Swap) */
static unsigned int  s_DiscSectors; /* PS1 sectors in the file */
static unsigned int  s_Skip;        /* where the chunk's first PS1 sector starts in the bounce buffer */
int MgsCd_Paced; /* set by libfs/cdbios.c for each read: a file read's (no callback) sectors still to come, or 0 */
#ifdef MGS_TAS
/* TAS replays: file reads (MgsCd_Paced: no callback; streams follow the PS1's clock already, stage loads end at
 * the PS1's loop) take as long as on the PS1's 2x drive, 150 sectors a second (2.5 a vertical blank: the
 * 10,240 bytes a game loop of the codec's face read at loop 5,796), plus a seek when a read doesn't go on
 * from where the last one (any read) ended, by distance (seek_fifths: measured from the PS1 trace's codec calls,
 * the RADIO.DAT read to the face read and the face read's end, against the port's). Both early and late matter: the call draws rand() a number of loops after its face read. Times in fifths of a vertical
 * blank (mts_get_tick_count). */
#define PS1_FIFTHS_PER_SECTOR 2
extern int          mts_get_tick_count(void);
static int seek_fifths(int from, int to)
{
    /* sqrt(distance) -> fifths of a vertical blank, measured: (0, 2 blanks) by guess, (38, 3) the face reads at loops
       789 and 5,796, (97, 11) and (347, 31) the RADIO.DAT reads at 778 and 5,775; on past it with the last slope */
    static const int     pts[][2] = {{0, 0}, {38, 0}, {97, 103}, {347, 193}};
    unsigned int         d = (unsigned int)(from > to ? from - to : to - from), r = 0;
    int                  i;
    while ((r + 1) * (r + 1) <= d)
    {
        r++;
    }
    for (i = 1; i < 3 && (int)r > pts[i][0]; i++)
    {
    }
    return pts[i - 1][1] + ((int)r - pts[i - 1][0]) * (pts[i][1] - pts[i - 1][1]) / (pts[i][0] - pts[i - 1][0]);
}
static int          s_Due;        /* when the read in progress is in */
static int          s_NextSector; /* where it ends */
#endif
static unsigned char s_Bounce[BOUNCE_SECTORS * DVD_SECTOR] __attribute__((aligned(64)));

/** A read that the TAS replay holds (stream.c StartRead): the PS1's drive went there all the same. */
void MgsCd_Head(int sector)
{
#ifdef MGS_TAS
    s_NextSector = sector;
#else
    (void)sector;
#endif
}

/** Finds the disc file; 1 when it's ready. */
int MgsCd_Init(void)
{
    if (s_Ready)
    {
        return 1;
    }
    sceCdInit(SCECdINIT);
    sceCdMmode(SCECdMmodeDvd);
    if (!sceCdSearchFile(&s_Disc, s_DiscNo == 2 ? "\\DISC2.BIN;1" : "\\DISC1.BIN;1"))
    {
        printf("cdbios: DISC%d.BIN not found on the disc\n", s_DiscNo);
        return 0;
    }
    s_DiscSectors = s_Disc.size / PS1_RAW_SECTOR;
    s_Ready       = 1;
    printf("cdbios: DISC%d.BIN at DVD sector %u (%u PS1 sectors)\n", s_DiscNo, s_Disc.lsn, s_DiscSectors);
    return 1;
}

/** The disc change screen (onoda/change/change.c), waiting for the tray to open: the other PS1 disc goes in at
 * once, with no player action. shortcut: until every file is on one DVD (then no swap at all). */
void MgsCd_Swap(void)
{
    s_DiscNo = 3 - s_DiscNo;
    s_Ready  = 0;
    MgsCd_Init();
}

/** Starts reading PS1 sectors [sector, sector + count); returns how many will be read (count is cut to
 * CHUNK_MAX and the end of the disc), 0 if the read didn't start. */
int MgsCd_Start(int sector, int count)
{
    unsigned long long off;
    unsigned int       lba = (unsigned int)(sector - PS1_PREGAP);
    sceCdRMode         mode;

    if (!s_Ready || sector < PS1_PREGAP || lba >= s_DiscSectors)
    {
        printf("cdbios: read of PS1 sector %d (outside the disc)\n", sector);
        return 0;
    }
    if (count > CHUNK_MAX)
    {
        count = CHUNK_MAX;
    }
    if (lba + (unsigned int)count > s_DiscSectors)
    {
        count = (int)(s_DiscSectors - lba);
    }
    off              = (unsigned long long)lba * PS1_RAW_SECTOR;
    s_Skip           = (unsigned int)(off % DVD_SECTOR);
    mode.trycount    = 0;
    mode.spindlctrl  = SCECdSpinNom;
    mode.datapattern = SCECdSecS2048;
    mode.pad         = 0;
    if (!sceCdRead(s_Disc.lsn + (unsigned int)(off / DVD_SECTOR),
                   (s_Skip + (unsigned int)count * PS1_RAW_SECTOR + DVD_SECTOR - 1) / DVD_SECTOR, s_Bounce, &mode))
    {
        return 0;
    }
#ifdef MGS_TAS
    {
        int now = mts_get_tick_count() * 5;
        int begin = !MgsCd_Paced ? now - count * PS1_FIFTHS_PER_SECTOR : sector != s_NextSector ? now + seek_fifths(s_NextSector, sector)
                  : s_Due > now - 10 ? s_Due : now; /* the drive read on while the task polled (up to 2 blanks) */
        s_Due        = begin + (MgsCd_Paced < count ? MgsCd_Paced : count) * PS1_FIFTHS_PER_SECTOR; /* the sectors
                                                                       the read wants, not the whole chunk */
        s_NextSector = sector + count;
    }
#endif
    return count;
}

/** 1 while the read is in progress, 0 when it's done, -1 on a drive error. */
int MgsCd_Poll(void)
{
    if (sceCdSync(1))
    {
        return 1;
    }
#ifdef MGS_TAS
    if (mts_get_tick_count() * 5 < s_Due)
    {
        return 1; /* in, but not yet on the PS1 */
    }
#endif
    if (sceCdGetError() != SCECdErNO)
    {
        printf("cdbios: drive error %d\n", sceCdGetError());
        return -1;
    }
    /* The IOP DMAed the sectors behind the EE's data cache (see the HAL's libcd_ps2.c chunk_finish). */
    InvalidDCache(s_Bounce, s_Bounce + sizeof(s_Bounce) - 1);
    return 0;
}

/** The i-th raw sector of the finished read (sync, header, subheader, data). */
const unsigned char* MgsCd_Sector(int i)
{
    return s_Bounce + s_Skip + (unsigned int)i * PS1_RAW_SECTOR;
}

/* PSY-Q libcd: the game's own CdInit calls (main.c, gamed.c) find the disc file; CdReset is called by
 * cdbios's error path only on the PS1 build. */
#undef CdInit
#undef CdIntToPos
int CdInit(void)
{
    return MgsCd_Init();
}

int CdReset(int mode)
{
    (void)mode;
    return MgsCd_Init();
}

/* safechk.obj's copy protection check (called by onoda/change/safety.c in the title and change
 * overlays): the disc always passes. */
int SafetyCheck(int minute, int second, int sector)
{
    (void)minute;
    (void)second;
    (void)sector;
    return 0;
}

/* Drive commands the game sends outside cdbios (safety.c, the disc change screens): done at once, with a
 * status of "motor on, shell closed" (CdlStatStandby). */
/* PSY-Q CdlLOC: minute, second, sector (BCD), track. */
unsigned char* CdIntToPos(int i, unsigned char* p)
{
    i += PS1_PREGAP;
    p[0] = (unsigned char)(i / 4500 / 10 << 4 | i / 4500 % 10);
    p[1] = (unsigned char)(i / 75 % 60 / 10 << 4 | i / 75 % 60 % 10);
    p[2] = (unsigned char)(i % 75 / 10 << 4 | i % 75 % 10);
    p[3] = 0;
    return p;
}

int CdControl(unsigned char com, unsigned char* param, unsigned char* result)
{
    (void)com;
    (void)param;
    if (result)
    {
        result[0] = 0x02;
    }
    return 1;
}

int CdControlB(unsigned char com, unsigned char* param, unsigned char* result)
{
    return CdControl(com, param, result);
}
