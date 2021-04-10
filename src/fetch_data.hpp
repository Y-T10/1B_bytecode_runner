/**
 * レジスタのPCに従いRAMからデータを取り出す機能を定める。
 */

#ifndef FETCH_DATA_HEADER
#define FETCH_DATA_HEADER

#include"binary_type.hpp"
#include"register.hpp"
#include"conv_bit_row.hpp"
#include<cassert>
#include<cstdint>

/**
 * PCが指すバイトを読み出す
 * @param ram RAMデータ
 * @param reg レジスタ
 * @return 読み出したバイトデータ
 */
const byte_t Fetch_from_PCaddr(const binary_code_t& ram, reg_t& reg);

/**
 * PCが指す16bit値をramから読み出す
 * @param ram RAMデータ
 * @param reg レジスタ
 * @return 読み出したバイトデータ
 */
const addr_t Fetch_16bit_from_PCaddr(const binary_code_t& ram, reg_t& reg);
#endif