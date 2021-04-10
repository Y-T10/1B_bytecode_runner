/**
 * 1バイト演算を定める。
 */

#ifndef CAL_OP_HEADER
#define CAL_OP_HEADER

#include"binary_type.hpp"
#include"op_types.hpp"
#include"register.hpp"
#include"conv_bit_row.hpp"
#include<cassert>

/**
 * 指定された演算の結果を返す
 * return src1 (cal_num) src2;
 * @param cal_num 計算番号
 * @param src1 右辺値1
 * @param src2 右辺値2
 * @param Cf キャリフラグ
 * @return 計算結果
 */
const byte_t calc8(const cal_no_t& cal_num, const byte_t& src1, const byte_t& src2, bit8_set& f);

#endif