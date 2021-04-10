/**
 * シミュレータが使用するレジスタを定める。
 */

#ifndef REGISTER_HEADER
#define REGISTER_HEADER

#include"binary_type.hpp"
#include<cstdint>
#include<array>
#include<string>
#include<sstream>

///汎用レジスタ
struct gene_reg_t{
    byte_t   m_B; /*汎用レジスタB*/
    byte_t   m_C; /*汎用レジスタC*/
    byte_t   m_D; /*汎用レジスタD*/
    byte_t   m_E; /*汎用レジスタE*/
    byte_t   m_H; /*汎用レジスタH*/
    byte_t   m_L; /*汎用レジスタL*/
};

///レジスタ構造体
struct reg_t{
    gene_reg_t m_gene; ///汎用レジスタ
    byte_t     m_A;    ///アキュームレータ
    bit8_set   m_F;    ///フラグレジスタ
    addr_t     m_pc;   ///プログラムカウンタ
    addr_t     m_sp;   ///スタックポインタ
};

///レジスタアドレス
enum reg_addr_t : byte_t {
    rB  = 0b000,
    rC  = 0b001,
    rD  = 0b010,
    rE  = 0b011,
    rH  = 0b100,
    rL  = 0b101,
    rHL = 0b110,
    rA  = 0b111,
};

///POP, PUSH時に使用されるペアレジスタアドレス
enum stk_pr_no_t : byte_t {
    ppBC = 0b00,
    ppDE = 0b01,
    ppHL = 0b10,
    ppAF = 0b11
};

///ペアレジスタアドレス
enum pr_no_t : byte_t {
    prBC = 0b00,
    prDE = 0b01,
    prHL = 0b10,
    prSP = 0b11
};

///フラグアドレス
///DAAを使用しないのでHは使わない
///加減算フラグも扱わない
enum cc_addr_t : byte_t {
    fC  = 0, //キャリ or リンク フラグ
    fPV = 2, //パリティ or オーバフロー フラグ
    fZ  = 6, //ゼロフラグ
    fS  = 7  //サインフラグ
};

#endif