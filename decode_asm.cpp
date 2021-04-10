#include"decode_asm.hpp"

const bool Is_prefix_code(const byte_t& op){
    //追加命令の接頭値かを判断する
    if(op_pref_set_t::added == op){
        //接頭値だと判断する
        return true;
    }

    //拡張命令の接頭値かを判断する
    if(op_pref_set_t::ext == op){
        //接頭値だと判断する
        return true;
    }

    //IXを伴う命令の接頭値かを判断する
    if(op_pref_set_t::ix == op){
        //接頭値だと判断する
        return true;
    }

    //IYを伴う命令の接頭値かを判断する
    if(op_pref_set_t::iy == op){
        //接頭値だと判断する
        return true;
    }

    //1バイトオペコードだと判断する
    return false;
}

const op_id_set_t Decode_1Bop(const uint8_t& op, const filter_t& filters){
    //フィルターで検索する
    for(auto f: filters){
        //パターンに一致するかを判断する
        if(Eval_filter(op, f)){
            //識別値を返す
            return static_cast<op_id_set_t>(to_byte(f.src));
        }
    }

    //NOPを返す
    return op_id_set_t::NOP;
}