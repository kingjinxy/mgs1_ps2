/** @brief TAS replay (docs/TAS Testing Plan.md, Phase 3): the pads the PS1 game read, game loop by game loop.
 *
 * MGS_TAS_PADS=<file> (build/link_ps2.py; made by tools/port/tas/trace_to_pads.py from BizHawk's trace) is
 * copied next to the disc image as tas_pads.bin, and Port_TasInit reads it from host: (likewise MGS_TAS_RAW,
 * MGS_TAS_TIME: tas_raw.bin, tas_time.bin) into the heap: embedded, the 5.6 MB of tables pushed the game's
 * .bss past 16 MB (see port/linkfile). mgs_tas_pads holds records of a little-endian u32 GV_Time and the 64 bytes of GV_PadData[0..3] the PS1
 * game had after GV_UpdatePadSystem in that loop, one record each time they change. Port_TasPads (the start of
 * libgv/pad.c's GV_UpdatePadSystem) rebuilds mts's raw pads (pad_800C14E0) from the record for the current
 * GV_Time, and the game computes GV_PadData itself: a loop can update the pads twice (dgd.c's, then a script's pad
 * command at a codec's end, with STATE_PADRELEASE cleared in between), and writing the recorded result at both
 * gave Snake the stick a call early (found with tools/port/tas/redux_replay.lua).
 *
 * With MGS_TAS_TIME too, mgs_tas_time holds 40 bytes per loop from GV_Time 0 (little-endian): the
 * tick the PS1's FS_StreamGetTick returned (s32; 0x80000000: its stream clock not started, so it returned
 * mts_time + 1), and the PS1's GM_GameStatus, GM_LoadRequest, GV_PassageTime, rand seed, GV_Clock and how far
 * its stream's data had come in from the disc (fs_stream_bottom's offset in the stream heap; not used yet: the
 * port's St* streaming is stubbed) at the end of the loop, the number of streams it had started, and the CD file
 * read's bytes still to come (FS_LoadFileSync; not used yet: the port's file reads are synchronous) and
 * gTotalFrameTime (the play time, which counts the load's loops too) before the loop. The port's timing then
 * follows the PS1's, so the game loops line up:
 *  - streams (cutscenes, codec voice) run on the PS1's clock (Port_TasTick, from capture_ps2.c's
 *    Capture_Tick) and start in the loop the PS1's did, not when the port's CD has the data
 *    (Port_TasStreamMayStart, from Capture_StreamMayStart: no start while the port has started as many as the
 *    PS1; GM_GameStatus's STATE_VOX_STREAM comes earlier, when strctrl.c's actor is made);
 *  - the game loop runs during loads, and they take a different number of loops here: when a load has
 *    ended (GM_LoadRequest back to 0 at the end of a loop), GV_Time becomes the loop the PS1's matching
 *    load ended in (the same count of load ends since boot), with the PS1's GV_Clock (the double buffer's
 *    parity), GV_PassageTime and gTotalFrameTime there, in Port_TasTrace;
 *  - GV_PassageTime is the PS1's (Port_TasPassageTime, libgv/gvd.c);
 *  - at the end of the loops a load is requested in (GM_LoadRequest set: not every load goes through loader.c),
 *    starts and ends in, the rand seed becomes the PS1's: the title runs a different number of loops before
 *    New Game (the boot's wait isn't a stage load), and a load's own loops call rand.
 *
 * With MGS_TAS_RAW too, mgs_tas_raw holds the PS1's raw mts pads (pad_800C14E0[0..1], 16 bytes) and
 * pad init states (pad_state_800C14F0[0..1], 8 bytes) as records of a u32 GV_Time and the 24 bytes, one each
 * time they change, as at the loop's vertical blank (just before the game reads them). Port_TasRawPads
 * (the end of mts_pad.c's do_control, in the vertical blank interrupt) puts them in place of the port's pads:
 * the readers that bypass GV_PadData (cancel.c's cutscene skip, gamed.c, movie.c) and
 * mts_get_pad_vibration_type (Psycho Mantis, GM_CONFIG_VIBRATION_OFF) then see the PS1's controller.
 *
 * Port_TasTrace (the end of libgv/gvd.c's Act: GV_Time, GV_Clock and GV_PassageTime are the new loop's, the
 * game state the last loop's, which is where BizHawk's trace samples) writes host:tas_trace.log, one line per
 * loop in tools/port/tas/trace.lua's format (the first field is the port's vertical blank count, not a movie
 * frame), for tools/port/tas/compare_trace.py.
 * Without the define both do nothing. */

#include <stdio.h>
#include <string.h>

