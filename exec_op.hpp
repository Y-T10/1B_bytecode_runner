/**
 * オペコードの識別値から命令の処理を実行する機能を定める。
 */

#ifndef EXEC_OP_HEADER
#define EXEC_OP_HEADER

#include"exec_func_list.hpp"
#include"op_types.hpp"
#include"binary_type.hpp"
#include"register.hpp"
#include<map>
#include<functional>
#include<cassert>

/**
 * 1バイト命令を実行する
 * @param op op
 * @param id opのID
 * @param ram RAM
 * @param reg レジスタ
 * @return true 実行成功
 * @return false 実行失敗
*/
const bool Exec_1Bop(const byte_t& op, const op_id_set_t& id, binary_code_t& ram, reg_t& reg);

#endif