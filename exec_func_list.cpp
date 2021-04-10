#include"exec_func_list.hpp"
#include<cassert>

const op_func ld_r_r         ;
const op_func ld_r_ab        ;
const op_func ld_aBC_A       ;
const op_func ld_aDE_A       ;
const op_func ld_A_aBC       ;
const op_func ld_A_aDE       ;
const op_func ld_a0xabcd_A   ;
const op_func ld_A_a0xabcd   ;
const op_func ld_SP_HL       ;
const op_func ld_a0xabcd_HL  ;
const op_func ld_pr_0xabcd   ;
const op_func ld_HL_a0xabcd  ;
const op_func pop_Pp         ;
const op_func push_Pp        ;
const op_func ex_DE_HL       ;
const op_func ex_aSP_HL      ;
const op_func cal_r          ;
const op_func inc_r          ;
const op_func dec_r          ;
const op_func cal_0xab       ;
const op_func add_HL_pr      ;
const op_func inc_pr         ;
const op_func dec_pr         ;
const op_func cpl            ;
const op_func ccf            ;
const op_func scf            ;
const op_func jp_0xabcd      ;
const op_func jp_CCC_0xabcd  ;
const op_func jp_aHL         ;
const op_func call_0xabcd    ;
const op_func call_CCC_0xabcd;
const op_func ret            ;
const op_func ret_CCC        ;
const op_func rst_ttt        ;
const op_func halt           ;
const op_func nop            ;
const op_func di             ;
const op_func ei             ;
const op_func out_n0xab_A    ;
const op_func in_A_n0xab     ;
const op_func rlca           ;
const op_func rla            ;
const op_func rrca           ;
const op_func rra            ;
const op_func daa            ;

///リセット先アドレスを取り出す
const addr_t Res_ttt(const byte_t& op){
    ///リセット時のアドレスを取り出す
    const byte_t op_src = op & 0b00111000;

    ///ソースを取り出して返す
    return static_cast<addr_t>(op_src);
}

id_func_ptr op_func_list::id_func_list_ptr = {};

