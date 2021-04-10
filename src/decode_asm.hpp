/**
 * 1バイトのオペコードを識別する機能を定める。
 */

#ifndef DECODE_ASM_HEADER
#define DECODE_ASM_HEADER

#include<cstddef>
#include<cassert>
#include<algorithm>
#include"op_types.hpp"
#include"decode_filter.hpp"
#include"conv_bit_row.hpp"

///接頭バイトかを判断する
const bool Is_prefix_code(const byte_t& op);

///1バイトオペコードを翻訳する
const op_id_set_t Decode_1Bop(const byte_t& op, const filter_t& B1_fil);

#endif