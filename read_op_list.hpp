/**
 * オペコード識別用のフィルタをCSVファイルから生成する機能を定める。
 */

#ifndef READ_OP_LIST_HEADER
#define READ_OP_LIST_HEADER

#include"filter_type.hpp"
#include<string>
#include<cstdio>
#include<fstream>
#include<cassert>
#include<regex>
#include<algorithm>

const filter_t Read_op_list(const std::string& file_path);

#endif