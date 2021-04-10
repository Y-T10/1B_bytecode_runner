/**
 * レジスタアドレスやフラグ番号、演算番号などを
 * オペコードから取り出す機能を提供する。
 */

#ifndef FETCH_NUM_HEADER
#define FETCH_NUM_HEADER

#include"binary_type.hpp"
#include"register.hpp"
#include"op_types.hpp"

///ソースレジスタの番号を取り出す
const reg_addr_t RegAddr_src(const byte_t& op);

///デスティネーションレジスタの番号を取り出す
const reg_addr_t RegAddr_dst(const byte_t& op);

///フラグ番号を取り出す
const ccc_no_t CCC(const byte_t& op);

///ペアレジスタを取り出す
const pr_no_t PR(const byte_t& op);

///POP, PUSH用のペアレジスタを取り出す
const stk_pr_no_t Pp(const byte_t& op);

///計算番号を取り出す
const cal_no_t Cal_num(const byte_t& op);

#endif