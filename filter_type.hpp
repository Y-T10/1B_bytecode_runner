/**
 * オペコード識別用フィルタを定義する。
 * またフィルタのビットパターンを定める。
 */

#ifndef FILTER_TYPE_HEADER
#define FILTER_TYPE_HEADER

#include"binary_type.hpp"
#include<vector>
#include<memory>

///op識別用のビットパターン型
struct bit_pattern_t{
    ///比較位置を表すマスク
    bit8_set mask;

    ///比較される8ビット値
    bit8_set src;
};

///フィルタ型
using filter_t = std::vector<bit_pattern_t>;

///フィルタ型のポインタ
using filter_ptr = std::shared_ptr<filter_t>;

#endif