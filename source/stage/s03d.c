#define DECLARE_NEWCHARA_PROTOS
#include "charalst.h"

/* s03d's own constructors (no CHARA_ name for them in charalst.h) */
void *NewMeryl3(int name, int where);
void *NewZakoCommander_800D580C(int name, int where);
void *NewZako_800CD5A0(int name, int where);

CHARA _StageCharacterEntries[] = {
    CHARA_TOBCNT,
    CHARA_ASIOTOKUN,   /* chara 足音君 */
    CHARA_CINEMA,      /* chara シネマスクリーン */
    CHARA_DEMODOLL,    /* chara デモ人形 */
    CHARA_FINDTRAP,    /* chara 発見トラップ */
    { 0xc755, (NEWCHARA *)NewMeryl3 }, // CHARA_MERYL3
    { 0x7cf7, (NEWCHARA *)NewZakoCommander_800D580C }, // CHARA_ZAKOCOM      /* chara ざこコマンダー */
    CHARA_WALL,        /* chara 障害物 */
    CHARA_ELEVPANEL,   /* chara エレベーターパネル */
    CHARA_UJI,         /* chara 蛆虫 */
    { 0xed87, (NEWCHARA *)NewZako_800CD5A0 }, // CHARA_ZAKO         /* chara ざこ */
    CHARA_DYNWALL,     /* chara 透明壁 */
    CHARA_TEXTURE,     /* chara テクスチャ */
    CHARA_MOSAIC,      /* chara モザイク */
    CHARA_FADEIO,      /* chara フェードイン・アウト */
    CHARA_HIYOKO,      /* chara ヒヨコ星 */
    CHARA_RADARPOINT,  /* chara レーダーポイント */
    CHARA_INTRUDECAM,  /* chara イントルードカメラ */
    CHARA_CAT_IN,      /* chara カットインカメラ */
    CHARA_MOTIONSE,

    DEMO_FADEIN,
    DEMO_FADEOUT,
    DEMO_SHADOW,
    DEMO_UNSHAPEVIEW,
    DEMO_BLUR,
    DEMO_MONOTONE,
    DEMO_GHOST,
    DEMO_FAMASLIGHT,

    CHARA_END
};