#ifdef MGS_TAS
#include <stdlib.h>

static unsigned char* mgs_tas_pads; /* NULL: no table (host: file missing) */
static unsigned int   size_mgs_tas_pads;
static unsigned char* mgs_tas_raw;
static unsigned int   size_mgs_tas_raw;
static unsigned char* mgs_tas_time;
static unsigned char* mgs_tas_loads; /* host:tas_loads.bin: GV_PadData at the PS1's load ends */
static unsigned int   size_mgs_tas_loads;
static unsigned int   size_mgs_tas_time;
static unsigned char* mgs_tas_timeline; /* host:tas_timeline.bin: the PS1's stream actor per loop (timeline_to_bin.py) */
static unsigned int   size_mgs_tas_timeline;
static unsigned char* mgs_tas_ticks; /* host:tas_ticks.bin: the PS1's mts tick per loop (trace_to_pads.py) */
static unsigned int   size_mgs_tas_ticks;

extern int          GV_Time, GV_Clock, GV_PassageTime, GM_GameStatus, GM_AlertMode, GM_LoadRequest;
extern int          DG_UnDrawFrameCount, GM_LoadComplete;
extern short        linkvarbuf[96];
extern unsigned char GV_PadData[64], pad_800C14E0[16], GM_PlayerPosition[8];
extern int          GM_PlayerStatus;
extern unsigned int dword_800AB950, dword_800AB954; /* libgv/pad.c: the pads' last status */
extern int          CDBIOS_ReadSync(void);
extern int          gTotalFrameTime;
extern void*        GM_PlayerControl;
extern char*        GM_GetArea(int flag);
extern int          mts_get_tick_count(void);
extern unsigned int Hal_RandSeed(void);
extern void         srand(unsigned int seed);
extern void         Display_RequestDump(void);
extern void         mts_wait_vbl(int count);

#define RECORD 68
#define NO_TICK 0x80000000u
#define TIME_RECORD 40
#define MAX_LOADS 4096

/** A host: file into the heap (NULL if missing). */
static unsigned char* load(const char* name, unsigned int* size)
{
    FILE*          f = fopen(name, "rb");
    unsigned char* data;
    long           n;
    if (!f)
    {
        printf("tas: no %s\n", name);
        return 0;
    }
    fseek(f, 0, SEEK_END);
    n = ftell(f);
    fseek(f, 0, SEEK_SET);
    data = malloc(n > 0 ? n : 1);
    if (!data || fread(data, 1, n, f) != (size_t)n)
    {
        printf("tas: reading %s failed\n", name);
        free(data);
        fclose(f);
        return 0;
    }
    fclose(f);
    *size = (unsigned int)n;
    return data;
}

static unsigned int read_u32(const unsigned char* p)
{
    return p[0] | p[1] << 8 | p[2] << 16 | (unsigned int)p[3] << 24;
}

static void hex(FILE* f, const void* data, int n)
{
    static const char digits[] = "0123456789abcdef";
    const unsigned char* p = data;
    char buf[512];
    int  i;
    for (i = 0; i < n; i++)
    {
        buf[i * 2]     = digits[p[i] >> 4];
        buf[i * 2 + 1] = digits[p[i] & 15];
    }
    buf[n * 2] = ' ';
    fwrite(buf, 1, n * 2 + 1, f);
}
#endif

#ifdef MGS_TAS
static int   s_Ps1Loads;
static int   s_Ps1LoadEnd[MAX_LOADS]; /* the PS1's load ends: the loops whose line has GM_LoadRequest back to 0 */
static int   s_Loads; /* the PS1 load ends passed */

/** The loop whose pads the port gets: its own, but once its load is in (GM_LoadComplete -1, loader.c: the stage's
 * actors are made and run), the PS1's last loop of that load: the port's load is faster, so its own loop number is
 * far behind (Snake's walk at loop 9,632 with down held). */
static unsigned int pads_time(void)
{
    if (GM_LoadRequest && GM_LoadComplete == -1 && s_Loads < s_Ps1Loads && GV_Time < s_Ps1LoadEnd[s_Loads] - 1)
    {
        return (unsigned int)(s_Ps1LoadEnd[s_Loads] - 1);
    }
    return (unsigned int)GV_Time;
}

/** The mts tick as game logic reads it (wolf2.c, key_item.c: rand() burns of tick % 256; mips2c.py's calls of
 * mts_get_tick_count): in TAS replays the PS1's in this loop (host:tas_ticks.bin), else the port's. */
