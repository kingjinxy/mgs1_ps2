/** @brief PS1 disc reads for libfs/cdbios.c (its MGS_PORT branch): the PS1 disc is one file on the DVD
 * (DISC1.BIN, raw 2352-byte sectors from the CHD, build/link_ps2.py), so PS1 sector n (absolute, as the
 * game counts them: LBA + 150) is at byte (n - 150) * 2352 of that file. Reads are asynchronous, in
 * chunks of whole PS1 sectors: MgsCd_Start, then MgsCd_Poll until done, then MgsCd_Sector.
 * PS2 side: compiled against ps2sdk's headers (build/link_ps2.py). */

#include <stdio.h>
#include <kernel.h>
#include <libcdvd.h>
#include <string.h>

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

/* Movies (game/movie.c, takabe/ending2.c: StSetRing, CdRead2, StGetNext, StFreeRing), as the HAL's movie_ps2.c does
 * Silent Hill's: one reader, the IOP's (sh1spu's xa.c), plays the movie's XA audio (file 1, channel 1) at the
 * drive's pace and forwards its other sectors (file 0: video frames and the font and subtitle chunks before them,
 * each with a 32-byte STR header) into a ring here. StGetNext puts a frame's sectors together and hands it to the
 * game, a video frame no sooner than its time (4 vertical blanks a frame: 10 sectors a frame at the drive's 150 a
 * second), since the game shows each frame as soon as it has it. The game decodes with libpress into the PS1's
 * VRAM as on the PS1. */
#define STR_RING    64 /* forwarded sectors, 2048 bytes each */
#define STR_PAYLOAD 2016
#define STR_CHUNKS  16 /* sectors a frame: at most 11 on the discs */
extern void Port_XaStart(unsigned int lsn, unsigned int index, unsigned int file, unsigned int chan); /* the HAL's spu_ps2.c */
extern void Port_XaStop(void);
extern void Port_XaForward(void* ring, unsigned int sectors, void* count);
extern void Port_XaAck(unsigned int used);
extern int  Port_VBlanks(unsigned int* cycles); /* the HAL's libetc_ps2.c */

static unsigned char s_StrRing[STR_RING][DVD_SECTOR] __attribute__((aligned(64)));
static unsigned int  s_StrCount[16] __attribute__((aligned(64))); /* [0]: sectors sent (the IOP's DMA) */
static unsigned char s_StrFrame[STR_CHUNKS * STR_PAYLOAD] __attribute__((aligned(64)));
static unsigned char s_StrHeader[32] __attribute__((aligned(4)));
static int           s_Loc;       /* CdlSetloc's sector */
static int           s_StrOpen, s_StrUsed, s_StrAcked, s_StrGot;
static int           s_StrHave;   /* a whole frame waits in s_StrFrame */
static int           s_StrT0 = -1; /* the vertical blank of video frame 1 */

static int str_blanks(void)
{
    unsigned int c;
    return Port_VBlanks(&c);
}

void StSetRing(unsigned long* ring, int sectors)
{
    (void)ring; /* the game's 32 sectors aren't used: frames are put together in s_StrFrame */
    (void)sectors;
}

void StSetStream(int mode, int start, int end, void* f1, void* f2)
{
    (void)mode, (void)start, (void)end, (void)f1, (void)f2;
}

int CdRead2(int mode)
{
    (void)mode;
    if (!s_Ready || s_Loc < PS1_PREGAP)
    {
        return 0;
    }
    *(volatile unsigned int*)((unsigned int)s_StrCount | 0x20000000) = 0;
    s_StrUsed = s_StrAcked = s_StrGot = s_StrHave = 0;
    s_StrT0   = -1;
    s_StrOpen = 1;
    Port_XaForward(s_StrRing, STR_RING, s_StrCount);
    Port_XaStart(s_Disc.lsn, (unsigned int)(s_Loc - PS1_PREGAP), 1, 1 | 0x100 /* whole 2352-byte sectors */);
    printf("movie: stream from PS1 sector %d\n", s_Loc);
    return 1;
}

/** 0 and the next frame's data and header (as a sector's: type, sectors, frame number, size) when one is due, else 1. */
int StGetNext(unsigned long** addr, unsigned long** header)
{
    if (!s_StrOpen)
    {
        return 1;
    }
    /* through the uncached mirror: the IOP's DMA wrote behind the data cache */
    while (!s_StrHave && s_StrUsed < (int)*(volatile unsigned int*)((unsigned int)s_StrCount | 0x20000000))
    {
        const unsigned char* d = (const unsigned char*)((unsigned int)s_StrRing[s_StrUsed++ % STR_RING] | 0x20000000);
        int                  chunk = d[4] | d[5] << 8, chunks = d[6] | d[7] << 8;
        if (d[0] != 0x60 || d[1] != 0x01 || chunk >= STR_CHUNKS || chunks > STR_CHUNKS)
        {
            continue;
        }
        if (chunk == 0)
        {
            s_StrGot = 0;
        }
        memcpy(s_StrFrame + chunk * STR_PAYLOAD, d + 32, STR_PAYLOAD);
        if (++s_StrGot == chunks && chunk == chunks - 1)
        {
            memcpy(s_StrHeader, d, 32);
            s_StrHave = 1;
        }
    }
    if (s_StrUsed - s_StrAcked >= 8)
    {
        Port_XaAck((unsigned int)(s_StrAcked = s_StrUsed));
    }
    if (!s_StrHave)
    {
        return 1;
    }
    if ((s_StrHeader[2] | s_StrHeader[3] << 8) == 0x8001)
    {
        int due = ((s_StrHeader[8] | s_StrHeader[9] << 8) - 1) * 4;
        if (s_StrT0 < 0)
        {
            s_StrT0 = str_blanks() - due;
        }
        if (str_blanks() - s_StrT0 < due)
        {
            return 1;
        }
    }
    *addr   = (unsigned long*)s_StrFrame;
    *header = (unsigned long*)s_StrHeader;
    return 0;
}

int StFreeRing(unsigned long* addr)
{
    (void)addr;
    s_StrHave = 0;
    return 0;
}

void StUnSetRing(void)
{
    if (s_StrOpen)
    {
        Port_XaStop();
        s_StrOpen = 0;
    }
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
    if (com == 0x02 && param) /* CdlSetloc: where a movie's CdRead2 starts (game/movie.c, takabe/ending2.c) */
    {
        s_Loc = ((param[0] >> 4) * 10 + (param[0] & 15)) * 4500 + ((param[1] >> 4) * 10 + (param[1] & 15)) * 75
              + (param[2] >> 4) * 10 + (param[2] & 15);
    }
    if (com == 0x09) /* CdlPause: a movie's end */
    {
        StUnSetRing();
    }
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
