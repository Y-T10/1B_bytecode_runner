#include"decode_filter.hpp"

filter_ptr decode_filter::f_list;

void decode_filter::init_list(){
    //フィルタの数
    const size_t filter_num = 44;
    //リストを生成する
    f_list = std::make_shared<filter_ptr::element_type>();

    //領域を確保する
    f_list->reserve(filter_num);

    //フィルタを読み込む
    *f_list = Read_op_list("op_list.csv");
}

const filter_ptr& decode_filter::filter(){
    //実体が生成されているを判断する
    if(!f_list){
        //リストを初期化する
        init_list();
    }

    //リストを返す
    return f_list;
}

const bool Bit_eq(const bit8_set& bitset, const bit_pattern_t& f);

const bool Eval_filter(const bit8_set& bitset, const bit_pattern_t& filter){
    //フィルタに適合するかを判断する
    return Bit_eq(bitset, filter);
}

const bool Bit_eq(const bit8_set& bitset, const bit_pattern_t& f){
    //マスクを用いて比較に用いる部分を取り出す
    const bit8_set dst_bits = bitset & f.mask;

    //ビット列が一致しているかを判断する
    return dst_bits == f.src;
}