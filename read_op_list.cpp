#include"read_op_list.hpp"

const bit8_set to_bit8_set(const std::string& bit8_str);

const std::string regex_replace(const std::string& str, const std::string& src, const std::string& pattern);
const bit8_set create_src(const std::string& bit_str);
const bit8_set create_mask(const std::string& bit_str);

const filter_t Read_op_list(const std::string& file_path){
    assert(!file_path.empty());

    //csvファイルを読み取る。
    std::ifstream op_list_file(file_path);

    //ファイルを開けたかを判断する
    if(!op_list_file){
        //空データを返す
        return {};
    }

    //フィルターリスト
    filter_t f_list = {};

    //一行づつ読む
    for(std::string one_line = ""; std::getline(op_list_file, one_line);){
        //バイナリ表現ののフォーマット
        std::string binary_str = "00000000";
        //フォーマットを読む
        binary_str = regex_replace(one_line, "0b", "");

        //フィルタを生成する
        const bit_pattern_t f = {create_mask(binary_str), create_src(binary_str)};

        //フィルターを追加する
        f_list.emplace_back(f);
    }

    return f_list;
}

const bit8_set to_bit8_set(const std::string& bit8_str){
    assert(bit8_str.size() == 8);

    //取得した文字列を逆にする
    std::string reverse_str = bit8_str;
    std::reverse(reverse_str.begin(), reverse_str.end());

    //変換された値
    bit8_set bit8_val = 0b00000000;

    for(size_t i = 0; i < bit8_val.size(); ++i){
        bit8_val[i] = (reverse_str[i] == '1');
    }

    return bit8_val;
}

const std::string regex_replace(const std::string& str, const std::string& src, const std::string& pattern){
    //パターンをsrc向けに置換する
    return std::regex_replace(str, std::regex(src), pattern);
}

//replace([x-2,y], "[^01]", 0, 0, 1)
const bit8_set create_src(const std::string& bit_str){
    assert(bit_str.size() == 8);

    //0,1以外をを0に置換する
    const std::string src_str = regex_replace(bit_str, "[^01]", "0");

    //置換によって得られて文字列から値を生成する
    return to_bit8_set(src_str);
}

//replace(replace([x-1,y], "[01]", 1, 0, 1), "[^10]", 0, 0, 1)
const bit8_set create_mask(const std::string& bit_str){
    //0,1を1に置換する
    const std::string mask_1_str = regex_replace(bit_str, "[01]", "1");

    //0,1以外を0に置換する
    const std::string mask_str   = regex_replace(mask_1_str, "[^01]", "0");

    //置換によって得られて文字列から値を生成する
    return to_bit8_set(mask_str);
}