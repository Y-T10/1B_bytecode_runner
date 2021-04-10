#include"access_reg.hpp"

byte_t& Acce_regaddr(const reg_addr_t& r_num, binary_code_t& ram, reg_t& reg){    
    //指定アドレスの参照を返す
    switch(r_num){
    case reg_addr_t::rB :
        return reg.m_gene.m_B;
    case reg_addr_t::rC :
        return reg.m_gene.m_C;
    case reg_addr_t::rD :
        return reg.m_gene.m_D;
    case reg_addr_t::rE :
        return reg.m_gene.m_E;
    case reg_addr_t::rH :
        return reg.m_gene.m_H;
    case reg_addr_t::rL :
        return reg.m_gene.m_L;
    case reg_addr_t::rA :
        return reg.m_A;
    case reg_addr_t::rHL:
        return ram[to_16bit(reg.m_gene.m_L, reg.m_gene.m_H)];
    }

    //ＨLへの参照を返す
    return reg.m_A;
}

const addr_t Read_PR(const pr_no_t& pr_num, reg_t& reg){
    //番号ごとに値を返す
    switch(pr_num){
        case pr_no_t::prBC: return to_16bit(reg.m_gene.m_C, reg.m_gene.m_B);
        case pr_no_t::prDE: return to_16bit(reg.m_gene.m_E, reg.m_gene.m_D);
        case pr_no_t::prHL: return to_16bit(reg.m_gene.m_L, reg.m_gene.m_H);
        case pr_no_t::prSP: break;
    }

    assert(pr_num == pr_no_t::prSP);
    //SPの値を返す
    return reg.m_sp;
}

void Write_PR(const pr_no_t& pr_num, reg_t& reg, const addr_t& val16){
    //値を2分割する
    const auto bit16_lh = to_8bit2(val16);

    //番号ごとに値を書き込む
    switch(pr_num){
        case pr_no_t::prBC:
        reg.m_gene.m_B = bit16_lh.second;
        reg.m_gene.m_C = bit16_lh.first;
        return;

        case pr_no_t::prDE:
        reg.m_gene.m_D = bit16_lh.second;
        reg.m_gene.m_E = bit16_lh.first;
        return;

        case pr_no_t::prHL:
        reg.m_gene.m_H = bit16_lh.second;
        reg.m_gene.m_L = bit16_lh.first;
        return;

        case pr_no_t::prSP:
        reg.m_sp = val16;
        return;
    }
}

const addr_t Read_Pp(const stk_pr_no_t& pp_num, reg_t& reg){
    //番号ごとに値を返す
    switch(pp_num){
        case stk_pr_no_t::ppBC: return to_16bit(reg.m_gene.m_C, reg.m_gene.m_B);
        case stk_pr_no_t::ppDE: return to_16bit(reg.m_gene.m_E, reg.m_gene.m_D);
        case stk_pr_no_t::ppHL: return to_16bit(reg.m_gene.m_L, reg.m_gene.m_H);
        case stk_pr_no_t::ppAF: break;
    }

    assert(pp_num == stk_pr_no_t::ppAF);
    //AFを返す
    return to_16bit(reg.m_A, to_byte(reg.m_F));
}

void Write_Pp(const stk_pr_no_t& pp_num, reg_t& reg, const addr_t& val16){
    //値を2分割する
    const auto bit16_lh = to_8bit2(val16);

    //番号ごとに値を書き込む
    switch(pp_num){
        case stk_pr_no_t::ppBC:
        reg.m_gene.m_B = bit16_lh.second;
        reg.m_gene.m_C = bit16_lh.first;
        return;

        case stk_pr_no_t::ppDE:
        reg.m_gene.m_D = bit16_lh.second;
        reg.m_gene.m_E = bit16_lh.first;
        return;

        case stk_pr_no_t::ppHL:
        reg.m_gene.m_H = bit16_lh.second;
        reg.m_gene.m_L = bit16_lh.first;
        return;

        case stk_pr_no_t::ppAF:
        reg.m_A = bit16_lh.second;
        reg.m_F = bit16_lh.first;
        return;
    }
}
///フラグ番号が指すフラグへの参照を返す
const bool Acce_CCC(const ccc_no_t& r_num, reg_t& reg){
    //フラグ番号に該当するフラグを返す
    switch(r_num){
    case ccc_no_t::ccNZ: return ~(reg.m_F[cc_addr_t::fZ]); //Z != 0
    case ccc_no_t::ccZ : return   reg.m_F[cc_addr_t::fZ] ; //Z == 0
    case ccc_no_t::ccNC: return ~(reg.m_F[cc_addr_t::fC]); //C != 1
    case ccc_no_t::ccC : return   reg.m_F[cc_addr_t::fC] ; //C == 1
    case ccc_no_t::ccPO: return ~reg.m_F[cc_addr_t::fPV] ; //Pが奇数
    case ccc_no_t::ccPE: return   reg.m_F[cc_addr_t::fPV]; //Pが偶数
    case ccc_no_t::ccP : return  ~reg.m_F[cc_addr_t::fS] ; //正の数
    case ccc_no_t::ccM : break;                            //負の数
    }

    assert(r_num == ccc_no_t::ccM);
    //Mのフラグを返す
    return   reg.m_F[cc_addr_t::fS] ; //負の数
}