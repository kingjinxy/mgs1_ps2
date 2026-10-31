#include "ps1align.h"
#include "mgstype.h"

extern const char s03d_dword_800DB5CC[];
extern const char s03d_dword_800DB5B8[];
extern const char s03d_dword_800DB5A4[];
void s03d_800D0CD4();
void s03d_800D0D6C();
void s03d_800D0DF0();
void s03d_800D0E2C();

int s03d_dword_800C39A8 = 0x75307530;
int s03d_dword_800C39AC = 0x00007530;
int s03d_dword_800C39B0 = 0x05DC012C;
int s03d_dword_800C39B4 = 0x0000012C;
int s03d_dword_800C39B8 = 0x00000000;
int s03d_dword_800C39BC = 0x00000000;
int s03d_dword_800C39C0 = 0x01F40190;
int s03d_dword_800C39C4 = 0x00000190;
int s03d_dword_800C39C8 = 0x00000064;
int s03d_dword_800C39CC = 0x00000000;
int s03d_dword_800C39D0 = 0x0320012C;
int s03d_dword_800C39D4 = 0x0000012C;
int s03d_dword_800C39D8 = 0x00000000;
int s03d_dword_800C39DC = 0x00000000;
int s03d_dword_800C39E0 = 0x00140013;
int s03d_dword_800C39E4 = 0x0016000A;
short s03d_word_800C39E8[2] PS1_ALIGN(2) = {0x0009, 0x0022};
short s03d_word_800C39EC[2] PS1_ALIGN(2) = {0x0023, 0x0024};
short s03d_word_800C39F0[2] PS1_ALIGN(2) = {0x002D, 0x000D};
int s03d_dword_800C39F4 = 0x001A000C;
int s03d_dword_800C39F8 = 0x000E000F;
int s03d_dword_800C39FC = 0x001B0010;
short s03d_word_800C3A00[2] PS1_ALIGN(2) = {0x0008, 0x0015};
int s03d_dword_800C3A04 = 0x001F001E;
int s03d_dword_800C3A08 = 0x00210020;
int s03d_dword_800C3A0C = 0x00190025;

short s03d_word_800C3A10[20] PS1_ALIGN(2) = {
    0x0005, 0x0002, 0x002A, 0x0004, 0x0027, 0x0028, 0x0006, 0x0007,
    0x0026, 0x0003, 0x0029, 0x0011, 0x0012, 0x002B, 0x0017, 0x0018,
    0x001C, 0x001D, 0x0000, 0x0001,
};

short s03d_word_800C3A38[2] PS1_ALIGN(2) = {0x0033, 0x0011};
short s03d_word_800C3A3C[2] PS1_ALIGN(2) = {0x0012, 0x002B};

int s03d_dword_800C3A40 = 0x00000016;
int s03d_dword_800C3A44 = 0x00FA109A;
int s03d_dword_800C3A48 = 0x000001F4;
int s03d_dword_800C3A4C = 0x00FA109A;
int s03d_dword_800C3A50 = 0x000001F4;
int s03d_dword_800C3A54 = 0x00320000;
int s03d_dword_800C3A58 = 0x000000C8;
int s03d_dword_800C3A5C = 0x0000FF6A;
int s03d_dword_800C3A60 = 0x0000012C;
int s03d_dword_800C3A64 = 0x00000000;
int s03d_dword_800C3A68 = 0x00000064;
int s03d_dword_800C3A6C = 0x0000FC00;
int s03d_dword_800C3A70 = 0x00000000;
int s03d_dword_800C3A74 = 0x00000000;
int s03d_dword_800C3A78 = 0x00000064;
int s03d_dword_800C3A7C = 0x0000FC00;
int s03d_dword_800C3A80 = 0x00000000;
int s03d_dword_800C3A84 = (int)s03d_dword_800DB5CC;
int s03d_dword_800C3A88 = (int)s03d_dword_800DB5B8;
int s03d_dword_800C3A8C = (int)s03d_dword_800DB5A4;
int s03d_dword_800C3A90 = (int)s03d_800D0CD4;
int s03d_dword_800C3A94 = (int)s03d_800D0D6C;
int s03d_dword_800C3A98 = (int)s03d_800D0DF0;
int s03d_dword_800C3A9C = (int)s03d_800D0E2C;
int s03d_dword_800C3AA0 = 0xFE0C0005;
int s03d_dword_800C3AA4 = 0x00000050;
int s03d_dword_800C3AA8 = 0x00000400;
int s03d_dword_800C3AAC = 0x00000000;
int s03d_dword_800C3AB0 = 0x00001F40;
int s03d_dword_800C3AB4 = 0x0000FC18;

const char s03d_dword_800DB3C4[] STR_PIECE = {'i', 'p', 'p', 'a'};
const char s03d_dword_800DB3C8[] STR_PIECE = {'n', 'h', 'e', 'i'};
const char s03d_dword_800DB3CC[] STR_PIECE = {0x0, 0x0, 0x0, 0x0};

