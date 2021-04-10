#include"fetch_num.hpp"

///下位3bitを取り出す
const byte_t under_3bits(const byte_t& byte);

///4,5,6ビットを取り出す
const byte_t mid_3bits(const byte_t& byte);

///ペアレジスタ番号を取り出す
const byte_t pr_bits(const byte_t& byte);

const reg_addr_t RegAddr_src(const byte_t& op){
    ///ソースを取り出して返す
    return static_cast<reg_addr_t>(under_3bits(op));
}

const reg_addr_t RegAddr_dst(const byte_t& op){
    ///ソースを取り出して返す
    return static_cast<reg_addr_t>(mid_3bits(op));
}

const ccc_no_t CCC(const byte_t& op){
    ///ソースを取り出して返す
    return static_cast<ccc_no_t>(mid_3bits(op));
}

const pr_no_t PR(const byte_t& op){
    ///ソースを取り出して返す
    return static_cast<pr_no_t>(pr_bits(op));
}

const stk_pr_no_t Pp(const byte_t& op){
    ///ソースを取り出して返す
    return static_cast<stk_pr_no_t>(pr_bits(op));
}

const cal_no_t Cal_num(const byte_t& op){
    ///ソースを取り出して返す
    return static_cast<cal_no_t>(mid_3bits(op));
}

const byte_t under_3bits(const byte_t& byte){
    return byte & 0b00000111;
}

const byte_t mid_3bits(const byte_t& byte){
    return (byte & 0b00111000) >> 3;
}

const byte_t pr_bits(const byte_t& byte){
    return (byte & 0b00110000) >> 4;
}