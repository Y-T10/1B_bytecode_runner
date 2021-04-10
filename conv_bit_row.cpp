#include"conv_bit_row.hpp"

const byte_t to_byte(const bit8_set& bit_set_var){
    //8bit値
    byte_t bit8 = 0;

    for(size_t i = 0; i < bit_num_per_1B; ++i){
        bit8 |= (bit_set_var[i] << i);
    }

    //値を返す
    return bit8;
}

const addr_t to_16bit(const byte_t& l, const byte_t& h){
    //2byteのビット列
    byte_t bit16_lh[2] = {l, h};
    //16bit値
    addr_t bit16;
    static_assert(sizeof(bit16) == sizeof(bit16_lh));

    //値をコピーする
    memcpy(&bit16, bit16_lh, sizeof(bit16_lh));

    //16bit値を生成する
    return bit16;
}

const std::pair<byte_t, byte_t> to_8bit2(const addr_t& addr){
    //2byteのビット列{l, h}
    byte_t bit16_lh[2] = { 0 };
    static_assert(sizeof(addr) == sizeof(bit16_lh));

    //値をコピーする
    memcpy(bit16_lh, &addr, sizeof(bit16_lh));

    //16bit値を生成する
    return {bit16_lh[0], bit16_lh[1]};
}

const std::pair<addr_t, addr_t> to_16bit2(const daddr_t& addr){
    //2byteのビット列{l, h}
    addr_t bit32_lh[2] = { 0 };
    static_assert(sizeof(addr) == sizeof(bit32_lh));

    //値をコピーする
    memcpy(bit32_lh, &addr, sizeof(bit32_lh));

    //16bit値を生成する
    return {bit32_lh[0], bit32_lh[1]};
}

const byte_t to_8bit(const bool& bit){
    //rue->0x01, false-> 0x0;
    return (bit)? 0x01: 0x00;
}