const id_func_ptr op_func_list::func_list(){
    //実体が生成されているか判断する
    if(id_func_list_ptr){
        //実体を返す
        return id_func_list_ptr;
    }
    //実体を生成する
    id_func_list_ptr = std::make_shared<id_func_ptr::element_type>();

    //リストを生成する
    id_func_list_ptr->emplace(LD_r_r         ,ld_r_r         );
    id_func_list_ptr->emplace(LD_r_0xab      ,ld_r_ab        );
    id_func_list_ptr->emplace(LD_aBC_A       ,ld_aBC_A       );
    id_func_list_ptr->emplace(LD_aDE_A       ,ld_aDE_A       );
    id_func_list_ptr->emplace(LD_A_aBC       ,ld_A_aBC       );
    id_func_list_ptr->emplace(LD_A_aDE       ,ld_A_aDE       );
    id_func_list_ptr->emplace(LD_a0xabcd_A   ,ld_a0xabcd_A   );
    id_func_list_ptr->emplace(LD_A_a0xabcd   ,ld_A_a0xabcd   );
    id_func_list_ptr->emplace(LD_SP_HL       ,ld_SP_HL       );
    id_func_list_ptr->emplace(LD_a0xabcd_HL  ,ld_a0xabcd_HL  );
    id_func_list_ptr->emplace(LD_pr_0xabcd   ,ld_pr_0xabcd   );
    id_func_list_ptr->emplace(LD_HL_a0xabcd  ,ld_HL_a0xabcd  );
    id_func_list_ptr->emplace(POP_Pp         ,pop_Pp         );
    id_func_list_ptr->emplace(PUSH_Pp        ,push_Pp        );
    id_func_list_ptr->emplace(EX_DE_HL       ,ex_DE_HL       );
    id_func_list_ptr->emplace(EX_aSP_HL      ,ex_aSP_HL      );
    id_func_list_ptr->emplace(CAL_r          ,cal_r          );
    id_func_list_ptr->emplace(INC_r          ,inc_r          );
    id_func_list_ptr->emplace(DEC_r          ,dec_r          );
    id_func_list_ptr->emplace(CAL_0xab       ,cal_0xab       );
    id_func_list_ptr->emplace(ADD_HL_pr      ,add_HL_pr      );
    id_func_list_ptr->emplace(INC_pr         ,inc_pr         );
    id_func_list_ptr->emplace(DEC_pr         ,dec_pr         );
    id_func_list_ptr->emplace(CPL            ,cpl            );
    id_func_list_ptr->emplace(CCF            ,ccf            );
    id_func_list_ptr->emplace(SCF            ,scf            );
    id_func_list_ptr->emplace(JP_0xabcd      ,jp_0xabcd      );
    id_func_list_ptr->emplace(JP_CCC_0xabcd  ,jp_CCC_0xabcd  );
    id_func_list_ptr->emplace(JP_aHL         ,jp_aHL         );
    id_func_list_ptr->emplace(CALL_0xabcd    ,call_0xabcd    );
    id_func_list_ptr->emplace(CALL_CCC_0xabcd,call_CCC_0xabcd);
    id_func_list_ptr->emplace(RET            ,ret            );
    id_func_list_ptr->emplace(RET_CCC        ,ret_CCC        );
    id_func_list_ptr->emplace(RST_ttt        ,rst_ttt        );
    id_func_list_ptr->emplace(HALT           ,halt           );
    id_func_list_ptr->emplace(NOP            ,nop            );
    id_func_list_ptr->emplace(DI             ,di             );
    id_func_list_ptr->emplace(EI             ,ei             );
    id_func_list_ptr->emplace(OUT_n0xab_A    ,out_n0xab_A    );
    id_func_list_ptr->emplace(IN_A_n0xab     ,in_A_n0xab     );
    id_func_list_ptr->emplace(RLCA           ,rlca           );
    id_func_list_ptr->emplace(RLA            ,rla            );
    id_func_list_ptr->emplace(RRCA           ,rrca           );
    id_func_list_ptr->emplace(RRA            ,rra            );
    id_func_list_ptr->emplace(DAA            ,daa            );

    //リストを返す
    return id_func_list_ptr;
}