int Port_GameTick(void)
{
#ifdef MGS_TAS
    if (mgs_tas_ticks && (unsigned int)GV_Time < size_mgs_tas_ticks / 4)
    {
        return (int)read_u32(mgs_tas_ticks + GV_Time * 4);
    }
#endif
    return mts_get_tick_count();
}

const char* Port_RecompLast[8]; /* recomp.h: the mips2c.py functions last entered */
int         Port_RecompN;
static const unsigned char* s_PadRecord; /* Port_TasPads' record */
static int          s_LoadEnded;    /* a load started or ended in this loop: the seed becomes the PS1's at its end */
static unsigned int s_StreamStarts; /* the streams started (FS_StreamTickStart), against the PS1's count */
static int          s_LoopTick;     /* the vertical blank the loop began at (Port_TasTrace) */

/** The PS1's record for loop `time`, or NULL without one. */
static const unsigned char* time_record_at(int time)
{
    if (!mgs_tas_time || time < 0 || (unsigned int)time >= size_mgs_tas_time / TIME_RECORD)
    {
        return 0;
    }
    return mgs_tas_time + time * TIME_RECORD;
}

static const unsigned char* time_record(void)
{
    return time_record_at(GV_Time);
}
#endif

#ifdef MGS_TAS
static int s_SoundModeLoop = -1;
#endif

/** FS_StreamSoundMode: the clock is reset to wait for the sound; strctrl.c asks again in the same loop (its
 * goto loop_case3), and the PS1's answer then was -1 (the sound not started yet, fs_stream_last_time -1), not
 * the tick the loop started with (loop 5,751). */
void Port_TasSoundMode(void)
{
#ifdef MGS_TAS
    s_SoundModeLoop = GV_Time;
#endif
}

int Port_TasTick(int* tick)
{
#ifdef MGS_TAS
    const unsigned char* r = time_record();
    if (!r)
    {
        return 0;
    }
    if (s_SoundModeLoop == GV_Time)
    {
        *tick = -1;
        return 1;
    }
    *tick = read_u32(r) == NO_TICK ? mts_get_tick_count() + 1 : (int)read_u32(r); /* last_time -1: now - -1 */
    return 1;
#else
    (void)tick;
    return 0;
#endif
}

/** jimctrl.c: the sound's counter from the PS1's tick (stream.c: tick = counter * 64 / 105 + 1), for the voice's
 * mouth data and subtitles, which read it directly: the port's IOP paces it, a loop early at 12,835 (Snake's lip
 * sync's rand). The largest counter giving the tick: it equals the PS1's str_tick_count on loops 12,870 to 12,889. */
void Port_TasStrCounter(int* counter)
{
#ifdef MGS_TAS
    int tick;
    if (*counter >= 0 && Port_TasTick(&tick) && tick > 0)
    {
        *counter = (tick * 105 - 1) / 64;
        if ((unsigned int)GV_Time + 1 < size_mgs_tas_timeline / 8 && mgs_tas_timeline)
        {
            /* the exact read: jimctrl.c's field_30 ends its loop at the counter >> 2, on line t + 1 */
            int recorded = (int)read_u32(mgs_tas_timeline + (GV_Time + 1) * 8 + 4);
            static int last;
            /* The PS1's sound ends during a loop: jimctrl.c read the old counter there, -1 only in the next
               (17,041's lip sync, 17,042's mouth) */
            if (mgs_tas_timeline[GV_Time * 8 + 1] & 1)
            {
                *counter = -1;
                return;
            }
            if (mgs_tas_timeline[(GV_Time + 1) * 8 + 1] & 1)
            {
                *counter = last;
                return;
            }
            if (recorded >= 0)
            {
                *counter = recorded << 2;
            }
            else if ((unsigned int)GV_Time + 2 < size_mgs_tas_timeline / 8 &&
                     (int)read_u32(mgs_tas_timeline + (GV_Time + 2) * 8 + 4) >= 0 && last > 0 && last <= *counter)
            {
                *counter = last; /* a loop the PS1's field_30 held, with a move after it (27,231's lip sync) */
            }
            last = *counter;
        }
    }
#else
    (void)counter;
#endif
}

/** -1: no TAS timing (the caller decides); 0/1: whether the PS1 had started its stream by this loop. */
int Port_TasStreamMayStart(void)
{
#ifdef MGS_TAS
    const unsigned char* r = time_record();
    if (!mgs_tas_time)
    {
        return -1;
    }
    return r && s_StreamStarts < read_u32(r + 28) ? 1 : 0;
#else
    return -1;
#endif
}

/** strctrl.c's Act, stream state 3: whether the play ended. The port's data state can come a loop after the PS1's with
 * the read already done (12,951, whose voice starts the guards' 60-loop count to 13,014), so when the PS1's Nth stream
 * reached Act2 the port's does too, if `idle` (no read running). Normal play: `ended`. */
