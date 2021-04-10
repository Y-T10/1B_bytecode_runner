/**
 * 命令を実行する関数を持つリストを提供する機能を定める。
 */

#ifndef EXEC_FUNC_LIST_HEADER
#define EXEC_FUNC_LIST_HEADER

#include"op_types.hpp"
#include"binary_type.hpp"
#include"register.hpp"
#include"fetch_data.hpp"
#include"fetch_num.hpp"
#include"access_reg.hpp"
#include"cal_op.hpp"
#include<memory>
#include<map>
#include<functional>
#include<iostream>
#include<cstdio>

/**
 * 命令に対応する関数の型
 * @param op オペコード
 * @param ram RAM
 * @param reg レジスタ
 */
using op_func = void(const byte_t& op, binary_code_t& ram, reg_t& reg);

///op_funcの関数オブジェクト型
using op_func_t = std::function<void(const byte_t&, binary_code_t&, reg_t&)>;

///識別値を鍵とするop_func_tのリスト型
using id_func_list_t = std::map<op_id_set_t,op_func_t>;

///id_func_list_tのポインタ型
using id_func_ptr = std::shared_ptr<id_func_list_t>;

///関数のリストを提供するクラス
class op_func_list{
    static id_func_ptr id_func_list_ptr;

    ///コンストラクタ
    explicit op_func_list() noexcept;
    public:
    explicit op_func_list(const op_func_list& rval) noexcept = delete;

    ///関数リストを返す
    static const id_func_ptr func_list();
};

#endif