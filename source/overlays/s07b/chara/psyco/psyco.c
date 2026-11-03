#ifdef MGS_PORT
#include "recomp.h"
#endif
#include "ps1align.h"
#include "chara/psyco/psyco.h"

#include <stdio.h>
#include "libgcl/libgcl.h"
#include "game/game.h"
#include "game/navi.h"
#include "takabe/cineutil.h"

/*---------------------------------------------------------------------------*/

#define BODY_DATA   GV_StrCode( "psycho" )
#define MOTION_DATA GV_StrCode( "psycho" )

#define BODY_FLAG   ( DG_FLAG_TEXT | DG_FLAG_TRANS | DG_FLAG_SHADE \
                    | DG_FLAG_GBOUND | DG_FLAG_AMBIENT | DG_FLAG_IRTEXTURE )

typedef struct _Work {
    /* 0x000 */ GV_ACT         actor;
    /* 0x020 */ CONTROL        control;
    /* 0x09C */ OBJECT         body;
    /* 0x180 */ MOTION_CONTROL m_ctrl;
    /* 0x1D0 */ MOTION_SEGMENT m_segs1[ 17 ];
    /* 0x434 */ MOTION_SEGMENT m_segs2[ 17 ];
    /* 0x698 */ SVECTOR        rots[ 16 ];
    /* 0x718 */ SVECTOR        adjust[ 16 ];
    /* 0x798 */ MATRIX         light[ 2 ];

    /* 0x7D8 */ char pad7D8[ 0x74 ];

    /* 0x84C */ int field_84C;

    /* 0x850 */ char pad850[ 0x4 ];

    /* 0x854 */ void *field_854;
    /* 0x858 */ int field_858;

    /* 0x85C */ char pad85C[ 0x8 ];

    /* 0x864 */ int field_864;

    /* 0x868 */ char pad868[ 0x6 ];

    /* 0x86E */ short field_86E;

    /* 0x870 */ char pad870[ 0x20 ];

    /* 0x890 */ SVECTOR pos;
    /* 0x898 */ SVECTOR rot;

    /* 0x8A0 */ char pad8A0[ 0x4 ];

    /* 0x8A4 */ int     n_points;
    /* 0x8A8 */ SVECTOR points[ 8 ];

    /* 0x8E8 */ char pad8E8[ 0x4 ];

    /* 0x8EC */ short field_8EC;
    /* 0x8EE */ short field_8EE;

    /* 0x8F0 */ char pad8F0[ 0x174 ];

    /* 0xA64 */ short field_A64;
    /* 0xA66 */ short field_A66;

    /* 0xA68 */ char padA68[ 0x28 ];

    /* 0xA90 */ int      proc_id;
    /* 0xA94 */ NAVIGATE navi;
    /* 0xAB4 */ int      field_AB4;
    /* 0xAB8 */ int      field_AB8;
    /* 0xABC */ int      field_ABC[ 4 ];
    /* 0xACC */ int      field_ACC[ 6 ];
    /* 0xAE4 */ char     field_AE4[ 4 ];
} Work;

extern char s07b_800CDF40[];
extern char s07b_800CE134[];
extern char s07b_800CE2A8[];
extern char s07b_800CE43C[];
extern char s07b_800CE660[];
extern char s07b_800CE85C[];
extern char s07b_800CEA18[];
extern char s07b_800CED04[];
extern char s07b_800CF130[];
int s07b_dword_800C3390 = 0x01900388;
int s07b_dword_800C3394 = 0x00F00140;
int s07b_dword_800C3398 = 0x00000078;
int s07b_dword_800C339C = 0x00240018;
int s07b_dword_800C33A0 = 0x00480030;
int s07b_dword_800C33A4 = 0x00E0002C;
int s07b_dword_800C33A8 = 0x00000040;
int s07b_dword_800C33AC = (int)&s07b_800CED04;
int s07b_dword_800C33B0 = (int)&s07b_800CF130;
int s07b_dword_800C33B4 = (int)&s07b_800CF130;
int s07b_dword_800C33B8 = (int)&s07b_800CF130;
int s07b_dword_800C33BC = (int)&s07b_800CDF40;
int s07b_dword_800C33C0 = (int)&s07b_800CE134;
int s07b_dword_800C33C4 = (int)&s07b_800CE2A8;
int s07b_dword_800C33C8 = (int)&s07b_800CE43C;
int s07b_dword_800C33CC = (int)&s07b_800CE660;
int s07b_dword_800C33D0 = (int)&s07b_800CE85C;
int s07b_dword_800C33D4 = (int)&s07b_800CEA18;
int s07b_dword_800C33D8 = 0x00000000;
int s07b_dword_800C33DC = 0x0000FA24;
int s07b_dword_800C33E0 = 0x00000000;
int s07b_dword_800C33E4 = 0x00000064;
int s07b_dword_800C33E8 = 0x0000FC00;
int s07b_dword_800C33EC = 0x00000000;
int s07b_dword_800C33F0 = 0x00000000;
int s07b_dword_800C33F4 = 0x000005DC;
int s07b_dword_800C33F8 = 0x000002EE;
int s07b_dword_800C33FC = 0x000000FA;
int s07b_dword_800C3400 = 0x03E8012C;
int s07b_dword_800C3404 = 0x0000012C;

