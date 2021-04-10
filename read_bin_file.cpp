#include"read_bin_file.hpp"

///ファイルヘッダ型
using fh_t = FILE*;

///存在するプログラムファイルを読み込む
const binary_code_t Read_prog_file(const std::string& name){
    assert(!name.empty());
    assert(std::filesystem::exists(name));

    //バイナリファイルを読み込む
    fh_t fp = fopen(name.data(), "rb");

    //ファイルの読み込みに失敗したかを判断する
    if(fp == NULL){
        //空を返す
        return {};
    }

    //ファイルサイズを求める
    const std::size_t prog_size = std::filesystem::file_size(name);

    //バイナリデータ保存領域を確保する
    binary_code_t prog_data;
    prog_data.reserve(prog_size);

    //バイナリデータを読み込む
    while(feof(fp) == 0){
        //読み込んだ値
        byte_t dst = 0;
        //ファイルから1バイト読み込む
        fread(&dst, sizeof(byte_t), 1, fp);
        //値を追加する
        prog_data.emplace_back(dst);
    }

    //ファイルを閉じる
    fclose(fp);

    //読み込んだプログラムデータを書き出す。
    return prog_data;
}