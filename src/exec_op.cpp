#include"exec_op.hpp"

const bool Exec_1Bop(const byte_t& op, const op_id_set_t& id, binary_code_t& ram, reg_t& reg){
    //番号と関数のリストを取得する
    const id_func_ptr f_list_ptr = op_func_list::func_list();
    assert(f_list_ptr);
    //リスト外のidかを判断する
    if(!f_list_ptr->contains(id)){
        //失敗
        return false;
    }

    //opに対する処理を実行する
    f_list_ptr->at(id)(op, ram, reg);

    //成功
    return true;
}