const char s07b_dword_800E4F5C[] = "shukan mode off\n";
const char s07b_dword_800E4F70[] = "shukan mode on\n";
const char s07b_dword_800E4F80[] = "psy shukan on %d\n";
const char s07b_dword_800E4F94[] = "psy shukan off %d\n";
const char s07b_dword_800E4FA8[] = "スネーク";
const char s07b_dword_800E4FB4[] = "attack end\n";
const char s07b_dword_800E4FC0[] = "胸像１";
const char s07b_dword_800E4FC8[] = "胸像２";

const char s07b_dword_800E4FD0[] PS1_ALIGN(4) = {0x0, 0x0, 0x0, 0x0};

const int s07b_dword_800E4FD4 = -2146643904;  /* unused in the port: mips2c.py reads jump tables from the PS1 binary */
const int s07b_dword_800E4FD8 = -2146643524;  /* unused in the port: mips2c.py reads jump tables from the PS1 binary */
const int s07b_dword_800E4FDC = -2146643548;  /* unused in the port: mips2c.py reads jump tables from the PS1 binary */
const int s07b_dword_800E4FE0 = -2146643524;  /* unused in the port: mips2c.py reads jump tables from the PS1 binary */
const int s07b_dword_800E4FE4 = -2146643548;  /* unused in the port: mips2c.py reads jump tables from the PS1 binary */
const int s07b_dword_800E4FE8 = -2146643524;  /* unused in the port: mips2c.py reads jump tables from the PS1 binary */
const int s07b_dword_800E4FEC = -2146643536;  /* unused in the port: mips2c.py reads jump tables from the PS1 binary */
const int s07b_dword_800E4FF0 = -2146643524;  /* unused in the port: mips2c.py reads jump tables from the PS1 binary */
const int s07b_dword_800E4FF4 = -2146643856;  /* unused in the port: mips2c.py reads jump tables from the PS1 binary */
const int s07b_dword_800E4FF8 = -2146643844;  /* unused in the port: mips2c.py reads jump tables from the PS1 binary */
const int s07b_dword_800E4FFC = -2146643844;  /* unused in the port: mips2c.py reads jump tables from the PS1 binary */
const int s07b_dword_800E5000 = -2146643844;  /* unused in the port: mips2c.py reads jump tables from the PS1 binary */
const int s07b_dword_800E5004 = -2146643720;  /* unused in the port: mips2c.py reads jump tables from the PS1 binary */
const int s07b_dword_800E5008 = -2146643748;  /* unused in the port: mips2c.py reads jump tables from the PS1 binary */
const int s07b_dword_800E500C = -2146643748;  /* unused in the port: mips2c.py reads jump tables from the PS1 binary */
const int s07b_dword_800E5010 = -2146643720;  /* unused in the port: mips2c.py reads jump tables from the PS1 binary */
const int s07b_dword_800E5014 = -2146643720;  /* unused in the port: mips2c.py reads jump tables from the PS1 binary */

const char s07b_dword_800E5018[] = "MANTIS";
const char s07b_dword_800E5020[] = "マンティス";

