/**
 * 識別用フィルタの提供機能を定める。
 * ビットパターンの比較機能を定める。
 */

#ifndef DECODE_FILTER_HEADER
#define DECODE_FILTER_HEADER

#include<functional>
#include<vector>
#include<utility>
#include<cassert>
#include<memory>
#include<map>
#include<sstream>
#include<algorithm>
#include"op_types.hpp"
#include"filter_type.hpp"
#include"read_op_list.hpp"

///フィルタを提供するクラス
class decode_filter {
    //フィルターのリスト
    static filter_ptr f_list;

    //リストを初期化する
    static void init_list();

    public:
    static const filter_ptr& filter();
};

/**
 * ビット列がフィルターを満たすかを評価する
 * @param bitset ビット列
 * @param filter フィルタ
 */
const bool Eval_filter(const bit8_set& bitset, const bit_pattern_t& filter);

#endif