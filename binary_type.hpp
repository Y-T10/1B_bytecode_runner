/**
 * プログラム内で使用するバイト値やアドレス値の情報を定める。
 */

#ifndef BINARY_TYPE_HEADER
#define BINARY_TYPE_HEADER

#include<cstdint>
#include<bitset>
#include<vector>
#include<climits>

//32ビットアドレスの型
using daddr_t = std::uint32_t;

///16ビットアドレスの型
using addr_t = std::uint16_t;

///バイト型
using byte_t = uint8_t;

///1バイト当たりのビット数
static_assert(CHAR_BIT == 8);
const std::size_t bit_num_per_1B = CHAR_BIT;

///16bitアドレスの範囲
static_assert(USHRT_MAX == 65535);
const std::size_t bit16_addr_size = USHRT_MAX + 1;

///8ビット列を扱う型
using bit8_set = std::bitset<bit_num_per_1B>;

///8ビットデータ列型
using binary_code_t = std::vector<byte_t>;

#endif