const int s07b_dword_800E502C = -2146631812;  /* unused in the port: mips2c.py reads jump tables from the PS1 binary */
const int s07b_dword_800E5030 = -2146631580;  /* unused in the port: mips2c.py reads jump tables from the PS1 binary */
const int s07b_dword_800E5034 = -2146631304;  /* unused in the port: mips2c.py reads jump tables from the PS1 binary */
const int s07b_dword_800E5038 = -2146630820;  /* unused in the port: mips2c.py reads jump tables from the PS1 binary */
const int s07b_dword_800E503C = -2146630820;  /* unused in the port: mips2c.py reads jump tables from the PS1 binary */
const int s07b_dword_800E5040 = -2146630356;  /* unused in the port: mips2c.py reads jump tables from the PS1 binary */
const int s07b_dword_800E5044 = -2146627388;  /* unused in the port: mips2c.py reads jump tables from the PS1 binary */
const int s07b_dword_800E5048 = -2146627372;  /* unused in the port: mips2c.py reads jump tables from the PS1 binary */
const int s07b_dword_800E504C = -2146627356;  /* unused in the port: mips2c.py reads jump tables from the PS1 binary */
const int s07b_dword_800E5050 = -2146627340;  /* unused in the port: mips2c.py reads jump tables from the PS1 binary */
const int s07b_dword_800E5054 = -2146627324;  /* unused in the port: mips2c.py reads jump tables from the PS1 binary */
const int s07b_dword_800E5058 = -2146627308;  /* unused in the port: mips2c.py reads jump tables from the PS1 binary */
const int s07b_dword_800E505C = -2146627292;  /* unused in the port: mips2c.py reads jump tables from the PS1 binary */
const int s07b_dword_800E5060 = -2146627276;  /* unused in the port: mips2c.py reads jump tables from the PS1 binary */
const int s07b_dword_800E5064 = -2146627260;  /* unused in the port: mips2c.py reads jump tables from the PS1 binary */
const int s07b_dword_800E5068 = -2146627244;  /* unused in the port: mips2c.py reads jump tables from the PS1 binary */
const int s07b_dword_800E506C = -2146627228;  /* unused in the port: mips2c.py reads jump tables from the PS1 binary */

const char s07b_dword_800E5070[] = "メリル";
const char s07b_dword_800E5078[] = "hideo_b";
const char s07b_dword_800E5080[] = "hideo_s";
const char s07b_dword_800E5088[] = "hideo";

SVECTOR SECTION(".bss") s07b_dword_800E5BE0;

/*---------------------------------------------------------------------------*/

extern void *NewPadManager( void );

/*---------------------------------------------------------------------------*/

void s07b_800CAD54( Work *work, int se_id )
{
    SVECTOR tmp;
    int dir, turn, ang, pan;

    GV_SubVec3( &work->control.mov, &GM_PlayerPosition, &tmp );
    GV_VecLen3( &tmp );
    dir = GV_VecDir2( &tmp );

    if ( GM_Camera.first_person )
    {
        turn = GM_SnakeCamera.rotate2.vy;
        ang = dir + 1024;
    }
    else
    {
        turn = gUnkCameraStruct2_800B7868.rotate.vy;
        ang = dir + 1024;
    }

    pan = rcos( ( ang - turn ) & 4095 ) * 31 / 4096;
    if ( pan < 0 ) pan += 255;

    GM_SeSet2( pan, 63, se_id );
}

void s07b_800CAE00( Work *work )
{
    SVECTOR tmp, dir;
    CONTROL *control;
    SVECTOR *pos, *rot;
    int scale, len, diff;

    control = &work->control;

    if ( control->mov.vy < ( control->levels[ 0 ] + control->height ) )
    {
        control->mov.vy = control->levels[ 0 ] + control->height;
    }

    pos = &work->pos;
    scale = work->field_86E;
    if ( scale == 0 ) scale = 96;

    GV_SubVec3( &control->mov, pos, &tmp );

    len = GV_VecLen3( &tmp );
    if ( scale < len )
    {
        GV_LenVec3( &tmp, &dir, len, scale );
        GV_AddVec3( pos, &dir, pos );
    }
    else
    {
        *pos = control->mov;
    }

    rot = &work->rot;
    diff = GV_DiffDirS( rot->vy, control->rot.vy );
    if ( ABS( diff ) > 128 )
    {
        rot->vy += ( diff > 0 ) ?  128 : -128;
    }
    else
    {
        rot->vy = control->rot.vy;
    }

    DG_SetPos2( pos, rot );
}

#ifdef MGS_PORT
#include "overlays/s07b/recomp/s07b_800CAF54.inc"
#else
#pragma INCLUDE_ASM("asm/overlays/s07b/s07b_800CAF54.s")
#endif
void s07b_800CAF54( Work *work );

#ifdef MGS_PORT
#include "overlays/s07b/recomp/s07b_800CAFC8.inc"
#else
#pragma INCLUDE_ASM("asm/overlays/s07b/s07b_800CAFC8.s")
#endif
#ifdef MGS_PORT
#include "overlays/s07b/recomp/s07b_800CB068.inc"
#else
#pragma INCLUDE_ASM("asm/overlays/s07b/s07b_800CB068.s")
#endif
void s07b_800CB068( int );