void ld_r_r         (const byte_t& op, binary_code_t& ram, reg_t& reg){
    assert(RegAddr_dst(op) != reg_addr_t::rHL || RegAddr_src(op) != reg_addr_t::rHL );

    //値をコピーする
    Acce_regaddr(RegAddr_dst(op), ram, reg) = Acce_regaddr(RegAddr_src(op), ram, reg);
}
void ld_r_ab        (const byte_t& op, binary_code_t& ram, reg_t& reg){
    //定数を代入する
    Acce_regaddr(RegAddr_dst(op), ram, reg) = Fetch_from_PCaddr(ram, reg);
}
void ld_aBC_A       (const byte_t& op, binary_code_t& ram, reg_t& reg){
    //アドレス
    const addr_t addr = to_16bit(reg.m_gene.m_B, reg.m_gene.m_C);
    //アドレス先に書き込む
    ram[addr] = reg.m_A;
}
void ld_aDE_A       (const byte_t& op, binary_code_t& ram, reg_t& reg){
    //アドレス
    const addr_t addr = to_16bit(reg.m_gene.m_D, reg.m_gene.m_E);
    //アドレス先に書き込む
    ram[addr] = reg.m_A;
}
void ld_A_aBC       (const byte_t& op, binary_code_t& ram, reg_t& reg){
    //アドレス
    const addr_t addr = to_16bit(reg.m_gene.m_B, reg.m_gene.m_C);
    //アドレス先に書き込む
    reg.m_A = ram[addr];
}
void ld_A_aDE       (const byte_t& op, binary_code_t& ram, reg_t& reg){
    //アドレス
    const addr_t addr = to_16bit(reg.m_gene.m_D, reg.m_gene.m_E);
    //アドレス先に書き込む
    reg.m_A = ram[addr];
}
void ld_a0xabcd_A   (const byte_t& op, binary_code_t& ram, reg_t& reg){
    //アドレス
    const addr_t addr = Fetch_16bit_from_PCaddr(ram, reg);

    //アドレス先に書き込む
    ram[addr] = reg.m_A;
}
void ld_A_a0xabcd   (const byte_t& op, binary_code_t& ram, reg_t& reg){
    //アドレス
    const addr_t addr = Fetch_16bit_from_PCaddr(ram, reg);

    //アドレス先に書き込む
    reg.m_A = ram[addr];
}
void ld_SP_HL       (const byte_t& op, binary_code_t& ram, reg_t& reg){
    //SPにHLの値を入れる
    reg.m_sp = to_16bit(reg.m_gene.m_L, reg.m_gene.m_H);
}
void ld_a0xabcd_HL  (const byte_t& op, binary_code_t& ram, reg_t& reg){
    //アドレス
    const addr_t addr = Fetch_16bit_from_PCaddr(ram, reg);

    //値を入れる
    ram[addr]     = reg.m_gene.m_L;
    ram[addr + 1] = reg.m_gene.m_H;
}
void ld_pr_0xabcd   (const byte_t& op, binary_code_t& ram, reg_t& reg){
    //アドレス
    const addr_t val = Fetch_16bit_from_PCaddr(ram, reg);
    //ペアレジスタに値を書き込む
    Write_PR(PR(op), reg, val);
}
void ld_HL_a0xabcd  (const byte_t& op, binary_code_t& ram, reg_t& reg){
    //アドレス
    const addr_t addr = Fetch_16bit_from_PCaddr(ram, reg);

    //値を入れる
    reg.m_gene.m_L = ram[addr]    ;
    reg.m_gene.m_H = ram[addr + 1];
}
void pop_Pp         (const byte_t& op, binary_code_t& ram, reg_t& reg){
    //スタックから16bit値を取り出す
    const byte_t stack_l = ram[reg.m_sp];
    const byte_t stack_h = ram[reg.m_sp + 1];
    //スタックをPOPする
    reg.m_sp += 2;

    //ペアレジスタに値を代入する
    Write_Pp(Pp(op), reg, to_16bit(stack_l, stack_h));
}
void push_Pp        (const byte_t& op, binary_code_t& ram, reg_t& reg){
    //ペアレジスタから値を読み出す
    const auto val16_lh = to_8bit2(Read_Pp(Pp(op), reg));

    //スタックに16bit値を書き出す
    ram[reg.m_sp - 1] = val16_lh.second;
    ram[reg.m_sp - 2] = val16_lh.first ;
    //スタックをPUSHする
    reg.m_sp -= 2;
}
void ex_DE_HL       (const byte_t& op, binary_code_t& ram, reg_t& reg){
    //値を交換する
    std::swap(reg.m_gene.m_D, reg.m_gene.m_H);
    std::swap(reg.m_gene.m_E, reg.m_gene.m_L);
}
void ex_aSP_HL      (const byte_t& op, binary_code_t& ram, reg_t& reg){
    //値を交換する
    std::swap(ram[reg.m_sp    ], reg.m_gene.m_L);
    std::swap(ram[reg.m_sp + 1], reg.m_gene.m_H);
}
void cal_r          (const byte_t& op, binary_code_t& ram, reg_t& reg){
    //演算子の右側への参照を受け取る
    const byte_t& or_rval_ref = Acce_regaddr(RegAddr_src(op), ram, reg);
    //演算を行い、フラグを設定する
    const byte_t res = calc8(Cal_num(op), reg.m_A, or_rval_ref, reg.m_F);
    //サインフラグを設定する
    reg.m_F[cc_addr_t::fS] = bit8_set(res)[7];
    //ゼロフラグを設定する
    reg.m_F[cc_addr_t::fZ] = bit8_set(res).none();
    //比較演算子ではないかを判断する
   if(Cal_num(op) != cal_no_t::CP){
        //Aを更新する
        reg.m_A = res;
    }
}
void inc_r          (const byte_t& op, binary_code_t& ram, reg_t& reg){
    //演算子の右側への参照を受け取る
    byte_t& or_rval_ref = Acce_regaddr(RegAddr_dst(op), ram, reg);
    //演算を行い、フラグを設定する
    or_rval_ref = calc8(cal_no_t::ADD, or_rval_ref, 1, reg.m_F);
    //サインフラグを設定する
    reg.m_F[cc_addr_t::fS] = bit8_set(or_rval_ref)[7];
    //ゼロフラグを設定する
    reg.m_F[cc_addr_t::fZ] = bit8_set(or_rval_ref).none();
}
void dec_r          (const byte_t& op, binary_code_t& ram, reg_t& reg){
    //演算子の右側への参照を受け取る
    byte_t& or_rval_ref = Acce_regaddr(RegAddr_dst(op), ram, reg);
    //演算を行い、フラグを設定する
    or_rval_ref = calc8(cal_no_t::SUB, or_rval_ref, 1, reg.m_F);
    //サインフラグを設定する
    reg.m_F[cc_addr_t::fS] = bit8_set(or_rval_ref)[7];
    //ゼロフラグを設定する
    reg.m_F[cc_addr_t::fZ] = bit8_set(or_rval_ref).none();
}
void cal_0xab       (const byte_t& op, binary_code_t& ram, reg_t& reg){
    //演算の右辺値を取り出す
    const byte_t or_rval = Fetch_from_PCaddr(ram, reg);
    //演算を行い、フラグを設定する
    const byte_t res = calc8(Cal_num(op), reg.m_A, or_rval, reg.m_F);
    //サインフラグを設定する
    reg.m_F[cc_addr_t::fS] = bit8_set(res)[7];
    //ゼロフラグを設定する
    reg.m_F[cc_addr_t::fZ] = bit8_set(res).none();
    //比較演算子ではないかを判断する
    if(Cal_num(op) != cal_no_t::CP){
        //Aを更新する
        reg.m_A = res;
    }
}
void add_HL_pr      (const byte_t& op, binary_code_t& ram, reg_t& reg){
    //ペアレジスタ番号
    const pr_no_t pr_num = PR(op);
    //ペアレジスタとHLの合計を求める
    const daddr_t sum32_hl_pr = (daddr_t)Read_PR(pr_num, reg) + (daddr_t)Read_PR(pr_no_t::prHL, reg);
    //上下16bitを取得する
    const auto sum32_hl = to_16bit2(sum32_hl_pr);
    //フラグを設定する
    reg.m_F[cc_addr_t::fC] = sum32_hl.second & 0x0001; //キャリフラグ
    //合計値をHLに書く
    Write_PR(pr_no_t::prHL, reg, sum32_hl.first);
}
void inc_pr         (const byte_t& op, binary_code_t& ram, reg_t& reg){
    //ペアレジスタ番号
    const pr_no_t pr_num = PR(op);
    //ペアレジスタの値を取得する
    const addr_t pr_val = Read_PR(pr_num, reg);
    //ペアレジスタの値を1上げる
    Write_PR(pr_num, reg, pr_val + (addr_t)(1));
}
void dec_pr         (const byte_t& op, binary_code_t& ram, reg_t& reg){
    //ペアレジスタ番号
    const pr_no_t pr_num = PR(op);
    //ペアレジスタの値を取得する
    const addr_t pr_val = Read_PR(pr_num, reg);
    //ペアレジスタの値を1上げる
    Write_PR(pr_num, reg, pr_val - (addr_t)(1));
}
void cpl            (const byte_t& op, binary_code_t& ram, reg_t& reg){
    //Aの補数を求める
    reg.m_A = ~reg.m_A;
}
void rlca           (const byte_t& op, binary_code_t& ram, reg_t& reg){
    //変更前のA
    const bit8_set before_A = reg.m_A;
    //変更後のA
    bit8_set after_A = 0x00;
    //Cを更新する
    reg.m_F[cc_addr_t::fC] = before_A[7];
    //全体を左に回す
    after_A = before_A << 1;
    //0に7の値を入れる
    after_A[0] = before_A[7];

    //Aの更新
    reg.m_A = to_byte(after_A);
}
void rla            (const byte_t& op, binary_code_t& ram, reg_t& reg){
    //変更前のA
    const bit8_set before_A = reg.m_A;
    //変更後のA
    bit8_set after_A = 0x00;
    //変更前のC
    const bool brefore_C = reg.m_F[cc_addr_t::fC];
    //キャリの更新
    reg.m_F[cc_addr_t::fC] = before_A[7];
    //全体を左にずらす
    after_A = before_A << 1;
    //末端にCの値を入れる
    after_A[0] = brefore_C;

    //Aの更新
    reg.m_A = to_byte(after_A);
}
void rrca           (const byte_t& op, binary_code_t& ram, reg_t& reg){
    //変更前のA
    const bit8_set before_A = reg.m_A;
    //変更後のA
    bit8_set after_A = 0x00;
    //Cを更新する
    reg.m_F[cc_addr_t::fC] = before_A[0];
    //全体を右に回す
    after_A = before_A >> 1;
    //A[7]にA[0]の値を入れる
    after_A[7] = before_A[0];

    //Aの更新
    reg.m_A = to_byte(after_A);
}
void rra            (const byte_t& op, binary_code_t& ram, reg_t& reg){
    //変更前のA
    const bit8_set before_A = reg.m_A;
    //変更後のA
    bit8_set after_A = 0x00;
    //変更前のC
    const bool brefore_C = reg.m_F[cc_addr_t::fC];
    //キャリの更新
    reg.m_F[cc_addr_t::fC] = before_A[0];
    //全体を右にずらす
    after_A = before_A >> 1;
    //先頭にCの値を入れる
    after_A[7] = brefore_C;

    //Aの更新
    reg.m_A = to_byte(after_A);
}
void ccf            (const byte_t& op, binary_code_t& ram, reg_t& reg){
    //キャリの補数にキャリを更新する
    reg.m_F[cc_addr_t::fC] = ~reg.m_F[cc_addr_t::fC];
}
void scf            (const byte_t& op, binary_code_t& ram, reg_t& reg){
    //キャリを1にする
    reg.m_F[cc_addr_t::fC] = 1;
}
void jp_0xabcd      (const byte_t& op, binary_code_t& ram, reg_t& reg){
    //ジャンプ先アドレスをPCに設定する
    reg.m_pc = Fetch_16bit_from_PCaddr(ram, reg);
}
void jp_CCC_0xabcd  (const byte_t& op, binary_code_t& ram, reg_t& reg){
    //ジャンプ先アドレスを取得する
    const addr_t jp_addr = Fetch_16bit_from_PCaddr(ram, reg);
    //条件が成立するかを判断する
    if(Acce_CCC(CCC(op), reg)){
        //JPの値を変更する
        reg.m_pc = jp_addr;
    }
}
void jp_aHL         (const byte_t& op, binary_code_t& ram, reg_t& reg){
    //HLの16bit値を取り出す
    const addr_t hl_addr = to_16bit(reg.m_gene.m_L, reg.m_gene.m_H);

    //PCをHLのアドレスに変更する
    reg.m_pc = hl_addr;
}
void call_0xabcd    (const byte_t& op, binary_code_t& ram, reg_t& reg){
    //プログラムカウンタの値を上下に2等分する
    const auto pc_hl = to_8bit2(reg.m_pc);
    //スタックに値を上げる
    ram[reg.m_sp - 1] = pc_hl.second;
    ram[reg.m_sp - 2] = pc_hl.first ;
    reg.m_sp -= 2;

    //ジャンプ先アドレスをPCに設定する
    reg.m_pc = Fetch_16bit_from_PCaddr(ram, reg);
}
void call_CCC_0xabcd(const byte_t& op, binary_code_t& ram, reg_t& reg){
    //ジャンプ先アドレスを取得する
    const addr_t jp_addr = Fetch_16bit_from_PCaddr(ram, reg);
    //条件が成立するかを判断する
    if(Acce_CCC(CCC(op), reg)){
        //プログラムカウンタの値を上下に2等分する
        const auto pc_hl = to_8bit2(reg.m_pc);
        //スタックに値を上げる
        ram[reg.m_sp - 1] = pc_hl.second;
        ram[reg.m_sp - 2] = pc_hl.first ;
        reg.m_sp -= 2;
        //JPの値を変更する
        reg.m_pc = jp_addr;
    }
}
void ret            (const byte_t& op, binary_code_t& ram, reg_t& reg){
    //PCの値を戻す
    reg.m_pc = to_16bit(ram[reg.m_sp], ram[reg.m_sp + 1]);
    //スタックをプッシュする
    reg.m_sp += 2;
}
void ret_CCC        (const byte_t& op, binary_code_t& ram, reg_t& reg){
    //条件が成立するかを判断する
    if(Acce_CCC(CCC(op), reg)){
        //PCの値を戻す
        reg.m_pc = to_16bit(ram[reg.m_sp], ram[reg.m_sp + 1]);
        //スタックをプッシュする
        reg.m_sp += 2;
    }
}
void rst_ttt        (const byte_t& op, binary_code_t& ram, reg_t& reg){
    //PCを2つに分ける
    const auto pc_pair = to_8bit2(reg.m_pc);
    //スタックに値を積む
    ram[reg.m_sp - 1] = pc_pair.second;
    ram[reg.m_sp - 2] = pc_pair.first ;
    reg.m_sp -= 2;

    //PCをリセットする
    reg.m_pc = Res_ttt(op);
}
void halt           (const byte_t& op, binary_code_t& ram, reg_t& reg){
    //何もしない
}
void nop            (const byte_t& op, binary_code_t& ram, reg_t& reg){
    //何もしない
}
void di             (const byte_t& op, binary_code_t& ram, reg_t& reg){
    //サポートされていない旨を知らせる
    std::cerr << "Not supported: DI" << std::endl;
}
void ei             (const byte_t& op, binary_code_t& ram, reg_t& reg){
    //サポートされていない旨を知らせる
    std::cerr << "Not supported: EI" << std::endl;
}
void out_n0xab_A    (const byte_t& op, binary_code_t& ram, reg_t& reg){
    //IOポート番号を取得する
    const byte_t port_num = Fetch_from_PCaddr(ram, reg);
    //が1かを判断する
    if(port_num == 1){
        //標準出力に値を書き出す
        std::cerr << "output: ";
        printf("0x%hhx", reg.m_A);
        std::cerr << std::endl;;
    }
    return;
}
void in_A_n0xab     (const byte_t& op, binary_code_t& ram, reg_t& reg){
    //IOポート番号を取得する
    const byte_t port_num = Fetch_from_PCaddr(ram, reg);
    //ポート番号が0かを判断する
    if(port_num == 0){
        //標準入力から値を読み込む
        std::cerr << "input: ";
        scanf("%hhx%*c", &reg.m_A);
    }

    return;
}
void daa            (const byte_t& op, binary_code_t& ram, reg_t& reg){
    //サポートされていない旨を知らせる
    std::cerr << "Not supported: DAA" << std::endl;
}