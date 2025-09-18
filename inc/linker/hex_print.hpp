#ifndef _hex_print_
#define _hex_print_

#include <iomanip>
#include <iostream>
#include <cstdint>
#include <vector>

std::string to_hex_8(uint32_t value);

std::string to_hex_2(uint8_t value);

uint8_t from_hex_8(const std::string& s);

uint32_t parseHex(const std::string& s);

#endif
