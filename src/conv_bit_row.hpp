/**
 * 8, 16, 32bit間の変換機能を定める
 */

#ifndef CONV_BIT_ROW
#define CONV_BIT_ROW

#include"binary_type.hpp"

/**
 * bit8_setをbyte_tに変換する
 * @param bit8 bit8_setの値
 * @return 変換した値
 */
const byte_t to_byte(const bit8_set& bit8);

///リトルエンディアンでアドレス値を2つのバイト値から生成する
const addr_t to_16bit(const byte_t& l, const byte_t& h);

///bool値を8bit値に拡大する
const byte_t to_8bit(const bool& bit);

/**
 * リトルエンディアンで2バイト値をアドレスから生成する
 * @param first  下位8ビット
 * @param second 上位8ビット
 */
const std::pair<byte_t, byte_t> to_8bit2(const addr_t& addr);

/**
 * リトルエンディアンで32bit値の上下を取得する
 * @param first  下位16ビット
 * @param second 上位16ビット
 */
const std::pair<addr_t, addr_t> to_16bit2(const daddr_t& addr);

#endif