#ifdef MGS_PORT
#include "overlays/s07b/recomp/s07b_800CB0B4.inc"
#else
#pragma INCLUDE_ASM("asm/overlays/s07b/s07b_800CB0B4.s")
#endif
void s07b_800CB0B4( Work *work, int );

#ifdef MGS_PORT
#include "overlays/s07b/recomp/s07b_800CB130.inc"
#else
#pragma INCLUDE_ASM("asm/overlays/s07b/s07b_800CB130.s")
#endif
#ifdef MGS_PORT
#include "overlays/s07b/recomp/s07b_800CB224.inc"
#else
#pragma INCLUDE_ASM("asm/overlays/s07b/s07b_800CB224.s")
#endif
#ifdef MGS_PORT
#include "overlays/s07b/recomp/s07b_800CB264.inc"
#else
#pragma INCLUDE_ASM("asm/overlays/s07b/s07b_800CB264.s")
#endif
#ifdef MGS_PORT
#include "overlays/s07b/recomp/s07b_800CB2A4.inc"
#else
#pragma INCLUDE_ASM("asm/overlays/s07b/s07b_800CB2A4.s")
#endif
#ifdef MGS_PORT
#include "overlays/s07b/recomp/s07b_800CB6B0.inc"
#else
#pragma INCLUDE_ASM("asm/overlays/s07b/s07b_800CB6B0.s")
#endif
#ifdef MGS_PORT
#include "overlays/s07b/recomp/s07b_800CB770.inc"
#else
#pragma INCLUDE_ASM("asm/overlays/s07b/s07b_800CB770.s")
#endif
#ifdef MGS_PORT
#include "overlays/s07b/recomp/s07b_800CB8CC.inc"
#else
#pragma INCLUDE_ASM("asm/overlays/s07b/s07b_800CB8CC.s")
#endif
#ifdef MGS_PORT
#include "overlays/s07b/recomp/s07b_800CB9E8.inc"
#else
#pragma INCLUDE_ASM("asm/overlays/s07b/s07b_800CB9E8.s")
#endif
#ifdef MGS_PORT
#include "overlays/s07b/recomp/s07b_800CBAA4.inc"
#else
#pragma INCLUDE_ASM("asm/overlays/s07b/s07b_800CBAA4.s")
#endif
#ifdef MGS_PORT
#include "overlays/s07b/recomp/s07b_800CBB38.inc"
#else
#pragma INCLUDE_ASM("asm/overlays/s07b/s07b_800CBB38.s")
#endif
#ifdef MGS_PORT
#include "overlays/s07b/recomp/s07b_800CBC20.inc"
#else
#pragma INCLUDE_ASM("asm/overlays/s07b/s07b_800CBC20.s")
#endif
#ifdef MGS_PORT
#include "overlays/s07b/recomp/s07b_800CBCE8.inc"
#else
#pragma INCLUDE_ASM("asm/overlays/s07b/s07b_800CBCE8.s")
#endif
#ifdef MGS_PORT
#include "overlays/s07b/recomp/s07b_800CBD4C.inc"
#else
#pragma INCLUDE_ASM("asm/overlays/s07b/s07b_800CBD4C.s")
#endif
#ifdef MGS_PORT
#include "overlays/s07b/recomp/s07b_800CBDA0.inc"
#else
#pragma INCLUDE_ASM("asm/overlays/s07b/s07b_800CBDA0.s")
#endif
#ifdef MGS_PORT
#include "overlays/s07b/recomp/s07b_800CBDCC.inc"
#else
#pragma INCLUDE_ASM("asm/overlays/s07b/s07b_800CBDCC.s")
#endif
#ifdef MGS_PORT
#include "overlays/s07b/recomp/s07b_800CBE34.inc"
#else
#pragma INCLUDE_ASM("asm/overlays/s07b/s07b_800CBE34.s")
#endif
#ifdef MGS_PORT
#include "overlays/s07b/recomp/s07b_800CBF00.inc"
#else
#pragma INCLUDE_ASM("asm/overlays/s07b/s07b_800CBF00.s")
#endif
#ifdef MGS_PORT
#include "overlays/s07b/recomp/s07b_800CBFB0.inc"
#else
#pragma INCLUDE_ASM("asm/overlays/s07b/s07b_800CBFB0.s")
#endif
#ifdef MGS_PORT
#include "overlays/s07b/recomp/s07b_800CC138.inc"
#else
#pragma INCLUDE_ASM("asm/overlays/s07b/s07b_800CC138.s")
#endif
#ifdef MGS_PORT
#include "overlays/s07b/recomp/s07b_800CC174.inc"
#else
#pragma INCLUDE_ASM("asm/overlays/s07b/s07b_800CC174.s")
#endif
#ifdef MGS_PORT
#include "overlays/s07b/recomp/s07b_800CC468.inc"
#else
#pragma INCLUDE_ASM("asm/overlays/s07b/s07b_800CC468.s")
#endif

