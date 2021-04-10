#include"fetch_data.hpp"

const byte_t Fetch_from_PCaddr(const binary_code_t& ram, reg_t& reg){
    assert(!ram.empty());
    //現在のPC
    const addr_t cur_pc = reg.m_pc;

    //PCを1バイト分進める
    reg.m_pc += 1;

    //指定のバイトを返す
    return ram[cur_pc];
}

const addr_t Fetch_16bit_from_PCaddr(const binary_code_t& ram, reg_t& reg){
    //定数アドレスの下位
    const byte_t let_l = Fetch_from_PCaddr(ram, reg);
    //定数アドレスの上位
    const byte_t let_h = Fetch_from_PCaddr(ram, reg);
    //アドレスを返す
    return to_16bit(let_l, let_h);
}