int Port_TasStreamPlayEnd(int ended, int idle)
{
#ifdef MGS_TAS
    if ((unsigned int)GV_Time + 1 < size_mgs_tas_timeline / 8 && mgs_tas_timeline)
    {
        static int scanned, ps1_plays, plays;
        for (; scanned <= GV_Time + 1; scanned++)
        {
            ps1_plays += scanned > 0 && mgs_tas_timeline[scanned * 8] == 2 && mgs_tas_timeline[(scanned - 1) * 8] == 1;
        }
        if (ended || (idle && ps1_plays > plays))
        {
            plays++;
            return 1;
        }
        return 0;
    }
#else
    (void)idle;
#endif
    return ended;
}

/** strctrl.c's Act2, destroying the stream's actor (its Die clears STATE_VOX_STREAM): whether the PS1's had gone
 * by this loop (its record without the bit, or a later stream started). It goes once the stream task stops,
 * after the SPU has played the last of the voice (sd_str.c's interrupts), which the port's IOP does at its own
 * pace: a loop early at 12,101. Not at Act's end: the PS1 ends the demo at loop 518 and clears the bit at 520.
 * So it only holds the destroy, never forces it. */
int Port_TasStreamMayEnd(void)
{
#ifdef MGS_TAS
    /* Die runs in the next loop (GV_DestroyActorQuick); a bit still set 8 loops on is the next stream's (the
       demo at loop 11,482 is followed by another, and the hold would never end) */
    int t;
    if ((unsigned int)GV_Time + 1 < size_mgs_tas_timeline / 8 && mgs_tas_timeline)
    {
        /* the recorded loop: the PS1's Nth stream through Act2 ended (line t + 1 going from 2 to 3 when its Act2
           destroyed the actor in t) before the port's Nth may, chained or not: a late port doesn't wait for the
           next one's (loop 12,952) */
        static int scanned, ps1_ends, ends;
        for (; scanned <= GV_Time + 1; scanned++)
        {
            ps1_ends += scanned > 0 && mgs_tas_timeline[scanned * 8] == 3 && mgs_tas_timeline[(scanned - 1) * 8] == 2;
        }
        if (ps1_ends > ends)
        {
            ends++;
            return 1;
        }
        return 0;
    }
    for (t = GV_Time + 1; t <= GV_Time + 8; t++)
    {
        const unsigned char* r = time_record_at(t);
        if (!r || !(read_u32(r + 4) & 0x20) || s_StreamStarts < read_u32(r + 28))
        {
            return t == GV_Time + 1;
        }
    }
    return 1;
#else
    return 1;
#endif
}

/** stream.c's StartRead, a stream's first read: held while the PS1's stream heap had no data yet (time.bin's
 * bottom 0). The PS1's can take seconds to come (the codec's voice at loop 5,827: at 5,950), the port's is in at
 * once, and the call runs differently meanwhile (its rand() at loop 5,846). */
int Port_TasStreamHold(void)
{
#ifdef MGS_TAS
    const unsigned char* r = time_record();
    return r && read_u32(r + 24) == 0;
#else
    return 0;
#endif
}

/** FS_StreamGetData: how far into the stream heap the PS1's data had come at this loop's start (time.bin's bottom),
 * or -1. Packets past it wait: the voice's mouth data (jimctrl.c) a loop early drew Snake's lip sync's rand at 12,835. */
int Port_TasStreamBottom(void)
{
#ifdef MGS_TAS
    const unsigned char* r = time_record();
    return r ? (int)read_u32(r + 24) : -1;
#else
    return -1;
#endif
}

/** cdbios.c, before each sector of a stream read (no size: 0x7FFF0000 bytes left at its start): whether the port
 * has read as far as the PS1 had by this loop (time.bin's file read bytes left), so the sector waits. The PS1's
 * drive brings 2.5 sectors a vertical blank, the port's at once, and a cutscene's packets come early (loop 6,660). */