void s07b_800CC50C( void )
{
    /* do nothing */
}

#ifdef MGS_PORT
#include "overlays/s07b/recomp/s07b_800CC514.inc"
#else
#pragma INCLUDE_ASM("asm/overlays/s07b/s07b_800CC514.s")
#endif
#ifdef MGS_PORT
#include "overlays/s07b/recomp/s07b_800CC578.inc"
#else
#pragma INCLUDE_ASM("asm/overlays/s07b/s07b_800CC578.s")
#endif
#ifdef MGS_PORT
#include "overlays/s07b/recomp/s07b_800CC67C.inc"
#else
#pragma INCLUDE_ASM("asm/overlays/s07b/s07b_800CC67C.s")
#endif
#ifdef MGS_PORT
#include "overlays/s07b/recomp/s07b_800CC6CC.inc"
#else
#pragma INCLUDE_ASM("asm/overlays/s07b/s07b_800CC6CC.s")
#endif
#ifdef MGS_PORT
#include "overlays/s07b/recomp/s07b_800CC704.inc"
#else
#pragma INCLUDE_ASM("asm/overlays/s07b/s07b_800CC704.s")
#endif
#ifdef MGS_PORT
#include "overlays/s07b/recomp/s07b_800CC790.inc"
#else
#pragma INCLUDE_ASM("asm/overlays/s07b/s07b_800CC790.s")
#endif
#ifdef MGS_PORT
#include "overlays/s07b/recomp/s07b_800CC89C.inc"
#else
#pragma INCLUDE_ASM("asm/overlays/s07b/s07b_800CC89C.s")
#endif
#ifdef MGS_PORT
#include "overlays/s07b/recomp/s07b_800CC8D4.inc"
#else
#pragma INCLUDE_ASM("asm/overlays/s07b/s07b_800CC8D4.s")
#endif
#ifdef MGS_PORT
#include "overlays/s07b/recomp/s07b_800CC930.inc"
#else
#pragma INCLUDE_ASM("asm/overlays/s07b/s07b_800CC930.s")
#endif
#ifdef MGS_PORT
#include "overlays/s07b/recomp/s07b_800CC970.inc"
#else
#pragma INCLUDE_ASM("asm/overlays/s07b/s07b_800CC970.s")
#endif
#ifdef MGS_PORT
#include "overlays/s07b/recomp/s07b_800CC9E8.inc"
#else
#pragma INCLUDE_ASM("asm/overlays/s07b/s07b_800CC9E8.s")
#endif
#ifdef MGS_PORT
#include "overlays/s07b/recomp/s07b_800CCA10.inc"
#else
#pragma INCLUDE_ASM("asm/overlays/s07b/s07b_800CCA10.s")
#endif
#ifdef MGS_PORT
#include "overlays/s07b/recomp/s07b_800CCA80.inc"
#else
#pragma INCLUDE_ASM("asm/overlays/s07b/s07b_800CCA80.s")
#endif
#ifdef MGS_PORT
#include "overlays/s07b/recomp/s07b_800CCBB0.inc"
#else
#pragma INCLUDE_ASM("asm/overlays/s07b/s07b_800CCBB0.s")
#endif
#ifdef MGS_PORT
#include "overlays/s07b/recomp/s07b_800CCBFC.inc"
#else
#pragma INCLUDE_ASM("asm/overlays/s07b/s07b_800CCBFC.s")
#endif
#ifdef MGS_PORT
#include "overlays/s07b/recomp/s07b_800CCFE4.inc"
#else
#pragma INCLUDE_ASM("asm/overlays/s07b/s07b_800CCFE4.s")
#endif
#ifdef MGS_PORT
#include "overlays/s07b/recomp/s07b_800CD86C.inc"
#else
#pragma INCLUDE_ASM("asm/overlays/s07b/s07b_800CD86C.s")
#endif

#ifdef MGS_PORT
#include "overlays/s07b/recomp/s07b_800CDA04.inc"
#else
#pragma INCLUDE_ASM("asm/overlays/s07b/s07b_800CDA04.s")
#endif
int s07b_800CDA04( Work *work );

