#include"cal_op.hpp"

//パリティを見る
const bool has_parity(const byte_t& val);

//2の補数を取る
const byte_t comp8(const byte_t& val);

//8bitの加算とP/V, Cを設定する
const byte_t add8_set_f(const byte_t& src1, const byte_t& src2, bit8_set& f, const byte_t& C = 0x00);

//8bitの減算とP/V, Cを設定する
const byte_t sub8_set_f(const byte_t& src1, const byte_t& src2, bit8_set& f, const byte_t& C = 0x00);

const byte_t calc8(const cal_no_t& cal_num, const byte_t& src1, const byte_t& src2, bit8_set& f){
    assert(cal_num <= cal_no_t::CP);
    ///演算を区別する
    ///演算後にフラグを設定する(must)
    byte_t res = 0x00;
    switch(cal_num){
        case cal_no_t::ADD:
            return add8_set_f(src1, src2, f);
        case cal_no_t::ADC:
            return add8_set_f(src1, src2, f, to_8bit(f[cc_addr_t::fC]));
        case cal_no_t::SUB:
            return sub8_set_f(src1, src2, f);
        case cal_no_t::SBC:
            return sub8_set_f(src1, src2, f, to_8bit(f[cc_addr_t::fC]));
        case cal_no_t::AND:
            res = src1 & src2;
            f[cc_addr_t::fPV] = has_parity(res);
            f[cc_addr_t::fC] = false;
            return res;
        case cal_no_t::XOR:
            res = src1 ^ src2;
            f[cc_addr_t::fPV] = has_parity(res);
            f[cc_addr_t::fC] = false;
            return res;
        case cal_no_t::OR :
            res = src1 | src2;
            f[cc_addr_t::fPV] = has_parity(res);
            f[cc_addr_t::fC] = false;
            return res;
        case cal_no_t::CP :
            //引き算を実行する
            return calc8(cal_no_t::SUB, src1, src2, f);
    }

    //零を返す
    return 0;
}

const byte_t comp8(const byte_t& val){
    //2の補数を求める
    return ~val +1;
}

const byte_t add8_set_f(const byte_t& src1, const byte_t& src2, bit8_set& f, const byte_t& C){
    //キャリを含めた加算を行う
    const addr_t sum16 = (addr_t)src1 + (addr_t)src2 + (addr_t)C;
    //加算結果を上下に分ける
    const auto sum16_hl = to_8bit2(sum16);
    //演算結果からフラグを定める
    f[cc_addr_t::fC]  = bit8_set(sum16_hl.second)[0]; //Cフラグ
    f[cc_addr_t::fPV] = (sum16 > (src1 + src2));      //PVフラグ
    //計算結果を返す
    return sum16_hl.first;
}

const byte_t sub8_set_f(const byte_t& src1, const byte_t& src2, bit8_set& f, const byte_t& C){
    //キャリを含めた加算を行う
    const addr_t sum16 = (addr_t)src1 + (addr_t)comp8(src2) + (addr_t)comp8(C);
    //加算結果を上下に分ける
    const auto sum16_hl = to_8bit2(sum16);
    //オーバフローを調べる
    const bool is_same_sign_ab = (bit8_set(src1)[7] == bit8_set(src2)[7]);
    const bool is_diff_sign_aR = (bit8_set(src1)[7] != bit8_set(sum16_hl.second)[7]);
    //演算結果からフラグを定める
    f[cc_addr_t::fC]  = ~bit8_set(sum16_hl.second)[0];        //Cフラグ
    f[cc_addr_t::fPV] = (is_same_sign_ab && is_diff_sign_aR); //PVフラグ
    //計算結果を返す
    return sum16_hl.first;
}

const bool has_parity(const byte_t& val){
    //1の数を2で割った余りを求める
    const byte_t rest = bit8_set(val).count() % 2;
    //偶数個かを判断する
    return rest == 0;
}