const char s03d_dword_800DB3D0[] STR_PIECE = {'e', 'n', 'e', 'm'};
const char s03d_dword_800DB3D4[] STR_PIECE = {'y', 0x0, 0x0, 0x0};

const char s03d_dword_800DB3D8[] STR_PIECE = {'f', 'a', 'm', 'a'};
const char s03d_dword_800DB3DC[] STR_PIECE = {'s', 0x0, 0x0, 0x0};

const char s03d_dword_800DB3E0[] STR_PIECE = {'E', 'r', 'r', ' '};
const char s03d_dword_800DB3E4[] STR_PIECE = {'n', 'o', 't', ' '};
const char s03d_dword_800DB3E8[] STR_PIECE = {'e', 'n', 'o', 'u'};
const char s03d_dword_800DB3EC[] STR_PIECE = {'g', 'h', ' ', 'w'};
const char s03d_dword_800DB3F0[] STR_PIECE = {'o', 'r', 'k', ' '};
const char s03d_dword_800DB3F4[] STR_PIECE = {'!', '!', '\n', 0x0};

const char s03d_dword_800DB3F8[] STR_PIECE = {'E', 'r', 'r', ' '};
const char s03d_dword_800DB3FC[] STR_PIECE = {'E', 'r', 'r', ' '};
const char s03d_dword_800DB400[] STR_PIECE = {'E', 'r', 'r', ' '};
const char s03d_dword_800DB404[] STR_PIECE = {'C', 'h', 'a', 'n'};
const char s03d_dword_800DB408[] STR_PIECE = {'g', 'e', ' ', 'R'};
const char s03d_dword_800DB40C[] STR_PIECE = {'o', 'o', 't', ' '};
const char s03d_dword_800DB410[] STR_PIECE = {'N', 'u', 'm', ' '};
const char s03d_dword_800DB414[] STR_PIECE = {'O', 'v', 'e', 'r'};
const char s03d_dword_800DB418[] STR_PIECE = {' ', '!', '!', '\n'};
const char s03d_dword_800DB41C[] STR_PIECE = {0x0, 0x0, 0x0, 0x0};

const char s03d_dword_800DB420[] STR_PIECE = {'E', 'r', 'r', ' '};
const char s03d_dword_800DB424[] STR_PIECE = {'E', 'r', 'r', ' '};
const char s03d_dword_800DB428[] STR_PIECE = {'E', 'r', 'r', ' '};
const char s03d_dword_800DB42C[] STR_PIECE = {'C', 'h', 'a', 'n'};
const char s03d_dword_800DB430[] STR_PIECE = {'g', 'e', ' ', 'D'};
const char s03d_dword_800DB434[] STR_PIECE = {'e', 'f', 'e', 'n'};
const char s03d_dword_800DB438[] STR_PIECE = {'d', ' ', 'N', 'u'};
const char s03d_dword_800DB43C[] STR_PIECE = {'m', ' ', 'O', 'v'};
const char s03d_dword_800DB440[] STR_PIECE = {'e', 'r', ' ', '!'};
const char s03d_dword_800DB444[] STR_PIECE = {'!', '\n', 0x0, 0x0};

const char s03d_dword_800DB448[] STR_PIECE = {'L', 'i', 'f', 'e'};
const char s03d_dword_800DB44C[] STR_PIECE = {'=', '%', 'd', ' '};
const char s03d_dword_800DB450[] STR_PIECE = {'F', 'a', 'i', 'n'};
const char s03d_dword_800DB454[] STR_PIECE = {'t', '=', '%', 'd'};
const char s03d_dword_800DB458[] STR_PIECE = {' ', 'B', 'l', 'o'};
const char s03d_dword_800DB45C[] STR_PIECE = {'o', 'd', '=', '%'};
const char s03d_dword_800DB460[] STR_PIECE = {'c', ' ', 'A', 'r'};
const char s03d_dword_800DB464[] STR_PIECE = {'e', 'a', '=', '%'};
const char s03d_dword_800DB468[] STR_PIECE = {'c', ' ', '\n', 0x0};

const char s03d_dword_800DB46C[] STR_PIECE = {'w', 'a', 't', 'c'};
const char s03d_dword_800DB470[] STR_PIECE = {'h', 'a', 'r', '.'};
const char s03d_dword_800DB474[] STR_PIECE = {'c', ' ', ':', ' '};
const char s03d_dword_800DB478[] STR_PIECE = {'a', 'c', 't', 'i'};
const char s03d_dword_800DB47C[] STR_PIECE = {'o', 'n', ' ', 'p'};
const char s03d_dword_800DB480[] STR_PIECE = {'o', 'i', 'n', 't'};
const char s03d_dword_800DB484[] STR_PIECE = {' ', 'E', 'r', 'r'};
const char s03d_dword_800DB488[] STR_PIECE = {'\n', 0x0, 0x0, 0x0};




