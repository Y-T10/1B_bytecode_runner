#include"register.hpp"
#include"decode_asm.hpp"
#include"read_bin_file.hpp"
#include"fetch_data.hpp"
#include"exec_op.hpp"
#include"conv_bit_row.hpp"
#include<iostream>
#include<cassert>
#include<string>
#include<filesystem>
#include<cstdio>

///プログラムの終了を判断する
const bool Check_finish(const byte_t& op);

///regの中身を出力する
void Print_reg_all(const reg_t& reg);

int main(int argc, char** argv){
    //バイナリファイルが指定されているかを判断する
    if(argc < 2){
        //プログラム名を取得する
        const auto prog_name = std::filesystem::path(argv[0]).filename();
        //使用法を出力する
        std::cerr << "usage: " << prog_name << " binary_file_path" << std::endl;
        return 1;
    }

    //バイナリファイルの名前を取得する
    const std::string prog_fname = std::string(argv[1]);
    assert(!prog_fname.empty());

    //ファイルが存在するかを判断する
    if(std::filesystem::exists(prog_fname) == false){
        std::cerr << "ファイルが存在しません" << std::endl;
        return 1;
    }

    //バイナリファイルをRAMに読み込む
    binary_code_t ram = Read_prog_file(prog_fname);
    
    //レジスタ
    reg_t reg = { 0 };
    //SPを設定する
    reg.m_sp = bit16_addr_size - 1;

    //プログラムの実行を知らせる
    std::cerr << "--program start--" << std::endl;

    //プログラムを実行する
    while(true){
        //opコードを取り出す
        const byte_t op = Fetch_from_PCaddr(ram, reg);

        //opコードが1バイト命令かを判断する
        if(Is_prefix_code(op) == false){
            //opをデコードする
            const op_id_set_t op_id = Decode_1Bop(op, *(decode_filter::filter()));

            //命令を実行する
            Exec_1Bop(op, op_id, ram, reg);
        }

        //プログラムが終了したかを判断する
        if(Check_finish(op)){
            break;
        }
    }

    //プログラムの実行を知らせる
    std::cerr << "--program end--\n" << std::endl;

    std::cerr << "--register state--" << std::endl;
    //実行後のレジスタを表示する
    Print_reg_all(reg);

    return 0;
}

const bool Check_finish(const byte_t& op){
    //Haltが実行されたかを判断する
    return op == op_id_set_t::HALT;
}

void Print_reg_all(const reg_t& reg){
    //汎用レジスタの値を書き出す
    fprintf(stderr, "(A, F) = (0x%02hhx, 0x%02hhx)\n", reg.m_A       , to_byte(reg.m_F));
    fprintf(stderr, "(B, C) = (0x%02hhx, 0x%02hhx)\n", reg.m_gene.m_B, reg.m_gene.m_C);
    fprintf(stderr, "(D, E) = (0x%02hhx, 0x%02hhx)\n", reg.m_gene.m_D, reg.m_gene.m_E);
    fprintf(stderr, "(H, L) = (0x%02hhx, 0x%02hhx)\n", reg.m_gene.m_H, reg.m_gene.m_L);

    //PC, SPの値を書き出す
    fprintf(stderr, "PC: %hu\n", reg.m_pc);
    fprintf(stderr, "SP: %hu\n", reg.m_sp);

    //フラグレジスタの値を書き出す
    const char* true_str = "true";
    const char* false_str = "false";
    fprintf(stderr, "PV: %s\n", reg.m_F[cc_addr_t::fPV]? true_str : false_str);
    fprintf(stderr, "S:  %s\n", reg.m_F[cc_addr_t::fS] ? true_str : false_str);
    fprintf(stderr, "Z:  %s\n", reg.m_F[cc_addr_t::fZ] ? true_str : false_str);
    fprintf(stderr, "C:  %s\n", reg.m_F[cc_addr_t::fC] ? true_str : false_str);
}