int Port_TasStreamAhead(int left)
{
#ifdef MGS_TAS
    /* BizHawk per frame (loop 6,663): the PS1's drive brings 2.5 sectors a vertical blank (6,144 and 4,096 bytes
       by turns), and a loop's logic sees what had come in at its start (a packet complete on the vertical blank
       that begins loop 6,663 was used by 6,663, not 6,662). So: the loop's start value (trace line t, the last
       loop's record), less 5,120 bytes a vertical blank since, down to its end value (line t + 1). */
    const unsigned char* p     = time_record_at(GV_Time - 1);
    const unsigned char* r     = time_record();
    int                  start = p ? (int)read_u32(p + 32) : 0;
    int                  end   = r ? (int)read_u32(r + 32) : 0;
    int                  v     = start - 5120 * (mts_get_tick_count() - s_LoopTick);
    if (end < 0x7F000000)
    {
        return 0;
    }
    if (start < 0x7F000000 || start < end || v < end)
    {
        v = end; /* a new read in the loop, or the loop's end reached */
    }
    return left <= v;
#else
    (void)left;
    return 0;
#endif
}

#ifdef MGS_TAS
static int s_FileLoop = -1; /* the PS1's loop that requested the file read in progress (Port_TasFileStart), or -1 */
static int s_FileSize;
#endif

/** CDBIOS_ReadRequest, a file read (no callback): finds the PS1's (time.bin's file read bytes left becoming the
 * size, from a few loops back on), whose progress Port_TasFileAhead then follows: the PS1's drive took from 4 to
 * 20 vertical blanks to start a read at about the same distance (loops 5,796 and 7,566), so the trace is the
 * reference, and cdbios_ps2.c's model only covers reads it doesn't show. */
void Port_TasFileStart(int size)
{
#ifdef MGS_TAS
    int t;
    s_FileLoop = -1;
    s_FileSize = size;
    for (t = GV_Time - 3; t < GV_Time + 60; t++)
    {
        const unsigned char* r = time_record_at(t);
        const unsigned char* p = time_record_at(t - 1);
        if (r && p && (int)read_u32(r + 32) == size && (int)read_u32(p + 32) != size)
        {
            s_FileLoop = t;
            break;
        }
    }
    if (s_FileLoop != GV_Time)
    {
        printf("tas: file read of %d bytes at loop %d, the PS1's at %d\n", size, GV_Time, s_FileLoop);
    }
#else
    (void)size;
#endif
}

int Port_TasFileMatched(void)
{
#ifdef MGS_TAS
    return s_FileLoop >= 0;
#else
    return 0;
#endif
}

/** cdbios.c, before each sector of a file read: whether the port has read as far as the PS1 had (as for streams,
 * Port_TasStreamAhead), so the sector waits. */
int Port_TasFileAhead(int left)
{
#ifdef MGS_TAS
    const unsigned char* p = time_record_at(GV_Time - 1);
    const unsigned char* r = time_record();
    int                  start, end, v;
    if (s_FileLoop < 0)
    {
        return 0;
    }
    /* before the PS1's request: nothing read; a value that isn't this read's: done */
    start = GV_Time - 1 < s_FileLoop || !p ? s_FileSize : (int)read_u32(p + 32);
    end   = GV_Time < s_FileLoop || !r ? s_FileSize : (int)read_u32(r + 32);
    if (start < 0 || start > s_FileSize)
    {
        start = 0;
    }
    if (end < 0 || end > s_FileSize)
    {
        end = 0;
    }
    v = start - 5120 * (mts_get_tick_count() - s_LoopTick);
    if (v < end)
    {
        v = end;
    }
    return left <= v;
#else
    (void)left;
    return 0;
#endif
}

/** FS_StreamTickStart (Capture_TickStart): a stream has started. */
void Port_TasTickStart(void)
{
#ifdef MGS_TAS
    s_StreamStarts++;
#endif
}

/** loader.c's NewLoader and Die: a load starts or has ended. */
void Port_TasLoadEnd(void)
{
#ifdef MGS_TAS
    s_LoadEnded = 1;
#endif
}

/** movie.c: STATE_DEMO goes in Die, the loop after the destroy; the record's status is its next line's. */
int Port_TasMovieMayEnd(void)
{
#ifdef MGS_TAS
    const unsigned char* r = time_record_at(GV_Time + 1);
    return !r || !(read_u32(r + 4) & 0x80000000u);
#else
    return 1;
#endif
}

/** radio.c's call state: its two rand()s, which only animate the signal bars, if the PS1's seed moved this loop.
 * shortcut: the port enters the state on its own loop (18,260), fix that if a call's timing ever matters. */
int Port_TasCodecDraw(void)
{
#ifdef MGS_TAS
    const unsigned char* r = time_record();
    const unsigned char* next = time_record_at(GV_Time + 1);
    return !r || !next || read_u32(r + 16) != read_u32(next + 16);
#else
    return 1;
#endif
}