#ifdef MGS_PORT
#include "overlays/s07b/recomp/s07b_800CDA90.inc"
#else
#pragma INCLUDE_ASM("asm/overlays/s07b/s07b_800CDA90.s")
#endif
#ifdef MGS_PORT
#include "overlays/s07b/recomp/s07b_800CDAFC.inc"
#else
#pragma INCLUDE_ASM("asm/overlays/s07b/s07b_800CDAFC.s")
#endif
#ifdef MGS_PORT
#include "overlays/s07b/recomp/s07b_800CDBA4.inc"
#else
#pragma INCLUDE_ASM("asm/overlays/s07b/s07b_800CDBA4.s")
#endif
#ifdef MGS_PORT
#include "overlays/s07b/recomp/s07b_800CDCAC.inc"
#else
#pragma INCLUDE_ASM("asm/overlays/s07b/s07b_800CDCAC.s")
#endif
#ifdef MGS_PORT
#include "overlays/s07b/recomp/s07b_800CDF40.inc"
#else
#pragma INCLUDE_ASM("asm/overlays/s07b/s07b_800CDF40.s")
#endif
#ifdef MGS_PORT
#include "overlays/s07b/recomp/s07b_800CE134.inc"
#else
#pragma INCLUDE_ASM("asm/overlays/s07b/s07b_800CE134.s")
#endif
#ifdef MGS_PORT
#include "overlays/s07b/recomp/s07b_800CE2A8.inc"
#else
#pragma INCLUDE_ASM("asm/overlays/s07b/s07b_800CE2A8.s")
#endif
#ifdef MGS_PORT
#include "overlays/s07b/recomp/s07b_800CE43C.inc"
#else
#pragma INCLUDE_ASM("asm/overlays/s07b/s07b_800CE43C.s")
#endif
#ifdef MGS_PORT
#include "overlays/s07b/recomp/s07b_800CE660.inc"
#else
#pragma INCLUDE_ASM("asm/overlays/s07b/s07b_800CE660.s")
#endif
#ifdef MGS_PORT
#include "overlays/s07b/recomp/s07b_800CE85C.inc"
#else
#pragma INCLUDE_ASM("asm/overlays/s07b/s07b_800CE85C.s")
#endif
#ifdef MGS_PORT
#include "overlays/s07b/recomp/s07b_800CEA18.inc"
#else
#pragma INCLUDE_ASM("asm/overlays/s07b/s07b_800CEA18.s")
#endif
#ifdef MGS_PORT
#include "overlays/s07b/recomp/s07b_800CEBAC.inc"
#else
#pragma INCLUDE_ASM("asm/overlays/s07b/s07b_800CEBAC.s")
#endif
#ifdef MGS_PORT
#include "overlays/s07b/recomp/s07b_800CED04.inc"
#else
#pragma INCLUDE_ASM("asm/overlays/s07b/s07b_800CED04.s")
#endif
#ifdef MGS_PORT
#include "overlays/s07b/recomp/s07b_800CEFF0.inc"
#else
#pragma INCLUDE_ASM("asm/overlays/s07b/s07b_800CEFF0.s")
#endif
#ifdef MGS_PORT
#include "overlays/s07b/recomp/s07b_800CF130.inc"
#else
#pragma INCLUDE_ASM("asm/overlays/s07b/s07b_800CF130.s")
#endif
#ifdef MGS_PORT
#include "overlays/s07b/recomp/s07b_800CF200.inc"
#else
#pragma INCLUDE_ASM("asm/overlays/s07b/s07b_800CF200.s")
#endif
#ifdef MGS_PORT
#include "overlays/s07b/recomp/s07b_800CF304.inc"
#else
#pragma INCLUDE_ASM("asm/overlays/s07b/s07b_800CF304.s")
#endif

#ifdef MGS_PORT
#include "overlays/s07b/recomp/s07b_800CF684.inc"
#else
#pragma INCLUDE_ASM("asm/overlays/s07b/s07b_800CF684.s")
#endif
void s07b_800CF684( void );

