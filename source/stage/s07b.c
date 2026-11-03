#define DECLARE_NEWCHARA_PROTOS
#include "charalst.h"

void *NewPsychoMantis(int name, int where, int argc, char **argv);
void *s07b_800CA8F8(int name, int where, int argc, char **argv);
void *NewMemoryPsycho(int name, int where, int argc, char **argv);
void *NewSecond(int name, int where, int argc, char **argv);

CHARA _StageCharacterEntries[] = {
    { 0x92bc, (NEWCHARA *)NewAsiotoKun }, //  CHARA_ASIOTOKUN,    /* chara 足音君 */
    { 0xa12e, (NEWCHARA *)NewFadeInOutSet }, //  CHARA_FADEIO,       /* chara フェードイン・アウト */
    { 0xa76f, (NEWCHARA *)NewPsychoMantis }, //  CHARA_PSYCHOMANTIS, /* chara サイコマンティス */
    { 0xf4b0, (NEWCHARA *)s07b_800CA8F8 }, //  CHARA_PSYCHOMERYL,  /* chara サイコメリル */
    { 0xaf72, (NEWCHARA *)NewMemoryPsycho }, //  CHARA_MEMPSY,
    CHARA_PSYOBJ,   /* chara サイコ物体 */
    { 0x1ad3, (NEWCHARA *)NewTextureLamp }, //  CHARA_TEXTURE,      /* chara テクスチャ */
    { 0x7a05, (NEWCHARA *)NewCinemaScreenSet }, //  CHARA_CINEMA,       /* chara シネマスクリーン */
    { 0xb103, (NEWCHARA *)NewDynamicWallSet }, //  CHARA_DYNWALL,      /* chara 透明壁 */
    { 0x711f, (NEWCHARA *)NewLifeUp }, //  CHARA_LIFEUP,       /* chara ライフ増加 */
    { 0xec77, (NEWCHARA *)NewWallGcl }, //  CHARA_WALL,         /* chara 障害物 */
    { 0x51c6, (NEWCHARA *)NewCutInCameraSet }, //  CHARA_CAT_IN,       /* chara カットインカメラ */
    { 0x5a50, (NEWCHARA *)NewGasEffectSet }, //  CHARA_GASEFFECT,    /* chara ガス効果 */
    { 0xe97e, (NEWCHARA *)NewDemoDoll }, //  CHARA_DEMODOLL,     /* chara デモ人形 */
    { 0x9ffd, (NEWCHARA *)GM_SetSecondAvailable }, //  CHARA_9FFD_2ND,
    { 0x2d0a, (NEWCHARA *)NewSecond }, //  CHARA_2D0A_2ND,
    { 0x0fad, (NEWCHARA *)NewMotionSoundEffect }, //  CHARA_MOTIONSE,

    { 0x0003, (NEWCHARA *)NewFadeInOut }, //  DEMO_FADEIN,
    { 0x0004, (NEWCHARA *)NewFadeInOut }, //  DEMO_FADEOUT,
    { 0x0005, (NEWCHARA *)NewTelop }, //  DEMO_TEXT,
    { 0x000f, (NEWCHARA *)NewDemoKage }, //  DEMO_SHADOW,
    { 0x001a, (NEWCHARA *)NewKogaku2 }, //  DEMO_OPTICSCAMOUFLAGE,
    { 0x001b, (NEWCHARA *)NewKogaku3 }, //  DEMO_OPTICSCAMOUFLAGE2,
    { 0x0021, (NEWCHARA *)NewFocusView }, //  DEMO_UNSHAPEVIEW,
    { 0x0025, (NEWCHARA *)NewBlurSet }, //  DEMO_BLUR,
    { 0x0028, (NEWCHARA *)NewSepia_800C5214 }, //  DEMO_MONOTONE,
    { 0x0037, (NEWCHARA *)NewRedAlert2 }, //  DEMO_ENVIRONMENTLIGHT,
    { 0x0038, (NEWCHARA *)RedAlert_800C4F48 }, //  DEMO_ENVIRONMENTLIGHT2,
    { 0x0044, (NEWCHARA *)NewBlurPure }, //  DEMO_GHOST,

    CHARA_END
};