/** gvd.c, after GV_PassageTime is measured: the PS1's. */
void Port_TasPassageTime(void)
{
#ifdef MGS_TAS
    const unsigned char* r = time_record();
    if (r)
    {
        GV_PassageTime = (int)read_u32(r + 12);
        gTotalFrameTime = (int)read_u32(r + 36); /* display only; the PS1's total also counts loops the port's load skips */
    }
#endif
}

/** mts_pad.c's do_control (vertical blank interrupt: no C library calls). */
void Port_TasRawPads(void* pads, void* states)
{
#ifdef MGS_TAS
    static unsigned int  next;
    unsigned int         count, time = pads_time(), i;
    const unsigned char* r;
    if (!mgs_tas_raw || (count = size_mgs_tas_raw / 28) == 0 || time < read_u32(mgs_tas_raw))
    {
        return;
    }
    while (next + 1 < count && read_u32(mgs_tas_raw + (next + 1) * 28) <= time)
    {
        next++;
    }
    while (next > 0 && read_u32(mgs_tas_raw + next * 28) > time)
    {
        next--;
    }
    r = mgs_tas_raw + next * 28 + 4;
    for (i = 0; i < 16; i++)
    {
        ((unsigned char*)pads)[i] = r[i];
    }
    for (i = 0; i < 8; i++)
    {
        ((unsigned char*)states)[i] = r[16 + i];
    }
#else
    (void)pads, (void)states;
#endif
}

#ifdef MGS_TAS
static unsigned char s_RawSaved[16]; /* mts's raw pads before Port_TasPads (Port_TasRawPads's: the PS1's) */
static int           s_RawHeld;
#endif

/** The end of GV_UpdatePadSystem: mts's raw pads back to the PS1's at the loop's vertical blank, for the code that
 * reads them directly later in the loop (pad_demo.c's cross to skip at loop 6,666: the record for the loop is the
 * next trace line's, with the cross already let go). */
void Port_TasPadsDone(void)
{
#ifdef MGS_TAS
    if (s_RawHeld)
    {
        int i;
        for (i = 0; i < 2; i++)
        {
            memcpy(pad_800C14E0 + i * 8 + 2, s_RawSaved + i * 8 + 2, 2); /* the buttons; the sticks as written */
        }
        s_RawHeld = 0;
    }
    /* A loop with two updates (the codec's end, script.c's PadCmd, loop 22,669): the first took a release the
       PS1's second reported. */
    if (s_PadRecord)
    {
        int i;
        for (i = 0; i < 64; i += 16)
        {
            unsigned char* p = GV_PadData + i;
            if (p[0] == s_PadRecord[i] && p[1] == s_PadRecord[i + 1] && !p[4] && !p[5])
            {
                memcpy(p + 4, s_PadRecord + i + 4, 2);
            }
        }
    }
#endif
}

void Port_TasPads(void)
{
#ifdef MGS_TAS
    static unsigned int next;
    unsigned int        count = size_mgs_tas_pads / RECORD, time = pads_time();
    if (!mgs_tas_pads || count == 0 || time < read_u32(mgs_tas_pads))
    {
        return;
    }
    while (next + 1 < count && read_u32(mgs_tas_pads + (next + 1) * RECORD) <= time)
    {
        next++;
    }
    while (next > 0 && read_u32(mgs_tas_pads + next * RECORD) > time)
    {
        next--;
    }
    {
        /* mts's raw pads as the PS1's controller this loop: [2]/[3].status are mts_PadRead's buttons (plus the
           stick's d-pad bits when GV_PadData's analog is set: cleared then), [0]/[1] hold the sticks, written
           whenever the raw pad (its mode from Port_TasRawPads) is analog: a held d-pad clears GV_PadData's analog
           but the game still copies the sticks (loop 2,462) */
        const unsigned char* r = mgs_tas_pads + next * RECORD + 4;
        int                  port;
        s_PadRecord = r;
        memcpy(s_RawSaved, pad_800C14E0, 16);
        s_RawHeld = 1;
        for (port = 0; port < 2; port++)
        {
            unsigned int   buttons = r[(2 + port) * 16] | r[(2 + port) * 16 + 1] << 8;
            short          analog  = (short)(r[port * 16 + 10] | r[port * 16 + 11] << 8);
            unsigned char* p       = pad_800C14E0 + port * 8;
            if (analog > 0)
            {
                buttons &= 0x0FFF;
            }
            if (analog > 0 || p[0] > 1)
            {
                memcpy(p + 4, r + port * 16 + 12, 4);
            }
            p[2] = (unsigned char)~buttons;
            p[3] = (unsigned char)(~buttons >> 8);
        }
    }
#endif
}