#ifdef MGS_PORT
#include "overlays/s07b/recomp/s07b_800CF6F0.inc"
#else
#pragma INCLUDE_ASM("asm/overlays/s07b/s07b_800CF6F0.s")
#endif
#ifdef MGS_PORT
#include "overlays/s07b/recomp/s07b_800CF768.inc"
#else
#pragma INCLUDE_ASM("asm/overlays/s07b/s07b_800CF768.s")
#endif
#ifdef MGS_PORT
#include "overlays/s07b/recomp/s07b_800CF9A0.inc"
#else
#pragma INCLUDE_ASM("asm/overlays/s07b/s07b_800CF9A0.s")
#endif
#ifdef MGS_PORT
#include "overlays/s07b/recomp/s07b_800D075C.inc"
#else
#pragma INCLUDE_ASM("asm/overlays/s07b/s07b_800D075C.s")
#endif
#ifdef MGS_PORT
#include "overlays/s07b/recomp/s07b_800D0774.inc"
#else
#pragma INCLUDE_ASM("asm/overlays/s07b/s07b_800D0774.s")
#endif
#ifdef MGS_PORT
#include "overlays/s07b/recomp/s07b_800D098C.inc"
#else
#pragma INCLUDE_ASM("asm/overlays/s07b/s07b_800D098C.s")
#endif
#ifdef MGS_PORT
#include "overlays/s07b/recomp/s07b_800D0A4C.inc"
#else
#pragma INCLUDE_ASM("asm/overlays/s07b/s07b_800D0A4C.s")
#endif
#ifdef MGS_PORT
#include "overlays/s07b/recomp/s07b_800D0A6C.inc"
#else
#pragma INCLUDE_ASM("asm/overlays/s07b/s07b_800D0A6C.s")
#endif

void s07b_800D0B40( void )
{
    /* do nothing */
}

#ifdef MGS_PORT
#include "overlays/s07b/recomp/s07b_800D0B48.inc"
#else
#pragma INCLUDE_ASM("asm/overlays/s07b/s07b_800D0B48.s")
#endif

void s07b_800D0C8C( void )
{
    /* do nothing */
}


#ifdef MGS_PORT
#include "overlays/s07b/recomp/s07b_800D0C94.inc"
#else
#pragma INCLUDE_ASM("asm/overlays/s07b/s07b_800D0C94.s")
#endif

void s07b_800D0DCC( void )
{
    /* do nothing */
}

#ifdef MGS_PORT
#include "overlays/s07b/recomp/s07b_800D0DD4.inc"
#else
#pragma INCLUDE_ASM("asm/overlays/s07b/s07b_800D0DD4.s")
#endif
#ifdef MGS_PORT
#include "overlays/s07b/recomp/s07b_800D0F94.inc"
#else
#pragma INCLUDE_ASM("asm/overlays/s07b/s07b_800D0F94.s")
#endif

void s07b_800D0FC0( Work *work, int arg1 )
{
    if ( arg1 == 0 )
    {
        CloseCinemaScreen();
        GM_Camera.first_person = 0;
        work->field_864 = 1;
        work->field_84C &= ~0x4;
        DG_VisibleObjs( GM_PlayerBody->objs );
        work->field_854 = s07b_800CF684;
        work->field_858 = 0;
        work->field_A66 = 0;
        work->field_A64 = 0;
        work->control.turn.vz = 0;
        work->control.turn.vx = 0;
        s07b_800CB0B4( work, 0 );
        s07b_800CB068( 0 );
    }
}

#ifdef MGS_PORT
#include "overlays/s07b/recomp/s07b_800D105C.inc"
#else
#pragma INCLUDE_ASM("asm/overlays/s07b/s07b_800D105C.s")
#endif

#ifdef MGS_PORT
#include "overlays/s07b/recomp/s07b_800D1254.inc"
#else
#pragma INCLUDE_ASM("asm/overlays/s07b/s07b_800D1254.s")
#endif
void s07b_800D1254( Work *work );

#ifdef MGS_PORT
#include "overlays/s07b/recomp/s07b_800D13C4.inc"
#else
#pragma INCLUDE_ASM("asm/overlays/s07b/s07b_800D13C4.s")
#endif
void s07b_800D13C4( Work *work );

#ifdef MGS_PORT
#include "overlays/s07b/recomp/s07b_800D1484.inc"
#else
#pragma INCLUDE_ASM("asm/overlays/s07b/s07b_800D1484.s")
#endif
int s07b_800D1484( Work *work );

#ifdef MGS_PORT
#include "overlays/s07b/recomp/s07b_800D1638.inc"
#else
#pragma INCLUDE_ASM("asm/overlays/s07b/s07b_800D1638.s")
#endif
void s07b_800D1638( Work *work );

int s07b_800D187C( HZD_PAT *patrol, int *count, SVECTOR *data )
{
    int n_points;
    HZD_PTP *point;

    n_points = *count = patrol->n_points;
    point = patrol->points;
    while ( --n_points >= 0 )
    {
        data->vx = point->x;
        data->vy = point->y;
        data->vz = point->z;
        data->pad = point->command;
        point++;
        data++;
    }

    return 0;
}

