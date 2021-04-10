/**
 * レジスタへのアクセス機能を提供する。
 */

#ifndef ACCESS_REG_HEADER
#define ACCESS_REG_HEADER

#include"binary_type.hpp"
#include"conv_bit_row.hpp"
#include"register.hpp"
#include"op_types.hpp"
#include<cassert>

///レジスタアドレスが指すメモリへの参照を返す
byte_t& Acce_regaddr(const reg_addr_t& r_num, binary_code_t& ram, reg_t& reg);

///フラグ番号が指すフラグへの参照を返す
const bool Acce_CCC(const ccc_no_t& r_num, reg_t& reg);

///指定のPRから値を読み込む
const addr_t Read_PR(const pr_no_t& pr_num, reg_t& reg);

///指定のPRに値を書き込む
void Write_PR(const pr_no_t& pr_num, reg_t& reg, const addr_t& val16);

///指定のPpから値を読み込む
const addr_t Read_Pp(const stk_pr_no_t& pp_num, reg_t& reg);

///指定のPpに値を書き込む
void Write_Pp(const stk_pr_no_t& pp_num, reg_t& reg, const addr_t& val16);

#endif