#ifdef MGS_TAS
static FILE* s_Trace;
static int   s_SeedDiffs;
static int   s_ShotLoop = -1; /* host:tas_shot.txt: the loop whose frame is dumped */
static int   s_RamLoop  = -1; /* host:tas_ramdump.txt: the loop whose game data (.data to _end) goes to host:tas_ram.bin,
                                 for tools/port/tas/ram_diff.py against ram_dump.lua's PS1 RAM */
#endif

/** HalGame_Init, before the game starts: the file and the table scan here, not in a game loop (a few
 * milliseconds after the GV_Clock flip let the HAL draw an ordering table not yet built: TLB misses in
 * DrawOTagImpl). */
#ifdef MGS_TAS
/** GV_PadData as the PS1's trace line of a load's end `time` has it (host:tas_loads.bin, trace_to_pads.py). */
static void pads_as_ps1(int time)
{
    unsigned int i;
    for (i = 0; mgs_tas_loads && i + 68 <= size_mgs_tas_loads; i += 68)
    {
        if ((int)read_u32(mgs_tas_loads + i) == time)
        {
            const unsigned char* p = mgs_tas_loads + i + 4;
            memcpy(GV_PadData, p, 64);
            /* and GV_UpdatePadSystem's last status, which its next press and release come from */
            dword_800AB950 = (p[0] | p[1] << 8) | (unsigned int)(p[16] | p[17] << 8) << 16;
            dword_800AB954 = (p[32] | p[33] << 8) | (unsigned int)(p[48] | p[49] << 8) << 16;
            return;
        }
    }
}
#endif

void Port_TasInit(void)
{
#ifdef MGS_TAS
    int   t, prev = 0, n;
    FILE* f;
    mgs_tas_pads = load("host:tas_pads.bin", &size_mgs_tas_pads);
    mgs_tas_raw  = load("host:tas_raw.bin", &size_mgs_tas_raw);
    mgs_tas_time = load("host:tas_time.bin", &size_mgs_tas_time);
    mgs_tas_loads = load("host:tas_loads.bin", &size_mgs_tas_loads);
    mgs_tas_timeline = load("host:tas_timeline.bin", &size_mgs_tas_timeline);
    mgs_tas_ticks = load("host:tas_ticks.bin", &size_mgs_tas_ticks);
    n            = mgs_tas_time ? (int)(size_mgs_tas_time / TIME_RECORD) : 0;
    for (t = 0; t < n && s_Ps1Loads < MAX_LOADS; t++)
    {
        int request = (int)read_u32(mgs_tas_time + t * TIME_RECORD + 8);
        if (prev && !request)
        {
            s_Ps1LoadEnd[s_Ps1Loads++] = t;
        }
        prev = request;
    }
    if ((f = fopen("host:tas_shot.txt", "r")) != 0) /* run_port.py --shot: the loop whose frame to dump */
    {
        if (fscanf(f, "%d", &s_ShotLoop) != 1)
        {
            s_ShotLoop = -1;
        }
        fclose(f);
    }
    if ((f = fopen("host:tas_ramdump.txt", "r")) != 0)
    {
        if (fscanf(f, "%d", &s_RamLoop) != 1)
        {
            s_RamLoop = -1;
        }
        fclose(f);
    }
    s_Trace = fopen("host:tas_trace.log", "w");
    printf("tas: replay, %d PS1 load ends, trace %s\n", s_Ps1Loads, s_Trace ? "host:tas_trace.log" : "unavailable");
#endif
}

#ifdef MGS_TAS
/** The end of a loop outside a load: a file read behind the PS1's waits here, up to 10 s. Port_TasFileAhead only
 * holds a port that's early; a late one ran on and took its result loops late (SH1's Port_RecFileSync). */
static void file_wait(void)
{
    const unsigned char* p = time_record_at(GV_Time - 1);
    int                  waited = 0, target;
    if (!p || GM_LoadRequest || s_FileLoop < 0 || GV_Time - 1 < s_FileLoop)
    {
        return;
    }
    target = (int)read_u32(p + 32);
    if (target < 0 || target > s_FileSize)
    {
        target = 0;
    }
    while (CDBIOS_ReadSync() > target && CDBIOS_ReadSync() <= s_FileSize && waited < 600)
    {
        mts_wait_vbl(1);
        waited++;
    }
    if (waited)
    {
        printf("tas: loop %d waited %d vertical blanks for its file read\n", GV_Time, waited);
    }
}

#endif