int s07b_800D18E0( Work *work )
{
    int route_no;
    HZD_HDL *hzd;
    HZD_PAT *route;

    if ( GCL_GetOption( 'r' ) )
    {
        route_no = GCL_StrToInt( GCL_NextStr() );
    }
    else
    {
        route_no = 0;
    }

    hzd = work->control.map->hzd;
    route = hzd->def->routes;
    route += route_no;

    if ( s07b_800D187C( route, &work->n_points, work->points ) < 0 ) return -1;
    return 0;
}

#ifdef MGS_PORT
#include "overlays/s07b/recomp/s07b_800D195C.inc"
#else
#pragma INCLUDE_ASM("asm/overlays/s07b/s07b_800D195C.s")
#endif
void s07b_800D195C( Work *work );

void s07b_800D1C80( Work *work )
{
    int i;
    int *data;
    char *str;

    if ( GCL_GetOption( 't' ) )
    {
        i = 0;
        data = work->field_ABC;
        while ( ( str = GCL_NextStr() ) != NULL )
        {
            if ( i == 4 ) break;
            *data = GCL_StrToInt( str );
            data++;
            i++;
        }
    }
}

void s07b_800D1CF8( Work *work )
{
    int i;
    int *data;
    char *str;

    if ( GCL_GetOption( 'c' ) )
    {
        i = 0;
        data = work->field_ACC;
        while ( ( str = GCL_NextStr() ) != NULL )
        {
            if ( i == 6 ) break;
            *data = GCL_StrToInt( str );
            data++;
            i++;
        }
    }
}

void s07b_800D1D70( Work *work )
{
    int i;
    char *data, *str;

    if ( GCL_GetOption( 'f' ) )
    {
        i = 0;
        data = work->field_AE4;
        while ( ( str = GCL_NextStr() ) != NULL )
        {
            if ( i == 4 ) break;
            *data = GCL_StrToInt( str );
            data++;
            i++;
        }
    }
}

int s07b_800D1DE8( Work *work, int name, int where )
{
    CONTROL *control;
    OBJECT *body;

    control = &work->control;
    if ( GM_InitControl( control, name, where ) < 0 ) return -1;
    GM_ConfigControlString( control, GCL_GetOption( 'p' ), GCL_GetOption( 'd' ) );
    GM_ConfigControlHazard( control, 750, 300, 300 );
    control->seg_flag = HZD_SEG_NO_NAVIGATE;
    GM_ConfigControlTrapCheck( control );

    body = &work->body;
    GM_InitObject( body, BODY_DATA, BODY_FLAG, MOTION_DATA );
    GM_ConfigObjectJoint( body );
    GM_ConfigMotionControl( body, &work->m_ctrl, MOTION_DATA, work->m_segs1, work->m_segs2, control, work->rots );
    GM_ConfigObjectLight( body, work->light );
    GM_ConfigObjectAction( body, 0, 0, 0 );

    if ( GCL_GetOption( 'e' ) )
    {
        work->proc_id = GCL_StrToInt( GCL_NextStr() );
    }
    else
    {
        work->proc_id = -1;
    }

    work->body.objs->light->t[ 0 ] = 0;
    work->body.objs->light->t[ 1 ] = 0;
    work->body.objs->light->t[ 2 ] = 0;

    if ( s07b_800D18E0( work ) < 0 ) return -1;
    if ( s07b_800D1484( work ) < 0 ) return -1;
    if ( s07b_800CDA04( work ) < 0 ) return - 1;

    s07b_800CAF54( work );
    s07b_800D1638( work );
    s07b_800D195C( work );
    s07b_800D1CF8( work );
    s07b_800D1C80( work );
    s07b_800D1D70( work );

    NagivateInit( &work->navi, control->map->hzd, &control->mov );

    work->field_AB4 = GM_SnakeCamera.track;
    work->field_AB8 = 0;
    work->field_8EC = 0;
    work->field_8EE = 0;

    GM_PlayerStatus |= PLAYER_SECOND_AVAILABLE;
    GM_GameStatus |= STATE_RADAR_OFF;

    NewPadManager();

    s07b_dword_800E5BE0 = control->mov;
    return 0;
}

void *NewPsychoMantis( int name, int where )
{
    Work *work;

    work = GV_NewActor( GV_ACTOR_AFTER2, sizeof(Work) );
    if ( work == NULL ) return NULL;

    GV_SetNamedActor(work, s07b_800D1254, s07b_800D13C4, "psyco.c" );
    if ( s07b_800D1DE8( work, name, where ) < 0 )
    {
        GV_DestroyActor( work );
        return NULL;
    }

    return (void *)work;
}
