/**
 * バイナリファイルを読み込む機能を定める。
 */

#ifndef READ_BIN_FILE_HEADER
#define READ_BIN_FILE_HEADER

#include<cassert>
#include"binary_type.hpp"
#include<string>
#include<filesystem>
#include<cstdio>

///存在するプログラムファイルを読み込む
const binary_code_t Read_prog_file(const std::string& name);

#endif