void Port_TasTrace(void)
{
#ifdef MGS_TAS
    static int           prev_request, traced = -1;
    FILE*                f = s_Trace;
    const char*          stage;
    const unsigned char* r;
    if (GV_Time == traced)
    {
        return; /* once per loop */
    }
    if (GV_Time == s_RamLoop)
    {
        extern char _fdata[], _end[];
        FILE*       d = fopen("host:tas_ram.bin", "wb");
        if (d)
        {
            unsigned int base = (unsigned int)_fdata;
            fwrite(&base, 4, 1, d);
            fwrite(_fdata, 1, _end - _fdata, d);
            fclose(d);
            printf("tas: game data of loop %d dumped\n", GV_Time);
        }
    }
    if (GV_Time == s_ShotLoop)
    {
        Display_RequestDump(); /* the frame this loop draws, at its display */
        printf("tas: frame of loop %d dumped\n", GV_Time);
    }
    if (prev_request && !GM_LoadRequest && s_Loads < s_Ps1Loads)
    {
        if (GV_Time != s_Ps1LoadEnd[s_Loads])
        {
            printf("tas: load end %d at loop %d, the PS1's at %d\n", s_Loads, GV_Time, s_Ps1LoadEnd[s_Loads]);
            GV_Time = s_Ps1LoadEnd[s_Loads];
            pads_as_ps1(GV_Time); /* the PS1 updated its pads all through its load; the port's are its last loop's
                                     (loop 9,633: down held) */
        }
        if ((r = time_record()) != 0)
        {
            GV_PassageTime  = (int)read_u32(r + 12);
            GV_Clock        = (int)read_u32(r + 20);
            gTotalFrameTime = (int)read_u32(r + 36);
            linkvarbuf[91]  = gTotalFrameTime / 60 / 3600; /* GM_PlayTimeHours/Seconds, as gamed.c's Act */
            linkvarbuf[92]  = gTotalFrameTime / 60 % 3600;
        }
        s_Loads++;
        s_LoadEnded = 1;
    }
    if (!prev_request && GM_LoadRequest)
    {
        s_LoadEnded = 1; /* a load requested: not every load goes through loader.c (s00a's at loop 917), and the
                            stage's actors made before its end (the rats) draw from the seed */
    }
    prev_request = GM_LoadRequest;
    r            = time_record();
    if (r && Hal_RandSeed() != read_u32(r + 16) && s_SeedDiffs++ < 40)
    {
        /* before any overwrite below: a seed set at a load would hide a load's own different draws. In the log
           for console runs too, which have no compare_trace.py following them */
        printf("tas: seed at loop %d: port %08x, PS1 %08x%s\n", GV_Time, Hal_RandSeed(), read_u32(r + 16),
               s_LoadEnded ? " (load: overwritten)" : "");
    }
    if (s_LoadEnded && r)
    {
        srand(read_u32(r + 16));
    }
    file_wait();
    s_LoadEnded = 0;
    traced      = GV_Time;
    s_LoopTick  = mts_get_tick_count();
    if (!f || (GM_LoadRequest && s_Loads < s_Ps1Loads && GV_Time >= s_Ps1LoadEnd[s_Loads]))
    {
        return; /* still loading at the PS1's load end (the PS1 drive's pace, cdbios_ps2.c): the loop's number is
                   set to the PS1's at the load's end */
    }
    stage = GM_GetArea(0);
    fprintf(f, "%d %d %d %d %08x %08x %.8s ", mts_get_tick_count(), GV_Time, GV_Clock, GV_PassageTime,
            GM_GameStatus, Hal_RandSeed(), stage && stage[0] ? stage : "-");
    hex(f, GV_PadData, 64);
    hex(f, pad_800C14E0, 16);
    hex(f, GM_PlayerPosition, 8);
    fprintf(f, "%d %d %d ", GM_AlertMode, GM_LoadRequest, DG_UnDrawFrameCount);
    hex(f, linkvarbuf, 192);
    /* the BizHawk-only fields (stream clock, pad states, the game task's wait, stream data, play time) as "-",
       but the file read's bytes left (field 20, not compared: the PS1 drive's pace, cdbios_ps2.c), then
       trace_debug.lua's: GM_PlayerStatus, Snake's CONTROL (124 bytes) and his work from 0x9B0 (192 bytes) */
    fprintf(f, "- - - - - - %d - %08x ", CDBIOS_ReadSync(), GM_PlayerStatus);
    if (GM_PlayerControl)
    {
        hex(f, GM_PlayerControl, 124);
        hex(f, (char*)GM_PlayerControl - 0x20 + 0x9B0, 192); /* Snake's work from 0x9B0 (sna_init.c) */
    }
    else
    {
        fputs("- - ", f);
    }
    fputc('\n', f);
    if ((GV_Time & 63) == 0)
    {
        fflush(f);
    }
#endif
}
