/**
 * Z80の命令を識別値を定める。
 * またZ80の命令の種類を定める。
 */

#ifndef OP_TYPE_HEADER
#define OP_TYPE_HEADER

#include"binary_type.hpp"

///接頭コードの種類
enum op_pref_set_t : byte_t {
    ///IX
    ix = 0xdd,
    ///IY
    iy = 0xdf,
    ///拡張命令
    ext = 0xed,
    ///追加命令
    added = 0xcb
};

///オペレーションのリスト
enum op_id_set_t : byte_t {
LD_r_r          = 0b01000000,
LD_r_0xab       = 0b00000110,
LD_aBC_A        = 0b00000010,
LD_aDE_A        = 0b00010010,
LD_A_aBC        = 0b00001010,
LD_A_aDE        = 0b00011010,
LD_a0xabcd_A    = 0b00110010,
LD_A_a0xabcd    = 0b00111010,
LD_SP_HL        = 0b11111001,
LD_a0xabcd_HL   = 0b00100010,
LD_pr_0xabcd    = 0b00000001,
LD_HL_a0xabcd   = 0b00101010,
POP_Pp          = 0b11000001,
PUSH_Pp         = 0b11000101,
EX_DE_HL        = 0b11101011,
EX_aSP_HL       = 0b11100011,
CAL_r           = 0b10000000,
INC_r           = 0b00000100,
DEC_r           = 0b00000101,
CAL_0xab        = 0b11000110,
ADD_HL_pr       = 0b00001001,
INC_pr          = 0b00000011,
DEC_pr          = 0b00001011,
CPL             = 0b00101111,
CCF             = 0b00111111,
SCF             = 0b00110111,
JP_0xabcd       = 0b11000011,
JP_CCC_0xabcd   = 0b11000010,
JP_aHL          = 0b11101001,
CALL_0xabcd     = 0b11001101,
CALL_CCC_0xabcd = 0b11000100,
RET             = 0b11001001,
RET_CCC         = 0b11000000,
RST_ttt         = 0b11000111,
HALT            = 0b01110110,
NOP             = 0b00000000,
DI              = 0b11110011,
EI              = 0b11111011,
OUT_n0xab_A     = 0b11010011,
IN_A_n0xab      = 0b11011011,
RLCA            = 0b00000111,
RLA             = 0b00010111,
RRCA            = 0b00001111,
RRA             = 0b00011111,
DAA             = 0b00100111
};

///演算番号
enum cal_no_t : uint8_t{
    ADD = 0b000,
    ADC = 0b001,
    SUB = 0b010,
    SBC = 0b011,
    AND = 0b100,
    XOR = 0b101,
    OR  = 0b110,
    CP  = 0b111
};

///フラグ番号
enum ccc_no_t : byte_t {
    ccNZ = 0b000,
    ccZ  = 0b001,
    ccNC = 0b010,
    ccC  = 0b011,
    ccPO = 0b100,
    ccPE = 0b101,
    ccP  = 0b110,
    ccM  = 0b111
};

#endif